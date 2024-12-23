char Alpha='A', Number='0';// set global variables as Alpha and Number
unsinged long SerialTimer;// assign timer value
void setup() {
  Serial.begin(38400);// set baun rate
  if(millis()-SerialTimer >= 500; // set up timer for 500 millis() interaval

}

void loop() {
 
 // part 1 transmits letters and numbers
  Serial.print(Alpha);// tells program to print Alpha 
  Serial.println(Number);//tells program to print Number  
  Alpha++;// increase Alpha by 1 every loop
  if(Alpha> 'Z') 
    Alpha ='A';// loops Alpha once it reaches Z
  Number++;// increases Number by 1 every loop
  if(Number>'9')
    Number = '0'; // loops Number once reaces 9

  SerialTimer += 500; //update timer

  /*/ part 2
  Serial.print('Z'); // print Z 
  //*/
  
if(Serial.available()>0)// checking for incoming characters
{
  if(Serial.read() == 'R'); // if serial imput is R
{
  Alpha ='A'; // reset to A
  Number = '0'; // reset to 0 
} // end of R 

} // end of character check

} // end of loop
