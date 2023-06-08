#include <M5Stack.h>

bool flag = true;  // flagという名前の真偽値をグローバル領域に宣言

void setup() {
  M5.begin();
}

void loop() {
  if (flag) {                                // flagの値で判定
    M5.Lcd.fillRect(90, 50, 140, 140, RED);  // flagがtrueの場合の処理
  } else {
    M5.Lcd.fillRect(90, 50, 140, 140, BLUE);  // flagがfalseの場合の処理
  }
  flag = !flag;
  delay(1000);
}