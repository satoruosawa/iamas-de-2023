#include <M5Stack.h>

void setup() {
  M5.begin();

  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(90, 90);
  M5.Lcd.println("Hello world.");
  M5.Lcd.setTextSize(3);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setCursor(60, 110);
  M5.Lcd.println("Hello IAMAS.");
}

void loop() {
}