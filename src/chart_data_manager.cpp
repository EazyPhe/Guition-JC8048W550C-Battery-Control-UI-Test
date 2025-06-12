#include "chart_data_manager.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <Arduino.h>  // For Serial debugging

// Global variables
static lv_timer_t* chart_update_timer = NULL;
static chart_data_t chart_registry[CHART_TYPE_COUNT];
static uint32_t update_counter = 0;
static bool manager_initialized = false;

// Demo data generation parameters
static float base_values[CHART_TYPE_COUNT] = {
    [CHART_TYPE_VOLTAGE] = 12.5f,      // 12.5V baseline
    [CHART_TYPE_CURRENT] = 5.0f,       // 5A baseline  
    [CHART_TYPE_TEMPERATURE] = 25.0f,   // 25°C baseline
    [CHART_TYPE_POWER] = 60.0f,        // 60W baseline
    [CHART_TYPE_SOC] = 75.0f,          // 75% SOC baseline
    [CHART_TYPE_DEMO] = 50.0f          // Demo baseline
};

static float amplitude[CHART_TYPE_COUNT] = {
    [CHART_TYPE_VOLTAGE] = 2.0f,       // ±2V variation
    [CHART_TYPE_CURRENT] = 3.0f,       // ±3A variation
    [CHART_TYPE_TEMPERATURE] = 10.0f,   // ±10°C variation
    [CHART_TYPE_POWER] = 25.0f,        // ±25W variation
    [CHART_TYPE_SOC] = 15.0f,          // ±15% variation
    [CHART_TYPE_DEMO] = 30.0f          // ±30 variation
};

static float frequency[CHART_TYPE_COUNT] = {
    [CHART_TYPE_VOLTAGE] = 0.05f,      // Slow variation
    [CHART_TYPE_CURRENT] = 0.1f,       // Medium variation
    [CHART_TYPE_TEMPERATURE] = 0.02f,   // Very slow variation
    [CHART_TYPE_POWER] = 0.08f,        // Medium-slow variation
    [CHART_TYPE_SOC] = 0.01f,          // Very slow variation
    [CHART_TYPE_DEMO] = 0.15f          // Fast variation for demo
};

// Generate realistic demo data with patterns - OPTIMIZED
lv_coord_t chart_data_manager_get_demo_value(chart_type_t type) {
    if (type >= CHART_TYPE_COUNT) return 50;
    
    // Use simpler calculations to avoid expensive floating-point operations
    static uint32_t simple_counter = 0;
    simple_counter++;
    
    // Create simple wave patterns using integer math only
    // Convert frequency to integer scaling factor (multiply by 1000 for precision)
    uint32_t freq_scaled = (uint32_t)(frequency[type] * 1000);
    
    // Simple wave generation using integer math
    uint32_t phase1 = (simple_counter * freq_scaled / 10) % 628;  // Scaled sine approximation  
    uint32_t phase2 = (simple_counter * freq_scaled / 8) % 628;   // Scaled cosine approximation
    
    // Convert to approximate sine/cosine using simple lookup
    int32_t wave1 = (phase1 < 314) ? (phase1 - 157) : (471 - phase1);  // Triangle wave ≈ sine
    int32_t wave2 = (phase2 < 314) ? (phase2 - 157) : (471 - phase2);  // Triangle wave ≈ cosine
    int32_t noise = (rand() % 200) - 100;  // Simple noise
    
    // Combine waves with reduced precision
    float value = base_values[type] + 
                  (wave1 * amplitude[type] * 0.6f / 157.0f) +
                  (wave2 * amplitude[type] * 0.3f / 157.0f) + 
                  (noise * amplitude[type] * 0.002f);
    
    // Apply constraints based on chart type
    switch (type) {
        case CHART_TYPE_VOLTAGE:
            value = fmaxf(10.0f, fminf(15.0f, value));  // 10-15V range
            break;
        case CHART_TYPE_CURRENT:
            value = fmaxf(0.0f, fminf(10.0f, value));   // 0-10A range
            break;
        case CHART_TYPE_TEMPERATURE:
            value = fmaxf(0.0f, fminf(60.0f, value));   // 0-60°C range
            break;
        case CHART_TYPE_POWER:
            value = fmaxf(0.0f, fminf(150.0f, value));  // 0-150W range
            break;
        case CHART_TYPE_SOC:
            value = fmaxf(0.0f, fminf(100.0f, value));  // 0-100% range
            break;
        case CHART_TYPE_DEMO:
            value = fmaxf(0.0f, fminf(100.0f, value));  // 0-100 range
            break;
        default:
            value = 50.0f;
            break;
    }
    
    return (lv_coord_t)value;
}

