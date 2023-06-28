#include <M5Stack.h>
#include <WiFi.h>
#include <WiFiUDP.h>
#include "Adafruit_MPR121.h"

String ssid = "iamas-de";        // WiFiのSSIDを指定
String password = "pass-iamas";  // WiFiパスワードを指定

// Wi-Fi UDP の設定
WiFiUDP wifi_udp;
String pc_ip = "XXX.XXX.XXX.XXX";  // PCのIPアドレスを指定
int pc_port = 12000;               // 送信先のポート
int m5_port = 12001;               // M5Stackのポート

Adafruit_MPR121 mpr121 = Adafruit_MPR121();  // タッチセンサライブラリを定義

int i2c_address = 0x5A;  // タッチセンサのI2Cアドレスを指定

// タッチセンサから個々のValueを取得する関数を定義しています。
// 以後、getTouchedValue関数を呼び出すこそができます。
bool getTouchedValue(uint16_t touched_data, int pin) {
  return (touched_data & (1 << pin)) != 0;
}

void setup() {
  M5.begin();

  // Wi-Fiの初期化
  WiFi.begin(ssid.c_str(), password.c_str());

  M5.Lcd.setTextSize(2);
  M5.Lcd.print("Connecting to the WiFi AP: " + ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    M5.Lcd.print(".");
  }

  M5.Lcd.println(" connected.");
  delay(1000);

  // タッチセンサの初期化
  if (!mpr121.begin(i2c_address)) {
    M5.Lcd.println("MPR121 is not found.");
    while (1)
      ;
  }

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.println("MPR121 UDP");
}

void loop() {
  // タッチデータを取得
  uint16_t touched_data = mpr121.touched();

  wifi_udp.beginPacket(pc_ip.c_str(), pc_port);
  wifi_udp.print(getTouchedValue(touched_data, 0));
  wifi_udp.print(",");
  wifi_udp.print(getTouchedValue(touched_data, 1));
  wifi_udp.print(",");
  wifi_udp.println(getTouchedValue(touched_data, 2));
  wifi_udp.endPacket();

  delay(10);
}