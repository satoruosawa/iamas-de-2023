#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.IMU.Init();
}

void loop() {
  float x_value;
  float y_value;
  float z_value;
  M5.IMU.getAccelData(&x_value, &y_value, &z_value);

  M5.Lcd.fillScreen(BLACK);
  int x = -x_value * 160 + 160;
  int y = y_value * 120 + 120;
  M5.Lcd.fillCircle(x, y, 10, WHITE);

  Serial.print(x_value);
  Serial.print(",");
  Serial.print(y_value);
  Serial.print(",");
  Serial.println(z_value);
  
  delay(20);
}