#include <Adafruit_NeoPixel.h>
int numberOfLeds = 12;
Adafruit_NeoPixel pixels(numberOfLeds, 6, NEO_GRB + NEO_KHZ800);
int generatedNumber;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  randomSeed(analogRead(0));
  pixels.begin();
  pixels.show();
}

void loop() {
  generatedNumber = random(0, 15);
  for (int i = 0; i < numberOfLeds; i++) {
    pixels.setPixelColor(i, pixels.Color(255 - generatedNumber,150 - generatedNumber, 0));
  }
  pixels.show();
  delay(100);
}
