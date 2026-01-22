# ThermOS - Système de Monitoring Température et Humidité

## 📋 Description

ThermOS est un projet Arduino permettant de surveiller en temps réel la température et l'humidité ambiante. Le système utilise un capteur DHT11 pour collecter les données environnementales et propose une interface visuelle complète avec indicateurs LED et affichage LCD I2C.

## 🎯 Objectifs pédagogiques

- Découvrir l'environnement de développement Arduino
- Manipuler des composants électroniques sur breadboard
- Exploiter les données d'un capteur DHT11
- Créer des indicateurs visuels avec LEDs
- Programmer un affichage LCD I2C
- Développer des effets lumineux progressifs

## 🔧 Matériel requis

- 1× Arduino UNO
- 1× Capteur DHT11 (température et humidité)
- 1× Écran LCD I2C
- LEDs (multiples couleurs : rouge, vert, bleu, jaune)
- Résistances appropriées pour LEDs
- 1× Breadboard
- Câbles de connexion
- Câble USB pour Arduino

## 💻 Logiciels nécessaires

- Arduino IDE
- Bibliothèques Arduino :
  - DHT sensor library
  - LiquidCrystal_I2C


```

## 🚀 Installation et configuration

### 1. Installation de l'IDE Arduino

Téléchargez et installez l'IDE Arduino depuis le site officiel : [arduino.cc](https://www.arduino.cc/en/software)

### 2. Test de connexion

Connectez votre Arduino UNO via USB et testez la connexion avec ce programme simple :

```cpp
// Programme de test pour faire clignoter la LED intégrée
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```

Si la LED clignote toutes les secondes, votre Arduino est prêt.

## 📖 Étapes du projet

### Étape 1 : Manipulation des LEDs sur breadboard

**Objectif** : Se familiariser avec le prototypage et les connexions de base.

**Scénarios implémentés** :
- Scénario 1 : Allumage de deux LEDs en parallèle
- Scénario 2 : Clignotement alterné entre deux LEDs
- Scénario 3 : Effet chenillard sur 4 LEDs
- Scénario 4 : Variations de vitesse de clignotement

### Étape 2 : Capteur DHT11 et affichage LCD

**Objectif** : Acquérir et afficher les données environnementales.

**Fonctionnalités** :
- Lecture de la température et de l'humidité
- Affichage dans le moniteur série
- Affichage en temps réel sur écran LCD I2C

⚠️ **Important** : Respectez la polarité lors du branchement du DHT11 (+ sur 5V, GND sur GND, signal sur broche numérique).

### Étape 3 : Indicateurs lumineux conditionnels

**Objectif** : Interpréter visuellement les données par seuils.

**Indicateurs de température** :
- 🔵 LED bleue : < 18°C (température basse)
- 🟢 LEDs vertes : 18-22°C (confortable)
- 🔴 LEDs rouges : > 22°C (température élevée)

**Indicateurs d'humidité** :
- 🟡 LEDs jaunes : < 30% (humidité basse)
- 🔵 LEDs bleues : 30-60% (humidité modérée)
- 🔴 LEDs rouges : > 60% (humidité élevée)

### Étape 4 : Effets avancés et alertes

**Objectif** : Finaliser l'expérience utilisateur avec des indicateurs dynamiques.

**Fonctionnalités** :
- Effet progressif de montée/descente des LEDs (thermomètre visuel)
- Messages d'alerte sur LCD selon les seuils
- Affichage dynamique des conditions anormales

## 📚 Ressources utiles

- [Documentation officielle Arduino](https://www.arduino.cc/reference/en/)
- [Tutoriel capteur DHT11](https://www.arduino.cc/en/Guide/Libraries)
- [Guide LCD I2C](https://www.arduino.cc/en/Reference/LiquidCrystal)

## 🔍 Dépannage

| Problème | Solution |
|----------|----------|
| LED intégrée ne clignote pas | Vérifier la connexion USB et le port COM sélectionné |
| Capteur DHT11 ne répond pas | Vérifier le câblage et la polarité |
| Écran LCD vide | Ajuster le contraste, vérifier l'adresse I2C |
| LEDs ne s'allument pas | Vérifier les résistances et le sens de branchement |

## 👥 Contribution

Ce projet est réalisé dans un cadre pédagogique. Les améliorations et suggestions sont les bienvenues.
