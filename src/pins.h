#pragma once

extern const int R_DISP_SCK_PIN;
extern const int R_DISP_SDA_PIN;
extern const int R_INPUT_PIN;

extern const int G_DISP_SCK_PIN;
extern const int G_DISP_SDA_PIN;
extern const int G_INPUT_PIN;

extern const int B_DISP_SCK_PIN;
extern const int B_DISP_SDA_PIN;
extern const int B_INPUT_PIN;

extern const int MASTER_INPUT_PIN;
extern const int MASTER_POWER_PIN;

extern const int MAX_INPUT_VALUE;

extern const int ADC_PINS[];

int readCalibratedValue(Inputs input);

enum Inputs {
    R_INPUT = 0,
    G_INPUT = 1,
    B_INPUT = 2,
    MASTER_INPUT = 3
};