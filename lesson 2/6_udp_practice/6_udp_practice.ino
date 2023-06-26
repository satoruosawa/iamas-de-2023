#include <WiFi.h>
#include <WiFiUDP.h>
#include <M5Stack.h>

String ssid = "Buffalo-G-8500";
String password = "55dbda7bfde68";

WiFiUDP wifi_udp;
String pc_ip = "192.168.1.7";
int pc_port = 12000;
int m5_port = 12001;

int i2c_address = 0x52;

void setup() {
  M5.begin();

  Wire.begin();  // マスターとしてI2C通信を開始
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
  Wire.requestFrom(i2c_address, 3);


  if (Wire.available()) {
    int x_value = Wire.read();
    int y_value = Wire.read();
    int button_value = Wire.read();

    M5.Lcd.fillScreen(BLACK);

    int x = -(x_value - 128) + 160;
    int y = y_value - 128 + 120;
    M5.Lcd.fillCircle(x, y, 10, WHITE);

    wifi_udp.beginPacket(pc_ip.c_str(), pc_port);
    wifi_udp.print(x_value);
    wifi_udp.print(",");
    wifi_udp.print(y_value);
    wifi_udp.print(",");
    wifi_udp.println(button_value);
    wifi_udp.endPacket();
  }

  delay(10);
}