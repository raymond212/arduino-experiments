#include <AlaLedRgb.h>

#define RED_PIN 3
#define GREEN_PIN 5
#define BLUE_PIN 6

AlaLedRgb rgbLed;

void setup() {
  rgbLed.initPWM(RED_PIN, GREEN_PIN, BLUE_PIN);
  rgbLed.setBrightness(0x66FF44);
  rgbLed.setAnimation(ALA_FADECOLORSLOOP, 5000, alaPalRgb);
}

void loop() {
  rgbLed.runAnimation();
}
