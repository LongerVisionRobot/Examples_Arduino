//设置控制Led的数字IO脚
int Led1 = 1;
int Led2 = 2;
int Led3 = 3;
int Led4 = 4;
int Led5 = 5;
int Led6 = 6;

//led灯花样显示样式1子程序
void style_1(void)
{
  unsigned char j;
  for(j=1; j <= 6; j++)
  {
    digitalWrite(j, HIGH);
    delay(200);
  }
  for(j=6; j >= 1; j--)
  {
    digitalWrite(j, LOW);
    delay(200);
  }
}

void setup()
{
  unsigned char i;
  for(i=1; i<=6; i++)//依次设置1~6个数字引脚为输出模式
    pinMode(i, OUTPUT);//设置第i个引脚为输出模式
}

void loop()
{
  style_1(); //样式1
}

