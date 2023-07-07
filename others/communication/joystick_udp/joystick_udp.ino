#include <M5Stack.h>
#include <WiFi.h>
#include <WiFiUDP.h>

String ssid = "iamas-de";        // WiFiのSSIDを指定
String password = "pass-iamas";  // WiFiパスワードを指定

// Wi-Fi UDP の設定
WiFiUDP wifi_udp;
String pc_ip = "XXX.XXX.XXX.XXX";  // 送信先PCのIPアドレスを指定
int pc_port = 12000;  // 送信先PCのポート
int m5_port = 12001;  // M5Stackのポート

int i2c_address = 0x52;  // ジョイスティックのI2Cアドレスを指定

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

  Wire.begin();  // マスターとしてI2C通信を開始

  M5.Lcd.setCursor(0, 10);
  M5.Lcd.println("Joystick Wi-Fi UDP Sample");

  // Wi-Fi UDP 通信の開始
  wifi_udp.begin(m5_port);
}

void loop() {
  Wire.requestFrom(i2c_address, 3);

  if (Wire.available()) {  // スレーブからデータが返ってきた場合の分岐
    int x_value = Wire.read();
    int y_value = Wire.read();
    int button_value = Wire.read();

    wifi_udp.beginPacket(pc_ip.c_str(), pc_port);
    wifi_udp.print(x_value);
    wifi_udp.print(",");
    wifi_udp.print(y_value);
    wifi_udp.print(",");
    wifi_udp.println(button_value);
    wifi_udp.endPacket();
  }

  delay(20);
}