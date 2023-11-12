#include "WiFiS3.h"
#include <ArduinoJson.h>

#include "arduino_secrets.h"
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;        // your network password

int status = WL_IDLE_STATUS;
WiFiSSLClient client;

char server[] = "api.openai.com"; // OpenAI API server
int port = 443;                   // HTTPS port

unsigned long lastConnectionTime = 0;
const unsigned long postingInterval = 10L * 1000L;

void setup() {
  Serial.begin(9600);
  while (!Serial) {}

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
  printWifiStatus();
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');

    // Print user input
    Serial.println("Me: " + input);

    sendRequestToChatGPT(input);
    delay(5000); // Small delay for processing

    String response = "";
    while (client.available()) {
      char c = client.read();
      response += c; // Accumulate the response
    }

    // Parse and print ChatGPT's reply
    parseAndPrintChatGPTReply(response);
    // Serial.println(response);

    client.stop();
  }
}

void parseAndPrintChatGPTReply(const String& response) {
  int startIndex = response.indexOf("\"content\": \"") + 12; // 12 is the length of "\"content\": \""
  if (startIndex > 11) { // Check if the substring was found
    int endIndex = response.indexOf("\"", startIndex);
    if (endIndex > startIndex) {
      String chatGPTReply = response.substring(startIndex, endIndex);
      Serial.println("ChatGPT: " + chatGPTReply);
    } else {
      Serial.println("End of content not found.");
    }
  } else {
    Serial.println("ChatGPT response not found.");
  }
}

void sendRequestToChatGPT(const String& input) {
  client.stop();
  if (client.connect(server, port)) {
    // Serial.println("Connecting to ChatGPT...");

    String postData;
    StaticJsonDocument<512> doc; // Increased size for payload

    JsonArray messages = doc.createNestedArray("messages");
    
    // User input as a message
    JsonObject userMessage = messages.createNestedObject();
    userMessage["role"] = "user";
    userMessage["content"] = input; // User input

    doc["max_tokens"] = 128;
    doc["model"] = "gpt-4-1106-preview"; // Specify your model

    serializeJson(doc, postData);

    client.println("POST /v1/chat/completions HTTP/1.1");
    client.println("Host: api.openai.com");
    client.println("Content-Type: application/json");
    client.println("Authorization: Bearer " + String(OPENAI_API_KEY)); // Use your API key
    client.print("Content-Length: ");
    client.println(postData.length());
    client.println();
    client.println(postData);

    lastConnectionTime = millis();
  } else {
    Serial.println("Connection to ChatGPT failed.");
  }
}

void printWifiStatus() {
  // Serial.print("SSID: ");
  // Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  // Serial.print("IP Address: ");
  // Serial.println(ip);
  long rssi = WiFi.RSSI();
  Serial.print("Signal strength (RSSI): ");
  Serial.print(rssi);
  Serial.println(" dBm");
  Serial.println("This is Longer Vision Technology !!!");
}
