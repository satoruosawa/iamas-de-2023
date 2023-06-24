#include <M5Stack.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 mpr121 = Adafruit_MPR121();  // タッチセンサライブラリを定義

int i2c_address = 0x5A;  // タッチセンサのI2Cアドレスを指定

// タッチセンサから個々のValueを取得する関数を定義しています。
// 以後、getTouchedValue関数を呼び出すこそができます。
bool getTouchedValue(uint16_t touched_data, int pin) {
  return (touched_data & (1 << pin)) != 0;
}

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
}

void loop() {
  // タッチデータを取得
  uint16_t touched_data = mpr121.touched();

  M5.Lcd.setCursor(0, 30);
  for (int i = 0; i < 12; i++) {
    // touched_dataから、個々のValueを取得
    bool touched_value = getTouchedValue(touched_data, i);

    M5.Lcd.print(i);
    M5.Lcd.print(": ");
    M5.Lcd.println(touched_value);
  }

  delay(100);
}
