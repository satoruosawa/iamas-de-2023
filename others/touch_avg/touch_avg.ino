#include <M5Stack.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 mpr121 = Adafruit_MPR121();  // タッチセンサライブラリを定義

int i2c_address = 0x5A;  // タッチセンサのI2Cアドレスを指定

float avg_value;         // 指数移動平均の計算結果
float avg_alpha = 0.01;  // 平滑化係数

unsigned long serial_interval = 100;
unsigned long last_serial = 0;


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

  // Serialプロッターの横軸幅が短いため、0.1秒ごとにSerialを送信しています。
  if (millis() > last_serial + serial_interval) {
    Serial.print(avg_value);
    Serial.print(",");
    Serial.println(50);  // グラフの最小値設定のために追加
    last_serial += serial_interval;
  }
}
