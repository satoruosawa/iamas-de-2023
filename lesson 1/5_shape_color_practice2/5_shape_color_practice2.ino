#include <M5Stack.h>

int flag = 0;  // flagという名前の真偽値をグローバル領域に宣言

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(WHITE);
}

void loop() {
  if (flag == 0) {
    M5.Lcd.fillRect(90, 50, 140, 140, CYAN);
  } else if (flag == 1) {
    M5.Lcd.fillRect(90, 50, 140, 140, MAGENTA);
  } else if (flag == 2) {
    M5.Lcd.fillRect(90, 50, 140, 140, YELLOW);
  } else {
    M5.Lcd.fillRect(90, 50, 140, 140, BLACK);
  }

  flag++;
  flag %= 4;

  delay(1000);
}
