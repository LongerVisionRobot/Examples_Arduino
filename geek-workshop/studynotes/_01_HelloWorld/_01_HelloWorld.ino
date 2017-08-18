void setup() {
  Serial.begin(9600); // Open serial port, and set bit rate to 9600.  
}

void loop() {
  Serial.println("Hello World"); // output "Hello World" to serial port.
  delay(1000); // wait for a second
}
