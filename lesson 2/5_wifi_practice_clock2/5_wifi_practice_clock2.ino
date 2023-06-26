#include <M5Stack.h>
#include <WiFi.h>

String ssid = "iamas-de";
String password = "pass-iamas";

String ntp_server = "ntp.nict.jp";

long gmt_offset_sec = 9 * 3600;
int daylight_offset_sec = 0;

TFT_eSprite img = TFT_eSprite(&M5.Lcd);  // Spriteを定義

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

  img.createSprite(200, 200);  // 200 * 200 ピクセルのキャンバスを作成
  M5.Lcd.fillScreen(BLACK);
}

void loop() {
  struct tm time_data;
  M5.Lcd.setCursor(0, 50);
  if (!getLocalTime(&time_data)) {
    M5.Lcd.println("Failed to obtain time");
    return;
  }

  img.fillSprite(BLACK);

  int center_x = 100;
  int center_y = 100;
  int hh_length = 50;
  int mh_length = 100;
  int sh_length = 100;

  float hh_value = (time_data.tm_hour % 12 + time_data.tm_min / 60.0 + time_data.tm_sec / 3600.0) / 12.0;
  img.drawLine(center_x,
               center_y,
               center_x + hh_length * cos(TWO_PI * hh_value - HALF_PI),
               center_y + hh_length * sin(TWO_PI * hh_value - HALF_PI),
               WHITE);

  float mh_value = (time_data.tm_min + time_data.tm_sec / 60.0) / 60.0;
  img.drawLine(center_x,
               center_y,
               center_x + mh_length * cos(TWO_PI * mh_value - HALF_PI),
               center_y + mh_length * sin(TWO_PI * mh_value - HALF_PI),
               WHITE);

  float sh_value = time_data.tm_sec / 60.0;
  img.drawLine(center_x,
               center_y,
               center_x + sh_length * cos(TWO_PI * sh_value - HALF_PI),
               center_y + sh_length * sin(TWO_PI * sh_value - HALF_PI),
               LIGHTGREY);
  img.pushSprite(60, 20);
}