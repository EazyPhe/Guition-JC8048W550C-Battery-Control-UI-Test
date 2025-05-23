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

## ESP32-2432S024R
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD Backlight    | 27   | GPIO_BCKL            |
| LCD SPI MOSI     | 13   | ILI9341_SPI_BUS_MOSI |
| LCD SPI MISO     | 12   | ILI9341_SPI_BUS_MISO |
| LCD SPI SCLK     | 14   | ILI9341_SPI_BUS_SCLK |
| LCD SPI CS       | 15   | ILI9341_SPI_CS       |
| LCD SPI DC       | 2    | ILI9341_SPI_DC       |
| Touch SPI MOSI   | 13   | XPT2046_SPI_BUS_MOSI |
| Touch SPI MISO   | 12   | XPT2046_SPI_BUS_MISO |
| Touch SPI SCLK   | 14   | XPT2046_SPI_BUS_SCLK |
| Touch SPI CS     | 33   | XPT2046_SPI_CS       |
| Touch INT        | 36   | XPT2046_TOUCH_INT    |
| SD Card CS       | 5    | TF_CS                |
| SD Card MOSI     | 23   | TF_SPI_MOSI          |
| SD Card SCLK     | 18   | TF_SPI_SCLK          |
| SD Card MISO     | 19   | TF_SPI_MISO          |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16   |                      |
| RGB LED B        | 17   |                      |
| CDS              | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-2432S028R
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD Backlight    | 21   | GPIO_BCKL            |
| LCD SPI MOSI     | 13   | ILI9341_SPI_BUS_MOSI |
| LCD SPI MISO     | 12   | ILI9341_SPI_BUS_MISO |
| LCD SPI SCLK     | 14   | ILI9341_SPI_BUS_SCLK |
| LCD SPI CS       | 15   | ILI9341_SPI_CS       |
| LCD SPI DC       | 2    | ILI9341_SPI_DC       |
| Touch SPI MOSI   | 32   | XPT2046_SPI_BUS_MOSI |
| Touch SPI MISO   | 39   | XPT2046_SPI_BUS_MISO |
| Touch SPI SCLK   | 25   | XPT2046_SPI_BUS_SCLK |
| Touch SPI CS     | 33   | XPT2046_SPI_CS       |
| Touch INT        | 36   | XPT2046_TOUCH_INT    |
| SD Card CS       | 5    | TF_CS                |
| SD Card MOSI     | 23   | TF_SPI_MOSI          |
| SD Card SCLK     | 18   | TF_SPI_SCLK          |
| SD Card MISO     | 19   | TF_SPI_MISO          |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16   |                      |
| RGB LED B        | 17   |                      |
| CDS              | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-2432S028Rv2
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD Backlight    | 21   | GPIO_BCKL            |
| LCD SPI MOSI     | 13   | ILI9341_SPI_BUS_MOSI |
| LCD SPI MISO     | 12   | ILI9341_SPI_BUS_MISO |
| LCD SPI SCLK     | 14   | ILI9341_SPI_BUS_SCLK |
| LCD SPI CS       | 15   | ILI9341_SPI_CS       |
| LCD SPI DC       | 2    | ILI9341_SPI_DC       |
| Touch SPI MOSI   | 32   | XPT2046_SPI_BUS_MOSI |
| Touch SPI MISO   | 39   | XPT2046_SPI_BUS_MISO |
| Touch SPI SCLK   | 25   | XPT2046_SPI_BUS_SCLK |
| Touch SPI CS     | 33   | XPT2046_SPI_CS       |
| Touch INT        | 36   | XPT2046_TOUCH_INT    |
| SD Card CS       | 5    | TF_CS                |
| SD Card MOSI     | 23   | TF_SPI_MOSI          |
| SD Card SCLK     | 18   | TF_SPI_SCLK          |
| SD Card MISO     | 19   | TF_SPI_MISO          |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16   |                      |
| RGB LED B        | 17   |                      |
| CDS              | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-2432S028Rv3
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD Backlight    | 21   | GPIO_BCKL            |
| LCD SPI MOSI     | 13   | ST7789_SPI_BUS_MOSI  |
| LCD SPI SCLK     | 14   | ST7789_SPI_BUS_SCLK  |
| LCD SPI CS       | 15   | ST7789_SPI_CS        |
| LCD SPI DC       | 2    | ST7789_SPI_DC        |
| Touch SPI MOSI   | 32   | XPT2046_SPI_BUS_MOSI |
| Touch SPI MISO   | 39   | XPT2046_SPI_BUS_MISO |
| Touch SPI SCLK   | 25   | XPT2046_SPI_BUS_SCLK |
| Touch SPI CS     | 33   | XPT2046_SPI_CS       |
| Touch INT        | 36   | XPT2046_TOUCH_INT    |
| SD Card CS       | 5    | TF_CS                |
| SD Card MOSI     | 23   | TF_SPI_MOSI          |
| SD Card SCLK     | 18   | TF_SPI_SCLK          |
| SD Card MISO     | 19   | TF_SPI_MISO          |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16   |                      |
| RGB LED B        | 17   |                      |
| CDS              | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-2432S032N
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD Backlight    | 27   | GPIO_BCKL            |
| LCD SPI MOSI     | 13   | ST7789_SPI_BUS_MOSI  |
| LCD SPI MISO     | 12   | ST7789_SPI_BUS_MISO  |
| LCD SPI SCLK     | 14   | ST7789_SPI_BUS_SCLK  |
| LCD SPI CS       | 15   | ST7789_SPI_CS        |
| LCD SPI DC       | 2    | ST7789_SPI_DC        |
| SD Card CS       | 5    | TF_CS                |
| SD Card MOSI     | 23   | TF_SPI_MOSI          |
| SD Card SCLK     | 18   | TF_SPI_SCLK          |
| SD Card MISO     | 19   | TF_SPI_MISO          |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16   |                      |
| RGB LED B        | 17   |                      |
| CDS              | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-2432S032R
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD Backlight    | 27   | GPIO_BCKL            |
| LCD SPI MOSI     | 13   | ST7789_SPI_BUS_MOSI  |
| LCD SPI MISO     | 12   | ST7789_SPI_BUS_MISO  |
| LCD SPI SCLK     | 14   | ST7789_SPI_BUS_SCLK  |
| LCD SPI CS       | 15   | ST7789_SPI_CS        |
| LCD SPI DC       | 2    | ST7789_SPI_DC        |
| Touch SPI MOSI   | 13   | XPT2046_SPI_BUS_MOSI |
| Touch SPI MISO   | 12   | XPT2046_SPI_BUS_MISO |
| Touch SPI SCLK   | 14   | XPT2046_SPI_BUS_SCLK |
| Touch SPI CS     | 33   | XPT2046_SPI_CS       |
| Touch INT        | 36   | XPT2046_TOUCH_INT    |
| SD Card CS       | 5    | TF_CS                |
| SD Card MOSI     | 23   | TF_SPI_MOSI          |
| SD Card SCLK     | 18   | TF_SPI_SCLK          |
| SD Card MISO     | 19   | TF_SPI_MISO          |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16   |                      |
| RGB LED B        | 17   |                      |
| CDS              | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-2432W328C
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD Backlight    | 27   | GPIO_BCKL            |
| LCD SPI MOSI     | 13   | ST7789_SPI_BUS_MOSI  |
| LCD SPI MISO     | 12   | ST7789_SPI_BUS_MISO  |
| LCD SPI SCLK     | 14   | ST7789_SPI_BUS_SCLK  |
| LCD SPI CS       | 15   | ST7789_SPI_CS        |
| LCD SPI DC       | 2    | ST7789_SPI_DC        |
| Touch SDA        | 33   | CST816S_I2C_SDA      |
| Touch SCL        | 32   | CST816S_I2C_SCL      |
| Touch INT        | 21   | CST816S_TOUCH_INT    |
| Touch RST        | 25   | CST816S_TOUCH_RST    |
| SD Card CS       | 5    | TF_CS                |
| SD Card MOSI     | 23   | TF_SPI_MOSI          |
| SD Card SCLK     | 18   | TF_SPI_SCLK          |
| SD Card MISO     | 19   | TF_SPI_MISO          |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16    |                      |
| RGB LED B        | 17    |                      |
| CDS              | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-3248S035R
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD Backlight    | 27   | GPIO_BCKL            |
| LCD SPI MOSI     | 13   | ST7796_SPI_BUS_MOSI  |
| LCD SPI MISO     | 12   | ST7796_SPI_BUS_MISO  |
| LCD SPI SCLK     | 14   | ST7796_SPI_BUS_SCLK  |
| LCD SPI CS       | 15   | ST7796_SPI_CS        |
| LCD SPI DC       | 2    | ST7796_SPI_DC        |
| Touch SPI MOSI   | 13   | XPT2046_SPI_BUS_MOSI |
| Touch SPI MISO   | 12   | XPT2046_SPI_BUS_MISO |
| Touch SPI SCLK   | 14   | XPT2046_SPI_BUS_SCLK |
| Touch SPI CS     | 33   | XPT2046_SPI_CS       |
| Touch INT        | 36   | XPT2046_TOUCH_INT    |
| SD Card CS       | 5    | TF_CS                |
| SD Card MOSI     | 23   | TF_SPI_MOSI          |
| SD Card SCLK     | 18   | TF_SPI_SCLK          |
| SD Card MISO     | 19   | TF_SPI_MISO          |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16   |                      |
| RGB LED B        | 17   |                      |
| CDS              | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-4827S043C
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
| Backlight        | 2    | GPIO_BCKL            |
| Touch SDA        | 19   | GT911_I2C_SDA        |
| Touch SCL        | 20   | GT911_I2C_SCL        |
| Touch INT        | 18   | GT911_TOUCH_INT      |
| Touch RST        | 38   | GT911_TOUCH_RST      |
| SD Card CS       | 10   | TF_CS                |
| SD Card MOSI     | 11   | TF_SPI_MOSI          |
| SD Card SCLK     | 12   | TF_SPI_SCLK          |
| SD Card MISO     | 13   | TF_SPI_MISO          |

