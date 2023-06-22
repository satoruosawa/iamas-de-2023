#include <M5Stack.h>

float x_value = 0.0;
float y_value = 0.0;
float z_value = 0.0;

void setup() {
  M5.begin();
  M5.IMU.Init();  // 加速度センサー(IMU)を初期化
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(2);
}

void loop() {
  M5.IMU.getAccelData(&x_value, &y_value, &z_value);  //　加速度センサーの値を取得

  M5.Lcd.setCursor(100, 50);
  M5.Lcd.print("X:");
  M5.Lcd.print(x_value);
  M5.Lcd.print("      ");
  M5.Lcd.setCursor(100, 80);
  M5.Lcd.print("Y:");
  M5.Lcd.print(y_value);
  M5.Lcd.print("      ");
  M5.Lcd.setCursor(100, 110);
  M5.Lcd.print("Z:");
  M5.Lcd.print(z_value);
  M5.Lcd.print("      ");

  delay(100);
}