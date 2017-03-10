#include "ElectroValve.h"

#include <Arduino.h>

ElectroValve::ElectroValve(int pin) : pin(pin) {}

void ElectroValve::init() {
  pinMode(this->pin, OUTPUT);
  this->close();
}

void ElectroValve::open() {
  digitalWrite(this->pin, HIGH);
}

void ElectroValve::close() {
  digitalWrite(this->pin, LOW);
}