// Timer callback for updating charts - FRAME AND LVGL SYNCHRONIZED  
static void chart_update_timer_cb(lv_timer_t* timer) {
    (void)timer;  // Unused parameter
    
    update_counter++;
    
    // CRITICAL: Wait for frame transmission to complete AND LVGL to be idle
    extern bool is_frame_trans_done(void);
    if (!is_frame_trans_done()) {
        // Skip this update if frame is still being transmitted
        return;
    }
    
    // Additional check: Skip if LVGL is currently doing any rendering work
    if (lv_disp_get_inactive_time(NULL) < 50) {  // LVGL has been active recently
        return;
    }
    
    // Update only ONE chart per callback to spread the load
    static int chart_index = 0;
    
    // Find next enabled chart
    int attempts = 0;
    while (attempts < CHART_TYPE_COUNT) {
        if (chart_registry[chart_index].chart && 
            chart_registry[chart_index].series && 
            chart_registry[chart_index].enabled) {
            
            // Update this chart with pre-calculated simple value
            lv_coord_t new_value = chart_data_manager_get_demo_value((chart_type_t)chart_index);
            
            // Temporarily disable auto-invalidation during chart update
            lv_obj_add_flag(chart_registry[chart_index].chart, LV_OBJ_FLAG_HIDDEN);
            lv_chart_set_next_value(chart_registry[chart_index].chart, 
                                  chart_registry[chart_index].series, new_value);
            lv_obj_clear_flag(chart_registry[chart_index].chart, LV_OBJ_FLAG_HIDDEN);
            
            // Manual invalidation at a safe time
            lv_obj_invalidate(chart_registry[chart_index].chart);
            break;
        }
        chart_index = (chart_index + 1) % CHART_TYPE_COUNT;
        attempts++;
    }
    
    // Move to next chart for next update
    chart_index = (chart_index + 1) % CHART_TYPE_COUNT;
}

void chart_data_manager_init(void) {
    Serial.println("[CHART] === chart_data_manager_init() CALLED ===");
    Serial.flush();
    
    if (manager_initialized) return;
    
    // Initialize random seed for demo data
    srand((unsigned int)lv_tick_get());
    
    // Initialize chart registry
    for (int i = 0; i < CHART_TYPE_COUNT; i++) {
        chart_registry[i].chart = NULL;
        chart_registry[i].series = NULL;
        chart_registry[i].min_value = 0;
        chart_registry[i].max_value = 100;
        chart_registry[i].enabled = false;
        chart_registry[i].name = NULL;
    }
    
    manager_initialized = true;
    update_counter = 0;
}

void chart_data_manager_deinit(void) {
    if (!manager_initialized) return;
    
    chart_data_manager_stop_updates();
    
    // Clear registry
    for (int i = 0; i < CHART_TYPE_COUNT; i++) {
        chart_registry[i].chart = NULL;
        chart_registry[i].series = NULL;
        chart_registry[i].enabled = false;
        chart_registry[i].name = NULL;
    }
    
    manager_initialized = false;
}

