#include <Servo.h> // Servo library toevoegen

Servo JoyServo;  // Een servo object aanmaken

const int vrxPin = A0; // Pin for the joystick x-axis
const int buttonPin = 8; // Pin for the button

int buttonJoyState = HIGH; // Variable for button state

void setup() {
  JoyServo.attach(9); // Attach the servo to pin 9
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as input with an internal pull-up resistor
}

void loop() {
  buttonJoyState = digitalRead(buttonPin);
  
  if (buttonJoyState == LOW) {
    buttonPress();
  } else {
    moveJoyHorizontal();
  }
}
  
void moveJoyHorizontal() {
  // Read the status of the x-axis pin
  int pinX = analogRead(vrxPin);

  // Map the joystick value to the servo range (0 to 180 degrees)
  int posX = map(pinX, 0, 1023, 0, 180); 
 
  // Move the servo to the correct position
  JoyServo.write(posX);  
}

void buttonPress() {
  // Move the servo one step at a time when the button is pressed
  for (int pos = 0; pos <= 120; pos++) {
    JoyServo.write(pos);
    delay(1000 / 120); // Spread 180 steps over 1 second
  }
  // Move the servo back to the original position
  for (int pos = 120; pos >= 0; pos--) {
    JoyServo.write(pos);
    delay(1000 / 120); // Spread 180 steps over 1 second
  }
}
