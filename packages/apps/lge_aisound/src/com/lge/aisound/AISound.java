/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.lge.aisound;

import android.content.ComponentName;
import android.content.Context;
import android.media.AudioAttributes;
import android.media.AudioDeviceCallback;
import android.media.AudioDeviceInfo;
import android.media.AudioManager;
import android.media.AudioPlaybackConfiguration;
import android.media.audiofx.AudioEffect;
import android.os.Handler;
import android.os.Looper;
import android.os.SystemProperties;
import android.service.quicksettings.TileService;
import android.util.Log;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.UUID;

public class AISound {
    private static final String TAG = "LGEAISound";

    public static final String PROPERTY_AISOUND_SWITCH = "persist.lge.audio.aisound.enable";
    public static final String PROPERTY_AISOUND_MODE = "persist.lge.audio.aisound.mode";

    // libaisound.so (aisound_pipeline) descriptor UUIDs
    private static final UUID EFFECT_TYPE_AISOUND =
            UUID.fromString("bfc26f7c-9714-11e9-bc42-526af7764f64");
    private static final UUID EFFECT_UUID_AISOUND =
            UUID.fromString("e1abd756-97b7-11e9-bc42-526af7764f64");

    // libaise_core.so parameter IDs
    private static final int PARAM_DEVICE = 0x2070;
    private static final int PARAM_SURROUND_ENABLE = 0x2071;
    private static final int PARAM_SURROUND_MODE = 0x2072;

    // audio_devices_t values expected by aise_core::setDevice
    private static final int AUDIO_DEVICE_OUT_SPEAKER = 0x2;
    private static final int AUDIO_DEVICE_OUT_WIRED_HEADSET = 0x4;

    private static final long REAPPLY_DELAY_MS = 200L;

    private static final Object sLock = new Object();
    private static final Map<Integer, AudioEffect> sEffects = new HashMap<>();
    private static boolean sDeviceCallbackRegistered = false;
    private static boolean sPlaybackCallbackRegistered = false;
    private static Handler sHandler;
    private static Runnable sPendingReapply;

    private static Handler getHandlerLocked() {
        if (sHandler == null) {
            sHandler = new Handler(Looper.getMainLooper());
        }
        return sHandler;
    }

    private static int getOutputDeviceMask(Context context) {
        AudioManager am = context.getSystemService(AudioManager.class);
        if (am != null) {
            AudioDeviceInfo[] devices = am.getDevices(AudioManager.GET_DEVICES_OUTPUTS);
            for (AudioDeviceInfo dev : devices) {
                int type = dev.getType();
                if (type == AudioDeviceInfo.TYPE_WIRED_HEADSET
                        || type == AudioDeviceInfo.TYPE_WIRED_HEADPHONES
                        || type == AudioDeviceInfo.TYPE_USB_HEADSET
                        || type == AudioDeviceInfo.TYPE_USB_DEVICE
                        || type == AudioDeviceInfo.TYPE_BLUETOOTH_A2DP) {
                    return AUDIO_DEVICE_OUT_WIRED_HEADSET;
                }
            }
        }
        return AUDIO_DEVICE_OUT_SPEAKER;
    }

    private static void registerCallbacksLocked(Context appContext) {
        AudioManager am = appContext.getSystemService(AudioManager.class);
        if (am == null) {
            return;
        }
        Handler handler = getHandlerLocked();

        if (!sDeviceCallbackRegistered) {
            am.registerAudioDeviceCallback(new AudioDeviceCallback() {
                @Override
                public void onAudioDevicesAdded(AudioDeviceInfo[] addedDevices) {
                    updateDeviceIfEnabled(appContext);
                }

                @Override
                public void onAudioDevicesRemoved(AudioDeviceInfo[] removedDevices) {
                    updateDeviceIfEnabled(appContext);
                }
            }, handler);
            sDeviceCallbackRegistered = true;
        }

        if (!sPlaybackCallbackRegistered) {
            am.registerAudioPlaybackCallback(new AudioManager.AudioPlaybackCallback() {
                @Override
                public void onPlaybackConfigChanged(List<AudioPlaybackConfiguration> configs) {
                    synchronized (sLock) {
                        boolean enabled = getAISoundState(appContext);
                        syncPlaybackSessionsLocked(appContext, configs, enabled);
                    }
                }
            }, handler);
            sPlaybackCallbackRegistered = true;
        }
    }

