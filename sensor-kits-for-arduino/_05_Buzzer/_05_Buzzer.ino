const int buttonPin = 4;
// 按键引脚;
const int speakerPin = 8;
//蜂鸣器引脚;
// variables will change:
int buttonState = 0;
// 读取按键引脚的一个值
void setup()
{
  //设置按键引脚为输入模式,蜂鸣器引脚为输出模式;
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop(){
  // 读取按键一个初值,这里在电路中我接了是在默认高电平,所以初值为高;
  buttonState = digitalRead(buttonPin);
  /* 如果按键为高,则蜂鸣器不响;
  因为我刚开始接在硬件电路中初值为高,所以 if 条件成立,蜂鸣器不响
  */
  if (buttonState == HIGH) {
    digitalWrite(speakerPin,LOW);
  }
  else {
    //这里按键的值为低电平(也是按键被按下时);蜂鸣器响起
    digitalWrite(speakerPin,HIGH);
  }
}

