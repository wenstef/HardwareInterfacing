void setup() {
  // Gebruik een for loop om elke pin vanaf 6 - 13 OUTPUT waarde mee te geven
  for (int pin = 6; pin <= 13; pin++) {
    pinMode(pin, OUTPUT); 
  }
}

void loop() {
  left(75);  // Aanroepen van functie left() met een wachttijd van 75ms
  right(75); // Aanroepen van functie right() met een wachttijd van 75ms
}

// De functie gaat door de rij van links naar rechts 
void left(int time) {
	for(int pin = 13; pin >= 6; pin--) {
		blinkLED(pin, time); // Roept de functie blinkLED aan
	}
}

// De functie gaat door de rij van rechts naar links
void right(int tijd) {
  for (int pin = 6; pin <= 13; pin++) {
    blinkLED(pin, tijd); // Roept de functie blinkLED aan
  }
}

// Laat de LEDjes steeds aan en uit gaan
void blinkLED(int pin, int tijd) {
  digitalWrite(pin, HIGH);
  delay(tijd);              
  digitalWrite(pin, LOW);  
  delay(tijd);             
}