    private static boolean isEligiblePlayback(AudioPlaybackConfiguration cfg) {
        if (cfg.getPlayerState() != AudioPlaybackConfiguration.PLAYER_STATE_STARTED) {
            return false;
        }
        if (cfg.getSessionId() <= 0) {
            return false;
        }
        int playerType = cfg.getPlayerType();
        if (playerType != AudioPlaybackConfiguration.PLAYER_TYPE_JAM_AUDIOTRACK
                && playerType != AudioPlaybackConfiguration.PLAYER_TYPE_JAM_MEDIAPLAYER) {
            return false;
        }
        AudioAttributes attrs = cfg.getAudioAttributes();
        if (attrs == null) {
            return true;
        }
        int usage = attrs.getUsage();
        return usage == AudioAttributes.USAGE_MEDIA || usage == AudioAttributes.USAGE_UNKNOWN;
    }

    private static void syncPlaybackSessionsLocked(
            Context appContext, List<AudioPlaybackConfiguration> configs, boolean enabled) {
        Set<Integer> activeSessions = new HashSet<>();

        boolean hasNewSession = false;
        if (configs != null) {
            for (AudioPlaybackConfiguration cfg : configs) {
                if (isEligiblePlayback(cfg)) {
                    int sessionId = cfg.getSessionId();
                    activeSessions.add(sessionId);
                    if (!sEffects.containsKey(sessionId)) {
                        hasNewSession = true;
                    }
                }
            }
        }

        // aise_core instances share global state: release before creating a new one.
        boolean releaseAll = enabled && hasNewSession;
        Iterator<Map.Entry<Integer, AudioEffect>> it = sEffects.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry<Integer, AudioEffect> entry = it.next();
            if (releaseAll || !activeSessions.contains(entry.getKey())) {
                releaseEffect(entry.getValue());
                it.remove();
            }
        }

