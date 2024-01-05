// fc37.cpp
#include "fc37.hpp"

Fc37::Fc37() {
  sensorReading = analogRead(ANALOGPIN);
  range = map(sensorReading, MIN_VOLTAGE, MAX_VOLTAGE, 0, 3);
}
String Fc37::getDatas() {
  String result = "data";  // You might want to allocate memory and populate result
  sensorReading = analogRead(ANALOGPIN);
  range = map(sensorReading, MIN_VOLTAGE, MAX_VOLTAGE, 0, 3);
  return result;
}

String Fc37::serialize() {
  getDatas();
  String res ;
  switch (range) {
    case 0:
      res ="sel";
      break;
    case 1:
      res="Yağmur";
      break;
    case 2:
      res="Hava Açık";
      break;
  }
  return res;
}


bool Fc37::isRaining(){
  getDatas();
  if(range==2)
    return false;
  return true;
}
