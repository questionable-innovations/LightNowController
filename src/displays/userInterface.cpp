#include <U8g2lib.h>
#include "userInterface.h"
#include <pins.h>

const u8g2_cb_t* rotation = U8G2_R0; // U8G2_R0, U8G2_R1, U8G2_R2, U8G2_R3

U8G2_SSD1306_128X64_VCOMH0_F_HW_I2C redDisplayRaw = U8G2_SSD1306_128X64_VCOMH0_F_HW_I2C(rotation, U8X8_PIN_NONE, R_DISP_SCK_PIN, R_DISP_SDA_PIN);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C greenDisplayRaw = U8G2_SSD1306_128X64_NONAME_F_SW_I2C(rotation, U8X8_PIN_NONE, G_DISP_SCK_PIN, G_DISP_SDA_PIN);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C blueDisplayRaw = U8G2_SSD1306_128X64_NONAME_F_SW_I2C(rotation, U8X8_PIN_NONE, B_DISP_SCK_PIN, B_DISP_SDA_PIN);

UserInterface::UserInterface()
    : redDisplay(redDisplayRaw, R_INPUT),
      greenDisplay(greenDisplayRaw, G_INPUT),
      blueDisplay(blueDisplayRaw, B_INPUT)
      {
}

void UserInterface::begin() {
    Serial.println("UserInterface::begin()");

    redDisplay.begin();
    // greenDisplay.begin();
    // blueDisplay.begin();

    redDisplay.setMasterInput(1);
    // greenDisplay.setMasterInput(1);
    // blueDisplay.setMasterInput(1);
}

KnobState UserInterface::loop() {
    Serial.println("UserInterface::loop()");
    KnobState knobState;
    knobState.changed = false;

    bool redChanged = redDisplay.loop();
    bool greenChanged = greenDisplay.loop();
    bool blueChanged = blueDisplay.loop();

    if (redChanged || greenChanged || blueChanged) {
        knobState.changed = true;
    }
    redDisplay.renderDisplay();
    // greenDisplay.renderDisplay();
    // blueDisplay.renderDisplay();

    // if (redChanged) {
        redDisplay.updateDisplay();
    // }
    // if (greenChanged) {
    //     greenDisplay.updateDisplay();
    // }
    // if (blueChanged) {
    //     blueDisplay.updateDisplay();
    // }
    knobState.rawValues.red = redDisplay.getValue();
    // knobState.rawValues.green = greenDisplay.getValue();
    // knobState.rawValues.blue = blueDisplay.getValue();

        

    return KnobState();
}
