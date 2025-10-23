
#include <LiquidCrystal_I2C.h>

#include  <Wire.h>

LiquidCrystal_I2C lcd(0x27,  16, 2);

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(8, OUTPUT);

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();

  
}

void loop() {

   digitalWrite(8, HIGH);
   digitalWrite(9, HIGH);
   digitalWrite(10, HIGH);
   digitalWrite(11, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(13, HIGH);
   delay(1000);


   digitalWrite(8, LOW);
   digitalWrite(10, LOW);
   digitalWrite(12, LOW);
   delay(1000);

 

 
 

  

 

}
