// dht11.hpp
#ifndef ATTIC_HPP
#define  ATTIC_HPP
#include "ACencor.hpp"
#include "Servo.h"
class Attic : public ACencor {
  private:
  int pos;
  bool attic_status;
  Servo servo;
  public:
  void move(int);
public:
  String getDatas() override;
  String serialize() override;
  void open();
  void close();
  bool getStatus();
  Attic();
};


#endif // ATTIC_HPP