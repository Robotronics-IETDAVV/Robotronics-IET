/* -------------------- ROBOTRONICS TUTORIAL
 3. Analog Input se delay CONTROL

 OBJECTIVE : Demonstrates analog input by reading an analog sensor on analog pin 0 and
             turning on and off a light emitting diode(LED) connected to digital pin 13.
  

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

*/

int sensorPin = A0;   // Here we create a variable to select the input pin for the potentiometer

// Can use pins A0 to A5 for Analog and 1 to 12 for Digital Pins
int ledPin = 13;      // NOW we declare  the pin for the LED as new variable SO in future to change pin we need tochange only the variable
int sensorValue = 0;  // NOW we define variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // range of AnalogRead is from 0 to 255
  digitalWrite(ledPin, HIGH);
  // stop the program for <sensorValue> milliseconds:
  //Jitna sensor value hai say 20 utne millisec ka delay do
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  
  delay(sensorValue);
}
