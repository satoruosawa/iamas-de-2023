#include <WiFi.h>
#include <WiFiUDP.h>
#include <M5Stack.h>

String ssid = "Buffalo-G-8500";     // WiFiのSSIDを指定
String password = "55dbda7bfde68";  // WiFiパスワードを指定

// Wi-Fi UDP の設定
WiFiUDP wifi_udp;
String pc_ip = "192.168.1.7";  // PCのIPアドレス
int pc_port = 12000;           // 送信先のポート
int m5_port = 12001;           // M5Stackのポート

int number = 0;

void setup() {
  M5.begin();

  WiFi.begin(ssid.c_str(), password.c_str());

  M5.Lcd.setTextSize(2);
  M5.Lcd.print("Connecting to the WiFi AP: " + ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    M5.Lcd.print(".");
  }

  M5.Lcd.println(" connected.");

  // Wi-Fi UDP へ接続開始
  wifi_udp.begin(m5_port);
}

void loop() {
  // パケット開始
  wifi_udp.beginPacket(pc_ip.c_str(), pc_port);
  wifi_udp.println(number);  // udp通信で文字列をPCへ送信
  wifi_udp.endPacket();
  // パケット終了

  number = number + 1;
  delay(1000);
}