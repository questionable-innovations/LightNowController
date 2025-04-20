#include "pins.h"
#include <Arduino.h>


const uint8_t R_DISP_SCK_PIN = 4;
const uint8_t R_DISP_SDA_PIN = 5;
const uint8_t R_INPUT_PIN = 40;

const uint8_t G_DISP_SCK_PIN = 6;
const uint8_t G_DISP_SDA_PIN = 7;
const uint8_t G_INPUT_PIN = 39;

const uint8_t B_DISP_SCK_PIN = 8;
const uint8_t B_DISP_SDA_PIN = 9;
const uint8_t B_INPUT_PIN = 38;

const uint8_t MASTER_INPUT_PIN = 18;
const uint8_t MASTER_POWER_PIN = 21;

const uint8_t MAX_INPUT_VALUE = 255;

const uint8_t ADC_PINS[] = {R_INPUT_PIN, G_INPUT_PIN, B_INPUT_PIN, MASTER_INPUT_PIN};


const int INPUT_RANGE_MAP[][2] = {
    {0, 4095}, // R_INPUT_PIN
    {0, 4095}, // G_INPUT_PIN
    {0, 4095}, // B_INPUT_PIN
    {0, 4095}  // MASTER_INPUT_PIN
};

int readCalibratedValue(Inputs input) {
    int rawValue = analogRead(ADC_PINS[input]);

    int minRange = INPUT_RANGE_MAP[input][0];
    int maxRange = INPUT_RANGE_MAP[input][1];

    int calibratedValue = map(rawValue, minRange, maxRange, 0, MAX_INPUT_VALUE);
    return calibratedValue;
}