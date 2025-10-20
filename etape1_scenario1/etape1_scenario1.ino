// Programme de test pour faire clignoter la LED intégrée toutes les secondes
    void setup() {
     pinMode(13, OUTPUT); // Définir la LED intégrée en mode sortie
     pinMode(12, OUTPUT);
    }

    void loop() {
     digitalWrite(13, HIGH); // Allume la LED
     digitalWrite(12, HIGH); // Allume la LED
    }
