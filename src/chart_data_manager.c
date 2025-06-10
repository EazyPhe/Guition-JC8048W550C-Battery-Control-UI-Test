#include "chart_data_manager.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

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

// Generate realistic demo data with patterns
lv_coord_t chart_data_manager_get_demo_value(chart_type_t type) {
    if (type >= CHART_TYPE_COUNT) return 50;
    
    float time_factor = update_counter * frequency[type];
    
    // Generate multiple wave components for realistic data
    float sine_wave = sinf(time_factor) * amplitude[type] * 0.6f;
    float cosine_wave = cosf(time_factor * 1.3f) * amplitude[type] * 0.3f;
    float noise = ((float)(rand() % 100) / 100.0f - 0.5f) * amplitude[type] * 0.2f;
    
    float value = base_values[type] + sine_wave + cosine_wave + noise;
    
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

// Timer callback for updating charts
static void chart_update_timer_cb(lv_timer_t* timer) {
    (void)timer;  // Unused parameter
    
    update_counter++;
    
    // Update all registered charts with new demo data
    for (int i = 0; i < CHART_TYPE_COUNT; i++) {
        if (chart_registry[i].chart && chart_registry[i].series && chart_registry[i].enabled) {
            lv_coord_t new_value = chart_data_manager_get_demo_value((chart_type_t)i);
            
            // Use lv_chart_set_next_value for scrolling behavior
            lv_chart_set_next_value(chart_registry[i].chart, chart_registry[i].series, new_value);
            
            // Optionally refresh the chart (usually not needed as set_next_value handles it)
            // lv_chart_refresh(chart_registry[i].chart);
        }
    }
}

void chart_data_manager_init(void) {
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
    if (!manager_initialized || !chart || type >= CHART_TYPE_COUNT) return;
    
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
    
    // Initialize with some data points to fill the chart
    for (int i = 0; i < CHART_POINT_COUNT; i++) {
        lv_coord_t value = chart_data_manager_get_demo_value(type);
        lv_chart_set_next_value(chart, series, value);
        update_counter++;  // Advance counter for varied initial data
    }
}

void chart_data_manager_start_updates(void) {
    if (!manager_initialized) return;
    
    if (chart_update_timer) {
        lv_timer_del(chart_update_timer);
    }
    
    chart_update_timer = lv_timer_create(chart_update_timer_cb, CHART_UPDATE_PERIOD_MS, NULL);
    lv_timer_set_repeat_count(chart_update_timer, -1);  // Repeat indefinitely
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