        if (enabled && hasNewSession) {
            int mode = getAISoundMode(appContext);
            for (int sessionId : activeSessions) {
                applySessionEffectLocked(appContext, sessionId, true, mode);
            }
            scheduleDelayedReapplyLocked(appContext);
        }
    }

    private static void scheduleDelayedReapplyLocked(Context appContext) {
        Handler handler = getHandlerLocked();
        if (sPendingReapply != null) {
            handler.removeCallbacks(sPendingReapply);
        }
        sPendingReapply = () -> {
            synchronized (sLock) {
                if (getAISoundState(appContext)) {
                    applyAllEffectsLocked(appContext, true, getAISoundMode(appContext));
                }
            }
        };
        handler.postDelayed(sPendingReapply, REAPPLY_DELAY_MS);
    }

    private static void updateDeviceIfEnabled(Context context) {
        synchronized (sLock) {
            if (!getAISoundState(context)) {
                return;
            }
            int deviceMask = getOutputDeviceMask(context);
            for (Map.Entry<Integer, AudioEffect> entry : sEffects.entrySet()) {
                AudioEffect effect = entry.getValue();
                if (effect == null) {
                    continue;
                }
                try {
                    effect.setParameter(PARAM_DEVICE, deviceMask);
                } catch (IllegalStateException e) {
                    Log.w(TAG, "AudioEffect state lost on session " + entry.getKey(), e);
                    releaseEffect(effect);
                    sEffects.put(entry.getKey(), null);
                    applySessionEffectLocked(
                            context, entry.getKey(), true, getAISoundMode(context));
                }
            }
        }
    }

    private static void releaseEffect(AudioEffect effect) {
        if (effect != null) {
            try {
                effect.release();
            } catch (Exception e) {
                Log.w(TAG, "Error releasing AudioEffect", e);
            }
        }
    }

    private static AudioEffect ensureEffectForSessionLocked(int sessionId) {
        AudioEffect effect = sEffects.get(sessionId);
        if (effect != null) {
            return effect;
        }
        try {
            effect = new AudioEffect(EFFECT_TYPE_AISOUND, EFFECT_UUID_AISOUND, 0, sessionId);
            sEffects.put(sessionId, effect);
            return effect;
        } catch (Exception e) {
            Log.e(TAG, "Failed to create AISound AudioEffect for session " + sessionId, e);
            sEffects.remove(sessionId);
            return null;
        }
    }

    private static void applySessionEffectLocked(
            Context context, int sessionId, boolean enable, int mode) {
        if (!enable) {
            AudioEffect effect = sEffects.get(sessionId);
            if (effect != null) {
                try {
                    effect.setParameter(PARAM_SURROUND_ENABLE, 0);
                    effect.setEnabled(false);
                } catch (IllegalStateException e) {
                    Log.w(TAG, "AudioEffect state lost while disabling session " + sessionId, e);
                    releaseEffect(effect);
                    sEffects.remove(sessionId);
                } catch (Exception e) {
                    Log.w(TAG, "Error disabling AISound AudioEffect on session " + sessionId, e);
                }
            }
            return;
        }

        int deviceMask = getOutputDeviceMask(context);
        for (int attempt = 0; attempt < 2; attempt++) {
            AudioEffect effect = ensureEffectForSessionLocked(sessionId);
            if (effect == null) {
                return;
            }
            try {
                effect.setParameter(PARAM_DEVICE, deviceMask);
                effect.setParameter(PARAM_SURROUND_MODE, mode);
                effect.setParameter(PARAM_SURROUND_ENABLE, 1);
                effect.setEnabled(true);
                return;
            } catch (IllegalStateException e) {
                Log.w(TAG, "AudioEffect illegal state on session " + sessionId + ", retrying", e);
                releaseEffect(effect);
                sEffects.remove(sessionId);
            } catch (Exception e) {
                Log.e(TAG, "Failed to configure AISound AudioEffect on session " + sessionId, e);
                return;
            }
        }
    }

    private static void applyAllEffectsLocked(Context appContext, boolean enable, int mode) {
        if (!enable) {
            if (sPendingReapply != null && sHandler != null) {
                sHandler.removeCallbacks(sPendingReapply);
                sPendingReapply = null;
            }
            for (Integer sessionId : new HashSet<>(sEffects.keySet())) {
                applySessionEffectLocked(appContext, sessionId, false, mode);
            }
            return;
        }

        AudioManager am = appContext.getSystemService(AudioManager.class);
        List<AudioPlaybackConfiguration> configs =
                am != null ? am.getActivePlaybackConfigurations() : null;
        syncPlaybackSessionsLocked(appContext, configs, true);

        for (Integer sessionId : new HashSet<>(sEffects.keySet())) {
            applySessionEffectLocked(appContext, sessionId, true, mode);
        }
    }

    public static void switchAISound(Context context, boolean enable) {
        AudioManager am = context.getSystemService(AudioManager.class);
        final String paramStr = enable ? "on" : "off";
        if (am != null) {
            am.setParameters("op_virt_on=" + paramStr);
        }
        SystemProperties.set(PROPERTY_AISOUND_SWITCH, paramStr);

        Context appContext = context.getApplicationContext();
        synchronized (sLock) {
            registerCallbacksLocked(appContext);
            applyAllEffectsLocked(appContext, enable, getAISoundMode(appContext));
            if (enable) {
                scheduleDelayedReapplyLocked(appContext);
            }
        }
        requestTileUpdate(appContext);
    }

    public static void setAISoundMode(Context context, int mode) {
        AudioManager am = context.getSystemService(AudioManager.class);
        if (am != null) {
            am.setParameters("op_virt_mode=" + mode);
        }
        SystemProperties.set(PROPERTY_AISOUND_MODE, mode + "");

        Context appContext = context.getApplicationContext();
        synchronized (sLock) {
            registerCallbacksLocked(appContext);
            if (getAISoundState(appContext)) {
                applyAllEffectsLocked(appContext, true, mode);
            }
        }
        requestTileUpdate(appContext);
    }

    private static void requestTileUpdate(Context appContext) {
        try {
            TileService.requestListeningState(
                    appContext, new ComponentName(appContext, AISoundTileService.class));
        } catch (Exception e) {
            Log.w(TAG, "Failed to request QS tile update", e);
        }
    }

    public static boolean getAISoundState(Context context) {
        return SystemProperties.get(PROPERTY_AISOUND_SWITCH, "off").equals("on");
    }

    public static int getAISoundMode(Context context) {
        return SystemProperties.getInt(PROPERTY_AISOUND_MODE, 0);
    }

    public static void onBoot(Context context) {
        Context appContext = context.getApplicationContext();
        synchronized (sLock) {
            registerCallbacksLocked(appContext);
        }
        switchAISound(appContext, getAISoundState(appContext));
    }
}
