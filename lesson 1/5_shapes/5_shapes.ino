#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Lcd.drawCircle(80, 120, 50, WHITE);      // 円を描画
  M5.Lcd.drawRect(190, 70, 100, 100, WHITE);  // 四角を描画
}

void loop() {}
