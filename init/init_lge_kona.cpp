/*
 * SPDX-FileCopyrightText: 2007 The Android Open Source Project
 * SPDX-FileCopyrightText: 2016 The CyanogenMod Project
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <fcntl.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <android-base/strings.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"

using android::base::Trim;
using android::base::GetProperty;

void property_override(const std::string& name, const std::string& value)
{
    size_t valuelen = value.size();

    prop_info* pi = (prop_info*) __system_property_find(name.c_str());
    if (pi != nullptr) {
        __system_property_update(pi, value.c_str(), valuelen);
    }
    else {
        int rc = __system_property_add(name.c_str(), name.size(), value.c_str(), valuelen);
        if (rc < 0) {
            LOG(ERROR) << "property_set(\"" << name << "\", \"" << value << "\") failed: "
                       << "__system_property_add failed";
        }
    }
}

void init_target_properties()
{
    //std::ifstream cust_prop_stream;
    std::string model;
    std::string product_name;
    std::string cmdline;
    bool unknownModel = true;
    bool dualSim = false;

    android::base::ReadFileToString("/proc/cmdline", &cmdline);

    for (const auto& entry : android::base::Split(android::base::Trim(cmdline), " ")) {
        std::vector<std::string> pieces = android::base::Split(entry, "=");
        if (pieces.size() == 2) {
            if(pieces[0].compare("androidboot.vendor.lge.product.model") == 0)
            {
                model = pieces[1];
                unknownModel = false;
            } else if(pieces[0].compare("androidboot.vendor.lge.sim_num") == 0 && pieces[1].compare("2") == 0)
            {
                dualSim = true;
            } else if(pieces[0].compare("androidboot.vendor.lge.hw.revision") == 0) {
                property_override("ro.boot.hardware.revision", pieces[1]);
            } else if(pieces[0].compare("androidboot.vendor.lge.nfc.vendor") == 0) {
                property_override("vendor.lge.nfc_vendor", pieces[1]);
            }
        }
    }

    if(unknownModel) {
        model = "UNKNOWN";
    }

    if(dualSim) {
        property_override("persist.radio.multisim.config", "dsds");
        property_override("persist.vendor.lge.ims.dualvolte", "1");
        property_override("persist.vendor.lge.data.ltedsds", "1");
    }

    property_override("ro.product.model", model);
    property_override("ro.product.odm.model", model);
    property_override("ro.product.product.model", model);
    property_override("ro.product.system.model", model);
    property_override("ro.product.vendor.model", model);
}

void vendor_load_properties() {
    LOG(INFO) << "Loading vendor specific properties";
    init_target_properties();
}
