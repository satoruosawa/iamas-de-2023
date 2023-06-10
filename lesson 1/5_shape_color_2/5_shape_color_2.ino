#include <M5Stack.h>

int flag = 0;  // flagという名前の整数値をグローバル領域に宣言

void setup() {
  M5.begin();
}

void loop() {
  if (flag == 0) {                           // flagの値で判定
    M5.Lcd.fillRect(90, 50, 140, 140, RED);  // flagが0の場合の処理
    flag = 1;
  } else if (flag == 1) {                      // flagの値で判定
    M5.Lcd.fillRect(90, 50, 140, 140, GREEN);  // flagが1の場合の処理
    flag = 2;
  } else {
    M5.Lcd.fillRect(90, 50, 140, 140, BLUE);  // flagが0と1以外の場合(2の場合)の処理
    flag = 0;
  }
  delay(1000);
}