void chart_data_manager_register_chart(lv_obj_t* chart, chart_type_t type, const char* name) {
    if (!manager_initialized || !chart || type >= CHART_TYPE_COUNT) {
        Serial.printf("[CHART] Registration failed: init=%d, chart=%p, type=%d\n", 
                     manager_initialized, chart, type);
        return;
    }
    
    // Configure the chart for real-time scrolling
    lv_chart_set_update_mode(chart, LV_CHART_UPDATE_MODE_SHIFT);  // Shift mode for scrolling
    lv_chart_set_point_count(chart, CHART_POINT_COUNT);
    
    // Get the first series (assuming single series per chart)
    lv_chart_series_t* series = lv_chart_get_series_next(chart, NULL);
    
    if (!series) {
        // Create a series if none exists
        lv_color_t colors[] = {
            lv_color_hex(0xFF6B6B),  // Red for voltage
            lv_color_hex(0x4ECDC4),  // Teal for current  
            lv_color_hex(0x45B7D1),  // Blue for temperature
            lv_color_hex(0xFFA07A),  // Orange for power
            lv_color_hex(0x98D8C8),  // Green for SOC
            lv_color_hex(0x808080)   // Gray for demo
        };
        
        lv_color_t color = (type < sizeof(colors)/sizeof(colors[0])) ? colors[type] : lv_color_hex(0x808080);
        series = lv_chart_add_series(chart, color, LV_CHART_AXIS_PRIMARY_Y);
        Serial.printf("[CHART] Created new series for %s\n", name);
    } else {
        Serial.printf("[CHART] Using existing series for %s\n", name);
    }
    
    // Set appropriate Y-axis range based on chart type
    switch (type) {
        case CHART_TYPE_VOLTAGE:
            lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 10, 15);
            chart_registry[type].min_value = 10;
            chart_registry[type].max_value = 15;
            break;
        case CHART_TYPE_CURRENT:
            lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 10);
            chart_registry[type].min_value = 0;
            chart_registry[type].max_value = 10;
            break;
        case CHART_TYPE_TEMPERATURE:
            lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 60);
            chart_registry[type].min_value = 0;
            chart_registry[type].max_value = 60;
            break;
        case CHART_TYPE_POWER:
            lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 150);
            chart_registry[type].min_value = 0;
            chart_registry[type].max_value = 150;
            break;
        case CHART_TYPE_SOC:
            lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
            chart_registry[type].min_value = 0;
            chart_registry[type].max_value = 100;
            break;
        case CHART_TYPE_DEMO:
        default:
            lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
            chart_registry[type].min_value = 0;
            chart_registry[type].max_value = 100;
            break;
    }
    
    // Register the chart
    chart_registry[type].chart = chart;
    chart_registry[type].series = series;
    chart_registry[type].enabled = true;
    chart_registry[type].name = name;
    
    Serial.printf("[CHART] Registered %s (type %d) with range %d-%d\n", 
                 name, type, chart_registry[type].min_value, chart_registry[type].max_value);
    
    // Initialize with some data points to fill the chart
    for (int i = 0; i < CHART_POINT_COUNT; i++) {
        lv_coord_t value = chart_data_manager_get_demo_value(type);
        lv_chart_set_next_value(chart, series, value);
        update_counter++;  // Advance counter for varied initial data
    }
    
    Serial.printf("[CHART] Initialized %s with %d data points\n", name, CHART_POINT_COUNT);
}

void chart_data_manager_start_updates(void) {
    if (!manager_initialized) {
        Serial.println("[CHART] ERROR: Manager not initialized!");
        return;
    }
    
    if (chart_update_timer) {
        lv_timer_del(chart_update_timer);
    }
      // Test 30Hz with frame synchronization for smooth animation
    chart_update_timer = lv_timer_create(chart_update_timer_cb, 33, NULL);
    lv_timer_set_repeat_count(chart_update_timer, -1);  // Repeat indefinitely
    
    Serial.printf("[CHART] Timer created with period %d ms (30Hz with frame sync)\n", 33);
}

void chart_data_manager_stop_updates(void) {
    if (chart_update_timer) {
        lv_timer_del(chart_update_timer);
        chart_update_timer = NULL;
    }
}

void chart_data_manager_update_chart(chart_type_t type, lv_coord_t value) {
    if (!manager_initialized || type >= CHART_TYPE_COUNT) return;
    
    if (chart_registry[type].chart && chart_registry[type].series && chart_registry[type].enabled) {
        // Clamp value to chart range
        if (value < chart_registry[type].min_value) value = chart_registry[type].min_value;
        if (value > chart_registry[type].max_value) value = chart_registry[type].max_value;
        
        lv_chart_set_next_value(chart_registry[type].chart, chart_registry[type].series, value);
    }
}
