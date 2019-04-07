

//Include ESP8266 libraries 
#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"

//Declare a global object variable from ESP8266WebServer class
ESP8266WebServer server(80);

const char* ssid = "said";
const char* password = "password";


void setup() {
 
  Serial.begin(115200);
  WiFi.begin(ssid, password);  //Connect to the WiFi network
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for connection
    delay(500);
    Serial.println("Waiting to connect…");
  }
 
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP


  server.on("/", []() {   //Define the handling function for the path
    server.send(200, "text/plain", "Hello world");
  });

  server.on("/other", handleRootPath);

  server.begin();                    //Start the server
  Serial.println("Server listening");
}

void handleRootPath() {            //Handler for the rooth path
  server.send(200, "text/plain", "another url");
}

 
void loop() {
  server.handleClient();         //Handling of incoming requests
}
 

 
