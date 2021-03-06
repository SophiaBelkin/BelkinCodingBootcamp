#include "ESP8266IFTTT.h"
#include "ESP8266WiFi.h"

#define ssid "coding-bootcamp"
#define password "belkin123"
#define IFTTT_API_KEY "api-key"
#define IFTTT_EVENT_NAME "event-name"

int ledPin = D8;
void setup() {

  pinMode(ledPin, OUTPUT);   // initialize the LED pin as an output:
  Serial.begin(115200);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting to connect...");
  }

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 

  IFTTT.trigger(IFTTT_EVENT_NAME, IFTTT_API_KEY);
  digitalWrite(ledPin, HIGH);   
  delay(200);              
  digitalWrite(ledPin, LOW); 
}

void loop() {
}
