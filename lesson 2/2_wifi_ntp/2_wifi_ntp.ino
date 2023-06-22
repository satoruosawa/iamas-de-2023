#include <M5Stack.h>
#include <WiFi.h>

const String ssid = "Buffalo-G-8500";     // XXXX部分を各自利用可能なWiFiのSSIDに変更
const String password = "55dbda7bfde68";  // XXXX部分を各自利用可能なWiFiのWiFiパスワードに変更
const String ntp_server = "ntp.nict.jp";  // NTPサーバーのアドレス

const long gmt_offset_sec = 9 * 3600;  // +9hours
const int daylight_offset_sec = 0;     // summer time offset

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

  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("IP address: ");
  M5.Lcd.println(WiFi.localIP());  // M5StackのIPアドレスを表示

  configTime(gmt_offset_sec, daylight_offset_sec,
             ntp_server.c_str());  // 時刻を同期
}

void loop() {
  // このパートでは、time_dataを取得しています。
  // struct tm に関しては特に理解する必要はありませんが、time_dataのあ使い方だけ知っておいてください。
  // 例えば、time_data.tm_hourでint型の時刻、time_data.tm_minでint型の分が取得できます。
  struct tm time_data;
  if (!getLocalTime(&time_data)) {
    M5.Lcd.setCursor(0, 50);
    M5.Lcd.println("Failed to obtain time");
    return;
  }
  // ここまでで、time_dataの取得が完了


  // ここからtime_dataの値を表示します。
  M5.Lcd.setCursor(0, 50);
  M5.Lcd.println(
    String(time_data.tm_year + 1900) + "/" + String(time_data.tm_mon + 1) + "/"
    + String(time_data.tm_mday) + " " + String(time_data.tm_hour) + ":"
    + String(time_data.tm_min) + ":" + String(time_data.tm_sec) + "   ");
  delay(100);
}