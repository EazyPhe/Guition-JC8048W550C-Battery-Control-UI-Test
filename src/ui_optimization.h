#ifndef UI_OPTIMIZATION_H
#define UI_OPTIMIZATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui/ui.h"

// Screen management for lazy loading
typedef enum {
    SCREEN_HOME = 0,
    SCREEN_MONITOR,
    SCREEN_CONTROL,
    SCREEN_SETTINGS,
    SCREEN_ANALYSIS,
    SCREEN_COUNT
} ui_screen_t;

// Function declarations for optimized UI management
void ui_optimized_init(void);
void ui_load_screen(ui_screen_t screen_id);
void ui_unload_unused_screens(ui_screen_t keep_screen);
void ui_memory_report(void);
bool ui_is_screen_initialized(ui_screen_t screen_id);
ui_screen_t ui_get_current_screen(void);
void ui_set_current_screen(ui_screen_t screen_id);

// Navigation functions
void ui_navigate_to_screen(ui_screen_t target_screen);

// Performance monitoring
void ui_performance_init(void);
void ui_performance_update(void);
uint32_t ui_get_fps(void);
uint32_t ui_get_free_heap(void);

#ifdef __cplusplus
}
#endif

#endif // UI_OPTIMIZATION_H
