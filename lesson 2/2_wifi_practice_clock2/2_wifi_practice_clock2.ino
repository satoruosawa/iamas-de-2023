#include <M5Stack.h>
#include <WiFi.h>

const String ssid = "Buffalo-G-8500";
const String password = "55dbda7bfde68";
const String ntp_server = "ntp.nict.jp";

const long gmt_offset_sec = 9 * 3600;
const int daylight_offset_sec = 0;

TFT_eSprite img = TFT_eSprite(&M5.Lcd);

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

  configTime(gmt_offset_sec, daylight_offset_sec,
             ntp_server.c_str());  // 時刻を同期

  M5.Lcd.fillScreen(BLACK);
  img.createSprite(200, 200);  // 200 * 200 ピクセルのキャンバスを作成
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
               center_x + hh_length * cos(TWO_PI * hh_value - PI / 2),
               center_y + hh_length * sin(TWO_PI * hh_value - PI / 2),
               WHITE);

  float mh_value = (time_data.tm_min + time_data.tm_sec / 60.0) / 60.0;
  img.drawLine(center_x,
               center_y,
               center_x + mh_length * cos(TWO_PI * mh_value - PI / 2),
               center_y + mh_length * sin(TWO_PI * mh_value - PI / 2),
               WHITE);

  float sh_value = time_data.tm_sec / 60.0;
  img.drawLine(center_x,
               center_y,
               center_x + sh_length * cos(TWO_PI * sh_value - PI / 2),
               center_y + sh_length * sin(TWO_PI * sh_value - PI / 2),
               WHITE);
  img.pushSprite(60, 20);
}