#include <SoftwareSerial.h>
#define ledPin 7

SoftwareSerial mySerial(10, 11); // RX, TX
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  Serial.begin(38400); // Default communication rate of the Bluetooth module
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  //mySerial.println("Hello, world?");
}

void loop() {   
  if(mySerial.available() > 0){ // Checks whether data is coming from the serial port
    state = mySerial.read(); // Reads the data from the serial port
    Serial.print("mySerial available!\n");
 }

 if (state == '0') {
  digitalWrite(ledPin, LOW); // Turn LED OFF
  Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 else if (state == '1') {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED: ON");;
  state = 0;
 } 
}

