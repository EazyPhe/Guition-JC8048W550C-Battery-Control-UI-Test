#ifndef UI_CHART_INIT_H
#define UI_CHART_INIT_H

#include "chart_data_manager.h"
#include "ui/ui.h"

#ifdef __cplusplus
extern "C" {
#endif

// Initialize all charts for real-time data streaming
void ui_charts_init_realtime(void);

// Initialize charts for a specific screen when it's loaded
void ui_charts_init_monitor_screen(void);
void ui_charts_init_control_screen(void);

// Start real-time data updates for all charts
void ui_charts_start_realtime(void);

// Stop real-time data updates
void ui_charts_stop_realtime(void);

#ifdef __cplusplus
}
#endif

#endif // UI_CHART_INIT_H