---

## ESP32-4827S043N
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
| Backlight        | 2    | GPIO_BCKL            |
| SD Card CS       | 10   | TF_CS                |
| SD Card MOSI     | 11   | TF_SPI_MOSI          |
| SD Card SCLK     | 12   | TF_SPI_SCLK          |
| SD Card MISO     | 13   | TF_SPI_MISO          |

---

## ESP32-4827S043R
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
| Backlight        | 2    | GPIO_BCKL            |
| Touch SPI MOSI   | 11   | XPT2046_SPI_BUS_MOSI |
| Touch SPI MISO   | 13   | XPT2046_SPI_BUS_MISO |
| Touch SPI SCLK   | 12   | XPT2046_SPI_BUS_SCLK |
| Touch SPI CS     | 38   | XPT2046_SPI_CS       |
| Touch INT        | 18   | XPT2046_TOUCH_INT    |
| SD Card CS       | 10   | TF_CS                |
| SD Card MOSI     | 11   | TF_SPI_MOSI          |
| SD Card SCLK     | 12   | TF_SPI_SCLK          |
| SD Card MISO     | 13   | TF_SPI_MISO          |

---

## ESP32-4848S040CIY1
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD Backlight    | 38   | GPIO_BCKL            |
| LCD SPI CS       | 39   | ST7701_SPI_CS        |
| LCD SPI SCL      | 48   | ST7701_SPI_SCL       |
| LCD SPI SDA      | 47   | ST7701_SPI_SDA       |
| LCD HSYNC        | 16   | ST7701_RGB           |
| LCD VSYNC        | 17   |                      |
| LCD DE           | 18   |                      |
| LCD PCLK         | 21   |                      |
| LCD R0           | 11   |                      |
| LCD R1           | 12   |                      |
| LCD R2           | 13   |                      |
| LCD R3           | 14   |                      |
| LCD R4           | 0    |                      |
| LCD G0           | 8    |                      |
| LCD G1           | 20   |                      |
| LCD G2           | 3    |                      |
| LCD G3           | 46   |                      |
| LCD G4           | 9    |                      |
| LCD G5           | 10   |                      |
| LCD B0           | 4    |                      |
| LCD B1           | 5    |                      |
| LCD B2           | 6    |                      |
| LCD B3           | 7    |                      |
| LCD B4           | 15   |                      |
| Touch SDA        | 19   | GT911_I2C_SDA        |
| Touch SCL        | 45   | GT911_I2C_SCL        |

