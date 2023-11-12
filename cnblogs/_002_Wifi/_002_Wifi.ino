#include <SoftwareSerial.h>
#define ledPin 7

#define DEBUG true

SoftwareSerial esp8266(10,11); // make TX Arduino line is pin 10, make RX Arduino line is pin 11.
int state = 0;
boolean alreadyConnected = false;

// This means that you need to connect the TX line from the esp to the Arduino's pin 10
                             // and the RX line from the esp to the Arduino's pin 11
void setup()
{
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,HIGH);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Serial Communication Built Up Successfully!");

  esp8266.begin(9600); // your esp's baud rate might be different

  sendData("AT+CWMODE=2\r\n",2000,DEBUG); // reset module
  // delay(20000);
  String s="AT+CWSAP=\"DDD\",\"12345678\",11,0\r\n";
  sendData(s,2000,DEBUG);// reset module
  Serial.println("1");
  // delay(30000);
  sendData("AT+RST\r\n",2000,DEBUG); // reset module
  delay(3000);
  sendData("AT+CIPMUX=1\r\n",1000,DEBUG); // configure for multiple connections
  // delay(20000);
  sendData("AT+CIPSERVER=1,6000\r\n",1000,DEBUG); // turn on server on port 80

  Serial.println("Server Ready");
}

void loop()
{
  String inString = "";  
  if(esp8266.available()>0) // check if the esp is sending a message 
  {
    state = esp8266.read();
    Serial.print("esp8266 available!\n");
    
    if (!alreadyConnected)
    {
      // clear out the input buffer:
      esp8266.flush();
      Serial.println("We have a new client");
      esp8266.println("Hello, client!");
      alreadyConnected = true;
    }

    if(esp8266.find("+IPD,"))
    {
      delay(10); // wait for the serial buffer to fill up (read all the serial data)

      int pinNumber = 0;
      String tempS = "";
      esp8266.find("pin="); // advance cursor to "pin="
      char temp = esp8266.read();
      tempS = temp;
     
      pinNumber = tempS.toInt();
      Serial.println(pinNumber);
      digitalWrite(pinNumber, !digitalRead(pinNumber)); // toggle pin    

     }
  }
}


/*
* Name: sendData
* Description: Function used to send data to ESP8266.
* Params: command - the data/command to send; timeout - the time to wait for a response; debug - print to Serial window?(true = yes, false = no)
* Returns: The response from the esp8266 (if there is a reponse)
*/
String sendData(String command, const int timeout, boolean debug)
{
  String response = "";

  esp8266.print(command); // send the read character to the esp8266

  long int time = millis();

  while( (time+timeout) > millis())
  {
    while(esp8266.available())
    {

    // The esp has data so display its output to the serial window 
    char c = esp8266.read(); // read the next character.
    response+=c;
    }  
  }

  if(debug)
  {
    Serial.print(response);
  }

  return response;
}
