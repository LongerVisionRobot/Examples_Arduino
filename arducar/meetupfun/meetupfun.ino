#include<AFMotor.h>


AF_DCMotor m1 = AF_DCMotor(1);
AF_DCMotor m2 = AF_DCMotor(2);
AF_DCMotor m3 = AF_DCMotor(3);
AF_DCMotor m4 = AF_DCMotor(4);

void setup()
{
  // turn on motor
  m1.setSpeed(200);
  m2.setSpeed(200);
  m3.setSpeed(200);
  m4.setSpeed(200);
  
  m1.run(RELEASE);
  m2.run(RELEASE); 
  m3.run(RELEASE); 
  m4.run(RELEASE); 
}

void loop()
{
//  forward();
//  delay(1000);
//
//  backward();
//  delay(1000);

  left();
  delay(1000);

//  right();
//  delay(1000);

}


void forward()
{
  Serial.println("forward");
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
  
  // turn on motor
  m1.setSpeed(200);
  m2.setSpeed(200);
  m3.setSpeed(200);
  m4.setSpeed(200);
}

void backward()
{
  Serial.println("backwards");
  m1.run(BACKWARD);
  m2.run(BACKWARD);
  m3.run(BACKWARD);
  m4.run(BACKWARD);
  
  // turn on motor
  m1.setSpeed(200);
  m2.setSpeed(200);
  m3.setSpeed(200);
  m4.setSpeed(200);
}

void left()
{
  Serial.println("forward");
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
  
  // turn on motor
  m1.setSpeed(200);
  m2.setSpeed(600);
  m3.setSpeed(200);
  m4.setSpeed(600);
}

void right()
{
  Serial.println("forward");
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
  
  // turn on motor
  m1.setSpeed(600);
  m2.setSpeed(0);
  m3.setSpeed(600);
  m4.setSpeed(0);
}


void stop()
{
  Serial.println("stop");
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
  
  // turn on motor
  m1.setSpeed(0);
  m2.setSpeed(0);
  m3.setSpeed(0);
  m4.setSpeed(0);
}


