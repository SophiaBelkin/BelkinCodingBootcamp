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
1. Launch the Arduino application, click on File > Preferences

2. Enter `http://arduino.esp8266.com/stable/package_esp8266com_index.json` in the "Additional Boards Manager URLs:" field

<img src="https://github.com/SophiaBelkin/BelkinCodingBootcamp/blob/master/images/PereferencesWindow.png?raw=true">

<span style="color:#f90">Note:</span> The "Sketchbook Location" is where your code will be saved. You can change it to wherever you want.

3. Go to Tools > Board: [board name] > Board Manager
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


<span style="color:#f90">Note:</span> If you're running into issue uploading the Sketch, try installing the port drivers 
[[OSX](https://github.com/SophiaBelkin/BelkinCodingBootcamp/tree/master/drivers/OSX)]
[[Windows Drivers](https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers)]



## Samples
1. Blank Sketch
2. Blinking Light
3. WiFi Access Point

We will talk about these examples during the coding bootcamp class. Don't worry about working on them now.




