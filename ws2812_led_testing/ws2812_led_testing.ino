#include <Adafruit_NeoPixel.h>

#define PIN 2 // The pin connected to the data line of the LED strip
#define NUM_LEDS 40 // Number of LEDs in the strip

int c_state = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(50);
  Serial.begin(9600);
}

void loop() {

  for(int i=0; i<=40; i++){
    if(c_state == 0){
      strip.setPixelColor(i, strip.Color(0,0,255));
      strip.show();
    }
    if(c_state == 1){
      strip.setPixelColor(i, strip.Color(255,0,0));
      strip.show();
    }
    if(c_state == 2){
      strip.setPixelColor(i, strip.Color(0,255,0));
      strip.show();
    }
    if(c_state == 3){
      strip.setPixelColor(i, strip.Color(255,0,255));
      strip.show();
    }
    if(c_state == 4){
      strip.setPixelColor(i, strip.Color(0,255,255));
      strip.show();
    }
    if(c_state == 5){
      strip.setPixelColor(i, strip.Color(255,255,0));
      strip.show();
    }
    if(c_state == 6){
      strip.setPixelColor(i, strip.Color(255,255,255));
      strip.show();
    }
    delay(50);
  }
  for(int i=40; i>=0; i--){
    strip.setPixelColor(i, strip.Color(0,0,0));
    strip.show();
    delay(50);
  }
  c_state++;
  if(c_state > 6) c_state = 0;

  delay(100);
}
