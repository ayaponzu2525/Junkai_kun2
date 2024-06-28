#include <SPI.h>
#include <SPI_NeoPixel.h>
//https://github.com/lipoyang/SPI_NeoPixel

const uint16_t NUM_PIXELS = 39;
//spiの送信のピン　= 11

SPI_NeoPixel neopixel(NUM_PIXELS);

int rightturn_sig[] = {4,5,6,7,8,9,10,11,12};  // 同時に点滅させるLEDのインデックスの配列（右）
int rightturn_leds = sizeof(rightturn_sig) / sizeof(rightturn_sig[0]);  // 配列の要素数を計算
int leftturn_sig[] = {25,26,27,28,29,30,31,32}; // 同時に点滅させるLEDのインデックスの配列（左）
int leftturn_leds = sizeof(leftturn_sig) / sizeof(leftturn_sig[0]);  // 配列の要素数を計算

void setup(){

    Serial.begin(115200);
    delay(1000);

    neopixel.begin();

    Serial.println("Serial console start!");
}

void loop(){
  for (int i=0; i<10; i++){
    neopixel.setPixelColor(i, 0x00FF00);
    delay(10);
    neopixel.show();
  }

  clearPixels(0,39);
  
  for (int i=0; i<3; i++){
    turn_signal(rightturn_sig, rightturn_leds, 0xFF0000, 500);  // 同時に点滅させるLEDを赤で点滅させる
    
  }

  for (int i=0; i<3; i++){
    turn_signal(leftturn_sig, leftturn_leds, 0x00FF00, 500);  // 同時に点滅させるLEDを緑で点滅させる
  }

  // LED_in_order(0, 10, 0xDD0000, 500);  // 左端から10番目のLEDを赤で点滅させる
  // delay(1000);  // 1秒待機

  //rainbowCycle(10, 128); // 虹色サイクルを10回繰り返し、最大の明るさを128に設定する
}

// 特定のLEDを点灯させる関数
void setPixelColor(int pixelIndex, uint32_t color) {
    if (pixelIndex >= 0 && pixelIndex < NUM_PIXELS) {
        neopixel.setPixelColor(pixelIndex, color);
        neopixel.show();
    }
}

// 順番に１つずつ指定された範囲のLEDを点滅させる関数
void LED_in_order(int startPixel, int length, uint32_t color, int interval) {//(最初のインデックス、何個分光らすか、１６進数のカラー、点滅（消灯）する時間)
    for (int i = startPixel; i < startPixel + length; i++) {
        setPixelColor(i % NUM_PIXELS, color);  // 範囲を超えた場合、ループする
        delay(interval);
        setPixelColor(i % NUM_PIXELS, 0);      // LEDを消す
        delay(interval);
    }
}

//複数のLEDを同時に点滅させる(ウィンカー)
void turn_signal(int *pixelIndices, int numPixels, uint32_t color, int interval) {
    // LEDを点灯する
    for (int i = 0; i < numPixels; i++) {//numPixelsは配列の要素数を表している。現在はビット数？
        setPixelColor(pixelIndices[i], color);
    }
    neopixel.show();  // LEDの表示を更新

    delay(interval);  // 指定時間待機

    // LEDを消灯する
    for (int i = 0; i < numPixels; i++) {
        setPixelColor(pixelIndices[i], 0);
    }
    neopixel.show();  // LEDの表示を更新

    delay(interval);  // 指定時間待機
}

// 特定の範囲のLEDを消す関数
void clearPixels(int startPixel, int length) {
    for (int i = startPixel; i < startPixel + length; i++) {
        setPixelColor(i % NUM_PIXELS, 0);  // LEDを消す
    }
}



// 虹色サイクルを実現する関数
void rainbowCycle(uint8_t wait, uint8_t maxBrightness)
{
    uint16_t i, j;

    for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
        for(i=0; i< neopixel.numPixels(); i++) {
            neopixel.setPixelColor(i, Wheel(((i * 256 / neopixel.numPixels()) + j) & 255, maxBrightness));
        }
        neopixel.show();
        delay(wait);
    }
}

// 虹色効果を生成する関数
uint32_t Wheel(byte WheelPos, uint8_t maxBrightness) {
    WheelPos = 255 - WheelPos;
    if(WheelPos < 85) {
        return neopixel.Color(((255 - WheelPos * 3) * maxBrightness) / 255, (WheelPos * 3 * maxBrightness) / 255, 0);
    }
    if(WheelPos < 170) {
        WheelPos -= 85;
        return neopixel.Color(0, ((WheelPos * 3 * maxBrightness) / 255), ((255 - WheelPos * 3 * maxBrightness) / 255));
    }
    WheelPos -= 170;
    return neopixel.Color(((WheelPos * 3 * maxBrightness) / 255), 0, ((255 - WheelPos * 3 * maxBrightness) / 255));
}
