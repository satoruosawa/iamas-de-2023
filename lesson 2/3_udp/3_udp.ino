#include <WiFi.h>
#include <WiFiUDP.h>
#include <M5Stack.h>

const String ssid = "Buffalo-G-8500";     // WiFiのSSIDを設定
const String password = "55dbda7bfde68";  // WiFiパスワードに変更

WiFiUDP wifiUdp;
String pc_ip = "192.168.1.7";  // PCのIPアドレス
int pc_port = 12000;           // 送信先のポート
int m5_port = 12001;           // M5Stackのポート

int number = 0;

void setup() {
  M5.begin();
  M5.Power.begin();
  M5.Lcd.setTextSize(2);

  WiFi.begin(ssid.c_str(), password.c_str());
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    M5.Lcd.print(".");
  }
  M5.Lcd.println("WiFi connected");
  M5.Lcd.print("IP address = ");
  M5.Lcd.println(WiFi.localIP());

  wifiUdp.begin(m5_port);
}

void loop() {
  wifiUdp.beginPacket(pc_ip.c_str(), pc_port);
  wifiUdp.println(number);  // udp通信で文字列をPCへ送信
  wifiUdp.endPacket();
  number = number + 1;
  delay(1000);
}