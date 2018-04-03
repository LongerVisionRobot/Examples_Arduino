#include <IRremote.h>
#include <IRremoteInt.h>

AF_DCMotor m1 = AF_DCMotor(1);
AF_DCMotor m2 = AF_DCMotor(2);
AF_DCMotor m3 = AF_DCMotor(3);
AF_DCMotor m4 = AF_DCMotor(4);

IRrecv irrecv(11);
decode_results results;


void setup()
{
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop()
{
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
    
  if (results.value == 0xFDA05F)
  {
   forward(); 
   delay(500);
   stop();
  }
    if (results.value == 0xFDB04F)
  {
   backwards(); 
   delay(500);
   stop();
  }
    if (results.value == 0xFD10EF)
  {
   left(); 
   delay(500);
   stop();
  }
    if (results.value == 0xFD50AF)
  {
   right(); 
   delay(500);
   stop();
  }
  }
  

  /*
  forward(); 
  stop();
  left();
  stop();
  backwards();
  stop();
  right();
  stop();
  */
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
  m1.setSpeed(100);
  m2.setSpeed(200);
  m3.setSpeed(100);
  m4.setSpeed(200);
}

void right()
{
  Serial.println("forward");
  m1.run(FORWARD);
  m2.run(FORWARD);
  m3.run(FORWARD);
  m4.run(FORWARD);
  
  // turn on motor
  m1.setSpeed(200);
  m2.setSpeed(100);
  m3.setSpeed(200);
  m4.setSpeed(100);
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
