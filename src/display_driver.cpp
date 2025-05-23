#include "display_driver.h"
// #include "st7262_panel/esp_lcd_st7262.h"

esp_lcd_panel_handle_t panel_handle = NULL;

esp_lcd_panel_handle_t lcd_panel_init(void) {
    Serial.println("Initializing LCD panel...");
    
    esp_lcd_rgb_panel_config_t panel_config = {
        .clk_src = LCD_CLK_SRC_PLL160M,
        .timings = {
            .pclk_hz = (16 * 1000000), // 16MHz pixel clock (matches Clocky)
            .h_res = 800,
            .v_res = 480,
            .hsync_pulse_width = 4,
            .hsync_back_porch = 8,
            .hsync_front_porch = 8,
            .vsync_pulse_width = 4,
            .vsync_back_porch = 8,
            .vsync_front_porch = 8,
            .flags = {
                .hsync_idle_low = false,
                .vsync_idle_low = false,
                .de_idle_high = false,
                .pclk_active_neg = true,
                .pclk_idle_high = false,
            },
        },
        .data_width = 16, // RGB565 (16-bit)
        .sram_trans_align = 4,
        .psram_trans_align = 64,
        .hsync_gpio_num = 39,
        .vsync_gpio_num = 41,
        .de_gpio_num = 40,
        .pclk_gpio_num = 42,
        .data_gpio_nums = {
            // R0-4
            8, 3, 46, 9, 1,
            // G0-5
            5, 6, 7, 15, 16, 4,
            // B0-4
            45, 48, 47, 21, 14,
        },
        .disp_gpio_num = -1, // GPIO_NUM_NC (not connected)
        .on_frame_trans_done = NULL,
        .user_ctx = NULL,
        .flags = {
            .disp_active_low = false,
            .fb_in_psram = true, // Using PSRAM for frame buffer
        },
    };
    
    // Print panel config for debugging
    Serial.println("Panel config:");
    Serial.printf("  clk_src: %d\n", panel_config.clk_src);
    Serial.printf("  timings.pclk_hz: %u\n", panel_config.timings.pclk_hz);
    Serial.printf("  timings.h_res: %u\n", panel_config.timings.h_res);
    Serial.printf("  timings.v_res: %u\n", panel_config.timings.v_res);
    Serial.printf("  timings.hsync_pulse_width: %u\n", panel_config.timings.hsync_pulse_width);
    Serial.printf("  timings.hsync_back_porch: %u\n", panel_config.timings.hsync_back_porch);
    Serial.printf("  timings.hsync_front_porch: %u\n", panel_config.timings.hsync_front_porch);
    Serial.printf("  timings.vsync_pulse_width: %u\n", panel_config.timings.vsync_pulse_width);
    Serial.printf("  timings.vsync_back_porch: %u\n", panel_config.timings.vsync_back_porch);
    Serial.printf("  timings.vsync_front_porch: %u\n", panel_config.timings.vsync_front_porch);
    Serial.printf("  timings.flags: hsync_idle_low=%d, vsync_idle_low=%d, de_idle_high=%d, pclk_active_neg=%d, pclk_idle_high=%d\n",
        panel_config.timings.flags.hsync_idle_low,
        panel_config.timings.flags.vsync_idle_low,
        panel_config.timings.flags.de_idle_high,
        panel_config.timings.flags.pclk_active_neg,
        panel_config.timings.flags.pclk_idle_high);
    Serial.printf("  data_width: %u\n", panel_config.data_width);
    Serial.printf("  sram_trans_align: %u\n", panel_config.sram_trans_align);
    Serial.printf("  psram_trans_align: %u\n", panel_config.psram_trans_align);
    Serial.printf("  hsync_gpio_num: %d\n", panel_config.hsync_gpio_num);
    Serial.printf("  vsync_gpio_num: %d\n", panel_config.vsync_gpio_num);
    Serial.printf("  de_gpio_num: %d\n", panel_config.de_gpio_num);
    Serial.printf("  pclk_gpio_num: %d\n", panel_config.pclk_gpio_num);
    Serial.print("  data_gpio_nums: ");
    for (int i = 0; i < 16; ++i) Serial.printf("%d ", panel_config.data_gpio_nums[i]);
    Serial.println();
    Serial.printf("  disp_gpio_num: %d\n", panel_config.disp_gpio_num);
    Serial.printf("  flags: disp_active_low=%d, fb_in_psram=%d\n", panel_config.flags.disp_active_low, panel_config.flags.fb_in_psram);

    // Initialize the LCD panel
    esp_err_t ret = esp_lcd_new_rgb_panel(&panel_config, &panel_handle);
    Serial.printf("esp_lcd_new_rgb_panel: %d\n", ret);
    if (ret != ESP_OK) {
        Serial.printf("LCD panel initialization failed: %d\n", ret);
        return NULL;
    }
    // Reset and initialize the panel
    ret = esp_lcd_panel_reset(panel_handle);
    Serial.printf("esp_lcd_panel_reset: %d\n", ret);
    if (ret != ESP_OK) {
        Serial.printf("LCD panel reset failed: %d\n", ret);
        return NULL;
    }
    ret = esp_lcd_panel_init(panel_handle);
    Serial.printf("esp_lcd_panel_init: %d\n", ret);
    if (ret != ESP_OK) {
        Serial.printf("LCD panel init failed: %d\n", ret);
        return NULL;
    }
    // Optional: invert color for IPS panels (safe to try)
    esp_lcd_panel_invert_color(panel_handle, false); // Changed from true to false
    // Optional: set gap (usually 0,0)
    esp_lcd_panel_set_gap(panel_handle, 0, 0);
    delay(50); // Allow panel hardware to settle before turning on
    // Do NOT call esp_lcd_panel_disp_on_off for ST7262 (not supported)
    Serial.println("LCD panel initialized successfully");
    
    // Initialize backlight
    lcd_backlight(true);
    
    return panel_handle;
}

void lcd_backlight(bool on) {
    // Configure backlight GPIO
    gpio_config_t bk_gpio_config = {
        .pin_bit_mask = 1ULL << GPIO_BCKL,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&bk_gpio_config);
    
    // Turn backlight on/off
    gpio_set_level((gpio_num_t)GPIO_BCKL, on ? 1 : 0);
    Serial.printf("Backlight turned %s\n", on ? "ON" : "OFF");
}
