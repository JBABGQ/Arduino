#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 8
#define BRIGHTNESS 100

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
    strip.begin();
    strip.setBrightness(BRIGHTNESS);
    strip.show();
}

void loop() {
    for (int i = 0; i < NUMPIXELS; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 255));
    }
    strip.show();
    delay(43200000);

    strip.clear();
    strip.show();
    delay(43200000);
}
