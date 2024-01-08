/*
  Arduino Soil Moisture Sensor Project Code
  Author: Raymond Li January, 2024

  Reads environmental moisture level from capacitive soil moisture sensor and displays moisture percentage on LCD.
*/

#include <LiquidCrystal.h>

const int SERIAL_SPEED = 9600;
const unsigned long UPDATE_INTERVAL = 100;    // do loop once every x ms
const uint8_t SENSOR_INPUT_PIN = A0;          // pin that receives sensor input
const uint8_t lcd_rows = 16;                  // number of rows on LCD
const uint8_t lcd_cols = 2;                   // number of columns on LCD
const int dry = 585;                          // maximum sensor value in ambient air - requires calibration
const int wet = 323;                          // minimum sensor value in water       - requires calibration

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sensor_input;
int moisture_percentage;

void setup() {
  Serial.begin(SERIAL_SPEED);
  lcd.begin(lcd_rows, lcd_cols);
}

void loop() {
  sensor_input = analogRead(SENSOR_INPUT_PIN);
  moisture_percentage = map(sensor_input, wet, dry, 100, 0);

  printCalibration();
  printLCD();

  delay(UPDATE_INTERVAL);
}

void printCalibration() {
  Serial.println(sensor_input);
  Serial.print(moisture_percentage);
  Serial.println("%");
}

void printLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture:");
  lcd.setCursor(0, 1);
  lcd.print(moisture_percentage);
  lcd.print("%");
}
