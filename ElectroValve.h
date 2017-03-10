#ifndef ElectroValve_h
#define ElectroValve_h

class ElectroValve {
  private:
    int pin;

  public:
    ElectroValve(int pin);
    void init();
    void open();
    void close();
};

#endif
