/* ---------------------ROBOTRONICS TUTORIAL
  2.Analog input, analog output, serial output

  Reads an analog input pin,
  maps the result to a range from 0 to 255 and
  usesthe result to setoutput of output pin.
  prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground through 220 ohm resistor

*/

// These constants won't change.
// They're used to give names to the pins used:
//constant(const) is a keyword used to declare constants
const int analogInPin = A0;  // Analog input pin for potentiometer
// Can use pins A0 to A5 for Analog and 1 to 12 for Digital Pins
const int analogOutPin = 9;  // Analog output pin for  LED

int sensorValue = 0;  // value readings  from the potentio.
int outputValue = 0;  // value output to the PWM pin of LED (analog out)

void setup() {
  // initialize serial communications at 9600 bps BITS PER SECOND :
  // 9600 is also baud rate
  // Matlab sensor se communicate karo
  Serial.begin(9600);
}

void loop() {
  // read the analog input value:
  // Analog Read function used to read input from Potentiometer
  // Range is 0 to 255 
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog output value:
  // AnalogWrite function is used to give output readings to analog pins
  // but range is from 0 to 1023
  // Hence we need to convert or map values of AnalogRead 0 to 255 to range of AnalogWrite 0 to 1023
  // We use map function for this
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
