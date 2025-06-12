#include "ui_optimization.h"
#include "ui_chart_init.h"
#include <esp_heap_caps.h>
#include <Arduino.h>

// Global variables for screen management
static bool screen_initialized[SCREEN_COUNT] = {false};
static ui_screen_t current_screen_id = SCREEN_HOME;
static uint32_t screen_load_times[SCREEN_COUNT] = {0};

// Performance monitoring variables
static uint32_t last_fps_time = 0;
static uint32_t fps_frame_count = 0;
static uint32_t current_fps = 0;

// Optimized UI initialization - only load home screen initially
void ui_optimized_init(void) {
    Serial.println("Starting optimized UI initialization...");
    
    // Initialize LVGL theme
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    // Only initialize home screen initially
    uint32_t start_time = millis();
    ui_Home_Screen_screen_init();
    screen_initialized[SCREEN_HOME] = true;
    screen_load_times[SCREEN_HOME] = millis() - start_time;
      // Load the home screen
    lv_disp_load_scr(ui_Home_Screen);
    current_screen_id = SCREEN_HOME;
    
    // Initialize chart data manager (but not register charts yet)
    ui_charts_init_realtime();
    
    // Start chart updates (charts will be registered when their screens load)
    ui_charts_start_realtime();
    
    Serial.printf("Home screen loaded in %d ms\n", screen_load_times[SCREEN_HOME]);
    ui_memory_report();
}

// Lazy load a specific screen
void ui_load_screen(ui_screen_t screen_id) {
    if (screen_id >= SCREEN_COUNT) {
        Serial.println("ERROR: Invalid screen ID");
        return;
    }
    
    if (screen_initialized[screen_id]) {
        Serial.printf("Screen %d already initialized\n", screen_id);
        return;
    }
      uint32_t start_time = millis();
    Serial.printf("[UI] Loading screen %d...\n", screen_id);
    
    switch (screen_id) {
        case SCREEN_HOME:
            ui_Home_Screen_screen_init();
            break;
        case SCREEN_MONITOR:
            Serial.println("[UI] Initializing Monitor Screen...");
            ui_Monitor_Screen_screen_init();
            // Initialize charts for Monitor screen after the screen is created
            ui_charts_init_monitor_screen();
            break;
        case SCREEN_CONTROL:
            Serial.println("[UI] Initializing Control Screen...");
            ui_Control_Screen_screen_init();
            // Initialize charts for Control screen after the screen is created
            ui_charts_init_control_screen();
            break;
        case SCREEN_SETTINGS:
            ui_Settings_Screen_screen_init();
            break;
        case SCREEN_ANALYSIS:
            ui_Analysis_Screen_screen_init();
            break;
        default:
            Serial.println("ERROR: Unknown screen ID");
            return;
    }
    
    screen_initialized[screen_id] = true;
    screen_load_times[screen_id] = millis() - start_time;
    current_screen_id = screen_id;
    
    Serial.printf("Screen %d loaded in %d ms\n", screen_id, screen_load_times[screen_id]);
    ui_memory_report();
}

// Unload unused screens to free memory (keep current screen)
void ui_unload_unused_screens(ui_screen_t keep_screen) {
    Serial.printf("Unloading unused screens (keeping screen %d)...\n", keep_screen);
    
    for (int i = 0; i < SCREEN_COUNT; i++) {
        if (i != keep_screen && screen_initialized[i]) {
            switch (i) {
                case SCREEN_HOME:
                    if (ui_Home_Screen) {
                        ui_Home_Screen_screen_destroy();
                        screen_initialized[SCREEN_HOME] = false;
                        Serial.println("Home screen unloaded");
                    }
                    break;
                case SCREEN_MONITOR:
                    if (ui_Monitor_Screen) {
                        ui_Monitor_Screen_screen_destroy();
                        screen_initialized[SCREEN_MONITOR] = false;
                        Serial.println("Monitor screen unloaded");
                    }
                    break;
                case SCREEN_CONTROL:
                    if (ui_Control_Screen) {
                        ui_Control_Screen_screen_destroy();
                        screen_initialized[SCREEN_CONTROL] = false;
                        Serial.println("Control screen unloaded");
                    }
                    break;
                case SCREEN_SETTINGS:
                    if (ui_Settings_Screen) {
                        ui_Settings_Screen_screen_destroy();
                        screen_initialized[SCREEN_SETTINGS] = false;
                        Serial.println("Settings screen unloaded");
                    }
                    break;
                case SCREEN_ANALYSIS:
                    if (ui_Analysis_Screen) {
                        ui_Analysis_Screen_screen_destroy();
                        screen_initialized[SCREEN_ANALYSIS] = false;
                        Serial.println("Analysis screen unloaded");
                    }
                    break;
            }
        }
    }
    
    ui_memory_report();
}

// Report current memory usage
void ui_memory_report(void) {
    uint32_t free_heap = esp_get_free_heap_size();
    uint32_t free_internal = heap_caps_get_free_size(MALLOC_CAP_INTERNAL);
    uint32_t free_psram = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);
    
    Serial.printf("Memory - Free Heap: %d KB, Internal: %d KB, PSRAM: %d KB\n", 
                  free_heap/1024, free_internal/1024, free_psram/1024);
    
    // Report which screens are loaded
    Serial.print("Loaded screens: ");
    for (int i = 0; i < SCREEN_COUNT; i++) {
        if (screen_initialized[i]) {
            Serial.printf("%d(%dms) ", i, screen_load_times[i]);
        }
    }
    Serial.println();
}

// Check if a screen is initialized
bool ui_is_screen_initialized(ui_screen_t screen_id) {
    if (screen_id >= SCREEN_COUNT) return false;
    return screen_initialized[screen_id];
}

// Get current screen ID
ui_screen_t ui_get_current_screen(void) {
    return current_screen_id;
}

// Set current screen ID
void ui_set_current_screen(ui_screen_t screen_id) {
    if (screen_id < SCREEN_COUNT) {
        current_screen_id = screen_id;
    }
}

// Initialize performance monitoring
void ui_performance_init(void) {
    last_fps_time = millis();
    fps_frame_count = 0;
    current_fps = 0;
}

// Update performance metrics
void ui_performance_update(void) {
    fps_frame_count++;
    
    uint32_t current_time = millis();
    uint32_t elapsed = current_time - last_fps_time;
    
    // Update FPS every second
    if (elapsed >= 1000) {
        current_fps = (fps_frame_count * 1000) / elapsed;
        fps_frame_count = 0;
        last_fps_time = current_time;
        
        // Print performance info every 5 seconds
        static uint32_t last_report = 0;
        if (current_time - last_report >= 5000) {
            Serial.printf("Performance: %d FPS, Free Heap: %d KB\n", 
                         current_fps, esp_get_free_heap_size()/1024);
            last_report = current_time;
        }
    }
}

// Get current FPS
uint32_t ui_get_fps(void) {
    return current_fps;
}

// Get free heap size
uint32_t ui_get_free_heap(void) {
    return esp_get_free_heap_size();
}
