/*
 * Copyright (C) 2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

package com.lge.aisound;

import android.service.quicksettings.Tile;
import android.service.quicksettings.TileService;

public class AISoundTileService extends TileService {

    @Override
    public void onStartListening() {
        super.onStartListening();
        updateTile();
    }

    @Override
    public void onClick() {
        super.onClick();
        boolean newState = !AISound.getAISoundState(this);
        AISound.switchAISound(this, newState);
        updateTile();
    }

    private void updateTile() {
        Tile tile = getQsTile();
        if (tile == null) {
            return;
        }
        boolean enabled = AISound.getAISoundState(this);
        tile.setState(enabled ? Tile.STATE_ACTIVE : Tile.STATE_INACTIVE);
        tile.setLabel(getString(R.string.aisound_qs_tile_label));
        if (enabled) {
            String[] entries = getResources().getStringArray(R.array.aisound_profile_entries);
            int mode = AISound.getAISoundMode(this);
            String subtitle = (mode >= 0 && mode < entries.length) ? entries[mode] : entries[0];
            tile.setSubtitle(subtitle);
        } else {
            tile.setSubtitle(getString(R.string.aisound_qs_off));
        }
        tile.updateTile();
    }
}
