#define STOP      0
#define FORWARD   1
#define BACKWARD  2
#define TURNLEFT  3
#define TURNRIGHT 4

int leftMotor1 = 16;
int leftMotor2 = 17;
int rightMotor1 = 14;
int rightMotor2 = 15;

int leftPWM = 5;
int rightPWM = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:  
  //usart read
  if(Serial.available()>0)
  {
    char cmd = Serial.read();//读取蓝牙模块发送到串口的数据

    Serial.print(cmd);
    motorRun(cmd);

  }  
}
void motorRun(int cmd)
{
  switch(cmd){
    case FORWARD:
      Serial.println("FORWARD");  // Output status
      analogWrite(leftPWM, 250);  // Set PWM output, namely, setup speed
      analogWrite(rightPWM, 250);
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      break;
     case BACKWARD:
      Serial.println("BACKWARD");     // Output status
      analogWrite(leftPWM, 250);  // Set PWM output, namely, setup speed
      analogWrite(rightPWM, 250);
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      break;
     case TURNLEFT:
      Serial.println("TURN  LEFT");   // Output status
      analogWrite(leftPWM, 250);  // Set PWM output, namely, setup speed
      analogWrite(rightPWM, 250);
      digitalWrite(leftMotor1, HIGH);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, HIGH);
      break;
     case TURNRIGHT:
      Serial.println("TURN  RIGHT");  // Output status
      analogWrite(leftPWM, 250);  // Set PWM output, namely, setup speed
      analogWrite(rightPWM, 250);
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, HIGH);
      digitalWrite(rightMotor1, HIGH);
      digitalWrite(rightMotor2, LOW);
      break;
     default:
      Serial.println("STOP");   // Output status
      analogWrite(leftPWM, 0);  // Set PWM output, namely, setup speed
      analogWrite(rightPWM, 0);
      digitalWrite(leftMotor1, LOW);
      digitalWrite(leftMotor2, LOW);
      digitalWrite(rightMotor1, LOW);
      digitalWrite(rightMotor2, LOW);
  }
}

