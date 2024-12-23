#include "EncoderMonitor.h"
#include "ButtonBebounce.h"
#include <LiquidCrystal.h>
LiquidCrystal LcdDriver(A5, A4, 5, 6, 7, 8);
unsigned long DisplayTimer = 0;

void setup() {
  EncoderInitialize();
  ButtonInitialize();
  LcdDriver.clear();
  LcdDriver.begin(16, 2);
  DisplayTimer = millis();
}
void loop() {
  if (millis() - DisplayTimer >= 100) {
    LcdDriver.clear();
    LcdDriver.setCursor(0, 0);
    LcdDriver.print(encoderPosition);
    DisplayTimer += 100;
  }
}
