#define ledPin 11
#define buttonPin 7

int time = 50;                
int buttonState = LOW;        // Huidige en default status van de knop
int countStateChange = 0;     // Teller om het aantal wijzigingen bij te houden
int ledState = LOW;           // Huidige en default status van de LED

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Leest de status van de knop
  buttonState = digitalRead(buttonPin);  

  // Als de knop wordt ingedrukt
  if (buttonState == HIGH) {
    // Tel het aantal statuswijzigingen bij elkaar op
    countStateChange++;
    
    // Controleer of het aantal statuswijzigingen oneven is (gedeeld door 2 met een rest van 1 (oneven))
    if (countStateChange % 2 == 1) {
      // Indien oneven, zet LED aan
      ledState = HIGH;  
    } else {
      // Anders, zet LED uit.
      ledState = LOW;   
    }

    // Leest LEDstatus op basis van bovenstaand statement
    digitalWrite(ledPin, ledState);

    // Wacht voor een bepaalde tijd
    delay(time);
  }
}
