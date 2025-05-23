#ifndef LV_CONF_H
#define LV_CONF_H

#include <stdint.h>

// Display resolution
#define LV_HOR_RES_MAX          800
#define LV_VER_RES_MAX          480

// Color depth
#define LV_COLOR_DEPTH          16

// Memory settings
#define LV_MEM_CUSTOM           1
#define LV_MEM_CUSTOM_INCLUDE   <stdlib.h>
#define LV_MEM_CUSTOM_ALLOC     malloc
#define LV_MEM_CUSTOM_FREE      free
#define LV_MEM_CUSTOM_REALLOC   realloc

// Enable GPU
#define LV_USE_GPU              0
#define LV_USE_GPU_STM32_DMA2D  0
#define LV_USE_GPU_NXP_PXP      0
#define LV_USE_GPU_NXP_VG_LITE  0
#define LV_USE_GPU_SWM341_DMA2D 0

// Logging
#define LV_USE_LOG              1
#define LV_LOG_LEVEL            LV_LOG_LEVEL_WARN

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
#define LV_USE_SHADOW          1
#define LV_SHADOW_CACHE_SIZE    0
#define LV_USE_BLEND_MODES      1
#define LV_USE_OPA_SCALE        1
#define LV_USE_IMG_TRANSFORM    1
#define LV_USE_GROUP            1
#define LV_USE_GPU_ESP32        0
#define LV_USE_FILESYSTEM       1
#define LV_USE_USER_DATA        1
#define LV_USE_PERF_MONITOR     0
#define LV_USE_API_EXTENSION_V6  1
#define LV_USE_API_EXTENSION_V7  1

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
#define LV_FONT_MONTSERRAT_14   1
#define LV_FONT_MONTSERRAT_16   1
#define LV_FONT_MONTSERRAT_20   1
#define LV_FONT_MONTSERRAT_24   1
#define LV_FONT_MONTSERRAT_28   0
#define LV_FONT_MONTSERRAT_32   0
#define LV_FONT_DEFAULT         &lv_font_montserrat_14

// --- LVGL CONFIG PATCH FOR ESP32/ESP32S3 ---
// Disable Helium/ARM-specific blend features that break ESP32 build
// (These are sometimes enabled by default in lv_conf.h for v9)
#ifndef LV_USE_DRAW_SW_HELIUM
#define LV_USE_DRAW_SW_HELIUM 0
#endif
#ifndef LV_USE_DRAW_SW
#define LV_USE_DRAW_SW 1
#endif
#ifndef LV_USE_DRAW_SW_ASM
#define LV_USE_DRAW_SW_ASM 0
#endif
#ifndef LV_USE_NATIVE_HELIUM_ASM
#define LV_USE_NATIVE_HELIUM_ASM 0
#endif

#endif // LV_CONF_H
