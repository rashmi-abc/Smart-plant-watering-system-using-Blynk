#include <LiquidCrystal_I2C.h>

// Define pin numbers
const int soilMoisturePin = A0; // Analog pin for soil moisture sensor
const int pumpPin = 7;          // Digital pin for water pump relay

// LCD configuration
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

// Define threshold values
const int moistureThreshold = 500; // Adjust this value based on your soil moisture sensor readings
const int pumpRunTime = 3000;      // Run the pump for 5 seconds

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Auto Watering");

  // Initialize pump pin
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  // Read soil moisture level
  int moistureLevel = analogRead(soilMoisturePin);

  // Display moisture level on LCD
  lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print(moistureLevel);

  // Check if soil moisture is below the threshold
  if (moistureLevel < moistureThreshold) {
    // Soil is dry, turn on water pump
    lcd.setCursor(0, 0);
    lcd.print("Watering...");

    digitalWrite(pumpPin, HIGH); // Turn on the water pump
    delay(pumpRunTime);           // Run the pump for a specified time
    digitalWrite(pumpPin, LOW);  // Turn off the water pump

    lcd.setCursor(0, 0);
    lcd.print("Watered   ");
  }

  // Delay before the next iteration
  delay(1000);
}
