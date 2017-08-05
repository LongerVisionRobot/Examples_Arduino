int ledPin = 13;
int switchPin = 7;
int value = 0;

void setup() {
  pinMode(ledPin,OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop()
{
  value = digitalRead(switchPin);
  if(HIGH == value) {
    // trun LED off
    digitalWrite(ledPin, LOW);
  } else {
    // turn LED on
    digitalWrite(ledPin, HIGH);
  }
}
