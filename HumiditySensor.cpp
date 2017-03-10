#include "HumiditySensor.h"

#include <Arduino.h>

HumiditySensor::HumiditySensor(int pin) : pin(pin) {}

int HumiditySensor::read() {
  return analogRead(this->pin);
}

