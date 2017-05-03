//fancy rgb neopixel 
int one();
int two();
 
#include <Adafruit_NeoPixel.h>
 
#define PIN      6
#define N_LEDS 16
 #define BRIGHTNESS 300
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
    strip.begin();
    Serial.begin(115200);
   strip.setBrightness(BRIGHTNESS);
  strip.begin();
   one();
   two();
}
 
void loop() {
  chase(strip.Color(255, 0, 255)); // purple
 one();
  chase(strip.Color(0, 255, 0)); // Green
  two();
  chase(strip.Color(255, 165, 0)); // orangotang
    theaterChase(strip.Color(0, 255, 255), 50); // yellow
  theaterChase(strip.Color(255, 165, 0), 50); // orango
  theaterChase(strip.Color(255, 0,0), 50); // Blue

  rainbow(20);
  
  theaterChaseRainbow(100);
  
  
}
 
static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+8; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(100);
  }
}
   
int one(){
int red = 150, green= 1, blue = 180, white = 50;
int wait = 250;
int led = 0;
int i;


  for ( led = 0; led < 16; led++){
    strip.setPixelColor(led, red, green , blue, white);
  }//end of for loop
    strip.show();
    delay(wait);
    red = red + 1;
    green = green + 150;
    blue = blue + 150;
    white = white + 1;

    if (red > 255) red = 0;
    if (green > 255) green = 0;
    if (blue > 255) blue = 0;
    if (white > 50) white = 0;

    if (red < 0) red = 255;
    if (green  < 0) green = 255;
    if (blue < 0) blue = 255;
    if (white  < 0 ) white = 50;


   }

   int two(){
int red = 10, green= 180, blue = 210, white = 50;
int wait = 200;
int led = 0;
int i;


  for ( led = 0; led < 16; led++){
    strip.setPixelColor(led, red, green , blue, white);
  }//end of for loop
    strip.show();
    delay(wait);
    red = red + 150;
    green = green + 1;
    blue = blue + 150;
    white = white + 1;

    if (red > 255) red = 0;
    if (green > 255) green = 0;
    if (blue > 255) blue = 0;
    if (white > 50) white = 0;

    if (red < 0) red = 255;
    if (green  < 0) green = 255;
    if (blue < 0) blue = 255;
    if (white  < 0 ) white = 50;

   }
   void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      ///strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      //strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        //strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

