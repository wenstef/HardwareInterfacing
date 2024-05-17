void setup()
{
  pinMode(11, OUTPUT); // Stel pin 11 in als OUTPUT voor het aansturen van LED1
  pinMode(12, OUTPUT); // Stel pin 12 in als OUTPUT voor het aansturen van LED2
}

void loop()
{
  blinkLED(11, 1000); // Roep de functie aan voor pin 11 en wacht 1 seconde
  blinkLED(12, 1000); // Roep de functie aan voor pin 12 en wacht 1 seconde
}

// Functie om een LED te laten knipperen met opgegeven tijd
void blinkLED(int pin, int tijd){
  digitalWrite(pin, HIGH); // Zet de pin HIGH om de LED aan te zetten
  delay(tijd); // Wacht een bepaalde tijd
  digitalWrite(pin, LOW); // Zet de pin LOW om de LED uit te zetten
  delay(tijd); // Wacht een bepaalde tijd
}
