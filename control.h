#pragma once

class Component {
  protected:
    int pin = A0;
  public:
    void setPin(int pin);
};

class Sensor : public Component {
  private:
    int points = 0;
    double y_cum = 0;
    double y_last = 0;
    double (*f)(double voltage);    
  public:
    void update();
    double mean();
    double read();
    double convert(double voltage);
    void setConvertFunction(double (*f)(double));
};
