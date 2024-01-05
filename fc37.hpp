#include "WString.h"
// fc37.hpp
#ifndef FC37_HPP
#define FC37_HPP

//#include <Arduino.h>
// may we override ACencor???
// use this cencor's percentage method, %60 or less is wet.
#include "ACencor.hpp"
#define ANALOGPIN A0
#define MIN_VOLTAGE 0
#define MAX_VOLTAGE 1024
class Fc37 : public ACencor {
public:
  int sensorReading;
  int range ;
public:
  Fc37();
  String serialize() override;
  String getDatas() override;
  bool isRaining();
};

#endif
