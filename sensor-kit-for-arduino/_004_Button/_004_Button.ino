int Led=13;       // Define LDE Pin
int buttonpin=3;  // Define the button/switch's pin
int val;          // Define Variable val
void setup()
{
  pinMode(Led,OUTPUT);  // Define LED as output
  pinMode(buttonpin,INPUT); // Define button/switch as input
}
void loop()
{
  val=digitalRead(buttonpin); // Assign digital pin's reading to val
  if(val==HIGH)   // if button pressed, LED starts flashing
  {
    digitalWrite(Led,HIGH);
  }
  else
  {
    digitalWrite(Led,LOW);
  }
}