///ROBOTRONICS CLUB
////Created by Ambika Joshi
/////Automatic Plant Watering System
/* The Automatic Plant Watering System ensures 
plants receive proper hydration without manual effort. 
It uses a soil moisture sensor to monitor soil conditions 
in real time. When the soil becomes too dry, 
the system automatically activates a water pump to 
irrigate the plant. 
LED indicators display the soil’s status: 
orange for dry and green for sufficient moisture.*/

int soilSensorPin = A0; // Soil sensor pin
int pumpPin = 7;        // Pump control pin
int dryIndicator = 8;   // Dry soil indicator (LED)
int wetIndicator = 9;   // Wet soil indicator (LED)
int threshold = 300;    // Adjustable moisture threshold

void setup()
{
  pinMode(soilSensorPin, INPUT);
  Serial.begin(9600);
  pinMode(pumpPin, OUTPUT);
  pinMode(dryIndicator, OUTPUT);
  pinMode(wetIndicator, OUTPUT);
}

void loop()
{
  int soilSensorValue = analogRead(soilSensorPin);
  Serial.print("Soil Moisture: ");
  Serial.println(soilSensorValue);

  if (soilSensorValue < threshold) {
    digitalWrite(pumpPin, HIGH);     // Turn ON the pump
    digitalWrite(dryIndicator, HIGH); // Dry soil indicator ON
    digitalWrite(wetIndicator, LOW);  // Wet soil indicator OFF
  } else {
    digitalWrite(pumpPin, LOW);       // Turn OFF the pump
    digitalWrite(dryIndicator, LOW); // Dry soil indicator OFF
    digitalWrite(wetIndicator, HIGH); // Wet soil indicator ON
  }
  delay(1000); // Wait for 1 second before reading again
}
