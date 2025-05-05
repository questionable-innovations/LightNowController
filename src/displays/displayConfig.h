#pragma once

#include <U8g2lib.h>

// Use the same driver definition as in the .cpp file
// #define DISPLAY_DRIVER U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C
#define DISPLAY_DRIVER U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C


extern const int DISPLAY_WIDTH;
extern const int DISPLAY_HEIGHT;

extern DISPLAY_DRIVER redDisplayRaw;
extern DISPLAY_DRIVER greenDisplayRaw;
extern DISPLAY_DRIVER blueDisplayRaw;