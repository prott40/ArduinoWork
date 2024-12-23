#include <SPI.h>
#include <LiquidCrystal.h>
LiquidCrystal LCD(A5, A4, 5, 6, 7, 8);
float ReadTemperature();
SPI.Settings(16000000,MSBFIRST,SPI_MODE0)));
SPI.transfer(0);
int TempBits;
TemBits = SPI.transfer16(0);
TempBits = (TempBits >> 3) & 0xfff;
SPI.transfer(1);
float Temperature;
Temperature = 0.25 * (float)TempBits;    // convert to celsius
Temperature = 1.8 * Tempurature + 32.0;  // converr to fahrenheit
unsined long TempTime

  void
  setup() {
  digitalWrite(12, OUTPUT);
  SPI.begin();
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  if (millis() - TempTime >= 1000) {
    digitalRead(11);
    lcd.write(Temperature);
  }
  TempTime += 1000;
}
