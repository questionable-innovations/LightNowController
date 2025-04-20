#include <U8g2lib.h>
#include "userInterface.h"
#include <pins.h>

const u8g2_cb_t* rotation = U8G2_R0; // U8G2_R0, U8G2_R1, U8G2_R2, U8G2_R3

U8G2_SSD1305_128X32_NONAME_F_SW_I2C redDisplay = U8G2_SSD1305_128X32_NONAME_F_SW_I2C(rotation, R_DISP_SCK_PIN, R_DISP_SDA_PIN);
U8G2_SSD1305_128X32_NONAME_F_HW_I2C greenDisplay = U8G2_SSD1305_128X32_NONAME_F_HW_I2C(rotation, G_DISP_SCK_PIN, G_DISP_SDA_PIN);
U8G2_SSD1305_128X32_NONAME_F_HW_I2C blueDisplay = U8G2_SSD1305_128X32_NONAME_F_HW_I2C(rotation, B_DISP_SCK_PIN, B_DISP_SDA_PIN);

void UserInterface::begin() {
}

KnobState UserInterface::loop() {
    return KnobState();
}
