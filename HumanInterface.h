#ifndef HumanInterface_h
#define HumanInterface_h

#include <Arduino.h>
#include <Deuligne.h>

class HumanInterface {
  private:
    Deuligne lcd;
    int *trigger;
    int minimum;
    int maximum;

  public:
    HumanInterface(int *trigger);

    void init();
    void idelay(int msec);
    void updateTrigger();
    void updateValue(int value);
    void updateDisplay(int value);
};

#endif
