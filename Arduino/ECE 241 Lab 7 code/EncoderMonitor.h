volatile int encoderPosition // integer postistion that can be changed

void EncoderMonitorA(){
  if(digitalRead(2)==digitalRead(3)){
    encoderPosition++;
  }
else{
  encoderPosition--;
}
}
void EncoderMonitorB(){
  if(digitalRead(2)==digitalRead(3)){
    encoderPosition--;
  }
  else{
    encoderPosition++;
  }
}
void EncoderInitialize(){
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),EncoderMonitorA,CHANGE);
  attachInterrupt(digitalPintoInterrupt(3),EncoderMonitorB,CHANGE);
}