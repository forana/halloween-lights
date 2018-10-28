#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUMPIXELS 30
#define MOD 15
#define INTENSITY 90

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

int c = 0;

void loop() {
  pixels.clear();
  for (int i=0;i<NUMPIXELS;i++) {
    int intensity = max(0, INTENSITY/4 + floor(INTENSITY * sin(2 * PI / NUMPIXELS * ((c + i) % MOD))));
    // every 6.66 seconds, switch between orange and green
    if (c / 100 % 2 == 0) {
      // orange
      pixels.setPixelColor(i, pixels.Color(intensity,intensity/6,0));
    } else {
      // green
      pixels.setPixelColor(i, pixels.Color(0,intensity,0));
    }
  }
  pixels.show();
  delay(66.6);
  c++;
}
