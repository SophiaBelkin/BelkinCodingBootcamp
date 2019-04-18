
#include "ESP8266WiFi.h"
#include "ESP8266WebServer.h"
 
// Replace with your network credentials
String ssid = "sophia-shield-qa";
String password = "belkin123";
 
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)

String page = ""; //Creates the HTML Page
int LEDPin = D8;
void setup(void){
  //the HTML of the web page
  page = "<h1>Simple NodeMCU Web Server</h1>"
  "<p><a href=\"LEDOn\"><button>ON</button></a>"
  "<a href=\"LEDOff\"><button>OFF</button></a></p>";
  
  //make the LED pin output and initially turned off
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);

  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi access point
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting to connect...");
  }

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 
   
  server.on("/", [](){
    server.send(200, "text/html", page);
  });
  server.on("/LEDOff", [](){
    server.send(200, "text/html", page);
    digitalWrite(LEDPin, LOW);
    delay(1000);
  });
  server.on("/LEDOn", [](){
    server.send(200, "text/html", page);
    digitalWrite(LEDPin, HIGH);
    delay(1000); 
  });
  
  server.begin();
  Serial.println("Web server started!");
}
 
void loop(void){
  server.handleClient();
}
