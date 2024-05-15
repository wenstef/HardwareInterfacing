// Using a loop to initialize pins 6 - 13 as outputs
void setup() {
  // Set all LED pins (6 to 13) as outputs
  for (int pin = 6; pin <= 13; pin++) {
    pinMode(pin, OUTPUT); // Set the pin mode to OUTPUT
  }
}

void loop() {
  left(75);  // Call the left function with a delay of 75 milliseconds
  right(75); // Call the right function with a delay of 75 milliseconds
}

// The left function iterates through the specified pins, calling blinkLED function
void left(int tijd) {
  for (int pin = 6; pin <= 13; pin++) {
    blinkLED(pin, tijd); // Call blinkLED function for each pin with delay
  }
}

// The right function also iterates through the pins, calling blinkLED function
void right(int tijd) {
  for (int pin = 6; pin <= 13; pin++) {
    blinkLED(pin, tijd); // Call blinkLED function for each pin with delay
  }
}

// Turning LED on and off by toggling the state of a LED
void blinkLED(int pin, int tijd) {
  digitalWrite(pin, HIGH);
  delay(tijd);              
  digitalWrite(pin, LOW);  
  delay(tijd);             
}
