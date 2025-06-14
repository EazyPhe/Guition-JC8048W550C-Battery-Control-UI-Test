// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.2
// LVGL version: 8.3.11
// Project name: Guition-JC8048W550C-Battery-Control-UI-Test

#ifndef _GUITION_JC8048W550C_BATTERY_CONTROL_UI_TEST_UI_H
#define _GUITION_JC8048W550C_BATTERY_CONTROL_UI_TEST_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"

///////////////////// SCREENS ////////////////////

#include "screens/ui_Home_Screen.h"
#include "screens/ui_Monitor_Screen.h"
#include "screens/ui_Control_Screen.h"
#include "screens/ui_Settings_Screen.h"
#include "screens/ui_Analysis_Screen.h"

///////////////////// VARIABLES ////////////////////


// EVENTS

extern lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS
LV_IMG_DECLARE(ui_img_200339424);    // assets/Fe_Li-Ion_250x250.png

// UI INIT
void ui_init(void);
void ui_destroy(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
