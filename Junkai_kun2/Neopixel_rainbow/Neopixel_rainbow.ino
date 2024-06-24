#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 39

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  rainbow(20);  // 虹色のエフェクトを表示（遅延を20msに設定）
}

// 虹色のエフェクトを生成する関数
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) { // 1周期256ステップ
    for(i=0; i<NUMPIXELS; i++) {
      pixels.setPixelColor(i, Wheel((i+j) & 100));
    }
    pixels.show();
    delay(wait);
  }
}

// 色を生成する関数
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
