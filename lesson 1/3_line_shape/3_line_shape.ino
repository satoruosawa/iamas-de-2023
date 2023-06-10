#include <M5Stack.h>

void setup() {
  M5.begin();

  M5.Lcd.drawLine(30, 85, 100, 85, WHITE);    // 1本目の線を描画
  M5.Lcd.drawLine(30, 120, 100, 120, WHITE);  // 2本目の線を描画
  M5.Lcd.drawLine(30, 155, 100, 155, WHITE);  // 3本目の線を描画

  M5.Lcd.fillRect(125, 85, 70, 70, WHITE);  // 四角を描画

  M5.Lcd.fillCircle(255, 120, 35, WHITE);  // 円を描画
}

void loop() {}
