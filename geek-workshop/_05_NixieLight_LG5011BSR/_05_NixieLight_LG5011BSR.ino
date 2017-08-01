//set IO pins according to LG5011BSR's schematics
int a=7;
int b=6;
int c=5;
int d=11;
int e=10;
int f=8;
int g=9;
int dp=4;

//display digit 1
void digital_1(void)
{
  unsigned char j;
  digitalWrite(c,LOW);//LOW - to light up pin 5 (c=5)
  digitalWrite(b,LOW);//LOW - to light up pin 6 (b=6)
  for(j=7;j<=11;j++)//HIGH - to turn off 7~11 (a,f,g,e,d)
    digitalWrite(j,HIGH);
  digitalWrite(dp,HIGH);//HIGH - to turn off dp (dp=4)
}
//display digit 2
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
//display digit 3
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
//display digit 4
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
//display digit 5
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
//display digit 6
void digital_6(void)
{
  unsigned char j;
  for(j=7;j<=11;j++)
    digitalWrite(j,LOW);
  digitalWrite(c,LOW);
  digitalWrite(dp,HIGH);
  digitalWrite(b,HIGH);   
}
//display digit 7
void digital_7(void)
{
  unsigned char j;
  for(j=5;j<=7;j++)
    digitalWrite(j,LOW);
  digitalWrite(dp,HIGH);
  for(j=8;j<=11;j++)
    digitalWrite(j,HIGH);
}
//display digit 8
void digital_8(void)
{
  unsigned char j;
  for(j=5;j<=11;j++)
    digitalWrite(j,LOW);
  digitalWrite(dp,HIGH);
}
//display digit 9
void digital_9(void)
{
  unsigned char j;
  for(j=5;j<=9;j++)
    digitalWrite(j,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
}
//display digit 0
void digital_0(void)
{
  unsigned char j;
  
}
void setup()
{
  int i;//variable definition
  for(i=4;i<=11;i++)
    pinMode(i,OUTPUT);//set pin 4~11 as mode OUTPUT
}
void loop()
{  
  while(1)
  {
    digital_1();//digital 1
    delay(2000);//delay 2 seconds
    digital_2();
    delay(2000);
    digital_3();
    delay(2000);
    digital_4();
    delay(2000);
    digital_5();
    delay(2000);
    digital_6();
    delay(2000);
    digital_7();
    delay(2000);
    digital_8();
    delay(2000);
    digital_9();
    delay(2000);
  }
}

