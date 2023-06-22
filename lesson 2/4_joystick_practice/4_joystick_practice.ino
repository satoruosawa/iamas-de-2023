#include <M5Stack.h>

#define ADDRESS 0x52  // ジョイスティックのI2Cアドレスを定義

int x_data;
int y_data;
int button_data;

void setup() {
  M5.begin();
  Wire.begin();  // マスターとしてI2C通信を開始
  M5.Lcd.setCursor(70, 0, 4);
  M5.Lcd.println("Joystick Sample");
}

void loop() {
  // 3バイトのデータをスレーブデバイスにリクエスト
  Wire.requestFrom(ADDRESS, 3);
  if (Wire.available()) {  // スレーブからデータが帰ってきた場合の分岐
    x_data = Wire.read();
    y_data = Wire.read();
    button_data = Wire.read();

    M5.Lcd.fillScreen(BLACK);
    int x = -(x_data - 128) + 160;
    int y = y_data - 128 + 120;
    M5.Lcd.fillCircle(x, y, 10, WHITE);
  }
  delay(10);
}