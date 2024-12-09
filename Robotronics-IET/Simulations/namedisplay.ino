#include <LiquidCrystal.h>
/* This project uses a 16x2 LCD module and Arduino 
to create an interactive text display. 
Users can customize the scrolling text on the first line
 by adding their name. 
The second line displays a static message, 
ensuring a dynamic yet stable presentation.*/


// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); // Set up the LCD's number of columns and rows (16x2 LCD)

  // Set static text on the second line
  lcd.setCursor(0, 1);
  lcd.print("ROBOTRONICS");
}

void loop() {
  String scrollingText = "Name"; // Replace with your actual name or message
  int lengthOfText = scrollingText.length();

  // Display static text on the first line for 1 second
  lcd.setCursor(0, 0);
  lcd.print(scrollingText);
  delay(1000); // Wait for 1 second

  // Loop to continuously scroll the first line
  for (int position = 0; position < lengthOfText + 16; position++) {
    lcd.setCursor(0, 0); // Set cursor to the start of the first line
    lcd.print(scrollingText.substring(position, position + 16)); // Display 16 characters at a time

    // Ensure the second line remains static
    lcd.setCursor(0, 1); 
    lcd.print("ROBOTRONICS");

    delay(300); // Delay for smooth scrolling

    // Reset position to the start once the scrolling text ends
    if (position == lengthOfText) {
      position = 0; // Restart scrolling when the end of the text is reached
    }
  }
}

