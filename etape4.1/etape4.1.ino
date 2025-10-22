
#include <LiquidCrystal_I2C.h>

#include  <Wire.h>

LiquidCrystal_I2C lcd(0x27,  16, 2);

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


  float Temp;
  float seuilTempMax = 22.0;
  float seuilTempMin = 18.0;
  float Humi;
  float seuilHumiMax = 60;
  float seuilHumiMin = 30;
  
void setup() {
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(11, OUTPUT);

  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();
  
}

void loop() {
  Temp = dht.readTemperature();
  Humi = dht.readHumidity();
  
  

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


   
  // Vérification des erreurs
  if (isnan(Temp) || isnan(Humi)) {
    lcd.setCursor(0,0);
    lcd.print("Erreur capteur");
    return;
  }

  // Affichage des valeurs
    lcd.setCursor(0,0);
    lcd.print("T:");
    lcd.print(Temp,1);
    lcd.print((char)223);
    lcd.print("C  ");

    
    lcd.setCursor(0,1);
    lcd.print("H:");
    lcd.print(Humi, 1);
    lcd.print("% "); 

    // Affichage dynamique des alertes
    lcd.setCursor(0,0);
    if(Temp > seuilTempMax){
        lcd.print("Temp Elevee !    ");
    }
    else if(Temp < seuilTempMin){
        lcd.print("Temp Basse !     ");
    }
    
    lcd.setCursor(0,1);
    if(Humi > seuilHumiMax){
        lcd.print("Hum Elevee !     ");
    }
    else if(Humi < seuilHumiMin){
        lcd.print("Hum Basse !      ");
    }
    else {
        lcd.print("Conditions OK    ");
    }


  delay(2000);
}


  
