#include <M5Stack.h>

// ジョイスティックのI2Cアドレスを指定
// 0xは16進数表記
int i2c_address = 0x52;

void setup() {
  M5.begin();

  Wire.begin();  // マスターとしてI2C通信を開始

  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("Joystick Serial Sample");
}

void loop() {
  // 3バイトのデータをJOYSTICKデバイスにリクエスト
  Wire.requestFrom(i2c_address, 3);

  if (Wire.available()) {  // スレーブからデータが返ってきた場合の分岐
    int x_value = Wire.read();
    int y_value = Wire.read();
    int button_value = Wire.read();

    Serial.print(x_value);
    Serial.print(",");
    Serial.print(y_value);
    Serial.print(",");
    Serial.println(button_value);
  }

  delay(10);
}