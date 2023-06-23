#include <WiFi.h>
#include <WiFiUDP.h>
#include <M5Stack.h>

String ssid = "Buffalo-G-8500";
String password = "55dbda7bfde68";

WiFiUDP wifi_udp;
String pc_ip = "192.168.1.7";
int pc_port = 12000;
int m5_port = 12001;

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

  wifi_udp.begin(m5_port);
}

void loop() {
  M5.update();

  int button_a = M5.BtnA.isPressed();
  int button_b = M5.BtnB.isPressed();
  int button_c = M5.BtnC.isPressed();

  // データ送信
  wifi_udp.beginPacket(pc_ip.c_str(), pc_port);
  wifi_udp.print(button_a);
  wifi_udp.print(",");
  wifi_udp.print(button_b);
  wifi_udp.print(",");
  wifi_udp.println(button_c);
  wifi_udp.endPacket();

  delay(100);
}