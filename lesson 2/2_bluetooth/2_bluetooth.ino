#include "BluetoothSerial.h"
#include <M5Stack.h>

BluetoothSerial SerialBT;
int number = 0;

void setup() {
  M5.Lcd.begin();
  SerialBT.begin("ESP32test");

  M5.Lcd.println("Done");
}

void loop() {
  // if (Serial.available()) {
  //   String sendData = Serial.readStringUntil(';');
  //   SerialBT.print(sendData);
  // }

  // if (SerialBT.available()) {
  //   String receiveData = SerialBT.readStringUntil(';');
  //   Serial.print(receiveData);
  // }

  SerialBT.println(number);  // シリアル通信で文字列をPCへ送信
  number = number + 1;
  M5.Lcd.setCursor(0, 30);
  M5.Lcd.print("Loop");
  M5.Lcd.println(number);
  delay(1000);
}
