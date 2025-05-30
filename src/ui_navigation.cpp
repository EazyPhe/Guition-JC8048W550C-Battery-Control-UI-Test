#include "ui_optimization.h"
#include <Arduino.h>

// Smart navigation function that handles lazy loading
void ui_navigate_to_screen(ui_screen_t target_screen) {
    if (target_screen >= SCREEN_COUNT) {
        Serial.println("ERROR: Invalid target screen");
        return;
    }
    
    Serial.printf("Navigating to screen %d\n", target_screen);
    
    // Load target screen if not already loaded
    if (!ui_is_screen_initialized(target_screen)) {
        ui_load_screen(target_screen);
    }
    
    // Switch to the target screen
    lv_obj_t* target_screen_obj = NULL;
    void (*screen_init_func)(void) = NULL;
    
    switch (target_screen) {
        case SCREEN_HOME:
            target_screen_obj = ui_Home_Screen;
            screen_init_func = ui_Home_Screen_screen_init;
            break;
        case SCREEN_MONITOR:
            target_screen_obj = ui_Monitor_Screen;
            screen_init_func = ui_Monitor_Screen_screen_init;
            break;
        case SCREEN_CONTROL:
            target_screen_obj = ui_Control_Screen;
            screen_init_func = ui_Control_Screen_screen_init;
            break;
        case SCREEN_SETTINGS:
            target_screen_obj = ui_Settings_Screen;
            screen_init_func = ui_Settings_Screen_screen_init;
            break;
        case SCREEN_ANALYSIS:
            target_screen_obj = ui_Analysis_Screen;
            screen_init_func = ui_Analysis_Screen_screen_init;
            break;
    }
    
    if (target_screen_obj && screen_init_func) {
        // Use LVGL's _ui_screen_change function if available, otherwise use direct load
        #ifdef _ui_screen_change
        _ui_screen_change(&target_screen_obj, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, screen_init_func);
        #else
        lv_scr_load_anim(target_screen_obj, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, false);
        #endif
        // Optionally unload unused screens to save memory
        ui_unload_unused_screens(target_screen);
        
        ui_set_current_screen(target_screen);
        Serial.printf("Switched to screen %d\n", target_screen);
    } else {
        Serial.println("ERROR: Failed to get screen object");
    }
}
