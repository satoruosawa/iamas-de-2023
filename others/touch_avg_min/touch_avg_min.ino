#include <M5Stack.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 mpr121 = Adafruit_MPR121();  // タッチセンサライブラリを定義

int i2c_address = 0x5A;  // タッチセンサのI2Cアドレスを指定

float avg_value;         // 指数移動平均の計算結果
float avg_alpha = 0.01;  // 平滑化係数

void setup() {
  M5.begin();

  M5.Lcd.setTextSize(2);

  if (!mpr121.begin(i2c_address)) {
    M5.Lcd.println("MPR121 is not found.");
    while (1)
      ;
  }

  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println("MPR121 Sample");
  avg_value = mpr121.filteredData(0);
}

void loop() {
  float value = (float)mpr121.filteredData(0);                  // 現在の値
  avg_value = avg_alpha * value + (1 - avg_alpha) * avg_value;  // 指数移動平均の計算
  Serial.println(avg_value);
}
