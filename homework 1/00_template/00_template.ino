#include <M5Stack.h>

bool is_measuring = false;
float accumulate_sec = 0;
float measure_sec = 0;  // 計測時間を保持している変数
float start_sec = 0;

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(3);
}

void loop() {
  M5.update();

  if (is_measuring) {
    if (M5.BtnC.wasPressed()) {
      is_measuring = false;
      //
      // タイマーをストップしたときの処理をここに追加
      //
    } else {
      measure_sec = millis() / 1000.0 - start_sec + accumulate_sec;
    }
  } else {
    if (M5.BtnA.wasPressed()) {
      measure_sec = 0;
      accumulate_sec = 0;
      //
      // タイマーをリセットしたときの処理をここに追加
      //
    }
    if (M5.BtnC.wasPressed()) {
      start_sec = millis() / 1000.0;
      accumulate_sec = measure_sec;
      is_measuring = true;
      //
      // タイマーをスタートしたときの処理をここに追加
      //
    }
  }
  //
  // 毎回行う処理をここに追加
  //
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print(measure_sec);
}
