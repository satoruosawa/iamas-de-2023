#include <M5Stack.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 mpr121 = Adafruit_MPR121();  // タッチセンサライブラリを定義
int i2c_address = 0x5A;                      // タッチセンサのI2Cアドレスを指定

// タッチセンサから個々のValueを取得する関数を定義しています。
// 以後、getTouchedValue関数を呼び出すこそができます。
bool getTouchedValue(uint16_t touched_data, int pin) {
  return (touched_data & (1 << pin)) != 0;
}

void setup() {
  M5.begin();

  M5.Lcd.setTextSize(2);

  // Touchセンサ初期化開始
  if (!mpr121.begin(i2c_address)) {
    M5.Lcd.println("MPR121 is not found.");
    while (1)
      ;
  }
  // Touchセンサ初期化完了

  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("Touch Serial Sample");
}

void loop() {
  // タッチデータを取得
  uint16_t touched_data = mpr121.touched();

  for (int i = 0; i < 12; i++) {
    // touched_dataから、個々のValueを取得
    bool touched_value = getTouchedValue(touched_data, i);

    if (i != 0) {
      Serial.print(",");
    }
    Serial.print(touched_value);
  }
  Serial.println();

  delay(100);
}