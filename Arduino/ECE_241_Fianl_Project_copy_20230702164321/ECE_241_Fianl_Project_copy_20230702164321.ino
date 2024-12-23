// put your setup code here, to run once:

void setup()
{
  // Set pins as output and deactivate.
  pinMode(A0, OUTPUT);
  digitalWrite(A0, HIGH);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, HIGH);
  // Set up serial port.
  Serial.begin(9600);
} // End of setup
// put your main code here, to run repeatedly:
void loop()
{
  // Check for incoming data
  if (Serial.available())
  {
    // Read data and take appropriate action.
    switch (Serial.read())
    {
    case '1': // If a 1 received, activate relay 0.
      digitalWrite(A0, HIGH);
      break;
    case '0': // If a 0 received, deactivate 0.
      digitalWrite(A0, LOW);
      digitalWrite(A1,LOW);
      break;
    case '2': // If a 2 received, activate relay 1.
      digitalWrite(A1, HIGH);
      break;
    case '3': // If a 3 received, deactivate 1.
      digitalWrite(A1, LOW);
      break;
    default: // otherwise do nothing.
      digitalWrite(A0,LOW);
      digitalWrite(A1,LOW);
      break;
    }
  }
} // End of loop.

