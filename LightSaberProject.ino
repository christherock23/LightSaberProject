#include "FastLED.h"
#include "Buttons.h"

#define DATA_PIN 0
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 67

#define BRIGHTNESS 255
#define FRAMES_PER_SECOND 120

CRGB leds[NUM_LEDS];

unsigned long previousMillis = millis();
const long interval = 50;

void setup() {
 pinMode(BUTTON_LEAD, INPUT_PULLUP);
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  }

void loop() {
  switch (mode) {
    case 1:
      colorWipe(0xff, 0x00, 0x00);
      break;

    case 2:
      colorWipeOut(0x00, 0x00, 0x00);
      break;

     case 3:
      colorWipe(0x00, 0xff, 0x00);
      break;

     case 4:
      colorWipeOut(0x00, 0x00, 0x00);
      break;

    case 5:
      colorWipe(0x00, 0x00, 0xff);
      break;

    case 6:
      colorWipeOut(0x00, 0x00, 0x00);
      break;

    case 7:
      colorWipe(0xff, 0x00, 0xff);
      break;

    case 8:
      colorWipeOut(0x00, 0x00, 0x00);
      break;

     default:
      mode = 1;
      break;
  }   
}

void colorWipe(byte red, byte green, byte blue){
  if(buttonListener()) { return; }
  if(millis() - previousMillis >= interval) {
      previousMillis = millis();
for(int i=0; i<NUM_LEDS; i++)
{
    setPixel(i, red, green, blue);
    FastLED.show();
}
}
}


void colorWipeOut(byte red, byte green, byte blue){
  if(buttonListener()) { return; }
  if(millis() - previousMillis >= interval) {
      previousMillis = millis();
for(int i=NUM_LEDS - 1; i>=0; i--)
{
    setPixel(i, red, green, blue);
    FastLED.show();
}
}
}


void setPixel(int Pixel, byte red, byte green, byte blue){
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
}
