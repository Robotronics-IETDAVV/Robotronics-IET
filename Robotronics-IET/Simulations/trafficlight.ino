///Robotronics Club IET DAVV
////Created by Ambika Joshi
/////Smart Traffic Light System
/*This project simulates a four-way traffic light system 
using an Arduino, LEDs, and a potentiometer.
The LEDs represent North-South and East-West traffic directions
cycling through green, yellow, and red light phases.*/

int leds[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2}; // LEDs connected from pin 13 to 2 (representing North-South and East-West traffic lights)
int pot = A0; // Potentiometer pin (A0)
int greenDelay;   // Variable to store green light delay
int currentLight = 0;  // Variable to track the current traffic light (0 to 3)

void setup() {
  // Set all LED pins as output
  for (int i = 0; i < 12; i++) {
    pinMode(leds[i], OUTPUT); 
  }
}

void loop() {
  // Read potentiometer value and map it to a delay range for green and red lights
  int potVal = analogRead(pot);          // Read potentiometer value
  greenDelay = map(potVal, 0, 1023, 10000, 40000);  // Map potentiometer to 10-40 seconds (10000ms to 40000ms)

  // Handle the light transitions based on the current light phase
  if (currentLight == 0) {
    // Traffic Light 1 (North-South) - Green, others red
    digitalWrite(leds[0], HIGH);  // Green for North
    digitalWrite(leds[1], LOW);   // Turn off Yellow for North
    digitalWrite(leds[2], LOW);   // Red for North
    digitalWrite(leds[3], LOW);   // Turn off Green for East
    digitalWrite(leds[4], LOW);   // Turn off Yellow for East
    digitalWrite(leds[5], HIGH);  // Red for East
    digitalWrite(leds[6], LOW);   // Turn off Green for West
    digitalWrite(leds[7], LOW);   // Turn off Yellow for West
    digitalWrite(leds[8], HIGH);  // Red for West
    digitalWrite(leds[9], LOW);   // Turn off Green for South
    digitalWrite(leds[10], LOW);  // Turn off Yellow for South
    digitalWrite(leds[11], HIGH); // Red for South
    delay(greenDelay);            // Wait for green light duration

    // Yellow phase for Traffic Light 1 (North-South)
    digitalWrite(leds[0], LOW);   // Turn off Green for North
    digitalWrite(leds[1], HIGH);  // Yellow for North
    delay(2000);                  // 2 seconds for Yellow
    digitalWrite(leds[1], LOW);   // Turn off Yellow

    // Turn on Red for Traffic Light 1 and move to next light immediately
    digitalWrite(leds[2], HIGH);  // Red for North
    currentLight = 1;  // Move to the next traffic light phase immediately
  }
  else if (currentLight == 1) {
    // Traffic Light 2 (East-West) - Green, others red
    digitalWrite(leds[3], HIGH);  // Green for East
    digitalWrite(leds[4], LOW);   // Turn off Yellow for East
    digitalWrite(leds[5], LOW);   // Red for East
    digitalWrite(leds[0], LOW);   // Turn off Green for North
    digitalWrite(leds[1], LOW);   // Turn off Yellow for North
    digitalWrite(leds[2], HIGH);  // Red for North
    digitalWrite(leds[6], LOW);   // Turn off Green for West
    digitalWrite(leds[7], LOW);   // Turn off Yellow for West
    digitalWrite(leds[8], HIGH);  // Red for West
    digitalWrite(leds[9], LOW);   // Turn off Green for South
    digitalWrite(leds[10], LOW);  // Turn off Yellow for South
    digitalWrite(leds[11], HIGH); // Red for South
    delay(greenDelay);            // Wait for green light duration

    // Yellow phase for Traffic Light 2 (East-West)
    digitalWrite(leds[3], LOW);   // Turn off Green for East
    digitalWrite(leds[4], HIGH);  // Yellow for East
    delay(2000);                  // 2 seconds for Yellow
    digitalWrite(leds[4], LOW);   // Turn off Yellow

    // Turn on Red for Traffic Light 2 and move to next light immediately
    digitalWrite(leds[5], HIGH);  // Red for East
    currentLight = 2;  // Move to the next traffic light phase immediately
  }
  else if (currentLight == 2) {
    // Traffic Light 3 (West-East) - Green, others red
    digitalWrite(leds[6], HIGH);  // Green for West
    digitalWrite(leds[7], LOW);   // Turn off Yellow for West
    digitalWrite(leds[8], LOW);   // Red for West
    digitalWrite(leds[3], LOW);   // Turn off Green for East
    digitalWrite(leds[4], LOW);   // Turn off Yellow for East
    digitalWrite(leds[5], HIGH);  // Red for East
    digitalWrite(leds[0], LOW);   // Turn off Green for North
    digitalWrite(leds[1], LOW);   // Turn off Yellow for North
    digitalWrite(leds[2], HIGH);  // Red for North
    digitalWrite(leds[9], LOW);   // Turn off Green for South
    digitalWrite(leds[10], LOW);  // Turn off Yellow for South
    digitalWrite(leds[11], HIGH); // Red for South
    delay(greenDelay);            // Wait for green light duration

    // Yellow phase for Traffic Light 3 (West-East)
    digitalWrite(leds[6], LOW);   // Turn off Green for West
    digitalWrite(leds[7], HIGH);  // Yellow for West
    delay(2000);                  // 2 seconds for Yellow
    digitalWrite(leds[7], LOW);   // Turn off Yellow

    // Turn on Red for Traffic Light 3 and move to next light immediately
    digitalWrite(leds[8], HIGH);  // Red for West
    currentLight = 3;  // Move to the next traffic light phase immediately
  }
  else if (currentLight == 3) {
    // Traffic Light 4 (South-North) - Green, others red
    digitalWrite(leds[9], HIGH);  // Green for South
    digitalWrite(leds[10], LOW);  // Turn off Yellow for South
    digitalWrite(leds[11], LOW);  // Red for South
    digitalWrite(leds[0], LOW);   // Turn off Green for North
    digitalWrite(leds[1], LOW);   // Turn off Yellow for North
    digitalWrite(leds[2], HIGH);  // Red for North
    digitalWrite(leds[3], LOW);   // Turn off Green for East
    digitalWrite(leds[4], LOW);   // Turn off Yellow for East
    digitalWrite(leds[5], HIGH);  // Red for East
    digitalWrite(leds[6], LOW);   // Turn off Green for West
    digitalWrite(leds[7], LOW);   // Turn off Yellow for West
    digitalWrite(leds[8], HIGH);  // Red for West
    delay(greenDelay);            // Wait for green light duration

    // Yellow phase for Traffic Light 4 (South-North)
    digitalWrite(leds[9], LOW);   // Turn off Green for South
    digitalWrite(leds[10], HIGH); // Yellow for South
    delay(2000);                  // 2 seconds for Yellow
    digitalWrite(leds[10], LOW);  // Turn off Yellow

    // Turn on Red for Traffic Light 4 and move to next light immediately
    digitalWrite(leds[11], HIGH); // Red for South
    currentLight = 0;  // Reset to Traffic Light 1 (North-South) and start the cycle again
  }
}
