int Led=13;      // Define LDE Pin
int buttonpin=3; // Define reed sensor's pin
int val;         // Define Variable val
void setup()
{
  pinMode(Led,OUTPUT);  // Define LED as output
  pinMode(buttonpin,INPUT); // Define reed sensor's pin as output
}
void loop()
{
  val=digitalRead(buttonpin); // assign digital pin 3's reading to val
  if(val==HIGH)  // anything detected by linear hall sensor, LED starts
  {
    digitalWrite(Led,HIGH);
  }
  else
  {
    digitalWrite(Led,LOW);
  }
}
