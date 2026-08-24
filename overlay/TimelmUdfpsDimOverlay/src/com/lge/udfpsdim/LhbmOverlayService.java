package com.lge.udfpsdim;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.graphics.PixelFormat;
import android.os.FileObserver;
import android.os.Handler;
import android.os.IBinder;
import android.os.Looper;
import android.provider.Settings;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.view.WindowManager;
import android.widget.FrameLayout;

import java.io.BufferedReader;
import java.io.FileReader;

public class LhbmOverlayService extends Service {

    private static final String TAG = "LhbmOverlay";
    private static final String LHBM_PATH = "/sys/class/panel/brightness/fp_lhbm";
    private static final int MAX_BRIGHTNESS = 255;
    private static final float MIN_ALPHA = 0.7f;

    private WindowManager mWindowManager;
    private View mOverlayView;
    private WindowManager.LayoutParams mOverlayParams;
    private FileObserver mFileObserver;
    private Handler mMainHandler;
    private boolean mOverlayCreated = false;

    @Override
    public void onCreate() {
        super.onCreate();
        mWindowManager = (WindowManager) getSystemService(Context.WINDOW_SERVICE);
        mMainHandler = new Handler(Looper.getMainLooper());
        createNotificationChannel();
        startForeground(1, buildNotification());
        createOverlay();
        startObserver();
        Log.d(TAG, "Service created");
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        return START_STICKY;
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        if (mFileObserver != null) mFileObserver.stopWatching();
        removeOverlay();
        Log.d(TAG, "Service destroyed");
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    private void createNotificationChannel() {
    NotificationChannel channel = new NotificationChannel(
            "lhbm_overlay",
            "LHBM Overlay",
            NotificationManager.IMPORTANCE_MIN);   // <-- MIN, not LOW
    channel.setDescription("Fingerprint dimmer service");
    channel.setShowBadge(false);
    channel.setSound(null, null);
    channel.enableVibration(false);
    channel.setLockscreenVisibility(Notification.VISIBILITY_SECRET);
    NotificationManager nm = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
    if (nm != null) nm.createNotificationChannel(channel);
}

    private Notification buildNotification() {
    return new Notification.Builder(this, "lhbm_overlay")
            .setContentTitle("LHBM Overlay")
            .setContentText("Running")
            .setSmallIcon(android.R.drawable.ic_menu_view)   // or a transparent drawable
            .setOngoing(true)
            .setSilent(true)
            .setOnlyAlertOnce(true)
            .build();
}

    private void createOverlay() {
        if (mOverlayCreated) return;

        mOverlayView = new FrameLayout(this);
        mOverlayView.setBackgroundColor(0xFF000000);

        mOverlayParams = new WindowManager.LayoutParams(
                WindowManager.LayoutParams.MATCH_PARENT,
                WindowManager.LayoutParams.MATCH_PARENT,
                WindowManager.LayoutParams.TYPE_SYSTEM_OVERLAY,   
                
                WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE
                        | WindowManager.LayoutParams.FLAG_NOT_TOUCHABLE
                        | WindowManager.LayoutParams.FLAG_LAYOUT_IN_SCREEN
                        | WindowManager.LayoutParams.FLAG_FULLSCREEN,
                PixelFormat.TRANSLUCENT);
        mOverlayParams.gravity = Gravity.TOP | Gravity.LEFT;
        mOverlayParams.setTitle("LHBM Blackout");
        mOverlayParams.alpha = 0.0f;

        try {
            mWindowManager.addView(mOverlayView, mOverlayParams);
            mOverlayCreated = true;
            Log.d(TAG, "Overlay created (invisible)");
        } catch (Exception e) {
            Log.e(TAG, "Failed to create overlay", e);
            mOverlayView = null;
        }
    }

    private void startObserver() {
        if (mFileObserver != null) return;
        mFileObserver = new FileObserver(LHBM_PATH, FileObserver.MODIFY) {
            @Override
            public void onEvent(int event, String path) {
                int value = readLhbmValue();
                Log.d(TAG, "LHBM value changed: " + value);
                mMainHandler.post(() -> {
                    if (value != 0) {
                        int brightness = getCurrentBrightness();
                        float alpha = 1.0f - ((float) brightness / MAX_BRIGHTNESS);
                        alpha = Math.max(MIN_ALPHA, Math.min(1.0f, alpha));
                        setOverlayWindowAlpha(alpha);
                    } else {
                        setOverlayWindowAlpha(0.0f);
                    }
                });
            }
        };
        mFileObserver.startWatching();
        Log.d(TAG, "FileObserver started on " + LHBM_PATH);
    }

    private int readLhbmValue() {
        try (BufferedReader reader = new BufferedReader(new FileReader(LHBM_PATH))) {
            String line = reader.readLine();
            if (line != null) return Integer.parseInt(line.trim());
        } catch (Exception e) {
            Log.e(TAG, "Failed to read LHBM node", e);
        }
        return 0;
    }

    private int getCurrentBrightness() {
        try {
            return Settings.System.getInt(getContentResolver(),
                    Settings.System.SCREEN_BRIGHTNESS);
        } catch (Settings.SettingNotFoundException e) {
            return MAX_BRIGHTNESS;
        }
    }

    private void setOverlayWindowAlpha(float alpha) {
        if (mOverlayView != null && mOverlayParams != null && mOverlayCreated) {
            mOverlayParams.alpha = alpha;
            try {
                mWindowManager.updateViewLayout(mOverlayView, mOverlayParams);
            } catch (Exception e) {
                Log.e(TAG, "Failed to update overlay alpha", e);
            }
        }
    }

    private void removeOverlay() {
        if (mOverlayView != null && mOverlayCreated) {
            mWindowManager.removeView(mOverlayView);
            mOverlayView = null;
            mOverlayParams = null;
            mOverlayCreated = false;
            Log.d(TAG, "Overlay removed");
        }
    }
}
