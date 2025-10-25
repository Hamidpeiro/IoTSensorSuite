# Smart Distance Sensor with LED, Buzzer, and LCD

**Smart Distance Sensor** is an Arduino-based system that measures distance using an ultrasonic sensor, displays it on an LCD, changes LED colors based on distance, and triggers a buzzer when an object gets very close.

## Goal

Create a system that:

* Measures distance with an ultrasonic sensor.
* Shows the distance on an **LCD 1602 with I2C**.
* Changes **LED colors** based on distance.
* Activates a **buzzer** when the object is very close.

## Behavior

| Distance | LED Color | Buzzer          |
| -------- | --------- | --------------- |
| < 5 cm   | Red       | ON continuously |
| < 10 cm  | Red       | OFF             |
| 10–40 cm | Green     | OFF             |
| > 40 cm  | Blue      | OFF             |

## Required Components

* Arduino Uno board
* **HC-SR04** ultrasonic sensor
* RGB LED module
* Active buzzer module
* LCD 1602 with I2C
* Jumper wires
* Breadboard

## Required Library

**LiquidCrystal_I2C** – For controlling the LCD.

### Installation

1. Open Arduino IDE.
2. Go to `Sketch → Include Library → Manage Libraries...`
3. Search for **LiquidCrystal I2C**
4. Install the library by **Frank de Brabander**

## Wiring

| Component       | Arduino Pin |
| --------------- | ----------- |
| Ultrasonic Trig | D9          |
| Ultrasonic Echo | D8          |
| RGB LED Red     | D10         |
| RGB LED Green   | D11         |
| RGB LED Blue    | D6          |
| Buzzer          | D7          |
| LCD SDA         | A4          |
| LCD SCL         | A5          |

> Pins may vary depending on your board; adjust accordingly.

## Usage

1. Connect all components as per the wiring table.
2. Open the Arduino sketch in Arduino IDE.
3. Upload the sketch to your Arduino Uno.
4. Open the Serial Monitor to view distance readings.
5. Observe LED color changes and buzzer behavior according to distance.
