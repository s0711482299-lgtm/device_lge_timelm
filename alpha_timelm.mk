#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from device
$(call inherit-product, device/lge/timelm/device.mk)

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/alpha/config/common_full_phone.mk)

# Device identifier. This must come after all inclusions.
PRODUCT_NAME := alpha_timelm
PRODUCT_DEVICE := timelm
PRODUCT_MANUFACTURER := LGE
PRODUCT_BRAND := lge
PRODUCT_MODEL := LM-V600

# Alpha Flags
TARGET_HAS_UDFPS := true
TARGET_ENABLE_BLUR := true
TARGET_EXCLUDES_AUDIOFX := false
TARGET_FACE_UNLOCK_SUPPORTED := true
TARGET_BOOT_ANIMATION_RES := 1080

ALPHA_BUILD_TYPE := UNOFFICIAL
ALPHA_MAINTAINER := "K5hiroi"

# Build Package Type
TARGET_BUILD_PACKAGE := 1

# Debug Flags
TARGET_INCLUDE_MATLOG := false

PRODUCT_GMS_CLIENTID_BASE := android-lge

PRODUCT_BUILD_PROP_OVERRIDES += \
    DeviceName=timelm \
    BuildDesc="timelm-user 13 TKQ1.220829.002 2318902104908 release-keys" \
    BuildFingerprint=lge/timelm/timelm:13/TKQ1.220829.002/2318902104908:user/release-keys
