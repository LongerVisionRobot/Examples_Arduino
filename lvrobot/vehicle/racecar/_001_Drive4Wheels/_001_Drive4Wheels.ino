int rightMotor1 = 14;
int rightMotor2 = 15;
int leftMotor1 = 16;
int leftMotor2 = 17;

int leftPWM = 5;
int rightPWM = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(leftPWM, OUTPUT);
  pinMode(rightPWM, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(leftPWM, 250);  // Set PWM output, namely, setup speed
  analogWrite(rightPWM, 250);

  digitalWrite(leftMotor1, LOW);
  digitalWrite(leftMotor2, HIGH);
  digitalWrite(rightMotor1, LOW);
  digitalWrite(rightMotor2, HIGH);
}
