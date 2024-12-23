

enum ButtonStates { ButtonIdle,
                    ButtonWait,
                    ButtonLow } ButtonState;  // lists states for SM
unsigned long ButtonTime;                     // declares ButtonTime as unsinged long variable

int ButtonInitialize() {     // function to get machine to read button presses
  pinMode(4, INPUT);         // sets button pin
  ButtonState = ButtonIdle;  // sets starting state
}
int ButtonNextState(int Input) {   // function that is to be called when loop is serviced
  switch (ButtonState) {           // states of button stats
    case ButtonIdle:               // when state is button Idle
      if (Input == LOW) {          // if pin 4 is low
        encoderPosition--;     
        ButtonState = ButtonWait;  // move to state Wait
      }
      break;
    case (ButtonWait):                          // when state is Wait
      if (Input == HIGH) {                      // if pin 4 is high
        ButtonState = ButtonIdle;               // set state to Idle
      } else if (millis() - ButtonTime >= 5) {  // if millis()-ButtonTime is less than or equal to 5
        ButtonState = ButtonLow;                // set state to Low
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