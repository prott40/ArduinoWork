<TimerOne.h> // import Timer1 library
unsigned long timer = 0; // create timer variable
void setup() { // start setup
  timer = millis();// set timer equal to millis
  Timer1.initialize(500);// begin timer 1
  Timer1.pwm(10,512,500);// set PWM with timer1
  pinMode(13,OUTPUT);// set pin 13 to output 
  serial.begin(9600);// activate serial port
}// end og setup

void loop() {// begin loop
 if(millis() - timer>= 10){// if millis minus timer is greater than 10
   PORTB |= 0x20;// activate pin 13
   int Input = analogRead(0);// read pin A0
   serial.Print(Input);// print waht is read on pin A0
   Timer1.setPwmDuty(10,Input);// set duty cycle on pin 10
   PORTB |= ~0x20;// turn pin 13 off
   timer += 10// update timer

 }// end if statemanet

}// end loop
