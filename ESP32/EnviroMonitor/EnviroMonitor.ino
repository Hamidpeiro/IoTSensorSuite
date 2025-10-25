#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// OLED Display setup
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Wi-Fi credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

// ThingSpeak API
String serverName = "http://api.thingspeak.com/update?api_key=REPLACE_WITH_YOUR_API_KEY";

// Timer setup
unsigned long lastTime = 0;
const unsigned long timerDelay = 1000; // 15 seconds

// DHT Sensor setup
#define DHT_PIN 26
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// Other sensors
#define KY018_PIN 34   // LDR (Light sensor)
#define KY037_PIN 35   // Sound sensor
#define KY027_PIN 25   // Cup signal sensor
#define KY027_LED 27   // KY027 module LED

WiFiClient client;
HTTPClient http;

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected to WiFi, IP: ");
  Serial.println(WiFi.localIP());

  // Initialize sensors
  dht.begin();
  pinMode(KY027_PIN, INPUT);
  pinMode(KY027_LED, OUTPUT);

  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.display();

  Serial.println("System ready. Sending data every 15 sec...");
}

void loop() {
  if (millis() - lastTime >= timerDelay) {
    if (WiFi.status() == WL_CONNECTED) {

      // Read sensors
      float temperature = dht.readTemperature();
      float humidity = dht.readHumidity();
      int lightValue = analogRead(KY018_PIN);     // 0-4095
      int soundValue = analogRead(KY037_PIN);     // 0-4095
      int cupValue = digitalRead(KY027_PIN);      // HIGH or LOW

      // KY027 LED follows signal
      digitalWrite(KY027_LED, cupValue);

      // Check DHT read
      if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read DHT sensor!");
        return;
      }

      // Construct ThingSpeak URL
      String serverPath = serverName +
                          "&field1=" + String(temperature, 2) +
                          "&field2=" + String(humidity, 2) +
                          "&field3=" + String(lightValue) +
                          "&field4=" + String(soundValue);
      Serial.println("Sending URL: " + serverPath);

      // Send HTTP GET request
      http.begin(client, serverPath.c_str());
      int httpResponseCode = http.GET();
      if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      } else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      http.end();

      // Display on OLED
      display.clearDisplay();
      display.setCursor(0,0);
      display.println("Temperature: " + String(temperature,1) + "C");
      display.println("Humidity: " + String(humidity,1) + "%");
      display.println("Light: " + String(lightValue));
      display.println("Sound: " + String(soundValue));
      display.println("Cup Signal: " + String(cupValue == HIGH ? "HIGH" : "LOW"));
      display.print("HTTP Resp: ");
      display.println(httpResponseCode);
      display.display();

    } else {
      Serial.println("WiFi Disconnected");
    }

    lastTime = millis();
  }
}