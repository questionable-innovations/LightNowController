#include "power.h"
#include <Arduino.h>
#include <pins.h>
#include <Bounce2.h>

Bounce2::Button button = Bounce2::Button();

bool powerState = true;

void setupPower() {
    button.attach(MASTER_POWER_PIN, INPUT_PULLUP);
    button.interval(5);
    button.setPressedState(LOW);


    pinMode(MASTER_POWER_LIGHT_PIN, OUTPUT); // Initialize the power light pin as output
    digitalWrite(MASTER_POWER_LIGHT_PIN, LOW); // Turn off the power light initially
}

bool loopPower() {
    button.update();

    // Read the power button state
    int powerButtonState = button.pressed();

    if (powerButtonState) {
        powerState = !powerState; // Toggle the power state
        digitalWrite(MASTER_POWER_LIGHT_PIN, !powerState ? HIGH : LOW); // Turn on/off the power light
    }
    return powerState;
}