---

## ESP32-4848S040CIY3
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD Backlight    | 38   | GPIO_BCKL            |
| LCD SPI CS       | 39   | ST7701_SPI_CS        |
| LCD SPI SCL      | 48   | ST7701_SPI_SCL       |
| LCD SPI SDA      | 47   | ST7701_SPI_SDA       |
| LCD HSYNC        | 16   | ST7701_RGB           |
| LCD VSYNC        | 17   |                      |
| LCD DE           | 18   |                      |
| LCD PCLK         | 21   |                      |
| LCD R0           | 11   |                      |
| LCD R1           | 12   |                      |
| LCD R2           | 13   |                      |
| LCD R3           | 14   |                      |
| LCD R4           | 0    |                      |
| LCD G0           | 8    |                      |
| LCD G1           | 20   |                      |
| LCD G2           | 3    |                      |
| LCD G3           | 46   |                      |
| LCD G4           | 9    |                      |
| LCD G5           | 10   |                      |
| LCD B0           | 4    |                      |
| LCD B1           | 5    |                      |
| LCD B2           | 6    |                      |
| LCD B3           | 7    |                      |
| LCD B4           | 15   |                      |
| Touch SDA        | 19   | GT911_I2C_SDA        |
| Touch SCL        | 45   | GT911_I2C_SCL        |

