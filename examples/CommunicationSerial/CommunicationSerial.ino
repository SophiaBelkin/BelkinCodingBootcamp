

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // start the serial port at 115200 Baud ( bps )
  Serial.begin(115200);
  Serial.println("Ready for user input...");
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Turn the LED on");
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  Serial.println("Turn the LED off");
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
