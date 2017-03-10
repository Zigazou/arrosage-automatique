#include "HumiditySensor.h"
#include "ElectroValve.h"
#include "HumanInterface.h"

#define HUMIDITYSENSORPIN 1
#define VALVEPIN 13

int openDelay = 2000;
int interval = 3000;
int trigger = 100;

int raw = 0;

ElectroValve valve(VALVEPIN);
HumiditySensor sensor(HUMIDITYSENSORPIN);
HumanInterface screen(&trigger);

void setup() {
  screen.init();
  valve.init();
}

void loop() {
  raw = sensor.read();

  screen.updateDisplay(raw);

  if(raw > trigger) {
    valve.open();
    screen.idelay(openDelay);
    valve.close();
  }
  
  screen.idelay(interval);
}
