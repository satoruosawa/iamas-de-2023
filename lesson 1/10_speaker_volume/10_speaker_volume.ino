#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Speaker.setVolume(6);  // スピーカーのボリュームを設定 範囲は 0 ~ 10
}

void loop() {
  M5.update();
  if (M5.BtnB.wasPressed()) {
    M5.Speaker.tone(3520, 40);
  }
}
