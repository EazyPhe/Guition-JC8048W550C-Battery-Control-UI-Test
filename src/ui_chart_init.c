#include "ui_chart_init.h"
#include "chart_data_manager.h"
#include "ui/ui.h"

void ui_charts_init_realtime(void) {
    // Initialize the chart data manager
    chart_data_manager_init();
    
    // Register Monitor Screen charts (ui_Chart1, ui_Chart2, ui_Chart3, ui_Chart4)
    if (ui_Chart1) {
        chart_data_manager_register_chart(ui_Chart1, CHART_TYPE_VOLTAGE, "Battery Voltage");
    }
    
    if (ui_Chart2) {
        chart_data_manager_register_chart(ui_Chart2, CHART_TYPE_CURRENT, "Battery Current");
    }
    
    if (ui_Chart3) {
        chart_data_manager_register_chart(ui_Chart3, CHART_TYPE_TEMPERATURE, "Temperature");
    }
    
    if (ui_Chart4) {
        chart_data_manager_register_chart(ui_Chart4, CHART_TYPE_SOC, "State of Charge");
    }
    
    // Register Control Screen charts (ui_Chart5, ui_Chart6)  
    if (ui_Chart5) {
        chart_data_manager_register_chart(ui_Chart5, CHART_TYPE_POWER, "Power Output");
    }
    
    if (ui_Chart6) {
        chart_data_manager_register_chart(ui_Chart6, CHART_TYPE_DEMO, "Demo Data");
    }
}

void ui_charts_start_realtime(void) {
    // Start the automatic data updates
    chart_data_manager_start_updates();
}

void ui_charts_stop_realtime(void) {
    // Stop the automatic data updates
    chart_data_manager_stop_updates();
}
