int relay = 10; // Define relay pin
void setup()
{
  pinMode(relay,OUTPUT); // Define relay pin as output
}
void loop()
{
  digitalWrite(relay,HIGH); // Relay open
  delay(1000);
  digitalWrite(relay,LOW);  // Relay close
  delay(1000);
}
