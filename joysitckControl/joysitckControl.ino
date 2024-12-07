#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int xpos = 64;
int ypos = 16;

int LR;
int UD;


const int xPin = A0;
const int yPin = A1;

int LRNeutral;
int UDNeutral;
void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  LRNeutral = analogRead(xPin);
  UDNeutral = analogRead(yPin);
  // Clear the buffer
  display.clearDisplay();

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
}
void loop() {
  display.clearDisplay();

  display.drawPixel(xpos%128, ypos%32, SSD1306_WHITE);

  // xpos += map(analogRead(xPin), 3, 1023, -2, 2);
  // ypos += map(analogRead(yPin), 0, 1023, 2, -2);

  LR = analogRead(xPin);
  UD = analogRead(yPin);
  display.display();

  if(LR>LRNeutral+100){
    xpos+=4;
  }
  if(LR<LRNeutral-100){
    xpos-=4;
  }
  if(UD<UDNeutral+100){
    ypos+=1;
  }
  if(UD>UDNeutral-100){
    ypos-=1;
  }

  delay(50);
}