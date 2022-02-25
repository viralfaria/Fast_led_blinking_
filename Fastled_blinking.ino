#include <FastLED.h>  // Include the lib 

#define NUM_LEDS 10 // Number 0f leds in the RGB strip

#define LED_PIN 2  // Data pin of RGB strip connected to digital pin 2 of arduino

#define LED_TYPE WS2812B

#define COLOR_ORDER GRB

#define BRIGHTNESS 50

#define selected_color1 Red
#define selected_color2 Green
#define selected_color3 Blue

#define selected_color4 Yellow
#define selected_color5 Magenta
#define selected_color6 Indigo
#define selected_color7 Orange

CRGB leds[NUM_LEDS]; // Define an array

uint8_t hue = 0;

void setup() {
  delay(3000); // 3 second delay for recovery
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,LED_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  
  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
// Simple Solid Color Pattern 
 fill_solid(leds,NUM_LEDS, CRGB::selected_color1);
 FastLED.show();
 delay(500);

 fill_solid(leds,NUM_LEDS, CRGB::selected_color2);
 FastLED.show();
 delay(500);

 fill_solid(leds,NUM_LEDS, CRGB::selected_color3);
 FastLED.show();
 delay(500);


//Simple Multi Color Solid Pattern
fill_gradient_RGB(leds,NUM_LEDS, CRGB::selected_color1,CRGB::selected_color2,CRGB::selected_color3);
FastLED.show();
delay(500);

fill_gradient_RGB(leds,NUM_LEDS, CRGB::selected_color4,CRGB::selected_color5,CRGB::selected_color6,CRGB::selected_color7);
FastLED.show();
delay(500);

// Simple Rainbow Color Solid Pattern
fill_rainbow(leds,NUM_LEDS,0,255/NUM_LEDS);
FastLED.show();
delay(500);


//Rainbow Color pattern across the strip
for(int i =0 ; i< NUM_LEDS; i++)
{
  leds[i]= CHSV(hue,255,255);
}
EVERY_N_MILLISECONDS(15)
{
  hue++;
}

FastLED.show();


//Rainbow Color pattern changing across the strip
for(int i =0 ; i< NUM_LEDS; i++)
{
  leds[i]= CHSV(hue + (i*10),255,255);
}
EVERY_N_MILLISECONDS(15)
{
  hue++;
}

FastLED.show();



EVERY_N_MILLISECONDS(50){
leds[0] = CHSV(160,random8(),random8(100,255));

for(int i =NUM_LEDS-1 ; i>0; i--)
{
  leds[i]= leds[i-1];
}
}

FastLED.show();



 // Waves for LED position
  uint8_t posBeat  = beatsin8(30, 0, NUM_LEDS - 1, 0, 0);
  uint8_t posBeat2 = beatsin8(60, 0, NUM_LEDS - 1, 0, 0);
  uint8_t posBeat3 = beatsin16(30, 0, NUM_LEDS - 1, 0, 127);
  uint8_t posBeat4 = beatsin16(60, 0, NUM_LEDS - 1, 0, 127);


  // In the video I use beatsin8 for the positions. For longer strips,
  // the resolution isn't high enough for position and can lead to some
  // LEDs not lighting. If this is the case, use the 16 bit versions below
  // uint16_t posBeat  = beatsin16(30, 0, NUM_LEDS - 1, 0, 0);
  // uint16_t posBeat2 = beatsin16(60, 0, NUM_LEDS - 1, 0, 0);
  // uint16_t posBeat3 = beatsin16(30, 0, NUM_LEDS - 1, 0, 32767);
  // uint16_t posBeat4 = beatsin16(60, 0, NUM_LEDS - 1, 0, 32767);

  // Wave for LED color
  uint8_t colBeat  = beatsin8(45, 0, 255, 0, 0);

  leds[(posBeat + posBeat2) / 2]  = CHSV(colBeat, 255, 255);
  leds[(posBeat3 + posBeat4) / 2]  = CHSV(colBeat, 255, 255);

  fadeToBlackBy(leds, NUM_LEDS, 10);

  FastLED.show();


  // Patterns

  

  
}
