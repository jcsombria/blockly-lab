#include <TimerOne.h>
#include "control.h"

const uint16_t period = 10000;
// -- Sensor declaration: 
// Sensor sensor1;

// -- Control Loop
void tic() {
}

void setup(void) {
// -- Sensor pin mapping:
// sensor1.setPin(pin);
  
  Timer1.initialize(period);
  Timer1.attachInterrupt(tic);
}

void loop(void) {
}
