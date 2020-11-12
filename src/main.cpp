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
uint16_t rawTemperatureValue = 0;

void loop() {
  rawTemperatureValue = lm35.read();
  rawPotentiometerValue = potentiometer.read();

  analogWrite(redLedPin, map(rawTemperatureValue, 0, 1024, 0, 255));
  analogWrite(greenLedPin, map(rawPotentiometerValue, 0, 1024, 0, 255));
}