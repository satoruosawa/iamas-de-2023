#include <M5Stack.h>

void setup() {
  M5.begin();

  M5.Lcd.fillRect(30, 30, 80, 80, MAROON);
  M5.Lcd.fillTriangle(130, 30, 130, 110, 210, 110, ORANGE);
  M5.Lcd.fillTriangle(30, 130, 30, 210, 110, 210, ORANGE);
  M5.Lcd.fillCircle(170, 170, 40, DARKCYAN);

  M5.Lcd.drawLine(230, 30, 230, 210, WHITE);
  M5.Lcd.drawLine(260, 30, 260, 210, WHITE);
  M5.Lcd.drawLine(290, 30, 290, 210, WHITE);
}

void loop() {}
