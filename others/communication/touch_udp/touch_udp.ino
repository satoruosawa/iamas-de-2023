#include <M5Stack.h>
#include <WiFi.h>
#include <WiFiUDP.h>
#include "Adafruit_MPR121.h"

String ssid = "iamas-de";        // WiFiのSSIDを指定
String password = "pass-iamas";  // WiFiパスワードを指定

// Wi-Fi UDP の設定
WiFiUDP wifi_udp;
String pc_ip = "XXX.XXX.XXX.XXX";  // 送信先PCのIPアドレスを指定
int pc_port = 12000;  // 送信先PCのポート
int m5_port = 12001;  // M5Stackのポート

Adafruit_MPR121 mpr121 = Adafruit_MPR121();  // タッチセンサライブラリを定義
int i2c_address = 0x5A;                      // タッチセンサのI2Cアドレスを指定

// タッチセンサから個々のValueを取得する関数を定義しています。
// 以後、getTouchedValue関数を呼び出すこそができます。
bool getTouchedValue(uint16_t touched_data, int pin) {
  return (touched_data & (1 << pin)) != 0;
}

void setup() {
  M5.begin();

  // Wi-Fiへ接続開始
  WiFi.begin(ssid.c_str(), password.c_str());

  M5.Lcd.setTextSize(2);
  M5.Lcd.print("Connecting to the WiFi AP: " + ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    M5.Lcd.print(".");
  }

  M5.Lcd.println(" connected.");
  delay(3000);  // "connected."を3秒間表示してから画面を消します。
  M5.Lcd.fillScreen(BLACK);
  // Wi-Fiへ接続完了

  // Touchセンサ初期化開始
  if (!mpr121.begin(i2c_address)) {
    M5.Lcd.println("MPR121 is not found.");
    while (1)
      ;
  }
  // Touchセンサ初期化完了

  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("Touch Wi-Fi UDP Sample");

  // Wi-Fi UDP 通信の開始
  wifi_udp.begin(m5_port);
}

void loop() {
  // タッチデータを取得
  uint16_t touched_data = mpr121.touched();


  wifi_udp.beginPacket(pc_ip.c_str(), pc_port);
  for (int i = 0; i < 12; i++) {
    // touched_dataから、個々のValueを取得
    bool touched_value = getTouchedValue(touched_data, i);

    if (i != 0) {
      wifi_udp.print(",");
    }
    wifi_udp.print(touched_value);
  }
  wifi_udp.println();
  wifi_udp.endPacket();

  delay(20);
}