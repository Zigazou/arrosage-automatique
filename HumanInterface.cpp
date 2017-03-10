#include "HumanInterface.h"

#define SLICE 200

HumanInterface::HumanInterface(int *trigger)
: trigger(trigger)
, minimum(1023)
, maximum(0) {}

void HumanInterface::init() {
  this->lcd.init();
}

void HumanInterface::idelay(int msec) {
  msec /= SLICE;
  for(int i = 0; i < msec; i++) {
    delay(200);
    this->updateTrigger();
  }
}

void HumanInterface::updateTrigger() {
  char str[8];

  switch(this->lcd.get_key()) {
    case 1: *(this->trigger) += 10; break;
    case 2: *(this->trigger) -= 10; break;
  }

  if(*(this->trigger) > 1020) *(this->trigger) = 1020;
  if(*(this->trigger) < 10) *(this->trigger) = 10;

  this->lcd.setCursor(0, 0);
  sprintf(str, "t%04d", *(this->trigger));
  this->lcd.print(str);
}

void HumanInterface::updateValue(int value) {
  char str[8];

  if(value < minimum) minimum = value;
  if(value > maximum) maximum = value;
  
  this->lcd.setCursor(6, 0);
  sprintf(str, "v%04d", value);
  this->lcd.print(str);

  this->lcd.setCursor(0, 1);
  sprintf(str, "m%04d", minimum);
  this->lcd.print(str);

  this->lcd.setCursor(6, 1);
  sprintf(str, "M%04d", maximum);
  this->lcd.print(str);
}

void HumanInterface::updateDisplay(int value) {
  this->updateTrigger();
  this->updateValue(value);
}

