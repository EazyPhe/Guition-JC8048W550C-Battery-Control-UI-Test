# Board Pinouts Reference

This document provides a summary of the display and touch controller pin mappings for all supported boards in this project. For full details, see the board JSON files in the `boards/` directory and the main project documentation.

---

## How to Use
- Use these tables to quickly identify the correct GPIO assignments for display, touch, and other peripherals for each board.
- For custom hardware, refer to the relevant table and update your board JSON and code accordingly.

---

<!-- Example Table: Add more boards below as needed -->

## JC8048W550 (ESP32-S3, 7" 800x480, ST7262 + GT911)

| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD HSYNC        | 39   | ST7262 RGB           |
| LCD VSYNC        | 41   |                      |
| LCD DE           | 40   |                      |
| LCD PCLK         | 42   |                      |
| LCD R0           | 8    |                      |
| LCD R1           | 3    |                      |
| LCD R2           | 46   |                      |
| LCD R3           | 9    |                      |
| LCD R4           | 1    |                      |
| LCD G0           | 5    |                      |
| LCD G1           | 6    |                      |
| LCD G2           | 7    |                      |
| LCD G3           | 15   |                      |
| LCD G4           | 16   |                      |
| LCD G5           | 4    |                      |
| LCD B0           | 45   |                      |
| LCD B1           | 48   |                      |
| LCD B2           | 47   |                      |
| LCD B3           | 21   |                      |
| LCD B4           | 14   |                      |
| Backlight        | 2    | Active high          |
| Touch SDA        | 19   | GT911 I2C            |
| Touch SCL        | 20   |                      |
| Touch INT        | 18   |                      |
| Touch RST        | 38   |                      |

---

<!-- Repeat for other boards, e.g. ESP32-8048S043C, ESP32-8048S050C, etc. -->

<!-- To add: Extract and summarize pinouts for each board from their respective JSON files. -->
