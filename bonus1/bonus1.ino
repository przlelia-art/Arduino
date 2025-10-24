const int leds[] = {3, 5, 6, 9, 10, 11}; // LEDs sur broches PWM
const int nLeds = sizeof(leds)/sizeof(leds[0]);

int brightness = 0;     // Intensité actuelle
int fadeAmount = 5;     // Vitesse de variation
bool increasing = true; // Sens de la respiration

void setup() {
  for (int i = 0; i < nLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Appliquer la même luminosité à toutes les LEDs
  for (int i = 0; i < nLeds; i++) {
    analogWrite(leds[i], brightness);
  }

  // Modifier la luminosité
  if (increasing) {
    brightness += fadeAmount;
    if (brightness >= 255) {
      brightness = 255;
      increasing = false;
    }
  } else {
    brightness -= fadeAmount;
    if (brightness <= 0) {
      brightness = 0;
      increasing = true;
    }
  }

  delay(30); // Ajuste la vitesse de la respiration
}