---

## ESP32-8048S043N
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
| Backlight        | 2    | GPIO_BCKL            |
| SD Card CS       | 10   | TF_CS                |
| SD Card MOSI     | 11   | TF_SPI_MOSI          |
| SD Card SCLK     | 12   | TF_SPI_SCLK          |
| SD Card MISO     | 13   | TF_SPI_MISO          |

---

## ESP32-8048S043R
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
| Backlight        | 2    | GPIO_BCKL            |
| Touch SPI MOSI   | 11   | XPT2046_SPI_BUS_MOSI |
| Touch SPI MISO   | 13   | XPT2046_SPI_BUS_MISO |
| Touch SPI SCLK   | 12   | XPT2046_SPI_BUS_SCLK |
| Touch SPI CS     | 38   | XPT2046_SPI_CS       |
| Touch INT        | 18   | XPT2046_TOUCH_INT    |
| SD Card CS       | 10   | TF_CS                |
| SD Card MOSI     | 11   | TF_SPI_MOSI          |
| SD Card SCLK     | 12   | TF_SPI_SCLK          |
| SD Card MISO     | 13   | TF_SPI_MISO          |

---

## ESP32-8048S050N
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
| Backlight        | 2    | GPIO_BCKL            |
| SD Card CS       | 10   | TF_CS                |
| SD Card MOSI     | 11   | TF_SPI_MOSI          |
| SD Card SCLK     | 12   | TF_SPI_SCLK          |
| SD Card MISO     | 13   | TF_SPI_MISO          |

---

## [PLACEHOLDER] ESP32-1732S019N
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| (Fill in pinout details from esp32-1732S019N.json) |

---

## ESP32-2424S012C (240x240, GC9A01A + CST816S)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD SPI MOSI     | 7    | GC9A01A SPI          |
| LCD SPI SCLK     | 6    |                      |
| LCD CS           | 10   |                      |
| LCD DC           | 2    |                      |
| Backlight        | 3    |                      |
| Touch SDA        | 4    | CST816S I2C          |
| Touch SCL        | 5    |                      |
| Touch INT        | 0    |                      |
| Touch RST        | 1    |                      |

