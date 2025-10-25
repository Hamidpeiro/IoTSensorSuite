Sound Monitor

Sound Monitor is an Arduino-based project that measures environmental sound intensity using a KY-038 sound sensor. The system displays the sound level on an LCD 1602 with I2C, changes an RGB LED’s color according to the intensity, and activates a buzzer for loud sounds.

Goal

Create a system that:
	•	Measures sound intensity using a KY-038 sound sensor.
	•	Converts the sound signal to an approximate decibel (dB) value.
	•	Displays the sound level on an LCD 1602 with I2C.
	•	Changes RGB LED color based on sound intensity.

Behavior
	•	Sound level < 40 dB → LED turns blue, buzzer OFF.
	•	Sound level between 40–70 dB → LED turns green, buzzer OFF.
	•	Sound level > 70 dB → LED turns red, buzzer ON continuously.

Required Components
	•	Arduino Uno board
	•	KY-038 sound sensor module
	•	RGB LED module (KY-016 or similar)
	•	Active buzzer module
	•	LCD 1602 with I2C
	•	Jumper wires
	•	Breadboard

Required Library
	•	LiquidCrystal_I2C – for controlling the LCD.

Installation
	1.	Open Arduino IDE → Sketch → Include Library → Manage Libraries…
	2.	Search for LiquidCrystal I2C.
	3.	Install the library by Frank de Brabander or similar.

Wiring

Component	Pin on Arduino Uno
KY-038 Sound Sensor	A0
RGB LED Red	D9
RGB LED Green	D10
RGB LED Blue	D11
Buzzer	D7
LCD SDA	A4
LCD SCL	A5

Adjust pins if needed according to your setup.

Usage
	1.	Clone the repository:

git clone https://github.com/yourusername/SoundMonitor.git

	2.	Open SoundMonitor.ino in Arduino IDE.
	3.	Upload the sketch to your Arduino Uno.
	4.	Open Serial Monitor at 9600 baud (optional) to see sensor readings.
	5.	Observe the LCD display, LED color changes, and buzzer behavior according to the sound levels.
