#include <Servo.h>  // Servo library toevoegen

Servo MyServo;  // Een servo object aanmaken

const int leftButtonPin = 8;   // Pin voor de linker knop
const int rightButtonPin = 9;  // Pin voor de rechter knop

int buttonLeftState = LOW;  // Variabele voor status linker knop
int buttonRightState = LOW; // Variabele voor status rechter knop

void setup() {
  MyServo.attach(11);  // De servo is aan pin 11 gekoppeld
  pinMode(leftButtonPin, INPUT);  // De knoppen instellen als input
  pinMode(rightButtonPin, INPUT); // "" 
}

void loop() {
  buttonLeftState = digitalRead(leftButtonPin);  // Om de status uit te lezen van de linker knop
  buttonRightState = digitalRead(rightButtonPin); // Om de status uit te lezen van de rechter knop

  // Eerst de logica voor beide knoppen
  if (buttonLeftState == HIGH && buttonRightState == HIGH) {
    // Wanneer beide knoppen zijn ingedrukt, servo steeds 1 stap verplaatsen
    for (int pos = 0; pos <= 120; pos++) {
      MyServo.write(pos);
      delay(1000 / 120); // Rekensommetje om 120 stapjes te verdelen over 1 seconde
    }
    delay(2000); // 2 seconden wachten voordat de servo in originele positie terug geplaatst wordt
    for (int pos = 120; pos >= 0; pos--) {
      MyServo.write(pos);
      delay(1000 / 120); // Rekensommetje om 120 stapjes te verdelen over 1 seconde
    }
  } else if (buttonLeftState == HIGH) {
    fastMove();
  } else if (buttonRightState == HIGH) {
    slowMove();
  }
}

void fastMove() {
  // Indien rechter knop is ingedrukt, servo steeds 1 stap verplaaten
  for (int pos = 0; pos <= 120; pos++) {
    MyServo.write(pos);
    delay(1000 / 120); // Rekensommetje om 120 stapjes te verdelen over 1 seconde
  }
  // Servo verplaatst terug naar originele positie
  for (int pos = 120; pos >= 0; pos--) {
    MyServo.write(pos);
    delay(1000 / 120); // Rekensommetje om 120 stapjes te verdelen over 1 seconde
  }
}

void slowMove() {
  // Indien linker knop is ingedrukt, servo steeds 1 stap verplaaten
  for (int pos = 0; pos <= 120; pos++) {
    MyServo.write(pos);
    delay(500 / 120); // Rekensommetje om 120 stapjes te verdelen over 0,5 seconde
  }
  // Servo verplaatst terug naar originele positie
  for (int pos = 120; pos >= 0; pos--) {
    MyServo.write(pos);
    delay(500 / 120); // Rekensommetje om 120 stapjes te verdelen over 0,5 seconde
  }
}
