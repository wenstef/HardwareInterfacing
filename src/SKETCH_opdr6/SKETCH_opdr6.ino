#include <Servo.h> // Servo library toevoegen

Servo JoyServo;  // Een servo object aanmaken

const int vrxPin = A0; // VRX koppelen aan analoge pin A0 
const int buttonPin = 8; // SW voor de knop koppelen aan pin 8

int buttonJoyState = HIGH; // Variabele waarde HIGH meegeven ivm pullup output

void setup() {
  JoyServo.attach(9); // Servo koppelen aan pin 9
  pinMode(buttonPin, INPUT_PULLUP); // De Joystick knop input_pullup meegeven
}

void loop() {
  // De status van de knop uitlezen
  buttonJoyState = digitalRead(buttonPin);
  // Indien knop ingedrukt, functie buttonPress aanroepen, anders functie moveJoyHorizontal blijven aanroepen
  if (buttonJoyState == LOW) { 
    buttonPress();
  } else {
    moveJoyHorizontal();
  }
}
  
void moveJoyHorizontal() {
  // Lees de waarde van de pin, horizontale (x-as) beweging
  int pinX = analogRead(vrxPin);

  // Schaal de waarde van de vrxpin met de servo 
  int posX = map(pinX, 0, 1023, 0, 180); 
 
  // Beweeg de servo obv de aangegeven positie
  JoyServo.write(posX);  
}

void buttonPress() {
  // Indien knop is ingedrukt, servo steeds 1 stap verplaatsen
  for (int pos = 0; pos <= 120; pos++) {
    JoyServo.write(pos);
    delay(1000 / 120); // Rekensommetje om 120 stapjes te verdelen over 1 seconde
  }
  // Servo verplaatst terug naar originele positie
  for (int pos = 120; pos >= 0; pos--) {
    JoyServo.write(pos);
    delay(1000 / 120); // Rekensommetje om 120 stapjes te verdelen over 1 seconde
  }
}
