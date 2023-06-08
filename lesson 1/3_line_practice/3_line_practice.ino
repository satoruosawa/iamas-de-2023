#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Lcd.drawLine(10, 230, 310, 10, RED);
  M5.Lcd.drawLine(10, 10, 310, 230, RED);
}

void loop() {}
