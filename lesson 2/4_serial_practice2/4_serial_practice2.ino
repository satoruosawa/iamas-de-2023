#include <M5Stack.h>

TFT_eSprite img = TFT_eSprite(&M5.Lcd);  // Spriteを定義

void setup() {
  M5.begin();
  M5.IMU.Init();

  img.setColorDepth(8);  // ColorDepthを指定しないと表示されないことがあるようです。
  img.createSprite(320, 240);
}

void loop() {
  float x_value;
  float y_value;
  float z_value;
  M5.IMU.getAccelData(&x_value, &y_value, &z_value);

  img.fillSprite(BLACK);
  int x = -x_value * 160 + 160;
  int y = y_value * 120 + 120;
  img.fillCircle(x, y, 10, WHITE);

  img.pushSprite(0, 0);

  Serial.print(x_value);
  Serial.print(",");
  Serial.print(y_value);
  Serial.print(",");
  Serial.println(z_value);

  delay(20);
}