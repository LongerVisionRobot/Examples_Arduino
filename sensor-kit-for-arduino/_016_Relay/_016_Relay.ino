int relay = 10; //继电器导通触发信号-高电平有效;
void setup()
{
  pinMode(relay,OUTPUT); //定义端口属性为输出;
}
void loop()
{
  digitalWrite(relay,HIGH); //继电器导通;
  delay(1000);
  digitalWrite(relay,LOW); //继电器开关断开;
  delay(1000);
}
