unsigned long Timer;// variable Timer
int ADC_output
float Voltage// vatiable Voltage
void setup() {// start setup
 SPI.begin(9600);// initiate SPI bus
analogRefrence(external);// set refrence voltage
Timer = millis();// set Timer equal to millis()
}// end setup

void loop() {
if(millis()-Timer>=500){// if millis() minus Timer is greater than or equal to 500
  ADC_output = analogRead(0);//  set ADC_output to value of pin 0
  voltage = (5*ADC_output)/1023.0;// convert ADC_output to Voltage
  serial.print(ADC_output);// print ADC_output
  serial.print(",");// print ,
  serial.println(Voltage)// on new line print Voltage
  Timer+=500;// update timer
}// end if loop

}//end of loop
