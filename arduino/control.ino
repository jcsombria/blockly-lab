double Sensor::read() {
  int sensorReading = analogRead(pin);
  double voltage = sensorReading * 5.0 / 1024.0;
  return voltage;
}

void Sensor::update() {
  points ++;
  int sensorReading = analogRead(pin);
  double voltage = sensorReading * 5.0 / 1024.0;
  if(!isnan(voltage)) {
    y_last = voltage;
    y_cum += y_last;
  }
}

double Sensor::mean() {
  if(points == 0) {
    return 0.0;
  }
  double value = y_cum / points;
  y_cum = 0;
  points = 0;
  return value;
}

double Sensor::convert(double voltage) {
  return f(voltage);
}

void Sensor::setConvertFunction(double (*f)(double)) {
  this->f = f;
}
