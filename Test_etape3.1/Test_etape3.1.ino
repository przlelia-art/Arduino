
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

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();

  int Temp = dht.readTemperature();
  int Humi = dht.readHumidity();
  
}

void loop() {
  
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Temp = " + String(dht.readTemperature())+" °C");
  lcd.setCursor(0,1);
  lcd.print("Humi = " + String(dht.readHumidity())+" %");

   if(Temp < 18){
   digitalWrite(13, HIGH);
   digitalWrite(12, LOW);
   digitalWrite(11, LOW);
   }
   
   else if(Temp >= 18 && Temp <= 22){
   digitalWrite(13, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(11, LOW);
   }

   else (Temp > 22);{
   digitalWrite(13, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(11, HIGH);
   }
   

   if(Humi > 60){ 
   digitalWrite(13, HIGH);
   digitalWrite(12, LOW);
   digitalWrite(11, LOW);
   }
   
   else if(Humi >= 30 && Humi <= 60){
   digitalWrite(13, LOW);
   digitalWrite(12, HIGH);
   digitalWrite(11, LOW);
   }

   else (Humi < 30);{
   digitalWrite(13, LOW);
   digitalWrite(12, LOW);
   digitalWrite(11, HIGH);
   }



}


  
