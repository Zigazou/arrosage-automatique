#ifndef HumiditySensor_h
#define HumiditySensor_h

class HumiditySensor {
  private:
    int pin;

  public:
    HumiditySensor(int pin);
    int read();
};

#endif
