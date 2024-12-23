

enum ButtonStates { ButtonIdle,
                    ButtonWait,
                    ButtonLow } ButtonState;  // lists states for SM
unsigned long ButtonTime;                     // declares ButtonTime as unsinged long variable

int ButtonInitialize() {     // function to get machine to read button presses
  pinMode(4, INPUT);         // sets button pin
  ButtonState = ButtonIdle;  // sets starting state
  pinMode(13, OUTPUT);       // sets pin for reading output
}
int ButtonNextState(int Input) {   // function that is to be called when loop is serviced
  switch (ButtonState) {           // states of button stats
    case ButtonIdle:               // when state is button Idle
      if (Input == LOW) {          // if pin 4 is low
        ButtonTime = millis();     // set ButtonTime = millis()
        ButtonState = ButtonWait;  // move to state Wait
        digitalWrite(13, HIGH);    // set pin 13 high
      }
      break;
    case (ButtonWait):                          // when state is Wait
      if (Input == HIGH) {                      // if pin 4 is high
        ButtonState = ButtonIdle;               // set state to Idle
        digitalWrite(13, LOW);                  // sets pin 13 low
      } else if (millis() - ButtonTime >= 5) {  // if millis()-ButtonTime is less than or equal to 5
        ButtonState = ButtonLow;                // set state to Low
        digitalWrite(13, LOW);                  // set pin 13 low
        return (1);                             // return the value 1
      }
      break;
    case ButtonLow:                // when stae is Low
      if (Input == HIGH) {         // if pin 4 is high
        ButtonState = ButtonIdle;  // set state to idle
        return (2);                // returns 2
      }
  }  // end of switch
  return (0);
}  // end of buttin next statement