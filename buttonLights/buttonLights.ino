// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 9 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels


void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  for (int i = 0; i < NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(20, 20, 20));
  }
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);

}
String color = "";
void loop() {
  if (digitalRead(2) == HIGH){
    color = "red";
  } else if (digitalRead(3) == HIGH){
    color = "blue";
  } else if (digitalRead(4) == HIGH){
    pixels.clear();
    pixels.show();
    color = "black";
  }

   for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
    if (color == "red") {
      pixels.setPixelColor(i, pixels.Color(20, 0, 0)); // Red
    } else if (color == "blue") {
      pixels.setPixelColor(i, pixels.Color(0, 0, 20)); // Blue
    } else if (color == "black") {
      color = "";
      Serial.println("No new button press");
      }
    pixels.show();  // Send the updated pixel colors to the hardware // Pause before next pass through loop
  }

  delay(500);

}
