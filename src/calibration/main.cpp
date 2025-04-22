#include <pins.h>
#include <Arduino.h>
#include <stdio.h>
#include <power.h>

void run() {
    pinMode(ADC_PINS[R_INPUT], INPUT);
    pinMode(ADC_PINS[G_INPUT], INPUT);
    pinMode(ADC_PINS[B_INPUT], INPUT);
    pinMode(ADC_PINS[MASTER_INPUT], INPUT);
    setupPower();

    while (1) {

        // Read out the potentiometer values
        int redRaw = analogRead(ADC_PINS[R_INPUT]);
        int redValue = readCalibratedValue(R_INPUT);
        int greenRaw = analogRead(ADC_PINS[G_INPUT]);
        int greenValue = readCalibratedValue(G_INPUT);
        int blueRaw = analogRead(ADC_PINS[B_INPUT]);
        int blueValue = readCalibratedValue(B_INPUT);
        int masterRaw = analogRead(ADC_PINS[MASTER_INPUT]);
        int masterValue = readCalibratedValue(MASTER_INPUT);

        // Read the power button state
        bool powerButtonState = loopPower();
    
        // Input range is stored in INPUT_RANGE_MAP
    
        // Print the values to the serial monitor
        char buffer[1024];
        int offset = 0;

        // Print for Teleplot
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, "Teleplot Data:\n");
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, ">R_INPUT: %d\n", redRaw);
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, ">G_INPUT: %d\n", greenRaw);
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, ">B_INPUT: %d\n", blueRaw);
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, ">MASTER_INPUT: %d\n", masterRaw);
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, ">POWER_BUTTON: %d\n", powerButtonState);
    
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, "--- Sensor Readings ---\n");
    
        // Red Channel
        offset += snprintf(buffer + offset, sizeof(buffer) - offset,
            "Channel: %s | Pin: %d | Raw: %d | Calc: %d | Range: [%d, %d]\n",
            getChannelName(R_INPUT), ADC_PINS[R_INPUT], redRaw, redValue,
            INPUT_RANGE_MAP[R_INPUT][0], INPUT_RANGE_MAP[R_INPUT][1]);
    
        // Green Channel
        offset += snprintf(buffer + offset, sizeof(buffer) - offset,
            "Channel: %s | Pin: %d | Raw: %d | Calc: %d | Range: [%d, %d]\n",
            getChannelName(G_INPUT), ADC_PINS[G_INPUT], greenRaw, greenValue,
            INPUT_RANGE_MAP[G_INPUT][0], INPUT_RANGE_MAP[G_INPUT][1]);
    
        // Blue Channel
        offset += snprintf(buffer + offset, sizeof(buffer) - offset,
            "Channel: %s | Pin: %d | Raw: %d | Calc: %d | Range: [%d, %d]\n",
            getChannelName(B_INPUT), ADC_PINS[B_INPUT], blueRaw, blueValue,
            INPUT_RANGE_MAP[B_INPUT][0], INPUT_RANGE_MAP[B_INPUT][1]);
    
        // Master Channel
        offset += snprintf(buffer + offset, sizeof(buffer) - offset,
            "Channel: %s | Pin: %d | Raw: %d | Calc: %d | Range: [%d, %d]\n",
            getChannelName(MASTER_INPUT), ADC_PINS[MASTER_INPUT], masterRaw, masterValue,
            INPUT_RANGE_MAP[MASTER_INPUT][0], INPUT_RANGE_MAP[MASTER_INPUT][1]);

        // Power Button Input
        offset += snprintf(buffer + offset, sizeof(buffer) - offset,
            "Input: Power Button | Pin: %d | State: %s\n",
            MASTER_POWER_PIN, powerButtonState == HIGH ? "HIGH (Not Pressed)" : "LOW (Pressed)");
    
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, "-----------------------\n");
    
        Serial.println(buffer);
    }

}