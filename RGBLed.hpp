#include <stdint.h>
#ifndef LED_HPP
#define LED_HPP
#include "ACencor.hpp"
#define RED 3
#define GREEN 4
#define BLUE 5


class RgbLed : public ACencor {
  private:
    bool led_status;
    String color;
public:
  String getDatas() override;
  String serialize() override;
  void colorify(String);
  void setColor(int,int,int);// red, green, blue
  bool getLedStatus();
 public: 
  RgbLed();
};


// do thing.
#endif