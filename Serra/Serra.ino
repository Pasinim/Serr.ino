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
#define OLED_RESET  -1   
#define SCREEN_ADDRESS 0x3c

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

/** ============================================================= */
void setup(){
	 Serial.begin(115200);
   dht.begin();
   LEDSetup();
   
   pinMode(fanPin, OUTPUT);
   
}

void loop(){
	Serial.print("LEggo temperature ");
  Serial.println(dht.readTemperature());
  //Serial.println(readTemperature());
	delay(100);
  setLed(CRGB::Blue);
}
