#include <M5Stack.h>

void setup() {
  M5.begin();

  M5.IMU.Init();  // 加速度センサ初期化

  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("Acceleration Serial Sample");
}

void loop() {
  float x_value;
  float y_value;
  float z_value;
  M5.IMU.getAccelData(&x_value, &y_value, &z_value);

  Serial.print(x_value);
  Serial.print(",");
  Serial.print(y_value);
  Serial.print(",");
  Serial.println(z_value);

  delay(20);
}