#include <M5Stack.h>

float number = 0;

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(4);
  M5.Lcd.setTextColor(YELLOW, BLACK);
}

void loop() {
  M5.Lcd.setCursor(100, 100);
  M5.Lcd.println(number);
  number = number + 0.1;
  delay(1000);
}
