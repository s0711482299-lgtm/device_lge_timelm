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

import android.content.Context;
import android.content.res.Configuration;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.GradientDrawable;
import android.os.Bundle;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Switch;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

public class AISoundSettingsFragment extends Fragment {

    private static final int MODE_AUTO = 0;
    private static final int MODE_MUSIC = 1;
    private static final int MODE_CINEMA = 2;
    private static final int MODE_VOICE = 3;

    private Switch mEnableSwitch;
    private View mEnableCard;
    private View mProfilesCard;
    private View mInfoCard;
    private View mRowAuto;
    private View mRowCinema;
    private View mRowMusic;
    private View mRowVoice;
    private boolean mUpdatingUi = false;

    @Nullable
    @Override
    public View onCreateView(
            @NonNull LayoutInflater inflater,
            @Nullable ViewGroup container,
            @Nullable Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_aisound, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        mEnableCard = view.findViewById(R.id.aisound_enable_card);
        mEnableSwitch = view.findViewById(R.id.aisound_enable_switch);
        mProfilesCard = view.findViewById(R.id.aisound_profiles_card);
        mInfoCard = view.findViewById(R.id.aisound_info_card);
        mRowAuto = view.findViewById(R.id.aisound_row_auto);
        mRowCinema = view.findViewById(R.id.aisound_row_cinema);
        mRowMusic = view.findViewById(R.id.aisound_row_music);
        mRowVoice = view.findViewById(R.id.aisound_row_voice);

        applyDynamicCardColors();

        mEnableCard.setOnClickListener(v -> mEnableSwitch.toggle());
        mEnableSwitch.setOnCheckedChangeListener((buttonView, isChecked) -> {
            if (mUpdatingUi) {
                return;
            }
            Context context = getContext();
            if (context == null) {
                return;
            }
            updateProfilesUi(isChecked, AISound.getAISoundMode(context));
            AISound.switchAISound(context, isChecked);
        });

        mRowAuto.setOnClickListener(v -> selectMode(MODE_AUTO));
        mRowCinema.setOnClickListener(v -> selectMode(MODE_CINEMA));
        mRowMusic.setOnClickListener(v -> selectMode(MODE_MUSIC));
        mRowVoice.setOnClickListener(v -> selectMode(MODE_VOICE));

        updateUiState();
    }

    @Override
    public void onResume() {
        super.onResume();
        updateUiState();
    }

    private float dp(float value) {
        return TypedValue.applyDimension(
                TypedValue.COMPLEX_UNIT_DIP, value, getResources().getDisplayMetrics());
    }

    private void applyDynamicCardColors() {
        Context context = getContext();
        if (context == null) {
            return;
        }
        boolean isNight = (getResources().getConfiguration().uiMode
                & Configuration.UI_MODE_NIGHT_MASK) == Configuration.UI_MODE_NIGHT_YES;

        int surfaceColor = context.getColor(isNight
                ? android.R.color.system_neutral1_800
                : android.R.color.system_neutral1_50);
        int infoColor = context.getColor(isNight
                ? android.R.color.system_accent2_800
                : android.R.color.system_accent2_100);
        int strokeColor = context.getColor(isNight
                ? android.R.color.system_neutral2_600
                : android.R.color.system_neutral2_200);

        mEnableCard.setBackground(makeRoundedCard(surfaceColor, 0, dp(24)));
        mProfilesCard.setBackground(makeRoundedCard(surfaceColor, 0, dp(24)));
        mInfoCard.setBackground(makeRoundedCard(infoColor, strokeColor, dp(24)));
    }

    private Drawable makeSelectedRowDrawable() {
        Context context = getContext();
        if (context == null) {
            return null;
        }
        boolean isNight = (getResources().getConfiguration().uiMode
                & Configuration.UI_MODE_NIGHT_MASK) == Configuration.UI_MODE_NIGHT_YES;
        int fillColor = context.getColor(isNight
                ? android.R.color.system_accent2_700
                : android.R.color.system_accent2_100);
        int strokeColor = context.getColor(isNight
                ? android.R.color.system_neutral2_500
                : android.R.color.system_neutral2_300);
        return makeRoundedCard(fillColor, strokeColor, dp(18));
    }

    private GradientDrawable makeRoundedCard(int fillColor, int strokeColor, float radiusPx) {
        GradientDrawable d = new GradientDrawable();
        d.setShape(GradientDrawable.RECTANGLE);
        d.setCornerRadius(radiusPx);
        d.setColor(fillColor);
        if (strokeColor != 0) {
            d.setStroke(Math.round(dp(1)), strokeColor);
        }
        return d;
    }

    private void selectMode(int mode) {
        Context context = getContext();
        if (context == null || !AISound.getAISoundState(context)) {
            return;
        }
        AISound.setAISoundMode(context, mode);
        updateProfilesUi(true, mode);
    }

    private void updateUiState() {
        Context context = getContext();
        if (context == null || mEnableSwitch == null) {
            return;
        }
        boolean enable = AISound.getAISoundState(context);
        int mode = AISound.getAISoundMode(context);

        mUpdatingUi = true;
        try {
            mEnableSwitch.setChecked(enable);
            updateProfilesUi(enable, mode);
        } finally {
            mUpdatingUi = false;
        }
    }

    private void updateProfilesUi(boolean enable, int mode) {
        mProfilesCard.setAlpha(enable ? 1.0f : 0.45f);
        mRowAuto.setEnabled(enable);
        mRowCinema.setEnabled(enable);
        mRowMusic.setEnabled(enable);
        mRowVoice.setEnabled(enable);

        mRowAuto.setBackground(mode == MODE_AUTO ? makeSelectedRowDrawable() : null);
        mRowCinema.setBackground(mode == MODE_CINEMA ? makeSelectedRowDrawable() : null);
        mRowMusic.setBackground(mode == MODE_MUSIC ? makeSelectedRowDrawable() : null);
        mRowVoice.setBackground(mode == MODE_VOICE ? makeSelectedRowDrawable() : null);
    }
}
