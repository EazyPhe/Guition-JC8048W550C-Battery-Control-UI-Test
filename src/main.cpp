#include <Arduino.h>
#include <Wire.h>
#include <lvgl.h>
#include <TAMC_GT911.h>
#include <esp_heap_caps.h>
#include "display_driver.h"
#include "diagnostics.h"
#include "ui_compat.h" // Include compatibility layer first
#include "ui/ui.h"     // Then include the SquareLine UI

// FreeRTOS includes for ESP32
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

// Display and touch configuration
#define TOUCH_WIDTH    800
#define TOUCH_HEIGHT   480
#define DISPLAY_WIDTH  TOUCH_WIDTH
#define DISPLAY_HEIGHT TOUCH_HEIGHT
#define GT911_I2C_ADDR 0x5D
#define GT911_INT_PIN  18
#define GT911_RST_PIN  38
#define GT911_SDA_PIN  19
#define GT911_SCL_PIN  20

// LVGL Buffer configuration
#define LVGL_BUFFER_PIXELS (DISPLAY_WIDTH * 40) // 40 lines buffer
#define LVGL_MALLOC_FLAGS (MALLOC_CAP_INTERNAL | MALLOC_CAP_DMA)

// Touch controller
TAMC_GT911 tp(GT911_SDA_PIN, GT911_SCL_PIN, GT911_INT_PIN, GT911_RST_PIN, TOUCH_WIDTH, TOUCH_HEIGHT);

// LVGL variables
static lv_color_t *buf;
static lv_disp_t *display;
static lv_indev_t *indev_touch;

// Touch indicator
static lv_obj_t *label;
static lv_obj_t *touch_point;

// Operating mode
enum DisplayMode {
    MODE_DEMO,       // Demo UI with touch indicator
    MODE_SQUARELINE  // SquareLine UI
};

static DisplayMode currentMode = MODE_SQUARELINE;
static lv_style_t style_touch_point;

// Display flush callback for LVGL 8.x
static void display_flush_cb(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p) {
    if (panel_handle) {
        esp_lcd_panel_draw_bitmap(panel_handle, area->x1, area->y1, area->x2 + 1, area->y2 + 1, color_p);
    } else {
        Serial.println("ERROR: No panel handle available");
    }
    lv_disp_flush_ready(disp_drv);
    static uint32_t flush_count = 0;
    if (++flush_count % 100 == 0) {
        Serial.printf("Display flush %d\n", flush_count);
    }
}

