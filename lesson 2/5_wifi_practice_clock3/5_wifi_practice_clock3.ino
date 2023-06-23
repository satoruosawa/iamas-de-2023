#include <M5Stack.h>
#include <WiFi.h>

const String ssid = "Buffalo-G-8500";
const String password = "55dbda7bfde68";

const String ntp_server = "ntp.nict.jp";

const long gmt_offset_sec = 9 * 3600;
const int daylight_offset_sec = 0;

void setup() {
  M5.begin();

  // WiFi へ接続開始
  WiFi.begin(ssid.c_str(), password.c_str());

  M5.Lcd.setTextSize(2);
  M5.Lcd.print("Connecting to the WiFi AP: " + ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    M5.Lcd.print(".");
  }

  // 接続完了
  M5.Lcd.println(" connected.");
  delay(3000);

  // 時刻を同期
  configTime(gmt_offset_sec, daylight_offset_sec, ntp_server.c_str());

  M5.Lcd.fillScreen(BLACK);
}

void loop() {
  struct tm time_data;
  M5.Lcd.setCursor(0, 50);
  if (!getLocalTime(&time_data)) {
    M5.Lcd.println("Failed to obtain time");
    return;
  }

  int radius = time_data.tm_sec * 2;
  M5.Lcd.drawCircle(160, 120, radius, WHITE);

  if (time_data.tm_sec == 0) {
    M5.Lcd.fillScreen(BLACK);
  }

  delay(100);
}