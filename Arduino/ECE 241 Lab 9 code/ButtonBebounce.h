enum ButtonStates { ButtonIdle,
                    ButtonWait,
                    ButtonLow
                  } ButtonState;  // lists states for SM
unsigned long ButtonTime;                     // declares ButtonTime as unsinged long variable

int ButtonInitialize() {     // function to get machine to read button presses
  pinMode(4, INPUT);         // sets button pin
  ButtonState = ButtonIdle;  // sets starting state
}
int ButtonNextState(int Input) { // function that is to be called when loop is serviced
  switch (ButtonState) { // states of button stats
    case ButtonIdle:// when state is Idle
      if (Input == LOW) {// when pin 4 is low
        ButtonState = ButtonWait;  // set state to ButtonWait
      break;// break state
      }//end of ButtonIdle state
    case ButtonWait:                          // when state is Wait
      if (Input == HIGH) {                      // if pin 4 is high
        ButtonState = ButtonIdle;               // set state to Idle
      }// end of if loop
      else if (millis() - ButtonTime >= 5) { // if millis() function minus ButtonTime is greater than or equal too 5
          ButtonState = ButtonLow;// state is set to Low
          return (1);// retun value 1
      }// end of else if loop
      break;// break state
    case ButtonLow:// when state is Low
      if (Input == HIGH) {// pin 4 is high
        ButtonState = ButtonIdle;// state is Idle
        return (2);// return value 2
      }// end of if loop
      break;// breal statment
  }  // end of switch
  return (0);// return value 0

