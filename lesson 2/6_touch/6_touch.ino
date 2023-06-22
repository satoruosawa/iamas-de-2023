#include <Wire.h>
#include <M5Stack.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif


// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

bool getSingleStatus(int pin) {
  return (currtouched & _BV(pin)) != 0;
}

void setup() {
  M5.begin();
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1)
      ;
  }
  Serial.println("MPR121 found!");
}

void loop() {
  // Serial.println(cap.readRegister8(0));
  // Get the currently touched pads
  currtouched = cap.touched();

  M5.Lcd.setCursor(0, 10);
  for (int i = 0; i < 12; i++) {
    M5.Lcd.print(i);
    M5.Lcd.print(": ");
    M5.Lcd.println(getSingleStatus(i));
  }

  // put a delay so it isn't overwhelming
  delay(100);
}