---

## ESP32-2424S012N (240x240, GC9A01A)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD SPI MOSI     | 7    | GC9A01A SPI          |
| LCD SPI SCLK     | 6    |                      |
| LCD CS           | 10   |                      |
| LCD DC           | 2    |                      |
| Backlight        | 3    |                      |
| Touch SDA        | 4    | CST816S I2C          |
| Touch SCL        | 5    |                      |
| Touch INT        | 0    |                      |
| Touch RST        | 1    |                      |

---

## ESP32-2432S022C (240x320, ST7789 + CST816S)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD I80 D8       | 15   | ST7789 I80           |
| LCD I80 D9       | 13   |                      |
| LCD I80 D10      | 12   |                      |
| LCD I80 D11      | 14   |                      |
| LCD I80 D12      | 27   |                      |
| LCD I80 D13      | 25   |                      |
| LCD I80 D14      | 33   |                      |
| LCD I80 D15      | 32   |                      |
| LCD I80 CS       | 17   |                      |
| LCD I80 DC       | 16   |                      |
| LCD I80 WR       | 4    |                      |
| LCD RD           | 2    |                      |
| Backlight        | 0    |                      |
| Touch SDA        | 21   | CST816S I2C          |
| Touch SCL        | 22   |                      |
| SD Card CS       | 5    |                      |
| SD Card MOSI     | 23   |                      |
| SD Card SCLK     | 18   |                      |
| SD Card MISO     | 19   |                      |
| Speaker          | 26   |                      |

---

## ESP32-2432S022N (240x320, ST7789)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD I80 D8       | 15   | ST7789 I80           |
| LCD I80 D9       | 13   |                      |
| LCD I80 D10      | 12   |                      |
| LCD I80 D11      | 14   |                      |
| LCD I80 D12      | 27   |                      |
| LCD I80 D13      | 25   |                      |
| LCD I80 D14      | 33   |                      |
| LCD I80 D15      | 32   |                      |
| LCD I80 CS       | 17   |                      |
| LCD I80 DC       | 16   |                      |
| LCD I80 WR       | 4    |                      |
| LCD RD           | 2    |                      |
| Backlight        | 0    |                      |
| SD Card CS       | 5    |                      |
| SD Card MOSI     | 23   |                      |
| SD Card SCLK     | 18   |                      |
| SD Card MISO     | 19   |                      |
| Speaker          | 26   |                      |

---

## ESP32-2432S024C (240x320, ILI9341 + CST816S)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD SPI MOSI     | 13   | ILI9341 SPI          |
| LCD SPI MISO     | 12   |                      |
| LCD SPI SCLK     | 14   |                      |
| LCD CS           | 15   |                      |
| LCD DC           | 2    |                      |
| Backlight        | 27   |                      |
| Touch SDA        | 33   | CST816S I2C          |
| Touch SCL        | 32   |                      |
| Touch INT        | 21   |                      |
| Touch RST        | 25   |                      |
| SD Card CS       | 5    |                      |
| SD Card MOSI     | 23   |                      |
| SD Card SCLK     | 18   |                      |
| SD Card MISO     | 19   |                      |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16    |                      |
| RGB LED B        | 17    |                      |
| CdS Light Sensor | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-2432S024N (240x320, ILI9341)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD SPI MOSI     | 13   | ILI9341 SPI          |
| LCD SPI MISO     | 12   |                      |
| LCD SPI SCLK     | 14   |                      |
| LCD CS           | 15   |                      |
| LCD DC           | 2    |                      |
| Backlight        | 27   |                      |
| SD Card CS       | 5    |                      |
| SD Card MOSI     | 23   |                      |
| SD Card SCLK     | 18   |                      |
| SD Card MISO     | 19   |                      |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16    |                      |
| RGB LED B        | 17    |                      |
| CdS Light Sensor | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-2432S024R (240x320, ILI9341 + XPT2046)
| Function         | GPIO | Notes                |
|------------------|------|----------------------|
| LCD SPI MOSI     | 13   | ILI9341 SPI          |
| LCD SPI MISO     | 12   |                      |
| LCD SPI SCLK     | 14   |                      |
| LCD CS           | 15   |                      |
| LCD DC           | 2    |                      |
| Backlight        | 27   |                      |
| Touch SPI MOSI   | 13   | XPT2046 SPI          |
| Touch SPI MISO   | 12   |                      |
| Touch SPI SCLK   | 14   |                      |
| Touch CS         | 33   |                      |
| Touch INT        | 36   |                      |
| SD Card CS       | 5    |                      |
| SD Card MOSI     | 23   |                      |
| SD Card SCLK     | 18   |                      |
| SD Card MISO     | 19   |                      |
| RGB LED R        | 4    |                      |
| RGB LED G        | 16    |                      |
| RGB LED B        | 17    |                      |
| CDS              | 34   |                      |
| Speaker          | 26   |                      |

