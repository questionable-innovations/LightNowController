#include "channelDisplay.h"
#include "displayConfig.h"

// Manages the 128x32 monochrome OLED display for the colour channel display
// It'll read input from the potentiometer and display the value on the screen
// It'll fill the screen up like a progress bar, and the value will be displayed in a rounded rectangle on the right-hand side of the screen.
// Using u8g2lib for the display management


void ChannelDisplay::begin() {
    setDisplayPower(true);

    pinMode(ADC_PINS[analogInput], INPUT);
    
    display.setBusClock(400000L);
    display.begin();

    display.setFont(u8g2_font_ncenB08_tr);
    display.setFontMode(1);
    display.setDrawColor(1);
    display.setContrast(255);
    
    display.clearBuffer();
    this->updateDisplay();
}

void ChannelDisplay::overrideSetValue(int value) {
    currentValue = value;
    lastValue = value;
    lastChangeTime = millis();
}

int ChannelDisplay::getValue() const {
    return currentValue;
}

void ChannelDisplay::setDisplayPower(bool powerOn) {
    if (powerOn == this->currentPowerState) {
        return; // No change in power state
    }
    this->currentPowerState = powerOn;
    if (!powerOn) {
        display.clearBuffer();
        this->updateDisplay();
    }
    display.setPowerSave(powerOn ? 0 : 1);
}

void ChannelDisplay::renderDisplay() {

    display.clearBuffer();
    display.setDrawColor(1);
    int padding = 2;


    String valueString = String(currentValue);
    int textWidth = display.getStrWidth(valueString.c_str());
    int textHeight = display.getMaxCharHeight();
    
    // Draw the rounded rectangle on the right side of the screen
    int rectWidth = textWidth + padding * 2; // Add padding to the width
    int rectHeight = (textHeight) + padding * 2; // Leave some space for the border
    int rectX = DISPLAY_WIDTH - rectWidth - padding; // 2 pixels from the right edge
    int rectY = (DISPLAY_HEIGHT / 2) - rectHeight/2; // 2 pixels from the top edge
    
    display.drawRBox(rectX, rectY, rectWidth, rectHeight, padding);
    
    // Fill the single bar based on the current value
    int fillWidth = map(currentValue, 0, MAX_INPUT, 0, DISPLAY_WIDTH);
    display.drawBox(0, 0, fillWidth, DISPLAY_HEIGHT); // Fill the bar from left to right
    
    // Draw the text inside the rectangle
    int textX = rectX + (rectWidth - textWidth) / 2; // Centered horizontally
    int textY = rectY + (rectHeight + 8) / 2; // Centered vertically
    
     // Set color to black for text
    display.setDrawColor(0);

    display.drawStr(textX, textY, valueString.c_str()); // Draw the value string
    
}

void ChannelDisplay::updateDisplay() {
    display.sendBuffer();
    unsigned long currentTime = millis();
}

bool ChannelDisplay::loop() {
    int newValue = readCalibratedValue(analogInput);
    currentValue = newValue;

    Serial.print("Channel: ");
    Serial.print(analogInput);
    Serial.print(" | Value: ");
    Serial.println(currentValue);

    if (abs(newValue - lastValue) > 2) { // Only update if the value has changed significantly    
        lastValue = newValue;
        lastChangeTime = millis();
        return true;
    }
    return false;
}
void ChannelDisplay::setMasterInput(int value) {
    masterInputValue = value;
}