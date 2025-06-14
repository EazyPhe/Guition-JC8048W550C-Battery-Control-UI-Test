#ifndef LV_CONF_H
#define LV_CONF_H

#include <stdint.h>

// Display resolution
#define LV_HOR_RES_MAX          800
#define LV_VER_RES_MAX          480

// Color depth
#define LV_COLOR_DEPTH          16
#define LV_COLOR_16_SWAP        0  // Disable byte swapping for RGB565 format on ESP32 (required by SquareLine Studio)

// Memory settings
#define LV_MEM_CUSTOM           1
#define LV_MEM_CUSTOM_INCLUDE   <stdlib.h>
#define LV_MEM_CUSTOM_ALLOC     malloc
#define LV_MEM_CUSTOM_FREE      free
#define LV_MEM_CUSTOM_REALLOC   realloc
#define LV_MEM_SIZE             (32U * 1024U) // 32KB, increase if you see allocation errors

// Image cache
#define LV_IMG_CACHE_DEF_SIZE   1 // Only cache 1 image, set to 0 if not needed

// Logging
#define LV_USE_LOG              0 // Disable logging for release
// #define LV_LOG_LEVEL         LV_LOG_LEVEL_WARN // Not needed if logging is off

// Input device settings
#define LV_INDEV_DEF_READ_PERIOD            30
#define LV_INDEV_DEF_DRAG_LIMIT             10
#define LV_INDEV_DEF_DRAG_THROW             10
#define LV_INDEV_DEF_LONG_PRESS_TIME        400
#define LV_INDEV_DEF_LONG_PRESS_REP_TIME    100
#define LV_INDEV_DEF_GESTURE_LIMIT          50
#define LV_INDEV_DEF_GESTURE_MIN_VELOCITY   3

// Feature configuration
#define LV_USE_ANIMATION        1
#define LV_USE_SHADOW           1
#define LV_SHADOW_CACHE_SIZE    0
#define LV_USE_BLEND_MODES      1
#define LV_USE_OPA_SCALE        1
#define LV_USE_IMG_TRANSFORM    1
#define LV_USE_GROUP            1
#define LV_USE_FILESYSTEM       1
#define LV_USE_USER_DATA        1
#define LV_USE_PERF_MONITOR     0

// Widget usage configuration
#define LV_USE_ARC             1
#define LV_USE_BAR             1
#define LV_USE_BTN             1
#define LV_USE_BTNMATRIX       1
#define LV_USE_CANVAS          1
#define LV_USE_CHECKBOX        1
#define LV_USE_DROPDOWN        1
#define LV_USE_IMG             1
#define LV_USE_LABEL           1
#define LV_USE_LINE            1
#define LV_USE_ROLLER          1
#define LV_USE_SLIDER          1
#define LV_USE_SWITCH          1
#define LV_USE_TEXTAREA        1
#define LV_USE_TABLE           1

// Theme configuration
#define LV_THEME_DEFAULT_INIT               lv_theme_default_init
#define LV_THEME_DEFAULT_COLOR_PRIMARY      lv_color_hex(0x01a2b1)
#define LV_THEME_DEFAULT_COLOR_SECONDARY    lv_color_hex(0x44d1b6)
#define LV_THEME_DEFAULT_FLAG               LV_THEME_DEFAULT_FLAG_LIGHT
#define LV_THEME_DEFAULT_FONT_SMALL         &lv_font_montserrat_14
#define LV_THEME_DEFAULT_FONT_NORMAL        &lv_font_montserrat_16
#define LV_THEME_DEFAULT_FONT_SUBTITLE      &lv_font_montserrat_20
#define LV_THEME_DEFAULT_FONT_TITLE         &lv_font_montserrat_24

// Font configuration
#define LV_FONT_MONTSERRAT_12   0
#define LV_FONT_MONTSERRAT_14 1
#define LV_FONT_MONTSERRAT_16   0
#define LV_FONT_MONTSERRAT_20   1
#define LV_FONT_MONTSERRAT_24   0
#define LV_FONT_MONTSERRAT_28   0
#define LV_FONT_MONTSERRAT_32   0
#define LV_FONT_MONTSERRAT_40   1
#define LV_FONT_DEFAULT         &lv_font_montserrat_14

#endif // LV_CONF_H
