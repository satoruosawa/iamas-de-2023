#include <M5Stack.h>

void setup() {
  M5.begin();
}

void loop() {
  M5.update();

  int button_a = M5.BtnA.isPressed();
  int button_b = M5.BtnB.isPressed();
  int button_c = M5.BtnC.isPressed();

  Serial.print(button_a);
  Serial.print(",");
  Serial.print(button_b);
  Serial.print(",");
  Serial.println(button_c);

  // ボタンA（左のボタン）の処理
  if (M5.BtnA.wasPressed()) {
    M5.Lcd.fillRect(0, 0, 100, 240, WHITE);
  }
  if (M5.BtnA.wasReleased()) {
    M5.Lcd.fillRect(0, 0, 100, 240, BLACK);
  }

  // ボタンB（真ん中のボタン）の処理
  if (M5.BtnB.wasPressed()) {
    M5.Lcd.fillRect(110, 0, 100, 240, WHITE);
  }
  if (M5.BtnB.wasReleased()) {
    M5.Lcd.fillRect(110, 0, 100, 240, BLACK);
  }

  // ボタンC（右のボタン）の処理
  if (M5.BtnC.wasPressed()) {
    M5.Lcd.fillRect(220, 0, 100, 240, WHITE);
  }
  if (M5.BtnC.wasReleased()) {
    M5.Lcd.fillRect(220, 0, 100, 240, BLACK);
  }
  
  delay(100);
}