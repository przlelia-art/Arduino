
#include <LiquidCrystal_I2C.h>

#include  <Wire.h>

//initialize the liquid crystal library
//the first parameter is  the I2C address
//the second parameter is how many rows are on your screen
//the  third parameter is how many columns are on your screen
LiquidCrystal_I2C lcd(0x27,  16, 2);

#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int Temperature = dht.readTemperature();

void setup() {
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(11, OUTPUT);
   pinMode(10, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(8, OUTPUT);

  
  //initialize lcd screen
  lcd.init();
  // turn on the backlight
  lcd.backlight();
  
  Serial.begin(9600);
  
  // Initialise la capteur DHT11
  dht.begin();

  
}
void loop() {
  //wait  for a second
  delay(1000);
  // tell the screen to write on the top row
  lcd.setCursor(0,0);
  // tell the screen to write “hello, from” on the top  row
  lcd.print("Temperature = " + String(dht.readTemperature())+" °C");
  // tell the screen to write on the bottom  row
  lcd.setCursor(0,1);
  // tell the screen to write “Arduino_uno_guy”  on the bottom row
  // you can change whats in the quotes to be what you want  it to be!
  lcd.print("Humidite = " + String(dht.readHumidity())+" %");

   if(Temperature < 18){
   digitalWrite(13, HIGH);
   digitalWrite(12, LOW);
   digitalWrite(11, LOW);
   }
   
   else if(Temperature >= 18 && Temperature <= 22){
   digitalWrite(13, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(11, LOW);
   }

   else (Temperature > 22);{
   digitalWrite(13, HIGH);
   digitalWrite(12, HIGH);
   digitalWrite(11, HIGH);
   }
}


  
