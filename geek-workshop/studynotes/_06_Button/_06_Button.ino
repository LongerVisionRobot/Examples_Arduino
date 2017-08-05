int key=7;//set LED pin IO
void setup()
{
  pinMode(key,OUTPUT);//set IO pin mode as OUTPUT
}
void loop()
{
  int i;//variable definition
  while(1)
  {
    i=analogRead(5);//Read analog data from analog pin 5
    if(i>1000)//if the reading data is bigger than 1000 (namely, 4.88Volt)
      digitalWrite(key,HIGH);//Set the 7th pin as HIGH, light up LED
    else
      digitalWrite(key,LOW);//Set the 7th pin as LOW, turn off LED
  }
}
