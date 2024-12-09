//ROBOTRONICS CLUB
///Robot Arm Circuit Simulation
///created by Ambika Joshi

/*This project demonstrates a 4-DOF robot arm control system 
using 
4 potentiometers for manual operation and 
a button to toggle between manual and automatic modes. 
Each potentiometer adjusts the angle of one servo motor, 
controlling the robot arm's base, shoulder, elbow, and wrist. 
In manual mode, the arm responds in real time 
to potentiometer inputs for precise movements. 
In automatic mode, the arm follows a predefined motion sequence. 
An LED indicates the active mode, providing an interactive 
and versatile robot arm solution.*/

#include <Servo.h>

// Define potentiometer pins
#define potBase A0      // Potentiometer for Base servo
#define potShoulder A1  // Potentiometer for Shoulder servo
#define potElbow A2     // Potentiometer for Elbow servo
#define potWrist A3     // Potentiometer for Wrist servo

// Define servo motors
Servo servoBase;      // Base servo
Servo servoShoulder;  // Shoulder servo
Servo servoElbow;     // Elbow servo
Servo servoWrist;     // Wrist servo

// Define button and LED pins
#define buttonPin 13
#define ledPin 10

// Variables for mode control
bool isAutomatic = false;  // Toggle between manual and automatic modes
bool lastButtonState = LOW; // Tracks the previous button state
unsigned long lastDebounceTime = 0; // Last time the button state changed
const unsigned long debounceDelay = 50; // Debounce time in milliseconds

void setup() {
  // Potentiometer pins as input
  pinMode(potBase, INPUT);
  pinMode(potShoulder, INPUT);
  pinMode(potElbow, INPUT);
  pinMode(potWrist, INPUT);

  // Button and LED pins
  pinMode(buttonPin, INPUT_PULLUP); // Use internal pull-up resistor
  pinMode(ledPin, OUTPUT);

  // Attach servos to PWM pins
  servoBase.attach(3);
  servoShoulder.attach(5);
  servoElbow.attach(6);
  servoWrist.attach(9);

  // Set initial positions for servos
  servoBase.write(90);
  servoShoulder.write(90);
  servoElbow.write(90);
  servoWrist.write(90);

  // Start Serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the current state of the button
  bool reading = digitalRead(buttonPin);

  // Check if the button state has changed
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // Reset debounce timer
  }

  // Check if the state is stable for debounceDelay
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the button state has changed, toggle the mode
    if (reading == LOW) { // Button pressed
      isAutomatic = !isAutomatic;
      digitalWrite(ledPin, isAutomatic); // Turn LED on/off based on mode
      Serial.print("Mode switched to: ");
      Serial.println(isAutomatic ? "Automatic" : "Manual");
    }
  }

  lastButtonState = reading; // Save the current state for the next loop

  // Run appropriate mode
  if (isAutomatic) {
    automaticMode();
  } else {
    manualMode();
  }
}

void manualMode() {
  // Read potentiometer values
  int potValueBase = analogRead(potBase);
  int potValueShoulder = analogRead(potShoulder);
  int potValueElbow = analogRead(potElbow);
  int potValueWrist = analogRead(potWrist);

  // Map potentiometer values to servo angles (0-180 degrees)
  int angleBase = map(potValueBase, 0, 1023, 0, 180);
  int angleShoulder = map(potValueShoulder, 0, 1023, 0, 180);
  int angleElbow = map(potValueElbow, 0, 1023, 0, 180);
  int angleWrist = map(potValueWrist, 0, 1023, 0, 180);

  // Move servos to corresponding angles
  servoBase.write(angleBase);
  servoShoulder.write(angleShoulder);
  servoElbow.write(angleElbow);
  servoWrist.write(angleWrist);

  // Debugging output to monitor potentiometer and servo values
  Serial.print("Base: "); Serial.println(angleBase);
  Serial.print("Shoulder: "); Serial.println(angleShoulder);
  Serial.print("Elbow: "); Serial.println(angleElbow);
  Serial.print("Wrist: "); Serial.println(angleWrist);
  Serial.println("--------------------");

  delay(50); // Smooth movement delay
}

void automaticMode() {
  // Example: Move servos to predefined positions
  for (int pos = 0; pos <= 180; pos += 10) {
    servoBase.write(pos);
    servoShoulder.write(180 - pos);
    servoElbow.write(pos / 2);
    servoWrist.write(180 - pos / 2);
    delay(200);
  }

  for (int pos = 180; pos >= 0; pos -= 10) {
    servoBase.write(pos);
    servoShoulder.write(180 - pos);
    servoElbow.write(pos / 2);
    servoWrist.write(180 - pos / 2);
    delay(200);
  }
}

