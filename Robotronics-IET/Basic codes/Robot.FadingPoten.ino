/*--------------------ROBOTRONICS CLUB------------------
3. Controlling LED Brightness using Potentiometer 
*/



void setup() {
  // initialize serial communications at 9600 bps BITS PER SECOND :
  // 9600 is also baud rate
  // Matlab sensor se communicate karo
  Serial.begin(9600); // This begins the serial communication from Potent.
}

void loop() {
  int sensorValue = analogRead(A0); // AnalogRead takes Input from Potentiometer
  // range of analog Read function is 0 to 255
// Can use pins A0 to A5 for Analog and 1 to 12 for Digital Pins
  float voltage = sensorValue * (5/1023); 
  int brightness = sensorValue/4; 
  analogWrite(11,brightness); // this gives input from brightness to pin 11 of LED
  // IMP: Range of analogfWrite functiomn is 0 to 1023 
  Serial.print("ADC reading ");
  Serial.print(sensorValue);
  Serial.print(" Analog voltage: ");
  Serial.print(voltage);
  delay(1);


}
