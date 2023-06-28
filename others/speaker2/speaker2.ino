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
  int length = sample_rate / float(frequency);
  float term = 1.0 / float(frequency) * 1000.0;
  int rep_count = duration_ms / term;
  // int remains = duration_ms;
  // for (int i = 0; i < duration_ms; i += 200) {
  //   if (remains < 200) {
  //     wave[remains * 999 / 200] = 0;
  //   }
  // M5.Speaker.playMusic(wave, sample_rate);


  // uint32_t length = strlen((char*)wave);
  uint16_t delay_interval = ((uint32_t)1000000 / sample_rate);
  for (int j = 0; j < rep_count; j++) {
    for (int i = 0; i < length; i++) {
      dacWrite(SPEAKER_PIN, wave[i] / 2);
      delayMicroseconds(delay_interval);
    }
  }

  // for (int t = wave[length - 1] / 2; t >= 0; t--) {
  //   dacWrite(SPEAKER_PIN, t);
  //   delay(2);
  // }
  // ledcSetup(TONE_PIN_CHANNEL, 0, 13);
  ledcAttachPin(SPEAKER_PIN, TONE_PIN_CHANNEL);

  //   remains -= 200;
  // }
}

void loop() {
  M5.update();
  playSineWave(400, 2000);
  delay(1000);
}