#include <M5Stack.h>

// ジョイスティックのI2Cアドレスを指定
// 0xは16進数表記
int i2c_address = 0x52;

int x_value;
int y_value;
int button_value;

void setup() {
  M5.begin();

  Wire.begin();  // マスターとしてI2C通信を開始

  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("Joystick Sample");
}

void loop() {
  // 3バイトのデータをJOYSTICKデバイスにリクエスト
  Wire.requestFrom(i2c_address, 3);

  if (Wire.available()) {  // スレーブからデータが帰ってきた場合の分岐
    x_value = Wire.read();
    y_value = Wire.read();
    button_value = Wire.read();

    M5.Lcd.setCursor(0, 50);
    M5.Lcd.print("X: ");
    M5.Lcd.print(x_value);
    M5.Lcd.println("      ");
    M5.Lcd.print("Y: ");
    M5.Lcd.print(y_value);
    M5.Lcd.println("      ");
    M5.Lcd.print("B: ");
    M5.Lcd.println(button_value);
    M5.Lcd.print("      ");
  }

  delay(10);
}