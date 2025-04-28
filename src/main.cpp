#include <Arduino.h>
#include "./calibration/main.h"
#include "displays/userInterface.h"

UserInterface ui;

void setup() {
  Serial.begin(115200);
  #ifdef CALIBRATION
  Serial.println("Calibration mode");
  run();
  Serial.println("Calibration finished");

  while(1) {
    delay(1000);
  }
  #endif

  delay(3000);
  Serial.println("Starting user interface");

  ui.begin();
  Serial.println("User interface started");

}

void loop() {
  ui.loop();
  Serial.println("Looping in user interface");
  delay(100);
}