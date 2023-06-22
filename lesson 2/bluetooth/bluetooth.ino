#include "BluetoothSerial.h"
#include <M5Stack.h>

BluetoothSerial SerialBT;
int number = 0;

void setup() {
  M5.begin();
  SerialBT.begin("M5StackSample");  // デバイス名を設定します。自分が分かる名前に変更しましょう。
}

void loop() {
  SerialBT.println(number);
  number = number + 1;
  delay(1000);
}