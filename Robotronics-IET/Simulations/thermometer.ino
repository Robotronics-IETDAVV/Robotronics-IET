///Robotronics Club IET DAVV
////Created by Ambika Joshi
/////Smart Traffic Light System
/*This project uses an Arduino, a temperature sensor, an LCD
and a button to create a temperature display that allows
users to toggle between Celsius and Kelvin units.
 It provides a simple interface for viewing temperature readings 
in real-time and switching between units with a button press.*/


#include <LiquidCrystal.h>

// Initialize the LCD: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pin definitions
const int tempSensorPin = A0; // Pin for the temperature sensor
const int buttonPin = 8;      // Pin for the button

// State variable
bool showKelvin = false; // Tracks whether to show Kelvin or Celsius

void setup() {
  lcd.begin(16, 2);               // Initialize the LCD (16x2 size)
  pinMode(tempSensorPin, INPUT);  // Set sensor pin as input
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor for the button

  lcd.print("Press button");      // Initial message
  delay(2000);                    // Wait for 2 seconds before starting
  lcd.clear();                    // Clear the initial message
}

void loop() {
  // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) { // Button is pressed when LOW
    delay(50);                         // Short delay to debounce the button

    showKelvin = !showKelvin;          // Toggle between Celsius and Kelvin mode
    delay(300);                        // Wait for button release
  }

  // Read the temperature sensor value
  int sensorValue = analogRead(tempSensorPin);          // Get raw sensor value
  int tempCelsius = map(sensorValue, 20, 358, -40, 125); // Convert to Celsius

  // Display the temperature
  lcd.setCursor(0, 0); // Start at the top left
  if (showKelvin) {
    lcd.print(tempCelsius + 273); // Convert Celsius to Kelvin
    lcd.print(" K  ");            // Extra spaces to overwrite previous text
    lcd.setCursor(0, 1);          // Move to the second row
    lcd.print("Press for C ");    // Instruction for next toggle
  } else {
    lcd.print(tempCelsius);       // Show Celsius
    lcd.print(" C  ");            // Extra spaces to overwrite previous text
    lcd.setCursor(0, 1);          // Move to the second row
    lcd.print("Press for K ");    // Instruction for next toggle
  }
}
