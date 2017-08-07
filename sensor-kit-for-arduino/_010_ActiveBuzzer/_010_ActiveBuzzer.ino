int speakerPin = 8;//控制喇叭的引脚
int potPin = 4;//控制可调电阻器的引脚
int value = 0;
void setup() {
  pinMode(speakerPin, OUTPUT);
}
void loop() {
  value = analogRead(potPin);//读电阻器引脚的值
  digitalWrite(speakerPin, HIGH);
  delay(value);//调节喇叭响的时间;
  digitalWrite(speakerPin, LOW);
  delay(value);//调节喇叭不响的时间;
}


