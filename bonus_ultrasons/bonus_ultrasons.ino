#include<Servo.h>

// définir les broches de sortie
const int TriggerPin = 11;
const int EchoPin = 12;
const int motorSignalPin = 9;

// position de départ
const int startAngle = 90;

// limites de rotation
const int minimumAngle = 6;
const int maximumAngle = 175;

// vitesse
const int degreesPerCycle = 1;

// instance de la classe de la bibliothèque
Servo motor;

void setup(void) 
{
    pinMode(TriggerPin, OUTPUT);
    pinMode(EchoPin, INPUT);
    motor.attach(motorSignalPin);
    Serial.begin(9600);
}

void loop(void)
{
    static int currentAngle = startAngle;
    static int motorRotateAmount = degreesPerCycle;

    // faire tourner le moteur
    motor.write(currentAngle);
    delay(10);
    // calculer la distance avec le capteur, et écrire la valeur avec l'angle dans le moniteur série
    SerialOutput(currentAngle, CalculateDistance());

    // mettre à jour la position du moteur
    currentAngle += motorRotateAmount;

    // si le moteur atteint une des limites, inverser la direction
    if(currentAngle <= minimumAngle || currentAngle >= maximumAngle) 
    {
        motorRotateAmount = -motorRotateAmount;
    }
}

int CalculateDistance(void)
{
    // déclencher le capteur ultrasonique et enregistrer le temps aller-retour
    digitalWrite(TriggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin, LOW);
    long duration = pulseIn(EchoPin, HIGH);
    // convertir cette durée en distance
    float distance = duration * 0.017F;
    return int(distance);
}

void SerialOutput(const int angle, const int distance)
{
    // convertir l’angle et la distance en chaîne de caractères et les afficher via le port série
    Serial.println(String(angle) + "," + String(distance));
}
