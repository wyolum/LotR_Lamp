#include <Adafruit_NeoPixel.h>

#include <ADCTouch.h>
int ref0, ref1;     //reference values to remove offset

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 3

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip(64, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  Serial.begin(9600); // open the serial port at 9600 bps
  strip.begin();
  strip.setBrightness(255);
  strip.show(); // Initialize all pixels to 'off'

  // No pins to setup, pins can still be used regularly, although it will affect readings

    ref0 = ADCTouch.read(A0, 500);    //create reference values to 
    ref1 = ADCTouch.read(A1, 500);    //account for the capacitance of the pad
  
}

void loop() {
uint16_t i, j, k;
uint16_t f=255;

    int value0 = ADCTouch.read(A0);   //no second parameter
    int value1 = ADCTouch.r
    
    
    ead(A1);   //   --> 100 samples

    value0 -= ref0;       //remove offset
    value1 -= ref1;

    Serial.print(value0 > 40);    //send (boolean) pressed or not pressed
    Serial.print("\t");           //use if(value > threshold) to get the state of a button

    Serial.print(value1 > 40);
    Serial.print("\t\t");

    Serial.print(value0);             //send actual reading
    Serial.print("\t");
  
    Serial.println(value1);
    delay(100);

    five_led_snake();
    five_led_snake();
    
      for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i,255,165,0); //original color is 255,85,0)
      strip.show();
      delay(30);
      }

      for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i,0,0,0);
      strip.show();
      delay(30);
      }

      for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i,255,165,0);
      strip.show();
      delay(30);
      }
      
      for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i,0,0,0);
      strip.show();
      delay(30);
      }

      for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i,255,165,0);
      strip.show();
      delay(30);
      }
      
      delay(10000);


strip.clear();
    
  
}


void five_led_snake(){

    for(int i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(0+i,255,165,0); // original color is 255,80 or 85,0
      strip.setPixelColor(1+i,255,165,0);
      strip.setPixelColor(2+i,255,165,0);
      strip.setPixelColor(3+i,255,165,0);
      strip.setPixelColor(4+i,255,165,0);
      strip.show();
      delay(50);
      strip.setPixelColor(0+i,0,0,0);
      strip.setPixelColor(1+i,0,0,0);
      strip.setPixelColor(2+i,0,0,0);
      strip.setPixelColor(3+i,0,0,0);
      strip.setPixelColor(4+i,0,0,0);
      strip.show();
      if (i>55) {
      strip.setPixelColor(0,255,165,0);
      }
      if (i>56) {
      strip.setPixelColor(1,255,165,0);
      }
      if (i>57) {
      strip.setPixelColor(2,255,165,0);
      }
      if (i>58) {
      strip.setPixelColor(3,255,165,0);
      }
      if (i>59) {
      strip.setPixelColor(4,255,165,0);
      }
    }
  
}
