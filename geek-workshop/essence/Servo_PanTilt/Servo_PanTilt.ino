// http://www.robotoid.com/appnotes/arduino-operating-two-servos.html

#include <Servo.h>

int x = 0;
Servo servoPan;          // Define pan servo
Servo servoTilt;         // Define tilt servo

void setup() { 
  servoPan.attach(10);  // Set pan servo to digital pin 10
  servoTilt.attach(9);  // Set tilt servo to digital pin 9
} 

void loop() {            // Loop through motion tests
  forward();             // Example: move forward
  delay(2000);           // Wait 2000 milliseconds (2 seconds)
  reverse();
  delay(2000);
  turnRight();
  delay(2000);
  turnLeft();
  delay(2000);
  stopRobot();
  delay(2000);
}

// Motion routines for forward, reverse, turns, and stop
void forward() {
  servoPan.write(0);
  servoTilt.write(180);
}

void reverse() {
  servoPan.write(180);
  servoTilt.write(0);
}

void turnRight() {
  servoPan.write(180);
  servoTilt.write(180);
}
void turnLeft() {
  servoPan.write(0);
  servoTilt.write(0);
}

void stopRobot() {
  servoPan.write(90);
  servoTilt.write(90);
}
