
#include <LiquidCrystal_I2C.h>

#include  <Wire.h>

LiquidCrystal_I2C lcd(0x27,  16, 2);

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int leds[] = {8, 9, 10, 11, 12, 13}; // Broches des 6 LEDs
const int nLeds = 6;                     // Nombre total de LEDs
const int intervalle = 1000; 

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();

  for (int i = 0; i < nLeds; i++) {
  pinMode(leds[i], OUTPUT);
  digitalWrite(leds[i], LOW);
  }
}

void loop() {

 
 // Étape 1 : allumer les LEDs une par une
    for (int i = 0; i < nLeds; i++) {
    digitalWrite(leds[i], HIGH);
    delay(intervalle);
     }

 // Étape 2 : clignotement final
    for (int blink = 0; blink < 3; blink++) {
    for (int i = 0; i < nLeds; i++) digitalWrite(leds[i], LOW);
    delay(300);
    for (int i = 0; i < nLeds; i++) digitalWrite(leds[i], HIGH);
    delay(300);
    }

  // Étape 3 : Réinitialisation
    for (int i = 0; i < nLeds; i++) digitalWrite(leds[i], LOW);

  // Pause avant de recommencer
  delay(2000);
}
