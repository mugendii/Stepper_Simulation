#include <Arduino.h>

// pins connected to the TB6600 driver
const int stepPin = 2;  // PUL+
const int dirPin = 3;   // DIR+
const int enPin = 4;    // ENA+

//const int stopButtonPin = 5; // Pin connected to a stop button


// speed and duration
const int stepDelay = 500; // Delay between steps (microseconds), adjust for moderate speed
const unsigned long forwardTime = 300000; // 5 minutes in milliseconds
const unsigned long backwardTime = 300000; // 5 minutes in milliseconds

void setup() {
  
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  //pinMode(stopButtonPin, INPUT_PULLUP);
  // Enable the driver
  digitalWrite(enPin, LOW);
}



void moveMotor(unsigned long duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    // Check if the stop button is pressed
    //if (digitalRead(stopButtonPin) == LOW) {
      // Stop the motor
     // break;
   // }
    Serial.println("Toggling Step Pin");
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(stepDelay);
  }
}
void loop() {
  // Move forward
  digitalWrite(dirPin, HIGH);
  moveMotor(forwardTime);

  // Short delay before reversing direction
  delay(1000);

  // Move backward
  digitalWrite(dirPin, LOW);
  moveMotor(backwardTime);
}