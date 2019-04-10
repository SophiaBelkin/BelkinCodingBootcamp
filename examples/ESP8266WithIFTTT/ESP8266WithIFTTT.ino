#include "IFTTTWebhook.h"
#include "ESP8266WiFi.h"

#define ledPin D8
#define wakePin 16
#define ssid "YOUR_WIFI_SSID"
#define password "YOUR_WIFI_PASSWORD"
#define IFTTT_API_KEY "IFTTT_KEY_GOES_HERE"
#define IFTTT_EVENT_NAME "IFTTT_EVENT_NAME_HERE"

void setup() {
  Serial.begin(115200);
  Serial.println(" ");// print an empty line before and after Button Press    
  Serial.println("Button Pressed");
  Serial.println(" ");// print an empty line  

  WiFi.begin(ssid, password);  
  Serial.println(" ");// print an empty line
  Serial.print("Attempting to connect: ");

  while(WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  } 
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); 

  //just connected to Wi-Fi
  IFTTTWebhook hook(IFTTT_API_KEY, IFTTT_EVENT_NAME);
  hook.trigger();
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);   
  delay(200);              
  digitalWrite(ledPin, LOW); 
  //now sending board to sleep
  
  ESP.deepSleep(wakePin); 
}

void loop() {
  Serial.print("This line should not run");
}
