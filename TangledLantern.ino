#include <Adafruit_NeoPixel.h>
int numberOfLeds = 12;
Adafruit_NeoPixel pixels(numberOfLeds, 4, NEO_GRB + NEO_KHZ800);
int generatedNumber;
boolean pressed = false;
boolean ledsOn = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(3, HIGH);
  randomSeed(100);
  pixels.begin();
  pixels.show();
}

void loop() {
  if(!pressed && digitalRead(2) == HIGH) {
    pressed = true;
    if(ledsOn) {
      for (int i = 0; i < numberOfLeds; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
      }
      pixels.show();
      digitalWrite(9, 0);
    }
    else {
      for (int i = 0; i < numberOfLeds; i++) {
        pixels.setPixelColor(i, pixels.Color(255, 130, 0));
      }
      pixels.show();
      digitalWrite(9, HIGH);
    }
    ledsOn = !ledsOn;
  }

  if(pressed && digitalRead(2) == LOW) {
    pressed = false;
  }

  if(ledsOn) {
    generatedNumber = random(200, 255);
    analogWrite(9, generatedNumber);
  }
  delay(100);
}
