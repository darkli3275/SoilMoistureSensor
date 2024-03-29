# SoilMoistureSensor
Reads environmental moisture level from capacitive soil moisture sensor and displays moisture percentage on LCD.
Arduino code in SoilMoistureSensor.ino

Highlights:
  1. Programmed an Arduino Uno microcontroller board to convert readings from a capacitive soil moisture sensor
     to percentages and display them on an LCD screen.
  2. Designed circuit and wired components.
  3. Calibrated sensor and experimentally tested components' behavior.

Project Stages:
  1. Test capacitive moisture sensor using serial monitor and get max & min values for calibration.
  2. Test analog->percentage conversion with serial monitor and output with LED lights.
  3. Wire LCD screen and final circuit. Test and confirm behavior in dry, wet, and average soil conditions.

Proposed Change For Periodic Readings: Every x milliseconds, read ten sensor values and average them for reading value.

Issues:
  Negative percentages. Potential Solution: Controlling for temperature.
  Inaccurate behavior when sensor not fully immersed in material. Potential solution: Use different sensor type.
