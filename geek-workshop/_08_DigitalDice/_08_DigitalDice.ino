//set all IO pins
int a=7;
int b=6;
int c=5;
int d=11;
int e=10;
int f=8;
int g=9;
int dp=4;

//display digital 1
void digital_1(void)
{
  unsigned char j;
  digitalWrite(c,LOW);//light on c (c=6)
  digitalWrite(b,LOW);//light on b (b=6)
  for(j=7;j<=11;j++)//turn off the rest
    digitalWrite(j,HIGH);
  digitalWrite(dp,HIGH);//turn off dp (dp=4)
}
//display digital 2
void digital_2(void)
{
  unsigned char j;
  digitalWrite(b,LOW);
  digitalWrite(a,LOW);
  for(j=9;j<=11;j++)
    digitalWrite(j,LOW);
  digitalWrite(dp,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(f,HIGH);
}
//display digital 3
void digital_3(void)
{
  unsigned char j;
  digitalWrite(g,LOW);
  digitalWrite(d,LOW);
  for(j=5;j<=7;j++)
    digitalWrite(j,LOW);
  digitalWrite(dp,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(e,HIGH);
}
//display digital 4
void digital_4(void)
{
  digitalWrite(c,LOW);
  digitalWrite(b,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(dp,HIGH);
  digitalWrite(a,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(d,HIGH);   
}
//display digital 5
void digital_5(void)
{
  unsigned char j;
  for(j=7;j<=9;j++)
    digitalWrite(j,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(dp,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(e,HIGH); 
}
//display digital 6
void digital_6(void)
{
  unsigned char j;
  for(j=7;j<=11;j++)
    digitalWrite(j,LOW);
  digitalWrite(c,LOW);
  digitalWrite(dp,HIGH);
  digitalWrite(b,HIGH);   
}
//display digital 7
void digital_7(void)
{
  unsigned char j;
  for(j=5;j<=7;j++)
    digitalWrite(j,LOW);
  digitalWrite(dp,HIGH);
  for(j=8;j<=11;j++)
    digitalWrite(j,HIGH);
}
//display digital 8
void digital_8(void)
{
  unsigned char j;
  for(j=5;j<=11;j++)
    digitalWrite(j,LOW);
  digitalWrite(dp,HIGH);
}
void setup()
{
    int i;
    for(i=4;i<=11;i++)
    {
      pinMode(i,OUTPUT);//set IO pin 4~11 as mode OUTPUT
    }
}
void loop()
{  
   while(1)
   {
       digital_1();//display digital 1
       while(analogRead(0)>1000);//read analog signal from pin analog0, if it's bigger than 1000, that means the button is pressed down.
       delay(100);//delay 100 miliseconds
        digital_2();
        while(analogRead(0)>1000);
       delay(100);
        digital_3();
        while(analogRead(0)>1000);
       delay(100);
        digital_4();
        while(analogRead(0)>1000);
       delay(100);
        digital_5();
        while(analogRead(0)>1000);
       delay(100);
        digital_6();
        while(analogRead(0)>1000);
       delay(100);
        digital_7();
        while(analogRead(0)>1000);
       delay(100);
        digital_8();
        while(analogRead(0)>1000);
       delay(100); 
   }
}
