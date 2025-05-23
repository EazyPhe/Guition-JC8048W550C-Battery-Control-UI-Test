#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include <Arduino.h>
#include <esp_heap_caps.h>
#include <esp_system.h>
#include <lvgl.h>

/**
 * Print system diagnostic information to the Serial console
 */
void print_diagnostics() {
    Serial.println("=== System Diagnostics ===");
    
    // ESP32 chip information
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    Serial.printf("ESP32 Chip: %s with %d CPU core(s), WiFi%s%s\n",
        CONFIG_IDF_TARGET,
        chip_info.cores,
        (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
        (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
    
    // Memory information
    Serial.printf("Internal Total Heap: %d, Free: %d\n", 
        heap_caps_get_total_size(MALLOC_CAP_INTERNAL), 
        heap_caps_get_free_size(MALLOC_CAP_INTERNAL));
        
    Serial.printf("PSRAM Total: %d, Free: %d\n", 
        heap_caps_get_total_size(MALLOC_CAP_SPIRAM), 
        heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
    
    // LVGL version info
    Serial.printf("LVGL version: %d.%d.%d\n", 
        lv_version_major(), lv_version_minor(), lv_version_patch());
    
    Serial.println("==========================");
}

#endif // DIAGNOSTICS_H
