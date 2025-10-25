#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// DHT Sensor setup
#define DHTPIN 2       // Pin for KY-015
#define DHTTYPE DHT11  // DHT sensor type
DHT dht(DHTPIN, DHTTYPE);

// LCD setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Other sensors and buzzer
const int lightPin = A0;   // KY-018 Photoresistor
const int buzzerPin = 7;   // Active buzzer

// Variables for sensor readings
float temperature;
float humidity;
int lightValue;

void setup() {
  // Initialize LCD
  lcd.init();
  lcd.backlight();

  // Initialize pins
  pinMode(lightPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Initialize DHT
  dht.begin();

  // Intro message
  lcd.setCursor(0, 0);
  lcd.print("Environmental Station");
  delay(1500);
  lcd.clear();
}

void loop() {
  // Read temperature and humidity
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // Read light level
  lightValue = analogRead(lightPin);

  // Display data on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Light: ");
  lcd.print(lightValue);
  lcd.print(" Hum: ");
  lcd.print(humidity, 1);
  lcd.print("%");

  // Buzzer condition
  if (temperature > 25 && lightValue > 20) {
    tone(buzzerPin, 50);  // Buzzer ON
  } else {
    noTone(buzzerPin);     // Buzzer OFF
  }

  delay(200); // Update every 0.2 seconds
}