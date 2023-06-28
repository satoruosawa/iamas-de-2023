#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Speaker.begin();
  M5.Speaker.setVolume(10);  // スピーカーのボリュームを設定 初期値は8で、範囲は 0 ~ 10
}

void playSineWave(uint16_t frequency, uint32_t duration_ms) {
  uint8_t wave[1000];
  float sample_rate = 20000.0;
  float delta_phase = TWO_PI / sample_rate * float(frequency);
  for (int i = 0; i < 1000; i++) {
    float phase = delta_phase * i;
    wave[i] = 127 - 126 * cos(phase);
  }
  wave[999] = 0;
  int remains = duration_ms;
  for (int i = 0; i < duration_ms; i += 200) {
    if (remains < 200) {
      wave[remains * 999 / 200] = 0;
    }
    M5.Speaker.playMusic(wave, sample_rate);
    remains -= 200;
  }
}

void loop() {
  M5.update();
  playSineWave(2000, 400);
  delay(1000);
}