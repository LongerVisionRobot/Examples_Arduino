int Led=13;//定义LED 接口
int SENSOR=3;//定义 霍尔磁力传感器接 口
int val;//定义数字变量val
void setup()
{
  pinMode(Led,OUTPUT);//定义LED 为输出接口
  pinMode(SENSOR,INPUT);//定义 霍尔磁力传感器 为输入接口
}

void loop()
{
  val=digitalRead(SENSOR);//将数字接口3 的值读取赋给val
  if(val==HIGH)//当震动传感器检测有信号时,LED 亮
  {
    digitalWrite(Led, HIGH);
  }
  {
    digitalWrite(Led, LOW);
  }
}
