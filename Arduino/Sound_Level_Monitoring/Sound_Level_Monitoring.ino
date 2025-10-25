#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <math.h>

// LCD setup: I2C address 0x27, 16x2 display
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin definitions
const int soundPin = A0;   // Analog input from sound sensor
const int redPin = 9;      // RGB LED Red
const int greenPin = 10;   // RGB LED Green
const int bluePin = 11;    // RGB LED Blue
const int buzzerPin = 7;   // Active buzzer

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Initialize pins
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Display initial message
  lcd.print("Sound Monitor");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Read sound sensor multiple times for stable value
  long total = 0;
  for (int i = 0; i < 10; i++) {
    total += analogRead(soundPin);
    delay(5);
  }
  int soundValue = total / 10;

  // Convert to voltage
  float voltage = (soundValue / 1023.0) * 5.0;

  // Convert voltage to decibels (approx.)
  float decibel = 20.0 * log10(voltage / 0.006);

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Sound Level:");
  lcd.setCursor(0, 1);
  lcd.print(decibel, 1);
  lcd.print(" dB   "); // Extra spaces to clear old values

  // RGB LED and buzzer behavior based on sound level
  if (decibel < 40) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255); // Blue for quiet
    noTone(buzzerPin);
  }
  else if (decibel < 70) {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255); // Green for moderate sound
    analogWrite(bluePin, 0);
    noTone(buzzerPin);
  }
  else {
    analogWrite(redPin, 255); // Red for loud sound
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    tone(buzzerPin, 1000); // 1kHz buzzer
  }

  delay(50); // Small delay for stability
}