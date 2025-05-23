#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#include <Arduino.h>
#include <esp_lcd_panel_io.h>
#include <esp_lcd_panel_rgb.h>
#include <esp_lcd_panel_ops.h>
#include <esp_heap_caps.h>
#include <driver/gpio.h>
#include <driver/spi_master.h>
#include <esp_err.h>
#include <lvgl.h>

// Display configuration (already defined in board JSON)
#ifndef DISPLAY_WIDTH
#define DISPLAY_WIDTH  800
#endif

#ifndef DISPLAY_HEIGHT
#define DISPLAY_HEIGHT 480
#endif

#ifndef GPIO_BCKL
#define GPIO_BCKL 2  // Backlight pin
#endif

// Function to initialize the RGB LCD panel for ST7262
esp_lcd_panel_handle_t lcd_panel_init(void);

// Function to turn backlight on/off
void lcd_backlight(bool on);

extern esp_lcd_panel_handle_t panel_handle;

#endif // DISPLAY_DRIVER_H
