#include <LiquidCrystal.h>                    // import Liquid Crystal library
LiquidCrystal LcdDriver(A5, A4, 5, 6, 7, 8);  // sets pins for LCD screen
int StopWatchtimer;                           // makes tiemr
int LCDtimer;                                 // makes timer
int count;                                    // sets count as integer
int count2;                                   // set count2 as integer

void setup() {
  LcdDriver.begin(16, 2);  // sets LCD screen size
  LcdDriver.clear();       // clear LCD screen
  count = 0;               // starts count at 0
}

void loop() {

  if (millis() - LCDtimer >= 1000)
    ;  // creates a 1 second loop
  {

    count++;  // increases count by 1
    LcdDriver.setCursor(0, 0);
    LcdDriver.print(count);  // selects cursor spot aswell as what is printed on screen
    LCDtimer = +1000;        // update timer
  }


  if (millis() - StopWatchtimer >= 100) {
    //if button is not pressed
    if ((PIND & 0x10))  // checking if pin 4 is high
    {
      count2 = 0;
    } else {
      count2++;
      LcdDriver.clear();
      LcdDriver.print(count);
      LcdDriver.setCursor(0, 1);
      LcdDriver.print(count2);
    }
    StopWatchtimer = +100;  // update timer by 100
  }
  return 0;
}
