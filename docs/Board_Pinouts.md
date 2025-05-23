# Board Pinouts Reference

This document provides a summary of the display and touch controller pin mappings for all supported boards in this project. For full details, see the board JSON files in the `boards/` directory and the main project documentation.

---

## How to Use
- Use these tables to quickly identify the correct GPIO assignments for display, touch, and other peripherals for each board.
- For custom hardware, refer to the relevant table and update your board JSON and code accordingly.

---

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

## ESP32-8048S043C (800x480, ST7262 + GT911)
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
| SD Card CS       | 10   |                      |
| SD Card MOSI     | 11   |                      |
| SD Card SCLK     | 12   |                      |
| SD Card MISO     | 13   |                      |

---

## ESP32-8048S050C (800x480, ST7262 + GT911)
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
| SD Card CS       | 10   |                      |
| SD Card MOSI     | 11   |                      |
| SD Card SCLK     | 12   |                      |
| SD Card MISO     | 13   |                      |

---

## ESP32-8048S070C (800x480, ST7262 + GT911)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD HSYNC        | 39   | ST7262 RGB           |
| LCD VSYNC        | 40   |                      |
| LCD DE           | 41   |                      |
| LCD PCLK         | 42   |                      |
| LCD R0           | 15   |                      |
| LCD R1           | 7    |                      |
| LCD R2           | 6    |                      |
| LCD R3           | 5    |                      |
| LCD R4           | 4    |                      |
| LCD G0           | 9    |                      |
| LCD G1           | 46   |                      |
| LCD G2           | 3    |                      |
| LCD G3           | 8    |                      |
| LCD G4           | 16   |                      |
| LCD G5           | 1    |                      |
| LCD B0           | 14   |                      |
| LCD B1           | 21   |                      |
| LCD B2           | 47   |                      |
| LCD B3           | 48   |                      |
| LCD B4           | 45   |                      |
| Backlight        | 2    | Active high          |
| Touch SDA        | 19   | GT911 I2C            |
| Touch SCL        | 20   |                      |
| Touch INT        | 18   |                      |
| Touch RST        | 38   |                      |
| SD Card CS       | 10   |                      |
| SD Card MOSI     | 11   |                      |
| SD Card SCLK     | 12   |                      |
| SD Card MISO     | 13   |                      |

---

## ESP32-S3-Touch-LCD-7 (800x480, ST7262 + GT911)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD HSYNC        | 46   | ST7262 RGB           |
| LCD VSYNC        | 3    |                      |
| LCD DE           | 5    |                      |
| LCD PCLK         | 7    |                      |
| LCD R0           | 14   |                      |
| LCD R1           | 38   |                      |
| LCD R2           | 18   |                      |
| LCD R3           | 17   |                      |
| LCD R4           | 10   |                      |
| LCD G0           | 39   |                      |
| LCD G1           | 0    |                      |
| LCD G2           | 45   |                      |
| LCD G3           | 48   |                      |
| LCD G4           | 47   |                      |
| LCD G5           | 21   |                      |
| LCD B0           | 1    |                      |
| LCD B1           | 2    |                      |
| LCD B2           | 42   |                      |
| LCD B3           | 41   |                      |
| LCD B4           | 40   |                      |
| Backlight        | -1   | Not connected         |
| Touch SDA        | 8    | GT911 I2C            |
| Touch SCL        | 9    |                      |
| Touch INT        | NC   | Not connected         |
| Touch RST        | NC   | Not connected         |

---

## ESP32-3248S035C (320x480, ST7796 + GT911)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD SPI MOSI     | 13   | ST7796 SPI           |
| LCD SPI MISO     | 12   |                      |
| LCD SPI SCLK     | 14   |                      |
| LCD CS           | 15   |                      |
| LCD DC           | 2    |                      |
| Backlight        | 27   |                      |
| Touch SDA        | 33   | GT911 I2C            |
| Touch SCL        | 32   |                      |
| Touch INT        | 21   |                      |
| Touch RST        | 25   |                      |
| SD Card CS       | 5    |                      |
| SD Card MOSI     | 23   |                      |
| SD Card SCLK     | 18   |                      |
| SD Card MISO     | 19   |                      |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16   |                      |
| RGB LED B        | 17   |                      |
| CdS Light Sensor | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-2432S032C (240x320, ST7789 + GT911)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD SPI MOSI     | 13   | ST7789 SPI           |
| LCD SPI MISO     | 12   |                      |
| LCD SPI SCLK     | 14   |                      |
| LCD CS           | 15   |                      |
| LCD DC           | 2    |                      |
| Backlight        | 27   |                      |
| Touch SDA        | 33   | GT911 I2C            |
| Touch SCL        | 32   |                      |
| Touch INT        | 21   |                      |
| Touch RST        | 25   |                      |
| SD Card CS       | 5    |                      |
| SD Card MOSI     | 23   |                      |
| SD Card SCLK     | 18   |                      |
| SD Card MISO     | 19   |                      |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16   |                      |
| RGB LED B        | 17   |                      |
| CdS Light Sensor | 34   |                      |
| Speaker          | 26   |                      |

---

## JC4827W543C (480x272, NV3041A + GT911)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD SPI MOSI     | 21   | NV3041A SPI          |
| LCD SPI MISO     | 48   |                      |
| LCD SPI SCLK     | 47   |                      |
| LCD CS           | 45   |                      |
| LCD DC           | 2    |                      |
| Backlight        | 1    |                      |
| Touch SDA        | 19   | GT911 I2C            |
| Touch SCL        | 20   |                      |
| Touch INT        | 18   |                      |
| Touch RST        | 38   |                      |
| SD Card CS       | 10   |                      |
| SD Card MOSI     | 11   |                      |
| SD Card SCLK     | 12   |                      |
| SD Card MISO     | 13   |                      |

---

## ESP32-1732S019C (170x320, ST7789 + GT911)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD SPI MOSI     | 13   | ST7789 SPI           |
| LCD SPI SCLK     | 12   |                      |
| LCD CS           | 10   |                      |
| LCD DC           | 11   |                      |
| LCD RST          | 1    |                      |
| Backlight        | 14   |                      |
| Touch SDA        | 9    | GT911 I2C            |
| Touch SCL        | 46   |                      |
| Touch INT        | 8    |                      |
| Touch RST        | 3    |                      |

---

<!-- Add more boards as needed by copying the format above and extracting from the relevant JSON files. -->
