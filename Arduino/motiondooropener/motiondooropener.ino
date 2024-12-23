#include <Servo.h>// open servo library

const int trigPin = 7;// sets pin 7 as trigger 
const int echoPin = 8;// sets pin 8 for echo
const int servPin = 9;// sets pin 9 as servo control 
Servo myservo;// names servo myservo

void setup() {
  
  Serial.begin(9600);// sets baud rate for serial comunication
  pinMode(trigPin,OUTPUT);// sets pin 7 as output
  pinMode(echoPin,INPUT);// sets pin 8 as input
  pinMode(servPin,OUTPUT);// sets pin 9 as output
  myservo.attach(servPin,544,1200);// sets servo pin and min-544, and max-1200 pwm in microsecends
}

void loop() {
  
  long duration, inches, cm;//sets variables of duration, inches and cm as long

  
  digitalWrite(trigPin, LOW);// sets pin 7 low
  delayMicroseconds(2);// delays 2 micro seconds
  digitalWrite(trigPin, HIGH);//set pin 7 high
  delayMicroseconds(10);//delay 10 micro seconds
  digitalWrite(trigPin, LOW);// set pin 7 low

 
  
  duration = pulseIn(echoPin, HIGH);// set duration equal to the pulse in micorseconds on pin 7 when high

  
  inches = microsecondsToInches(duration);// sets inches equal to the conversion of microseconds to inches
  cm = microsecondsToCentimeters(duration);// sets cm equal to the conversion of microseconds to centimeters

  Serial.print(inches);// serial print variable inches
  Serial.print("in, "); //print in,
  Serial.print(cm);// print varible cm
  Serial.print("cm");// print cm
  Serial.println();// starts new line
  Serial.print(myservo.read());// prints angle at which servo is
  Serial.print("degrees");// print degrees
  Serial.println();//moves to a new line

if(  inches <= 30)// if inches variable is greater than 3 but less than 60
{
myservo.write(15);// sets servo angle to 15 degress
}
else{

  myservo.write(115);// set servo angle to 115 degrees
}


  delay(100);// delay 100 milli seconds

}
long microsecondsToInches(long microseconds) {
  
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  
  return microseconds / 29 / 2;
}


