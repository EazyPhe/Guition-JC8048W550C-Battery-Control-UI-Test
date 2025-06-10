#ifndef CHART_DATA_MANAGER_H
#define CHART_DATA_MANAGER_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Chart configuration
#define CHART_POINT_COUNT 20  // Number of points visible on each chart
#define CHART_UPDATE_PERIOD_MS 33 // 30Hz update rate for smooth chart animation

// Chart data structure
typedef struct {
    lv_obj_t* chart;
    lv_chart_series_t* series;
    int32_t min_value;
    int32_t max_value;
    bool enabled;
    const char* name;
} chart_data_t;

// Chart types for different data sources
typedef enum {
    CHART_TYPE_VOLTAGE,
    CHART_TYPE_CURRENT,
    CHART_TYPE_TEMPERATURE,
    CHART_TYPE_POWER,
    CHART_TYPE_SOC,
    CHART_TYPE_DEMO,
    CHART_TYPE_COUNT
} chart_type_t;

// Function prototypes
void chart_data_manager_init(void);
void chart_data_manager_deinit(void);
void chart_data_manager_register_chart(lv_obj_t* chart, chart_type_t type, const char* name);
void chart_data_manager_start_updates(void);
void chart_data_manager_stop_updates(void);
void chart_data_manager_update_chart(chart_type_t type, lv_coord_t value);
lv_coord_t chart_data_manager_get_demo_value(chart_type_t type);

#ifdef __cplusplus
}
#endif

#endif // CHART_DATA_MANAGER_H
