// C++ code
//
#include <Adafruit_NeoPixel.h>
// Which pin on the Arduino is connected to the NeoPixels?
#define LED_PIN    8

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 20

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
uint32_t magenta;
uint32_t cyan;
uint32_t yellow;
void setup()
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  //A little color theory cause Benny doesn't understand Additive vs Subtractive colors
  magenta = strip.Color(255, 0, 255);
  yellow = strip.Color(255, 255, 0);
  cyan = strip.Color(0, 255, 255);
  //Use voltage on A0 as random seed for "true" randomness, set to 0 for consistent "randomness"
  randomSeed(analogRead(0));
}

int curPixel = 0;
void loop()
{
  uint32_t redColor = random(0, 255);
  uint32_t greenColor = random(0,255);
  uint32_t blueColor = random(0, 255);
  if(redColor == 0 || greenColor == 0 || blueColor == 0){
      //Turns off all LEDs
    strip.clear();
    strip.show();
  }
  strip.setPixelColor(curPixel, redColor, blueColor, greenColor);
  strip.show();
  curPixel = ++curPixel % LED_COUNT;
  delay(100);
}
