#include "ui_chart_init.h"
#include "chart_data_manager.h"
#include "ui/ui.h"
#include <Arduino.h>  // For Serial debugging

// Global constructor to test if this file is compiled
struct ChartInitDebug {
    ChartInitDebug() {
        // This will run when the module loads - can't use Serial here yet
    }
};
static ChartInitDebug debug_instance;

extern "C" void ui_charts_init_realtime(void) {
    Serial.println("[CHART] === ui_charts_init_realtime() CALLED ===");
    Serial.flush();
    
    // Initialize the chart data manager first
    chart_data_manager_init();
    Serial.println("[CHART] Chart data manager initialized");
    
    // In optimized mode, charts are initialized when their screens are loaded
    // This function now only initializes the chart manager
    Serial.println("[CHART] Using optimized UI mode - charts will be initialized per screen");
}

extern "C" void ui_charts_init_monitor_screen(void) {
    Serial.println("[CHART] === ui_charts_init_monitor_screen() CALLED ===");
    Serial.flush();
    
    // Register Monitor Screen charts (ui_Chart1, ui_Chart2, ui_Chart3, ui_Chart4)
    if (ui_Chart1) {
        chart_data_manager_register_chart(ui_Chart1, CHART_TYPE_VOLTAGE, "Battery Voltage");
        Serial.println("[CHART] Registered ui_Chart1 (Voltage)");
    } else {
        Serial.println("[CHART] ERROR: ui_Chart1 is NULL!");
    }
    
    if (ui_Chart2) {
        chart_data_manager_register_chart(ui_Chart2, CHART_TYPE_CURRENT, "Battery Current");
        Serial.println("[CHART] Registered ui_Chart2 (Current)");
    } else {
        Serial.println("[CHART] ERROR: ui_Chart2 is NULL!");
    }
    
    if (ui_Chart3) {
        chart_data_manager_register_chart(ui_Chart3, CHART_TYPE_TEMPERATURE, "Temperature");
        Serial.println("[CHART] Registered ui_Chart3 (Temperature)");
    } else {
        Serial.println("[CHART] ERROR: ui_Chart3 is NULL!");
    }
    
    if (ui_Chart4) {
        chart_data_manager_register_chart(ui_Chart4, CHART_TYPE_SOC, "State of Charge");
        Serial.println("[CHART] Registered ui_Chart4 (SOC)");
    } else {
        Serial.println("[CHART] ERROR: ui_Chart4 is NULL!");
    }
}

extern "C" void ui_charts_init_control_screen(void) {
    Serial.println("[CHART] === ui_charts_init_control_screen() CALLED ===");
    Serial.flush();
    
    // Register Control Screen charts (ui_Chart5, ui_Chart6)  
    if (ui_Chart5) {
        chart_data_manager_register_chart(ui_Chart5, CHART_TYPE_POWER, "Power Output");
        Serial.println("[CHART] Registered ui_Chart5 (Power)");
    } else {
        Serial.println("[CHART] ERROR: ui_Chart5 is NULL!");
    }
    
    if (ui_Chart6) {
        chart_data_manager_register_chart(ui_Chart6, CHART_TYPE_DEMO, "Demo Data");
        Serial.println("[CHART] Registered ui_Chart6 (Demo)");
    } else {
        Serial.println("[CHART] ERROR: ui_Chart6 is NULL!");
    }
}

extern "C" void ui_charts_start_realtime(void) {
    Serial.println("[CHART] === ui_charts_start_realtime() CALLED ===");
    Serial.flush();
    
    // Start the automatic data updates
    chart_data_manager_start_updates();
    Serial.println("[CHART] Chart updates started");
}

extern "C" void ui_charts_stop_realtime(void) {
    // Stop the automatic data updates
    chart_data_manager_stop_updates();
}
