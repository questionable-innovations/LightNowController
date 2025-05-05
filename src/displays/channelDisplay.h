#pragma once
#include <Wire.h>
#include <U8g2lib.h>
#include <pins.h>

class ChannelDisplay {
public:
    ChannelDisplay(U8G2& display, Inputs analogInput) 
        : display(display), analogInput(analogInput) {
    };
    
    void begin();

    void overrideSetValue(int value);
    int getValue() const;

    void setDisplayPower(bool powerOn);

    void renderDisplay();
    void updateDisplay();

    // Returns true if the input value has changed
    // Returns false if the input value has not changed
    bool loop();

    void setMasterInput(int value);

private:
    U8G2& display;
    
    Inputs analogInput;
    int currentValue = 0;
    bool currentPowerState = true;

    int lastValue = 0; // Last value read from the analog input
    int masterInputValue = 0; // Value of the master input (if applicable)

    unsigned long lastChangeTime = 0; // Last time the dial was turned
    unsigned long lastUpdateTime = 0; // Last time the display was updated
};