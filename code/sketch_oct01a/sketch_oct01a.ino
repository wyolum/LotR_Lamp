#include <FastLED.h>
#include <CapacitiveSensor.h>

#define PIN_LED 6
#define PIN_TOUCH1 2
#define PIN_TOUCH2 3
#define PIN_TOUCH3 4
#define PIN_TOUCH4 5

#define DATA_PIN    3
//#define CLK_PIN   4
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    64
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

// FastLED.h leds(NUM_LEDS, PIN_LED);

// Capacitive sensor pins
CapacitiveSensor sensor1 = CapacitiveSensor(PIN_TOUCH1, PIN_TOUCH1);
CapacitiveSensor sensor2 = CapacitiveSensor(PIN_TOUCH2, PIN_TOUCH2);
CapacitiveSensor sensor3 = CapacitiveSensor(PIN_TOUCH3, PIN_TOUCH3);
CapacitiveSensor sensor4 = CapacitiveSensor(PIN_TOUCH4, PIN_TOUCH4);

// Global variables for brightness, speed, color, and original values
int brightness = 128;
int speed = 50;
int color = 0; // 0 for red, 1 for green, 2 for blue
int originalBrightness = 128;
int originalSpeed = 50;
int originalColor = 0;

void setup() {
  FastLED.setBrightness(brightness);
  originalBrightness = brightness;
  originalSpeed = speed;
  originalColor = color;
}

void loop() {
  // Read capacitive sensor values
  long sensorValue1 = sensor1.capacitance();
  long sensorValue2 = sensor2.capacitance();
  long sensorValue3 = sensor3.capacitance();
  long sensorValue4 = sensor4.capacitance();

  // Check for touch events
  if (sensorValue1 > 1000) { // Adjust threshold as needed
    brightness = (brightness + 16) % 256;
    FastLED.setBrightness(brightness);
  }
  if (sensorValue2 > 1000) {
    speed = (speed + 10) % 256;
  }
  if (sensorValue3 > 1000) {
    color = (color + 1) % 3;
  }
  if (sensorValue4 > 1000) {
    brightness = originalBrightness;
    speed = originalSpeed;
    color = originalColor;
    FastLED.setBrightness(brightness);
  }

  // Update LED strip based on current values
  for (int i = 0; i < NUM_LEDS; i++) {
    switch (color) {
      case 0:
        leds[i] = CRGB::Red;
        break;
      case 1:
        leds[i] = CRGB::Green;
        break;
      case 2:
        leds[i] = CRGB::Blue;
        break;
    }
  }
  FastLED.show();
  delay(speed);
}
