#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,  16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht.begin();
}
void loop() {
  int Temperature = dht.readTemperature();
  int Humidite = dht.readHumidity();

  delay(5000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature= " + String(Temperature) + "C");

  lcd.setCursor(0,1);
  if(Temperature <18){
    lcd.print("Temp basse");
  }
  else if(Temperature >=18 && Temperature<=22){
    lcd.print("Temp ideal");
  }
  else{
    lcd.print("Temp elevee");
  }

  delay(5000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidite = " + String(Humidite) + "%");

  lcd.setCursor(0,1);
  if(Humidite <30){
    lcd.setCursor(0, 1);
    lcd.print("Humi basse");
  }
  else if(Humidite >=30 && Humidite<=60){
    lcd.print("Humi ideal");
  }
  else{
    lcd.print("Humi elevee");

  }
}
