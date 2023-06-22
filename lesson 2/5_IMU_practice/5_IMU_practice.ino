#include <M5Stack.h>

float x_value = 0.0;
float y_value = 0.0;
float z_value = 0.0;

void setup() {
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(2);
}

void loop() {
  M5.IMU.getAccelData(&x_value, &y_value, &z_value);

  M5.Lcd.fillScreen(BLACK);
  int x = -x_value * 160 + 160;
  int y = y_value * 120 + 120;
  M5.Lcd.fillCircle(x, y, 10, WHITE);

  delay(20);
}