#include <M5Stack.h>

int i2c_address = 0x52;

void setup() {
  M5.begin();
  Wire.begin();
}

void loop() {
  Wire.requestFrom(i2c_address, 3);

  if (Wire.available()) { 
    int x_value = Wire.read();
    int y_value = Wire.read();

    M5.Lcd.fillScreen(BLACK);
    
    int x = -(x_value - 128) + 160;
    int y = y_value - 128 + 120;
    M5.Lcd.fillCircle(x, y, 10, WHITE);
  }

  delay(10);
}