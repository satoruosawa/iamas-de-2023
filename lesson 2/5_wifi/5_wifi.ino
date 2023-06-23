#include <M5Stack.h>
#include <WiFi.h>

// Wi-Fiの設定
String ssid = "Buffalo-G-8500";     // WiFiのSSIDを指定
String password = "55dbda7bfde68";  // WiFiパスワードを指定

void setup() {
  M5.begin();

  // WiFi へ接続開始
  // WiFi.begin関数は第一引数がSSID, 第二引数がパスワードを取ります。
  // c_str()はStringからC言語スタイルの文字配列を取得する関数です。
  WiFi.begin(ssid.c_str(), password.c_str());

  M5.Lcd.setTextSize(2);
  M5.Lcd.print("Connecting to the WiFi AP: " + ssid);

  while (WiFi.status() != WL_CONNECTED) {
    // 接続完了までループ
    delay(500);
    M5.Lcd.print(".");
  }

  // ループを抜けたということは、接続完了を意味します。
  M5.Lcd.println(" connected.");
  delay(3000);  // "connected."を3秒間表示してから画面を消します。

  M5.Lcd.fillScreen(BLACK);

  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("IP Address: ");
  M5.Lcd.println(WiFi.localIP());  // M5StackのIPアドレスを表示
}

void loop() {}