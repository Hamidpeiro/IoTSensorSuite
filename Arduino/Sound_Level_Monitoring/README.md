# Sound Monitor with LED, Buzzer, and LCD

**Sound Monitor** is an Arduino project that measures sound intensity using a KY-038 sensor, displays the sound level on an LCD 1602 (I2C), and uses an RGB LED and buzzer to indicate different sound levels.

## Goal

Create a system that:

- Measures sound intensity using a KY-038 sound sensor.
- Converts sound signal to an approximate decibel (dB) value.
- Shows the sound level on an LCD 1602 with I2C.
- Changes RGB LED color based on sound intensity.
- Activates a buzzer if the sound exceeds a certain threshold.

## Behavior

- Sound level < 40 dB → LED turns **blue**, buzzer **OFF**.
- Sound level between 40–70 dB → LED turns **green**, buzzer **OFF**.
- Sound level > 70 dB → LED turns **red**, buzzer **ON** continuously.

## Required Components

- Arduino Uno board  
- KY-038 sound sensor module  
- RGB LED module (KY-016 or similar)  
- Active buzzer module  
- LCD 1602 with I2C  
- Jumper wires  
- Breadboard  

## Required Library

- `LiquidCrystal_I2C` for controlling the LCD.  

### Installation

1. Open Arduino IDE.
2. Go to **Sketch → Include Library → Manage Libraries…**
3. Search `"LiquidCrystal I2C"`.
4. Install the library by Frank de Brabander (or similar).

## Wiring

| Component     | Arduino Pin |
|---------------|-------------|
| KY-038 Signal | A0          |
| RGB LED Red   | D9          |
| RGB LED Green | D10         |
| RGB LED Blue  | D11         |
| Buzzer        | D7          |
| LCD SDA       | A4          |
| LCD SCL       | A5          |

> Adjust pins if necessary for your board setup.

## Usage

1. Connect all components as per the wiring table.
2. Open the Arduino sketch `SoundMonitor.ino` in Arduino IDE.
3. Upload the sketch to your Arduino Uno.
4. Open the Serial Monitor at 9600 baud (optional) to check debug information.
5. Watch the LCD for real-time sound levels and the RGB LED/buzzer for feedback.

## Notes

- Calibration may be required for accurate decibel readings.
- The LED and buzzer thresholds can be adjusted in the code.
