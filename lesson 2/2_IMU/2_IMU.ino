#include <M5Stack.h>

void setup() {
  M5.begin();

  M5.IMU.Init();  // 加速度センサー(IMU)を初期化

  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("Acceleration Sensor Sample");
}

void loop() {
  // 加速度センサーのデータを取得するための変数を定義
  float x_value = 0.0;
  float y_value = 0.0;
  float z_value = 0.0;

  // 加速度センサーの値を取得
  // 引数の頭に&をつけて渡すことを、ポインタ渡しと言います。
  M5.IMU.getAccelData(&x_value, &y_value, &z_value);

  M5.Lcd.setCursor(0, 50);
  M5.Lcd.print("X: ");
  M5.Lcd.print(x_value);
  M5.Lcd.println("      ");
  M5.Lcd.print("Y: ");
  M5.Lcd.print(y_value);
  M5.Lcd.println("      ");
  M5.Lcd.print("Z: ");
  M5.Lcd.print(z_value);
  M5.Lcd.print("      ");

  delay(100);
}