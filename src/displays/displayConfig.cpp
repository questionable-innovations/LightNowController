#include "displayConfig.h"
#include <pins.h>

const int DISPLAY_WIDTH = 128;
const int DISPLAY_HEIGHT = 32;

const u8g2_cb_t* rotation = U8G2_R0; // U8G2_R0, U8G2_R1, U8G2_R2, U8G2_R3


DISPLAY_DRIVER redDisplayRaw(rotation, R_DISP_SCK_PIN, R_DISP_SDA_PIN, U8X8_PIN_NONE);
DISPLAY_DRIVER greenDisplayRaw(rotation, G_DISP_SCK_PIN, G_DISP_SDA_PIN, U8X8_PIN_NONE);
DISPLAY_DRIVER blueDisplayRaw(rotation, B_DISP_SCK_PIN, B_DISP_SDA_PIN, U8X8_PIN_NONE);
