#include <Arduino.h>
#include <Wire.h>
#include <lvgl.h>
#include <TAMC_GT911.h>
#include <esp_heap_caps.h> // For heap_caps_malloc

// GT911 config (update if needed)
#define GT911_I2C_ADDR 0x5D
#define GT911_INT_PIN  18
#define GT911_RST_PIN  38
#define GT911_SDA_PIN  19
#define GT911_SCL_PIN  20
#define TOUCH_WIDTH    800
#define TOUCH_HEIGHT   480

// LVGL Display and Buffer configuration
#define DISPLAY_WIDTH  TOUCH_WIDTH
#define DISPLAY_HEIGHT TOUCH_HEIGHT
#define LVGL_BUFFER_PIXELS (DISPLAY_WIDTH * 40) // Buffer size: 40 lines
#define LVGL_MALLOC_FLAGS (MALLOC_CAP_INTERNAL | MALLOC_CAP_DMA) // ESP32 internal RAM

TAMC_GT911 tp(GT911_SDA_PIN, GT911_SCL_PIN, GT911_INT_PIN, GT911_RST_PIN, TOUCH_WIDTH, TOUCH_HEIGHT);

// LVGL 9 types
// static lv_draw_buf_t draw_buf; // Not directly needed for lv_display_set_buffers in v9
static lv_color_t *buf;
static lv_display_t *display;
static lv_indev_t *indev_touch; // Added declaration

// LVGL objects
static lv_obj_t *label;
static lv_obj_t *touch_point;

// Touch indicator style
static lv_style_t style_touch_point;

// Display flush callback
static void display_flush_cb(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map) { // LVGL v9 signature
    // esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t)lv_display_get_user_data(disp); // Correct way to get user_data if set
    
    // Placeholder for actual display flush
    // esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, px_map);
    
    lv_display_flush_ready(disp); // Use disp
}

// Touch read callback
static void touch_read_cb(lv_indev_t *indev, lv_indev_data_t *data) { // LVGL v9 signature
    tp.read(); // Read touch data from GT911
    bool touched = tp.isTouched; // TAMC_GT911 sets this flag
    
    if (touched && tp.touches > 0) { // Ensure there's at least one touch point
        data->point.x = tp.points[0].x; // Use the points array
        data->point.y = tp.points[0].y;
        data->state = LV_INDEV_STATE_PRESSED;

        // Update label with coordinates
        char coord_buf_str[32]; // Renamed to avoid conflict and be more specific
        snprintf(coord_buf_str, sizeof(coord_buf_str), "Touch: (%d,%d)", data->point.x, data->point.y);
        if(label) lv_label_set_text(label, coord_buf_str);
        
        // Move the touch indicator
        if(touch_point) {
            // Center the touch point indicator on the touch coordinates
            lv_obj_set_pos(touch_point, data->point.x - lv_obj_get_width(touch_point) / 2, data->point.y - lv_obj_get_height(touch_point) / 2);
            lv_obj_clear_flag(touch_point, LV_OBJ_FLAG_HIDDEN);
        }
        
        // Print to Serial as well
        Serial.printf("Touch: x=%d, y=%d\n", data->point.x, data->point.y);
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
        if(touch_point) lv_obj_add_flag(touch_point, LV_OBJ_FLAG_HIDDEN);
    }
}

void setup() {
    Serial.begin(115200);
    delay(100);
    // Wire.begin(GT911_SDA_PIN, GT911_SCL_PIN); // Redundant, tp.begin() calls Wire.begin()
    tp.begin();
    // tp.isOnline() does not exist, tp.begin() initializes.
    // We can assume it's online or add error handling based on touch reads later.
    Serial.println("Attempted GT911 initialization.");


    // LVGL 9 init
    lv_init();
    buf = (lv_color_t *)heap_caps_malloc(LVGL_BUFFER_PIXELS * sizeof(lv_color_t), LVGL_MALLOC_FLAGS);
    assert(buf != NULL);

    // Initialize draw buffer - Not needed as a separate step for lv_display_set_buffers
    // lv_draw_buf_init(&draw_buf, DISPLAY_WIDTH, DISPLAY_HEIGHT, LV_COLOR_FORMAT_RGB565_SWAP, DISPLAY_WIDTH * sizeof(lv_color_t), buf, LVGL_BUFFER_PIXELS * sizeof(lv_color_t));

    // Create display
    display = lv_display_create(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    lv_display_set_flush_cb(display, display_flush_cb);
    // lv_display_set_draw_buffers(display, &draw_buf, NULL); // v8 style
    lv_display_set_buffers(display, buf, NULL, LVGL_BUFFER_PIXELS, LV_DISPLAY_RENDER_MODE_PARTIAL); // LVGL v9
    // lv_display_set_render_mode(display, LV_DISPLAY_RENDER_MODE_PARTIAL); // Redundant if set in lv_display_set_buffers
    // lv_display_set_user_data(display, panel_handle); // If you have a panel_handle

    // Initialize input device
    indev_touch = lv_indev_create();
    lv_indev_set_type(indev_touch, LV_INDEV_TYPE_POINTER);
    lv_indev_set_read_cb(indev_touch, touch_read_cb);

    // Create a style for the touch point indicator
    lv_style_init(&style_touch_point);
    lv_style_set_radius(&style_touch_point, 5);
    lv_style_set_bg_color(&style_touch_point, lv_color_make(255, 0, 0));
    lv_style_set_bg_opa(&style_touch_point, LV_OPA_70);
    
    // Create a label for displaying coordinates
    label = lv_label_create(lv_scr_act());
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 10);
    lv_label_set_text(label, "Touch the screen");
    
    // Create touch point indicator
    touch_point = lv_obj_create(lv_scr_act());
    lv_obj_set_size(touch_point, 10, 10);
    lv_obj_add_style(touch_point, &style_touch_point, 0);
    lv_obj_add_flag(touch_point, LV_OBJ_FLAG_HIDDEN);
}

void loop() {
    // tp.read(); // Moved to touch_read_cb for LVGL, but can be here for non-LVGL debug
    // if (tp.isTouched) {
    //     TP_Point p = tp.readPoint(0); // Corrected method name
    //     Serial.printf("Touch: x=%d, y=%d\n", p.x, p.y);
    // }
    lv_timer_handler();
    delay(10);
}