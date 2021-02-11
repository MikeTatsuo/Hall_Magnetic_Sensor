#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define SENSOR_PIN 2

void setup() {
  pinMode(SENSOR_PIN, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Hall Magnetic Sensor");

  lcd.setCursor(0, 2);
  lcd.print("Status:");
}

void loop() {
  lcd.setCursor(8, 2);

  if (digitalRead(SENSOR_PIN)) {
    lcd.print("OPEN  ");
  } else {
    lcd.print("CLOSED");
  }
}
