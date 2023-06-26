#include <M5Stack.h>
#include "Adafruit_MPR121.h"

Adafruit_MPR121 mpr121 = Adafruit_MPR121();

int i2c_address = 0x5A;  // タッチセンサのI2Cアドレスを指定

bool getTouchedValue(uint16_t touched_data, int pin) {
  return (touched_data & (1 << pin)) != 0;
}

void setup() {
  M5.begin();

  M5.Lcd.setTextSize(2);
  if (!mpr121.begin(i2c_address)) {
    M5.Lcd.println("MPR121 is not found.");
    while (true) {}
  }
}

void loop() {
  uint16_t touched_data = mpr121.touched();

  for (int i = 0; i < 12; i++) {
    if (getTouchedValue(touched_data, i)) {
      M5.Lcd.fillRect(i * 26, 0, 25, 240, WHITE);
    } else {
      M5.Lcd.fillRect(i * 26, 0, 25, 240, BLACK);
    }
  }

  delay(100);
}
