#include <M5Stack.h>

int flag = 0;

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(WHITE);
}

void loop() {
  switch (flag) {
    case 0:
      M5.Lcd.fillRect(90, 50, 140, 140, CYAN);
      break;
    case 1:
      M5.Lcd.fillRect(90, 50, 140, 140, MAGENTA);
      break;
    case 2:
      M5.Lcd.fillRect(90, 50, 140, 140, YELLOW);
      break;
    default:
      M5.Lcd.fillRect(90, 50, 140, 140, BLACK);
      break;
  }

  flag++;
  flag %= 4;

  delay(1000);
}
