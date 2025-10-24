
#include <Servo.h>

//Définir les broches Trig et Echo de l'ultrason
const int trigPin = 10;
const int echoPin = 9;

//Déclaration de la durée et de la distance
long duration;
int distance;

Servo myServo; //Création d'un objet pour cotroler le servomoteur

int pos = 0;    // variable pour la position du servomoteur

void setup() {
  pinMode(trigPin, OUTPUT); //Mettre la broche trig en sortie
  pinMode(echoPin, INPUT); //Mettre la broche echo en sortie
  Serial.begin(9600);
  myServo.attach(8);  // définir sur quel PIn est le servomoteur
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { //va de 180 degré à 0
    // in steps of 1 degree
    myservo.write(pos);              //dis au servo d'aller dans la variable "pos"
    delay(10);                       //attends 15 ms que le servo moteur atteigne sa position
  }
  for (pos = 180; pos >= 0; pos -= 1) { //va de 180 degré à 0
    myservo.write(pos);              //dis au servo d'aller dans la variable "pos"
    delay(10);                       //attends 15 ms que le servo moteur atteigne sa position
  }
  distance = calculateDistance(); //calcul de la mesure par le capteur ultrason à chaque degré
  Serial.print(pos); //Envoyer les valeurs en degré dans le port série
  Serial.print(","); //Envoie du caractère additionnel
  Serial.print(distance); //Envoyer la valeur de la distance au port série
  Serial.print(","); //Envoie du caractère additionnel
}
