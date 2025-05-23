# ST7262 + ESP32S3 + LVGL 8.3.x Integration Guide

This guide summarizes the key learnings and configuration steps for successfully initializing and running an ST7262-based LCD panel with an ESP32S3 using LVGL 8.3.x, based on analysis of a working project ("Clocky") and the current project setup.

## 1. Hardware and Board Configuration
- **Panel:** ST7262, 800x480 RGB interface
- **MCU:** ESP32S3
- **Touch:** GT911 (I2C)
- **Backlight:** GPIO2 (active high)

## 2. PlatformIO and Board Settings
- Use a custom board JSON (e.g., `JC8048W550.json`) with all display/touch pin assignments and timings as preprocessor macros.
- Example relevant `extra_flags` for the display:
  ```
  '-D DISPLAY_WIDTH=800'
  '-D DISPLAY_HEIGHT=480'
  '-D GPIO_BCKL=2'
  '-D DISPLAY_ST7262_PAR'
  '-D ST7262_PANEL_CONFIG_CLK_SRC=LCD_CLK_SRC_PLL160M'
  '-D ST7262_PANEL_CONFIG_TIMINGS_PCLK_HZ=(16*1000000)'
  '-D ST7262_PANEL_CONFIG_TIMINGS_H_RES=DISPLAY_WIDTH'
  '-D ST7262_PANEL_CONFIG_TIMINGS_V_RES=DISPLAY_HEIGHT'
  '-D ST7262_PANEL_CONFIG_TIMINGS_HSYNC_PULSE_WIDTH=4'
  '-D ST7262_PANEL_CONFIG_TIMINGS_HSYNC_BACK_PORCH=8'
  '-D ST7262_PANEL_CONFIG_TIMINGS_HSYNC_FRONT_PORCH=8'
  '-D ST7262_PANEL_CONFIG_TIMINGS_VSYNC_PULSE_WIDTH=4'
  '-D ST7262_PANEL_CONFIG_TIMINGS_VSYNC_BACK_PORCH=8'
  '-D ST7262_PANEL_CONFIG_TIMINGS_VSYNC_FRONT_PORCH=8'
  '-D ST7262_PANEL_CONFIG_TIMINGS_FLAGS_HSYNC_IDLE_LOW=false'
  '-D ST7262_PANEL_CONFIG_TIMINGS_FLAGS_VSYNC_IDLE_LOW=false'
  '-D ST7262_PANEL_CONFIG_TIMINGS_FLAGS_DE_IDLE_HIGH=false'
  '-D ST7262_PANEL_CONFIG_TIMINGS_FLAGS_PCLK_ACTIVE_NEG=true'
  '-D ST7262_PANEL_CONFIG_TIMINGS_FLAGS_PCLK_IDLE_HIGH=false'
  '-D ST7262_PANEL_CONFIG_DATA_WIDTH=16'
  '-D ST7262_PANEL_CONFIG_SRAM_TRANS_ALIGN=4'
  '-D ST7262_PANEL_CONFIG_PSRAM_TRANS_ALIGN=64'
  '-D ST7262_PANEL_CONFIG_HSYNC_GPIO_NUM=39'
  '-D ST7262_PANEL_CONFIG_VSYNC_GPIO_NUM=41'
  '-D ST7262_PANEL_CONFIG_DE_GPIO_NUM=40'
  '-D ST7262_PANEL_CONFIG_PCLK_GPIO_NUM=42'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_R0=8'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_R1=3'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_R2=46'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_R3=9'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_R4=1'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_G0=5'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_G1=6'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_G2=7'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_G3=15'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_G4=16'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_G5=4'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_B0=45'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_B1=48'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_B2=47'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_B3=21'
  '-D ST7262_PANEL_CONFIG_DATA_GPIO_B4=14'
  '-D ST7262_PANEL_CONFIG_DISP_GPIO_NUM=GPIO_NUM_NC'
  '-D ST7262_PANEL_CONFIG_FLAGS_DISP_ACTIVE_LOW=false'
  '-D ST7262_PANEL_CONFIG_FLAGS_RELAX_ON_IDLE=false'
  '-D ST7262_PANEL_CONFIG_FLAGS_FB_IN_PSRAM=true'
  ```
- Ensure all macros are set in both `platformio.ini` and the board JSON.

## 3. LVGL and Display Driver Setup
- Use LVGL 8.3.x (not 9.x) for compatibility with existing drivers and APIs.
- In your display driver (e.g., `display_driver.cpp`), configure the `esp_lcd_rgb_panel_config_t` struct to match the working project exactly:
  ```cpp
  esp_lcd_rgb_panel_config_t panel_config = {
      .clk_src = LCD_CLK_SRC_PLL160M,
      .timings = {
          .pclk_hz = (16 * 1000000),
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
      .data_width = 16,
      .sram_trans_align = 4,
      .psram_trans_align = 64,
      .hsync_gpio_num = 39,
      .vsync_gpio_num = 41,
      .de_gpio_num = 40,
      .pclk_gpio_num = 42,
      .data_gpio_nums = {8, 3, 46, 9, 1, 5, 6, 7, 15, 16, 4, 45, 48, 47, 21, 14},
      .disp_gpio_num = -1, // GPIO_NUM_NC
      .on_frame_trans_done = NULL,
      .user_ctx = NULL,
      .flags = {
          .disp_active_low = false,
          .fb_in_psram = true,
      },
  };
  ```
- Call the following initialization sequence:
  ```cpp
  esp_lcd_new_rgb_panel(&panel_config, &panel_handle);
  esp_lcd_panel_reset(panel_handle);
  esp_lcd_panel_init(panel_handle);
  esp_lcd_panel_disp_on_off(panel_handle, true);
  ```
- If you use a backlight, configure and enable it after the panel is initialized.

## 4. Touch Controller (GT911)
- Use the same I2C pins and configuration as the working project.
- Test touch independently to confirm correct operation before enabling full display code.

## 5. Debugging Tips
- Print all panel config values before initialization to verify correctness.
- If `esp_lcd_panel_disp_on_off` fails (error 262), double-check all timings, pin assignments, and flags.
- If the display still does not work, investigate whether the working project or its libraries perform any additional ST7262 register initialization (not typical for RGB panels, but possible in some libraries).

## 6. No Custom ST7262 Register Sequence Needed
- The working project does not perform any explicit ST7262 register writes; all configuration is handled via the ESP-IDF RGB panel driver and correct config values.
- If you need to add custom register writes, you would need to implement them before calling `esp_lcd_panel_disp_on_off`.

## 7. Summary Checklist
- [x] LVGL 8.3.x in use
- [x] All display/touch macros match working project
- [x] Panel config struct matches working project
- [x] Initialization sequence matches working project
- [x] Backlight enabled after panel init
- [x] Touch controller tested and working

---

**If you follow these steps and match the working project's configuration exactly, your ST7262 panel should initialize and display correctly on the ESP32S3 with LVGL 8.3.x.**
