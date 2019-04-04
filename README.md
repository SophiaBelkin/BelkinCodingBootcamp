# Setting up your development enviroment for Belkin coding bootcamp

###### Contributed by Aaron Malone and Jared Triplett

## Getting Started

1. Installing the Arduino IDE
2. Adding ESP8266 Library to the IDE
3. Configuring the port Settings
4. Uploading a sketch to the module
5. Adding Extra Plugins if needed


## Setting Up The Computer
In order to complete this guide, you may need administrative powers in order to install the required drivers.

## 1. Installing the Arduino IDE
1. Goto [https://www.arduino.cc/en/main/software](https://www.arduino.cc/en/main/software) 
2. Download and install the IDE
* On Windows, get the ZIP file download to avoid entering admin password

<img src="https://github.com/SophiaBelkin/BelkinCodingBootcamp/blob/master/images/IDEDownload.png?raw=true">


## 2. Add ESP8266 Library to the IDE
1. Click on File > Preferences
* On Windows, click on 'File' (at the top of the window), then 'Preferences'
* On OS X, click on 'Arduino' (at the top), then 'Preferences'
2. Enter `http://arduino.esp8266.com/versions/2.2.0/package_esp8266com_index.json` in the "Additional Boards Manager URLs:" field

<img src="https://github.com/SophiaBelkin/BelkinCodingBootcamp/blob/master/images/PereferencesWindow.png?raw=true">

<span style="color:#f90">Note:</span> The "Sketchbook Location" is where your code will be saved. You can change it to wherever you want.

3. Go to Tools > Boards:"[boardName]" > Board Manager
<img src="https://github.com/SophiaBelkin/BelkinCodingBootcamp/blob/master/images/boardManager1.png?raw=true">

4. Filter for `ESP8266`
<img src="https://github.com/SophiaBelkin/BelkinCodingBootcamp/blob/master/images/BoardManager.png?raw=true">

5. Install the latest version of the library

## 3. Configuring the Upload Settings
1. Plug in the NodeMCU in to the PC

2. Select ModeMCU as the board
1). At the top, click on "Tools"
2). Hover over "Board: ..."
3). Select "NodeMCU 1.0 (ESP-12E Module)"

<img src="https://github.com/SophiaBelkin/BelkinCodingBootcamp/blob/master/images/chooseBoard.png?raw=true">

3.Configure to the proper upload settings
Upload Speed: 115200
CPU Frequency: 80 MHz
Flash Size: 4M (3M SPIFFS)

<img src="https://github.com/Snappsu/Coding-Bootcamp/blob/master/pics/UploadSettings.png?raw=true">

4. Pick the right port
<img src="https://github.com/SophiaBelkin/BelkinCodingBootcamp/blob/master/images/choosePort.png?raw=true">

<span style="color:#f90">Note:</span> If you're having trouble finding the right port, try unplugging the module, observing the list of avaiable port, then pluging in the module into the same port, and looking for any differences.

<img src="https://github.com/SophiaBelkin/BelkinCodingBootcamp/blob/master/images/UploadSettings.png?raw=true">



## 5. Uploading a sketch to the module

1. At the top left, click the arrow pointing right.

<img src="https://github.com/SophiaBelkin/BelkinCodingBootcamp/blob/master/images/UploadButton.png?raw=true">

2. If everything is correct the bottom of IDE should look like this.

<img src="https://github.com/SophiaBelkin/BelkinCodingBootcamp/blob/master/images/ConsoleUpload.png?raw=true">


<span style="color:#f90">Note:</span> If you're running into issue uploading the Sketch on Mac, try installing the port drivers [[HERE](https://github.com/SophiaBelkin/BelkinCodingBootcamp/tree/master/drivers/OSX)]

We will talk about these examples during the coding bootcamp class. Don't worry about working on them now.

## Samples
1. Blank Sketch
2. Blinking Light
3. WiFi Access Point


# Samples

## Blank Arduino Sketch
```ino
void setup() {
  // put your setup code here, to run once:

}
void loop() {
  // put your main code here, to run repeatedly:

}
```

## Blinking Light

```ino
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
```


## Wifi Access Point
```ino
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
// Replace with your network credentials
const char* ssid = "WiFi_Name_Here";
const char* password = "WiFi_Password_Here";
 
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
String page = ""; //Creates the HTML Page
int LEDPin = 2;
void setup(){
  //the HTML of the web page
  page = "<h1>Simple NodeMCU Web Server</h1><p><a href=\"LEDOn\"><button>ON</button></a>&nbsp;<a href=\"LEDOff\"><button>OFF</button></a></p>";
  //make the LED pin output and initially turned off
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);
   
  delay(1000);
  Serial.begin(115200);
  WiFi.softAP(ssid, password); //begin WiFi access point
  Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP()); 
   
  server.on("/", [](){
    server.send(200, "text/html", page);
  });
  server.on("/LEDOff", [](){
    server.send(200, "text/html", page);
    digitalWrite(LEDPin, HIGH);
    delay(1000);
  });
  server.on("/LEDOn", [](){
    server.send(200, "text/html", page);
    digitalWrite(LEDPin, LOW);
    delay(1000); 
  });
  server.begin();
  Serial.println("Web server started!");
}
 
void loop(void){
  server.handleClient();
}
```



