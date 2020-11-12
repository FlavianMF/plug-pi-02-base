#ifndef __SETUPSTEPS_H__
#define __SETUPSTEPS_H__

#include <Arduino.h>

#include "pins.h"

void firstStep() {
  uint64_t timer = 0;
  timer = millis();
  digitalWrite(redLedPin, true);
  while (millis() < timer + 500)
    ;
  digitalWrite(redLedPin, false);
}

void secondStep() {
  uint64_t timer = 0;
  timer = millis();
  digitalWrite(yellowLedPin, true);
  while (millis() < timer + 500)
    ;
  digitalWrite(redLedPin, false);
}

void thirdStep() {
  uint64_t timer = 0;
  timer = millis();
  digitalWrite(greenLedPin, true);
  while (millis() < timer + 500)
    ;
  digitalWrite(redLedPin, false);
}

void steps() {
  firstStep();
  secondStep();
  thirdStep();
}

#endif  // __SETUPSTEPS_H__