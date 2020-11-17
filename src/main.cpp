#include <Arduino.h>
#include <EduIntro.h>

#include "pins.h"
#include "setupFunctions.h"
#include "setupSteps.h"

LM35 lm35(lm35Pin);
Potentiometer potentiometer(potentiometerPin);

void setup() {
  Serial.begin(115200);

  setupPins();

  steps();
}

uint16_t rawPotentiometerValue = 0;

void loop() {
  rawPotentiometerValue = analogRead();

  if (rawPotentiometerValue <= 333) {
    analogWrite(greenLedPin, map(rawPotentiometerValue, 0, 333, 0, 255));
    analogWrite(redLedPin, 0);
    analogWrite(yellowLedPin, 0);
  } else if (rawPotentiometerValue >= 666) {
    analogWrite(redLedPin, map(rawPotentiometerValue, 666, 1000, 0, 255));
    analogWrite(yellowLedPin, 255);
    analogWrite(greenLedPin, 255);
  } else {
    analogWrite(yellowLedPin, map(rawPotentiometerValue, 333, 666, 0, 255));
    analogWrite(redLedPin, 0);
    analogWrite(yellowLedPin, 255);
  }
}