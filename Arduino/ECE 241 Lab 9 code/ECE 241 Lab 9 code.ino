#include <SPI.h> // open SPI library
#include <LiquidCrystal.h>// open LCD library
#include "ButtonBebounce.h"// open ButtonBebounce library
#include "EncoderMonitor.h"// open EncoderMonitor library
float HoldTemp = 75.0; // variable HoldTemp to be set by encoder monitor for heating and cooling element to reach
static unsigned long TempTime, Time; // timers used to set when to pull temperature from thermocuople and when to paint LCD screen
float CurrentTemp = 0; // variable addigned to temperature read by thermocoulpe
bool flag = false; // variable used by flag to dignify on and off
#include "HeatingCooling.h"// open SPI library
LiquidCrystal LCD(A5, A4, 5, 6, 7, 8); // sets pins for LCD
float ReadTemperature() { // function that will be done every time the thermocouple take temperature
  int TempBits; // variable assigned bits given by thermocouple
  float Temperature; // variable used in conversiomn of TempBits to temperature in degrees Fahrenheit 
  PORTC &= 0xFE;  // set A0 low
  TempBits = SPI.transfer16(0); // transfering bits from Thermocouple to Arduino
  PORTC |= 0x01;  // set A0 high
  TempBits = (TempBits >> 3) & 0x0fff; // shifts TempBits by 3 spaces and sets all none 1's to 0
  Temperature = 0.25 * (float)TempBits;    // convert to celsius
  Temperature = 1.8 * Temperature + 32.0;  // convert to fahrenheit
  return Temperature;// value that will be returned once ReadTemperature() function has run.
}// end of ReadTemperature() function



void setup() {// start of setup

  EncoderInitialize();// tells arduino to recognize encoder movement
  SystemInitialize();// tells arduino to recognize Heating and Cooling
  ButtonInitialize();// tells arduino to recognie button press
  SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0)); // starts SPI settings and begins transfer 
  pinMode(A0, OUTPUT); // sets the A0 pin as an output
  SPI.begin(); //Initializes SPI bus sets SCK, MOSI, and SS to outputs and SCK, MOSI low and SS high
  LCD.begin(16, 2); // begins LCD setting screen size
  LCD.clear();// clear LCD screen
  LCD.setCursor(0, 0);// sets cursor on screen
  TempTime = millis();// sets TempTime equal to millis() function
  Time = millis();// sets Time equal to millis() function
  pinMode(A1, OUTPUT);// sets pin A1 to output
  pinMode(A2, OUTPUT);// sets pin A0 to output
}// end of setup

void loop() {
  if (millis() - TempTime >= 1000) {// when milllis() function minus TempTime is greater than or equal to 1 second
    TempTime += 1000; // update Temp Time by 1000 milliseconds
    CurrentTemp = ReadTemperature();// set CurrentTemp equal to temperature read from thermocouple
    if (flag == true) {// when button is pressed setting the flag to be true
      UpdateTemperature(CurrentTemp);// function containing Heating and Cooling state machine with input of current temperature
      if (HC_State == HC_Cooling) {// when state machine is in state of cooling 
        digitalWrite(A1, HIGH);// sets pin A1 connected to blue LED high
        digitalWrite(A2, LOW); // sets pin A2 connected to red LED low
      }// end of Cooling state
      else if (HC_State == HC_Heating) {// when state machine in state heating
        digitalWrite(A1, LOW);// Pin A1 set low 
        digitalWrite(A2, HIGH);// pin A2 set high
      }// end of heating state
      else if (HC_State == HC_Nothing) {// when state machine is in hold state
        digitalWrite(A1, LOW);// sets Pin A1 low
        digitalWrite(A2, LOW);// sets pin A2 low
      }// end of hold stae
    }// end of heating cooling state machine
  }// end of 1 second loop

  if (ButtonNextState(digitalRead(4)) == 1) {// when button state machine enters state 1 
    flag = !flag;// flag is set equal to oposite of flag
  }// end of button press loop


  if (encoderPosition >= 4) {// when encoder is incremented  4  or more units
    if (flag == false) {// if the flag is set to false, signifying system is in off state
      HoldTemp += .5;// increment HoldTemp by .5
    }// end of if loop
    encoderPosition -= 4; // reset encoderPosition for next input by -4 units
  }// end of if loop
  else if (encoderPosition <= -4) {// when encoder positon is decremented by -4 units
    if (flag == false) {// if the flag is false, sigifying system is in off state
      HoldTemp -= .5;// decrament HoldTemp by -.5
    }//end of if loop
    encoderPosition += 4; // reset encoderPosition  for next input by 4 units
  }// end of else if loop

  if (millis() - Time >= 100) {// when millis() function mius Time variable is greater than or equal too 100
    Time += 100;// increment Time variable by 100
    LCD.clear();// clear LCD screen
    LCD.setCursor(0, 0);// set cursor toinitial position
    LCD.print(CurrentTemp);// print CurrentTemp
    LCD.setCursor(8, 0);// move cursor 8 colums
    LCD.print(HoldTemp);// print Hold temp
    switch (HC_State) {// switch into Heating and cooling state machine
      case HC_Cooling:// when in cooling state
        LCD.setCursor(0, 1);// set cursor to row 1
        LCD.print("Cooling");// print cooling
        break;// break state
      case HC_Heating:// when in heating state
        LCD.setCursor(0, 1);// move to row 1
        LCD.print("Heating");// print heating
        break;// break state
      case HC_Nothing:// when in hold state
        LCD.setCursor(0, 1);// set cursor row 1
        LCD.print("Holding");// print Holding
        break;// break state
    }//end of heating and cooling state machine
    if (flag == true) {//if flag is set to true
      LCD.setCursor(0, 1);// set cursor to row 1
    }// end of if loop
    else if (flag == false) {// else if flag is false
      LCD.setCursor(8, 0);// move cursor to row 0 coulum 8
    } LCD.blink();// blink cursor at that position
  }// end of 100 ms loop