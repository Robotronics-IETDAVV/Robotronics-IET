/*--------------- ROBOTRONICS TUTORIAL-----------
  1. Blink an LED */


// the setup function runs once when you press reset or power the board Hence write all pin defining in it
void setup() {
  // The pinMode function is used to set the pin as Input Or Output.
  // Set pin 12 as OUTPUT
// Can use pins A0 to A5 for Analog and 1 to 12 for Digital Pins
  pinMode(12, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(12, HIGH);  // turn the LED on (HIGH is the voltage level) 
  delay(1000);                      // We also decide ki kab tak LED ko high par rakhna hai SO we use" delay" to decide duration
                                    // delay does work in milliseconds Hence 1000 mtlb 1000 milisec = 1sec
  digitalWrite(12, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
