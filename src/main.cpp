#include <Arduino.h>
#include "./calibration/main.h"

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

}

void loop() {
  // put your main code here, to run repeatedly:
}