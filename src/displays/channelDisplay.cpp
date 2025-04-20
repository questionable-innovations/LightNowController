#include "./channelDisplay.h"
#include "channelDisplay.h"

// U8G2_SSD1305_128X32_NONAME_F_SW_I2C(rotation, clk, data [, rst])
// U8G2_SSD1305_128X32_NONAME_F_HW_I2C(rotation, [rst [, clk, data]])

const int DISPLAY_WIDTH = 128;
const int DISPLAY_HEIGHT = 32;

// Manages the 128x32 monochrome OLED display for the colour channel display
// It'll read input from the potentiometer and display the value on the screen
// It'll fill the screen up like a progress bar, and the value will be displayed in a rounded rectangle on the right-hand side of the screen.
// Using u8g2lib for the display management

void ChannelDisplay::begin() {
    setDisplayPower(true);

    pinMode(ADC_PINS[analogInput], INPUT);
    
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
    display.clearBuffer();
    this->updateDisplay();
    display.setPowerSave(powerOn ? 0 : 1);
}

void ChannelDisplay::renderDisplay() {
    display.clearBuffer();
    
    // Draw the rounded rectangle on the right side of the screen
    int rectWidth = 20;
    int rectHeight = DISPLAY_HEIGHT - 4; // Leave some space for the border
    int rectX = DISPLAY_WIDTH - rectWidth - 2; // 2 pixels from the right edge
    int rectY = 2; // 2 pixels from the top edge
    
    display.drawFrame(rectX, rectY, rectWidth, rectHeight); // Draw the frame of the rectangle
    
    // Fill the rectangle based on the current value
    int fillHeight = map(currentValue, 0, MAX_INPUT, 0, rectHeight);
    display.drawBox(rectX + 1, rectY + (rectHeight - fillHeight), rectWidth - 2, fillHeight); // Fill the rectangle
    
    // Draw the text inside the rectangle
    String valueString = String(currentValue);
    int textWidth = display.getStrWidth(valueString.c_str());
    int textX = rectX + (rectWidth - textWidth) / 2; // Centered horizontally
    int textY = rectY + (rectHeight + 8) / 2; // Centered vertically
    
    display.setDrawColor(0); // Set color to white for text
    display.drawStr(textX, textY, valueString.c_str()); // Draw the value string
    
    display.sendBuffer(); // Send buffer to display
}

void ChannelDisplay::updateDisplay() {
    display.sendBuffer();
    unsigned long currentTime = millis();
}

bool ChannelDisplay::loop() {
    int newValue = readCalibratedValue(analogInput);

    if (abs(newValue - lastValue) > 2) { // Only update if the value has changed significantly
        currentValue = newValue;
        lastValue = newValue;
        lastChangeTime = millis();
        return true;
    }
    return false;
}
void ChannelDisplay::setMasterInput(int value) {
    masterInputValue = value;
}