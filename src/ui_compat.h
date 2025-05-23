#ifndef UI_COMPAT_H
#define UI_COMPAT_H

#include <lvgl.h>

/**
 * This file provides compatibility between LVGL 8.3.11 (used by SquareLine Studio 1.5.2)
 * and LVGL 9.x used in your project.
 */

// Common compatibility fixes for LVGL 8 to LVGL 9 migration

// LVGL 8 Parts compatibility
#ifndef LV_PART_MAIN
#define LV_PART_MAIN LV_PART_INDICATOR
#endif

// Theme compatibility
#ifndef lv_theme_get_from_obj
#define lv_theme_get_from_obj(obj) lv_obj_get_theme(obj)
#endif

// Theme initialization compatibility
#ifndef lv_theme_default_init
#define lv_theme_default_init(disp, pri, sec, dark, font) lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), dark, font)
#endif

// Style compatibility
#ifndef lv_style_set_text_color
#define lv_style_set_text_color(style, value) lv_style_set_text_color(style, lv_color_hex(value))
#endif

// Remove all v9-to-v8 macro redefinitions to avoid conflicts with LVGL 8.x
// Only keep compatibility helpers that do not alias types or functions

// Color compatibility
// Use lv_color_make directly for LVGL 9.x compatibility

// Font compatibility
#ifndef lv_font_montserrat_14
extern const lv_font_t lv_font_montserrat_14;
#endif

#endif // UI_COMPAT_H
