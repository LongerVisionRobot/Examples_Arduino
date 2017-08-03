int photocellPin = 2; //define variable photocellsh=2, where we read the voltage
int ledPin = 12;  //define variable ledPin=12, led voltage output
int val = 0;    //define variable val


void setup() { 
  pinMode(ledPin, OUTPUT);  // set ledPin as mode OUTPUT
} 

void loop() { 
  val = analogRead(photocellPin);    //read analog signal from pin 2
  Serial.print(val);
  if(val<=512){      //512=2.5V, if more sensitive is expected, increase 512; otherwise, decrease 512
    digitalWrite(ledPin, HIGH); //if val < 512(2.5V), led is light up.
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}
