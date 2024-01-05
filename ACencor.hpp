#ifndef ACENCOR
#define ACENCOR
#include "Arduino.h"
class ACencor{
  public:
  ACencor();
  virtual String getDatas()=0; // returns data as string.
  virtual String serialize()=0; // returns serialized cencor content.
};
#endif 