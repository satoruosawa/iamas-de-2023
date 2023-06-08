#include <M5Stack.h>

bool button_a_flag = false;
bool button_b_flag = false;
bool button_c_flag = false;

void setup() {
  M5.begin();
}

void loop() {
  M5.update();  // buttonを使うときはこの行を追加

  // ボタンAの処理
  if (M5.BtnA.wasPressed()) {
    button_a_flag = !button_a_flag;
    if (button_a_flag) {
      M5.Lcd.fillRect(0, 0, 100, 240, WHITE);
    } else {
      M5.Lcd.fillRect(0, 0, 100, 240, BLACK);
    }
  }

  // ボタンBの処理
  if (M5.BtnB.wasPressed()) {
    button_b_flag = !button_b_flag;
    if (button_b_flag) {
      M5.Lcd.fillRect(110, 0, 100, 240, WHITE);
    } else {
      M5.Lcd.fillRect(110, 0, 100, 240, BLACK);
    }
  }

  // ボタンCの処理
  if (M5.BtnC.wasPressed()) {
    button_c_flag = !button_c_flag;
    if (button_c_flag) {
      M5.Lcd.fillRect(220, 0, 100, 240, WHITE);
    } else {
      M5.Lcd.fillRect(220, 0, 100, 240, BLACK);
    }
  }
  delay(100);
}
