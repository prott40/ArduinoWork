volatile int encoderPosition; // integer postistion that can be changed

void EncoderMonitorA() {// function for encoder movement
  if (digitalRead(3) == digitalRead(2)) {// if pin 2 is equal to pin 3
    encoderPosition--;// decrament encoderPosition
  }// end of if loop
  else {// else
    encoderPosition++;// increment encoderPosition
  }// end of else loop
}// end of EncoderMonitorA()
void EncoderMonitorB() {// function for encoder movement
  if (digitalRead(3) == digitalRead(2)) {// if pin 3 is equal to pin 2
    encoderPosition++;//increment encoderPosition by 1
  }// end of if loop
  else {// else
    encoderPosition--;// decrement encoderPosition
  }//end of else loop
}
void EncoderInitialize() {// fucntion to initialixe encoder
  encoderPosition = 0;// set encoderPosition equal to 0
  pinMode(2, INPUT);// set pin 2 as input
  pinMode(3, INPUT);// set pin 3 as input
  attachInterrupt(digitalPinToInterrupt(2), EncoderMonitorA, CHANGE);// attach service interupt when encoder is moved
  attachInterrupt(digitalPinToInterrupt(3), EncoderMonitorB, CHANGE);// attach service interupt when encoder is moved
}//end of EncoderInitialize

}  // end of buttin next statement