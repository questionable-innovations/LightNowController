#include "userInterface.h"
#include <pins.h>
#include "displayConfig.h"
#include <power.h>



UserInterface::UserInterface()
    : redDisplay(redDisplayRaw, R_INPUT),
      greenDisplay(greenDisplayRaw, G_INPUT),
      blueDisplay(blueDisplayRaw, B_INPUT)
      {
}

void UserInterface::begin() {
    Serial.println("UserInterface::begin()");

    redDisplay.begin();
    greenDisplay.begin();
    blueDisplay.begin();

    redDisplay.setMasterInput(1);
    greenDisplay.setMasterInput(1);
    blueDisplay.setMasterInput(1);

    setupPower();
}

KnobState UserInterface::loop() {
    Serial.println("UserInterface::loop()");
    KnobState knobState;
    knobState.changed = false;

    // Power
    bool powerState = loopPower();
    redDisplay.setDisplayPower(powerState);
    greenDisplay.setDisplayPower(powerState);
    blueDisplay.setDisplayPower(powerState);

    bool redChanged = redDisplay.loop();
    bool greenChanged = greenDisplay.loop();
    bool blueChanged = blueDisplay.loop();

    if (redChanged || greenChanged || blueChanged) {
        knobState.changed = true;
    }
    
    if (redChanged) {
        redDisplay.renderDisplay();
        redDisplay.updateDisplay();
    }
    if (greenChanged) {
        greenDisplay.renderDisplay();
        greenDisplay.updateDisplay();
    }
    if (blueChanged) {
        blueDisplay.renderDisplay();
        blueDisplay.updateDisplay();
    }
    
    knobState.rawValues.red = redDisplay.getValue();
    knobState.rawValues.green = greenDisplay.getValue();
    knobState.rawValues.blue = blueDisplay.getValue();

    knobState.powerState = powerState; 
    Serial.print("Power state: ");
    Serial.println(knobState.powerState ? "ON" : "OFF");

    return knobState;
}
