# Environmental Monitoring Station

**Environmental Monitoring Station** is a simple Arduino-based project to monitor temperature, humidity, and light levels, displaying the data on an LCD 1602 screen and triggering a buzzer under certain conditions.

## Features

* Reads **DHT11** sensor for temperature and humidity.
* Reads **KY-018** photoresistor for light intensity.
* Displays real-time data on a 16x2 **LCD display** (I2C).
* Activates an **active buzzer** if temperature > 25°C and light > 20.

## Required Components

* Arduino Uno board
* DHT11 sensor (KY-015)
* KY-018 light sensor
* Active buzzer module
* LCD 1602 with I2C
* Jumper wires
* Breadboard

## Required Library

* `DHT.h` for reading temperature and humidity
* `LiquidCrystal_I2C.h` for LCD display

To install the library:

1. Go to Sketch → Include Library → Manage Libraries...
2. Search for `LiquidCrystal I2C` and install the library by Frank de Brabander.
3. Search for `DHT sensor library` and install the library by Adafruit.

## Wiring

| Sensor / Device | Pin on Arduino |
| --------------- | -------------- |
| DHT11           | D2             |
| KY-018          | A0             |
| Buzzer          | D7             |
| LCD SDA         | A4             |
| LCD SCL         | A5             |

> Adjust pins as needed for your board.

## Usage

1. Open Arduino IDE and load `EnviroStation.ino`.
2. Upload the sketch to your Arduino Uno.
3. The LCD will display Temperature, Humidity, and Light.
4. The buzzer will activate when Temperature > 25°C and Light > 20.

## Behavior

* Temperature > 25°C **and** Light > 20 → Buzzer ON
* Otherwise → Buzzer OFF

## License

This project is open source and available under the MIT License.
