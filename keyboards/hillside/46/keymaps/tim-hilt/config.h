#pragma once

// Has to be defined so that left side is detected correctly
#define SPLIT_HAND_MATRIX_GRID_LOW_IS_RIGHT

#define RP2040_FLASH_GD25Q64CS
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED D5 // Specify an optional status LED by GPIO number which blinks when entering the bootloader

// Some boards have issues detecting handedness using the vbus voltage.
// Such as Elite-C v3, but not v3.1 on. Also apparently some ProMicro boards.
// For those boands, use usb detection instead.
// #define SPLIT_USB_DETECT
