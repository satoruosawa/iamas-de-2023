#include <M5Stack.h>

int number = 0;

void setup() {
  // M5.begin関数の中でSerial.begin関数が呼ばれています。
  // ボーレートは115200です。
  M5.begin();

  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("Serial Sample");
}

void loop() {
  Serial.println(number);  // シリアル通信で文字列をPCへ送信
  number++;
  delay(1000);
}
