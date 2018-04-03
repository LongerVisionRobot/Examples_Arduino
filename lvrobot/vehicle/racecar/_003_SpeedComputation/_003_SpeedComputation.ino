int leftCounter=0,  rightCounter=0;
unsigned long time = 0, old_time = 0; // for time stamp
unsigned long time1 = 0;  // for time stamp
float lv,rv ; // left wheel speed, right wheel speed

#define STOP      0
#define FORWARD   1
#define BACKWARD  2
#define TURNLEFT  3
#define TURNRIGHT 4

int rightMotor1 = 17;
int rightMotor2 = 18;
int leftMotor1 = 13;
int leftMotor2 = 14;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(0,RightCount_CallBack, FALLING);
  attachInterrupt(1,LeftCount_CallBack, FALLING);

  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  SpeedEstimation();
  if(Serial.available()>0)
  {
    int cmd = Serial.read();

    Serial.print(cmd);
    motorRun(cmd);
  }  
}
/*
 ** Compute wheel speed
 */
bool SpeedEstimation()
{
  time = millis();  // record the timestamp for computing the running speed. unit in milliseconds.
  if(abs(time - old_time) >= 1000)  // if it's already 1 second
  {  
    detachInterrupt(0); // detach external interrupt 0
    detachInterrupt(1); // detach external interrupt 1
    // Compute wheel speed from the counters (frequencies)
    // if we present the speed in "how many wheel rounds per minute
    // For this specific wheel, there are 20 0/1s, the speed is easily estimated as:
    // counter*60/20
    lv =(float)leftCounter*60/20; // motor speed calculation
    rv =(float)rightCounter*60/20;// motor speed calculation
    Serial.print("left:");
    Serial.print(lv); // send left wheel speed to upper-level computer
    Serial.print("     right:");
    Serial.println(rv);// send right wheel speed to upper-level computer
    // return to the initial status of the speed encoder
    leftCounter = 0;  // for every 1 second, reset counters to 0.
    rightCounter = 0; // for every 1 second, reset counters to 0.
    old_time=  millis();  // record the timestamp for computing the running speed 
    attachInterrupt(0, RightCount_CallBack,FALLING);  // re-attach external interrupt 0
    attachInterrupt(1, LeftCount_CallBack,FALLING);   // re-attach external interrupt 1
    return 1;
  }
  else
    return 0;
}
/*
 ** Right wheel speed encoder callback() function
 */
void RightCount_CallBack()
{
  rightCounter++;
}
/*
 ** Left wheel speed encoder callback() function
 */
void LeftCount_CallBack()
{
  leftCounter++;
}
/*
 ** Motor Control for vehicle running
 */
void motorRun(int cmd)
{
  switch(cmd){
    case FORWARD:
      Serial.println("FORWARD");  // print out vehicle status
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      break;
     case BACKWARD:
      Serial.println("BACKWARD"); // print out vehicle status
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      break;
     case TURNLEFT:
      Serial.println("TURN  LEFT"); // print out vehicle status
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      break;
     case TURNRIGHT:
      Serial.println("TURN  RIGHT"); // print out vehicle status
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      break;
     default:
      Serial.println("STOP"); // print out vehicle status
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, LOW);
  }
}

