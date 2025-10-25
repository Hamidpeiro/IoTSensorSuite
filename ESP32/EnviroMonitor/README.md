# EnviroMonitor

**EnviroMonitor** is a multi-sensor IoT project using ESP32 (and optionally Raspberry Pi) to monitor environmental parameters such as temperature, humidity, light, and sound. Data is displayed on an OLED screen and uploaded to ThingSpeak for real-time monitoring.

## Features

- Reads **DHT11** sensor for temperature and humidity.
- Reads **KY018** sensor for light intensity.
- Reads **KY037** sensor for sound levels.
- Reads **KY027** cup signal sensor with onboard LED feedback.
- Displays real-time sensor data on a 128x64 **OLED display**.
- Sends sensor data to **ThingSpeak** via Wi-Fi.
- Compatible with **ESP32**, with future Raspberry Pi support planned.

## Hardware

- ESP32 board
- DHT11 temperature & humidity sensor
- KY018 light sensor
- KY037 sound sensor
- KY027 cup signal sensor (with LED)
- 128x64 OLED display (I2C)

## Software Requirements

- Arduino IDE (1.8+ recommended)
- ESP32 board support installed in Arduino IDE
- Libraries:
  - `WiFi.h`
  - `HTTPClient.h`
  - `Adafruit_GFX.h`
  - `Adafruit_SSD1306.h`
  - `DHT.h`

## Wiring

| Sensor      | Pin on ESP32 |
|------------|-------------|
| DHT11      | D26         |
| KY018      | A2 / D34    |
| KY037      | A3 / D35    |
| KY027 signal | D25       |
| KY027 LED  | D27         |
| OLED SDA   | D21         |
| OLED SCL   | D22         |

> Adjust pins as needed for your board.

## Usage

1. Clone the repository:


git clone https://github.com/yourusername/EnviroMonitor.git

2.	Open the Arduino sketch EnviroMonitor.ino in Arduino IDE.

3.	Replace Wi-Fi credentials and ThingSpeak API key:
  const char* ssid = "YOUR_WIFI_SSID";
  const char* password = "YOUR_WIFI_PASSWORD";
  String serverName = "http://api.thingspeak.com/update?api_key=YOUR_API_KEY";

4.	Upload the sketch to your ESP32 board.

5.	Open the Serial Monitor at 115200 baud to see sensor readings and HTTP response.

ThingSpeak Setup
	•	Create a ThingSpeak channel.
	•	Add fields for Temperature, Humidity, Light, Sound.
	•	Use the provided Write API Key in the sketch.
