#include <M5Stack.h>  // M5Stackライブラリを読み込む
 
void setup() {
  // setupの中は、最初に一度だけ処理される

  M5.begin();  // M5Stackライブラリの初期化

  M5.Lcd.setTextSize(3);           // テキストのサイズを指定、初期値は1
  M5.Lcd.setCursor(60, 100);         // カーソルの位置(x,y)を指定、初期値は(0,0)
  M5.Lcd.print("Hello IAMAS.");  // 文字列を表示
  M5.Lcd.println("Hello IAMAS.");  // 文字列を表示
}

void loop() {
  // loopの中は、setupの後に繰り返し処理される
}