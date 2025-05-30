#include <M5Stack.h>

bool is_measuring = false;
float accumulate_sec = 0;
float measure_sec = 0;
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
    } else {
      measure_sec = millis() / 1000.0 - start_sec + accumulate_sec;
    }
  } else {
    if (M5.BtnA.wasPressed()) {
      measure_sec = 0;
      accumulate_sec = 0;
      M5.Lcd.fillScreen(BLACK);
    }
    if (M5.BtnC.wasPressed()) {
      start_sec = millis() / 1000.0;
      accumulate_sec = measure_sec;
      is_measuring = true;
    }
  }

  int x = fmod(measure_sec, 10) / 10 * 320;
  // fmod(x, y)は実数のモジュロ演算。x/yの余り。
  // arduinoでは % は、整数同士でしか使えません。実数のモジュロ演算をしたい場合はfmod関数を使いましょう。

  int y = floor(measure_sec / 10);  // floor(x)は切り捨て

  M5.Lcd.drawRect(x, y * 20 + 40, 1, 18, WHITE);

  M5.Lcd.setCursor(10, 10);
  M5.Lcd.print(measure_sec);
}
