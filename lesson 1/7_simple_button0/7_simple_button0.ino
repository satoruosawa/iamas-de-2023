#include <M5Stack.h>

void setup() {
  M5.begin();
}

void loop() {
  M5.update();  // buttonを使うときはこの行を追加
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println(M5.BtnA.wasPressed());
  M5.Lcd.println(M5.BtnB.wasPressed());
  M5.Lcd.println(M5.BtnC.wasPressed());
  M5.Lcd.println(M5.BtnA.wasReleased());
  M5.Lcd.println(M5.BtnB.wasReleased());
  M5.Lcd.println(M5.BtnC.wasReleased());
  delay(100);
}