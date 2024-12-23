#include "ButtonBebounce.h"

void setup() {
  ButtonInitialize();
  Serial.begin(9600);  // sets baud rate
}
void loop() {
  switch (ButtonNextState(digitalRead(4))) {  //when the Button is pressed and state is changed
    case 1:
      Serial.println("released");  // when the button is pressed prints pressed
      break;
    case 2:
      Serial.println("pressed");  // when button is released prints realesed
      break;
  }
}
