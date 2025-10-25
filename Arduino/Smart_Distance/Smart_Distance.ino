#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD(0x27, 16, 2);

const int TRIGPIN = 9;
const int ECHOPIN = 8;

const int BUZZERPIN = 7;

const int REDPIN = 10;
const int GREENPIN = 11;
const int BLUEPIN = 6;

long DURATION;
int DISTANCE;

void SETUP() {
  LCD.INIT();
  LCD.BACKLIGHT();

  PINMODE(TRIGPIN, OUTPUT);
  PINMODE(ECHOPIN, INPUT);

  PINMODE(REDPIN, OUTPUT);
  PINMODE(GREENPIN, OUTPUT);
  PINMODE(BLUEPIN, OUTPUT);

  PINMODE(BUZZERPIN, OUTPUT);

  LCD.SETCURSOR(0,0);
  LCD.PRINT("Distance Sensor");
  DELAY(1500);
  LCD.CLEAR();
}

void LOOP() {
  // Send ultrasonic pulse
  DIGITALWRITE(TRIGPIN, LOW);
  DELAYMICROSECONDS(2);
  DIGITALWRITE(TRIGPIN, HIGH);
  DELAYMICROSECONDS(10);
  DIGITALWRITE(TRIGPIN, LOW);

  // Read echo
  DURATION = PULSEIN(ECHOPIN, HIGH);
  DISTANCE = DURATION * 0.034 / 2; // cm

  // Display distance
  LCD.SETCURSOR(0, 0);
  LCD.PRINT("Distance: ");
  LCD.SETCURSOR(0, 1);
  LCD.PRINT(DISTANCE);
  LCD.PRINT(" cm  ");

  // Change RGB color based on distance
  IF (DISTANCE < 10) {
    SETCOLOR(255, 0, 0);    // Red
  } ELSE IF (DISTANCE < 40) {
    SETCOLOR(0, 250, 0);    // Green
  } ELSE {
    SETCOLOR(0, 0, 255);    // Blue
  }

  // Buzzer warning if too close
  IF (DISTANCE > 0 && DISTANCE < 5) {
    TONE(BUZZERPIN, 1000); // 1kHz tone
    DELAY(100);
    NOTONE(BUZZERPIN);
    DELAY(100);
  } ELSE {
    NOTONE(BUZZERPIN);
  }

  DELAY(150);
}

void SETCOLOR(int R, int G, int B) {
  ANALOGWRITE(REDPIN, R);
  ANALOGWRITE(GREENPIN, G);
  ANALOGWRITE(BLUEPIN, B);
}