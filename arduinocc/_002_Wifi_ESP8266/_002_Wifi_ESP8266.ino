#include <SoftwareSerial.h>

SoftwareSerial mySerial(11,10);	// TX=11, RX=10

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while(!Serial) {
    ;	// wait for serial port to connect. Needed for Leonardo only
  }

  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200);
}

void loop() {
  if(mySerial.available())
    Serial.write(mySerial.read());
  if(Serial.available())
    mySerial.write(Serial.read());
}