// Touch read callback for LVGL 8.x
static void touch_read_cb(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
    tp.read();
    bool touched = tp.isTouched;
    if (touched && tp.touches > 0) {
        data->point.x = TOUCH_WIDTH - 1 - tp.points[0].x; // Flip X axis
        data->point.y = TOUCH_HEIGHT - 1 - tp.points[0].y; // Flip Y axis
        data->state = LV_INDEV_STATE_PRESSED;
        char buf[32];
        snprintf(buf, sizeof(buf), "Touch: %d,%d", data->point.x, data->point.y);
        if (label) {
            lv_label_set_text(label, buf);
        }
        if (touch_point) {
            lv_obj_clear_flag(touch_point, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_pos(touch_point, data->point.x - 5, data->point.y - 5);
        }
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
        if (touch_point) {
            lv_obj_add_flag(touch_point, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

// Create a simple test UI
static void create_simple_ui(void) {
    // Create a screen with a button and a label
    lv_obj_t *scr = lv_scr_act();
    lv_obj_set_style_bg_color(scr, lv_color_make(0, 0, 128), LV_PART_MAIN);
    
    // Create a title
    lv_obj_t *title = lv_label_create(scr);
    lv_obj_align(title, LV_ALIGN_TOP_MID, 0, 20);
    lv_obj_set_style_text_font(title, &lv_font_montserrat_14, LV_PART_MAIN);
    lv_obj_set_style_text_color(title, lv_color_make(255, 255, 255), LV_PART_MAIN);
    lv_label_set_text(title, "Display Test");
    
    // Create a touch coordinates label
    label = lv_label_create(scr);
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 50);
    lv_obj_set_style_text_color(label, lv_color_make(255, 255, 0), LV_PART_MAIN);
    lv_label_set_text(label, "Touch the screen");
    
    // Create a red circle for touch indication
    touch_point = lv_obj_create(scr);
    lv_obj_set_size(touch_point, 10, 10);
    lv_obj_set_style_radius(touch_point, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(touch_point, lv_color_make(255, 0, 0), LV_PART_MAIN);
    lv_obj_add_flag(touch_point, LV_OBJ_FLAG_HIDDEN);
    
    // Create a test button
    lv_obj_t *btn = lv_btn_create(scr);
    lv_obj_set_size(btn, 120, 50);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, -40);
    lv_obj_set_style_bg_color(btn, lv_color_make(0, 180, 0), LV_PART_MAIN);
    
    lv_obj_t *btn_label = lv_label_create(btn);
    lv_label_set_text(btn_label, "Load UI");
    lv_obj_center(btn_label);
    
    // Add event to switch to SquareLine UI (LVGL 8.x: use lv_obj_add_event_cb)
    lv_obj_add_event_cb(btn, [](lv_event_t *e) {
        currentMode = MODE_SQUARELINE;
        ui_init(); // Initialize and load the SquareLine UI
    }, LV_EVENT_CLICKED, NULL);
}

// Uncomment to enable GT911 touch test mode (no LCD required)
// #define TOUCH_TEST_MODE

#ifdef TOUCH_TEST_MODE
void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("\nGT911 Touch Test Mode (LCD not initialized)");
    tp.begin();
    Serial.println("GT911 initialization command sent. Touch the panel to test.");
}

void loop() {
    tp.read();
    if (tp.isTouched && tp.touches > 0) {
        Serial.printf("Touch: x=%d, y=%d\n", tp.points[0].x, tp.points[0].y);
    } else {
        Serial.println("No touch");
    }
    delay(200);
}
#else
// --- FreeRTOS LVGL integration ---
// LVGL tick timer handle
static TimerHandle_t lvgl_tick_timer = NULL;
// LVGL task handle
static TaskHandle_t lvgl_task_handle = NULL;

// LVGL tick increment callback (called every 1ms)
void lvgl_tick_task(TimerHandle_t xTimer) {
    lv_tick_inc(1);
}

// LVGL handler task (runs lv_timer_handler in a loop)
void lvgl_task(void *pvParameter) {
    while (1) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(5)); // 5ms for smooth UI
    }
}

// --- Touch debug task for serial output ---
void touch_debug_task(void *pvParameter) {
    while (1) {
        tp.read();
        if (tp.isTouched && tp.touches > 0) {
            Serial.printf("[Touch Debug] x=%d, y=%d\n", tp.points[0].x, tp.points[0].y);
        }
        vTaskDelay(pdMS_TO_TICKS(100)); // Print every 100ms
    }
}

void setup() {
    Serial.begin(115200);
    delay(100);
    Serial.println("Display Test - Basic Version");
    print_diagnostics();
    tp.begin();
    Serial.println("Touch controller initialized");
    panel_handle = lcd_panel_init();
    if (!panel_handle) {
        Serial.println("ERROR: Failed to initialize LCD panel!");
        while (1) delay(100);
    }
    lv_init();
    Serial.println("LVGL initialized");
    uint32_t buf_size = LVGL_BUFFER_PIXELS;
    buf = (lv_color_t *)heap_caps_malloc(buf_size * sizeof(lv_color_t), LVGL_MALLOC_FLAGS);
    if (!buf) {
        Serial.println("ERROR: Failed to allocate LVGL buffer!");
        while (1) delay(100);
    }
    Serial.printf("LVGL buffer allocated: %d pixels\n", buf_size);
    // LVGL 8.x display driver setup
    static lv_disp_draw_buf_t draw_buf;
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, buf_size);
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = DISPLAY_WIDTH;
    disp_drv.ver_res = DISPLAY_HEIGHT;
    disp_drv.flush_cb = display_flush_cb;
    disp_drv.draw_buf = &draw_buf;
    display = lv_disp_drv_register(&disp_drv);
    // LVGL 8.x input device driver setup
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = touch_read_cb;
    indev_touch = lv_indev_drv_register(&indev_drv);
    // Initialize UI based on current mode
    // if (currentMode == MODE_DEMO) {
    //     create_simple_ui();
    //     Serial.println("Demo UI initialized");
    // } else {
        ui_init();
        Serial.println("SquareLine UI initialized");
    // }
    Serial.println("Setup complete");

    // --- Start FreeRTOS LVGL tick timer (1ms) ---
    lvgl_tick_timer = xTimerCreate("lvgl_tick", pdMS_TO_TICKS(1), pdTRUE, NULL, lvgl_tick_task);
    if (lvgl_tick_timer != NULL) {
        xTimerStart(lvgl_tick_timer, 0);
    } else {
        Serial.println("ERROR: Failed to create LVGL tick timer!");
    }
    // --- Start FreeRTOS LVGL handler task ---
    xTaskCreatePinnedToCore(lvgl_task, "LVGL", 4096, NULL, 2, &lvgl_task_handle, 1); // Core 1, priority 2
    // --- Start touch debug task ---
    xTaskCreatePinnedToCore(touch_debug_task, "TouchDebug", 2048, NULL, 1, NULL, 1); // Core 1, lower priority
}

void loop() {
    // Main loop can be used for other tasks, but LVGL is now handled by FreeRTOS
    vTaskDelay(pdMS_TO_TICKS(100));
}
#endif
