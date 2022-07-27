/** ===================================================
 * Le seguenti linee di codice servono per configurare il sensore di temperatura, importando la libreria,
 * impostando il modello del sensore per inizializzare il sensore stesso
 **/
#include "DHT.h"
#define DHTTYPE DHT11
const int tempPin = A3;
DHT dht(tempPin, DHTTYPE); //inizializzo il sensore di temperatura

/** ===================================================
 * Le seguenti linee di codice servono per configurare il display OLED i2c
 */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET  -1   
#define SCREEN_ADDRESS 0x3c
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
String displayString;

/** ===================================================
 * Le seguenti linee di codice servono per configurare i led e la libreria per poterlo
 * gestire (FastLED)
 */
#include <FastLED.h>
#define NUM_LEDS 9 
#define COLOR_ORDER GRB //Inserendo RGB verde e blu sono invertiti
#define LED_TYPE WS2811
CRGB leds[NUM_LEDS];
const int ledPin = 2;

 
const int fanPin = 13; //(pin del relay connesso alle ventole)

const int SCLPin = A5;
const int SDAPin = A4;
const int photoPin = A2;
//const int soilPin = A1;
//const int waterPumpPin = 2;

/** ==================== Setup =============================== */
void LEDSetup(){
  FastLED.addLeds<LED_TYPE, ledPin, GRB>(leds, NUM_LEDS);         
  FastLED.setBrightness(255);
  //FastLED.show();
}

void displaySetup(){
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
    Serial.println(F("SSD1306 allocation failed"));
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  displayString.reserve(20); //senza questa riga il buffer ha problemi(?)
}

//* ==================== Funzioni =============================== */
void fanON(){
  digitalWrite(fanPin, HIGH);
}

/**
 * Imposta i led del colore passato come argomento
 */
void setLed(const struct CRGB color){
  fill_solid(leds, NUM_LEDS, color);
  FastLED.show();
  
}

void getTemperature(){
   int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;
  displayString = "TEMP:" + String(dht.readTemperature(), 1) + "C";

  //Trovo la grandezza della stringa
  display.getTextBounds(displayString, 0, 0, &x1, &y1, &width, &height);
  display.clearDisplay(); 
  display.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);
  display.println(displayString);
  Serial.println(displayString);
  display.display();
}

/** ============================================================= */
void setup(){
	 Serial.begin(115200);
   dht.begin();
   LEDSetup();
   displaySetup();
   pinMode(fanPin, OUTPUT);
   
}

void loop(){
  getTemperature();
  delay(2000);
  setLed(CRGB::White);
  digitalWrite(fanPin, HIGH);
  delay(2000);
  //digitalWrite(fanPin, LOW);
}
