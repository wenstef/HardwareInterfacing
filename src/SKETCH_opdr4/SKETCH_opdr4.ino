const int potPin = A5; // Refereert aan input A5 van de ARDUINO 
int potMeterValue = 0; 

void setup() {
  // Een loop in oplopende volgorde pin 7 - 13d de OUTPUT waarde mee te geven.
    for (int pin = 7; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
  }
  
  // Bepaalt dat potPin de INPUT waarde heeft
  pinMode(potPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  // Leest de waarde van de potPin
  potMeterValue = analogRead(potPin);

  // Map gebruikt een berekening om per ledPin een potWaarde toe te kennen.
  int ledNumber = map(potMeterValue, 0, 1023, 6, 13);

  // Print waarde van de potMeter en daaraan gekoppelde ledPin
  Serial.print("Potentiometer value: ");
  Serial.print(potMeterValue);
  Serial.print(" -> LED number: ");
  Serial.println(ledNumber);

  //Bepaalt op basis van de waarde die toegekend is mbv map, wanneer de LED aan gaat.
  for (int pin = 7; pin <= 13; pin++) {
    if (pin <= ledNumber) {
      digitalWrite(pin, HIGH); 
    } else {
      digitalWrite(pin, LOW);
    }
  }

  delay(100);
}
