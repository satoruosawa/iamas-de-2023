#include <M5Stack.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 mpr121 = Adafruit_MPR121();  // タッチセンサライブラリを定義

int i2c_address = 0x5A;  // タッチセンサのI2Cアドレスを指定

// タッチセンサから個々のValueを取得する関数を定義しています。
// 以後、getTouchedValue関数を呼び出すこそができます。
bool getTouchedValue(uint16_t touched_data, int pin) {
  return (touched_data & (1 << pin)) != 0;
}

uint16_t getColor(uint8_t red, uint8_t green, uint8_t blue){
  return ((red>>3)<<11) | ((green>>2)<<5) | (blue>>3);
}

void setup() {
  M5.begin();

  M5.Lcd.setTextSize(2);
  if (!mpr121.begin(i2c_address)) {
    M5.Lcd.println("MPR121 is not found.");
    while (1)
      ;
  }

  M5.Speaker.setVolume(3);  // スピーカーのボリュームを設定 初期値は8で、範囲は 0 ~ 10
}

void loop() {
  M5.update();  // ボタンかスピーカーを使うときは、この行を追加
  // タッチデータを取得
  uint16_t touched_data = mpr121.touched();

  M5.Lcd.setCursor(0, 30);
  for (int i = 0; i < 3; i++) {
    // touched_dataから、個々のValueを取得
    int y = i * 75 + 15;
    for (int j = 0; j < 3; j++) {
      int x = j * 100 + 20;
      int pin_index = j + i * 3;
      bool touched_value = getTouchedValue(touched_data, pin_index);
      int freq = 100 + pin_index * 100;
      if (touched_value) {
        M5.Speaker.tone(freq, 40);  // 3135Hzの音を40ミリ秒再生
        M5.Lcd.fillRect(x, y, 80, 60, WHITE);
      } else {
        M5.Lcd.fillRect(x, y, 80, 60, getColor(50,50,50));
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    // touched_dataから、個々のValueを取得
    bool touched_value = getTouchedValue(touched_data, i);
    if (i != 0) {
      Serial.print(",");
    }
    Serial.print(touched_value);
  }
  Serial.println();

  // delay(10);
}