// Programme de test pour faire clignoter la LED intégrée toutes les secondes
    void setup() {
     pinMode(LED_BUILTIN, OUTPUT); // Définir la LED intégrée en mode sortie
    }

    void loop() {
     digitalWrite(LED_BUILTIN, HIGH); // Allume la LED
     delay(1000);           // Attendre 1 seconde
     digitalWrite(LED_BUILTIN, LOW); // Éteint la LED
     delay(1000);           // Attendre 1 seconde
    }
