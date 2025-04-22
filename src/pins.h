#pragma once
#include <Arduino.h>

extern const uint8_t R_DISP_SCK_PIN;
extern const uint8_t R_DISP_SDA_PIN;
extern const uint8_t R_INPUT_PIN;

extern const uint8_t G_DISP_SCK_PIN;
extern const uint8_t G_DISP_SDA_PIN;
extern const uint8_t G_INPUT_PIN;

extern const uint8_t B_DISP_SCK_PIN;
extern const uint8_t B_DISP_SDA_PIN;
extern const uint8_t B_INPUT_PIN;

extern const uint8_t MASTER_INPUT_PIN;
extern const uint8_t MASTER_POWER_PIN;
extern const uint8_t MASTER_POWER_LIGHT_PIN;

extern const uint8_t MAX_INPUT_VALUE;

extern const uint8_t ADC_PINS[];

extern const int INPUT_RANGE_MAP[][2];

enum Inputs {
    R_INPUT = 0,
    G_INPUT = 1,
    B_INPUT = 2,
    MASTER_INPUT = 3
};
int readCalibratedValue(Inputs input);

const char* getChannelName(Inputs input);
