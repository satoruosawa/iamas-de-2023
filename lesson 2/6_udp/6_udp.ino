#include <M5Stack.h>
#include <WiFi.h>
#include <WiFiUDP.h>

String ssid = "iamas-de";        // WiFiのSSIDを指定
String password = "pass-iamas";  // WiFiパスワードを指定

// Wi-Fi UDP の設定
WiFiUDP wifi_udp;
String pc_ip = "192.168.2.5";  // PCのIPアドレス
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
  delay(3000);  // "connected."を3秒間表示してから画面を消します。
  M5.Lcd.fillScreen(BLACK);

  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("IP Address: ");
  M5.Lcd.println(WiFi.localIP());  // M5StackのIPアドレスを表示

  // Wi-Fi UDP 通信の開始
  wifi_udp.begin(m5_port);
}

void loop() {
  // パケット開始
  wifi_udp.beginPacket(pc_ip.c_str(), pc_port);
  wifi_udp.print(number);      // UDP通信でnumberのデータをPCへ送信
  wifi_udp.print(",");         // UDP通信で "," をPCへ送信
  wifi_udp.println(random());  // UDP通信で乱数をPCへ送信
  wifi_udp.endPacket();
  // パケット終了

  number++;

  delay(1000);
}