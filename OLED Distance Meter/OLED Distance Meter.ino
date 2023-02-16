#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>
#include <Adafruit_SSD1331.h>
#define cs 10
#define dc 9
#define res 2
// Color definitions
#define BLACK    0x0000
#define BLUE     0x001F
#define RED      0xF300
#define GREEN    0x07E0
#define ORANGE   0xFF00
#define CYAN     0x07FF
#define MAGENTA  0xF81F
#define YELLOW   0xFFE0
#define WHITE    0xFFFF

Adafruit_SSD1331 display = Adafruit_SSD1331(cs,dc,res);

const int trigPin = 7;
const int echoPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  display.begin();
  display.fillScreen(0);
  display.setRotation(2);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance based on the speed of sound
  // (343 meters/second or 0.0343 centimeters/microsecond)
  float distance = duration * 0.0343 / 2;
  // Display is 96x64
  if(distance < 20 && distance > 10){
    display.setTextColor(ORANGE, 0xF000);
    display.println("Move back!");
    display.setCursor(2,0);
  }
  else if(distance < 10){
    display.setTextColor(RED, 0xFF00);
    display.println("MOVE BACK!");
    display.setCursor(2,0);
  }
  display.setCursor(0,0);
  display.setTextColor(WHITE, 0x0000);
  display.println(String(distance));
  delay(25);

}

