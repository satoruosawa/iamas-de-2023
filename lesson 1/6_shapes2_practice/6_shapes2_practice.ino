#include <M5Stack.h>

int flag = 0;

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(WHITE);
}

void loop() {
  if (flag == 0) {
    M5.Lcd.fillRect(90, 50, 140, 140, CYAN);
    flag = 1;
  } else if (flag == 1) {
    M5.Lcd.fillRect(90, 50, 140, 140, MAGENTA);
    flag = 2;
  } else if (flag == 2) {
    M5.Lcd.fillRect(90, 50, 140, 140, YELLOW);
    flag = 3;
  } else {
    M5.Lcd.fillRect(90, 50, 140, 140, BLACK);
    flag = 0;
  }

  delay(1000);
}