---

## ESP32-8048S050R
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
| Backlight        | 2    | GPIO_BCKL            |
| Touch SPI MOSI   | 11   | XPT2046_SPI_BUS_MOSI |
| Touch SPI MISO   | 13   | XPT2046_SPI_BUS_MISO |
| Touch SPI SCLK   | 12   | XPT2046_SPI_BUS_SCLK |
| Touch SPI CS     | 38   | XPT2046_SPI_CS       |
| Touch INT        | 18   | XPT2046_TOUCH_INT    |
| SD Card CS       | 10   | TF_CS                |
| SD Card MOSI     | 11   | TF_SPI_MOSI          |
| SD Card SCLK     | 12   | TF_SPI_SCLK          |
| SD Card MISO     | 13   | TF_SPI_MISO          |

---

## ESP32-8048S070N
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
| Backlight        | 2    | GPIO_BCKL            |
| SD Card CS       | 10   | TF_CS                |
| SD Card MOSI     | 11   | TF_SPI_MOSI          |
| SD Card SCLK     | 12   | TF_SPI_SCLK          |
| SD Card MISO     | 13   | TF_SPI_MISO          |

---

## ESP32-8048S070R
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
| Backlight        | 2    | GPIO_BCKL            |
| Touch SPI MOSI   | 11   | XPT2046_SPI_BUS_MOSI |
| Touch SPI MISO   | 13   | XPT2046_SPI_BUS_MISO |
| Touch SPI SCLK   | 12   | XPT2046_SPI_BUS_SCLK |
| Touch SPI CS     | 38   | XPT2046_SPI_CS       |
| Touch INT        | 18   | XPT2046_TOUCH_INT    |
| SD Card CS       | 10   | TF_CS                |
| SD Card MOSI     | 11   | TF_SPI_MOSI          |
| SD Card SCLK     | 12   | TF_SPI_SCLK          |
| SD Card MISO     | 13   | TF_SPI_MISO          |

---

## ESP32-8048S550C
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
| Backlight        | 2    | GPIO_BCKL            |
| Touch SDA        | 19   | GT911_I2C_SDA        |
| Touch SCL        | 20   | GT911_I2C_SCL        |
| Touch INT        | 18   | GT911_TOUCH_INT      |
| Touch RST        | 38   | GT911_TOUCH_RST      |
| SD Card CS       | 10   | TF_CS                |
| SD Card MOSI     | 11   | TF_SPI_MOSI          |
| SD Card SCLK     | 12   | TF_SPI_SCLK          |
| SD Card MISO     | 13   | TF_SPI_MISO          |

---

## ESP32-S3-Touch-LCD-7
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
| Touch SDA        | 8    | GT911_I2C_SDA        |
| Touch SCL        | 9    | GT911_I2C_SCL        |
| Touch INT        | NC   | Not connected         |
| Touch RST        | NC   | Not connected         |

---
