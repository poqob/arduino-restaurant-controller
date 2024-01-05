// dht11.hpp
#ifndef DHT11_HPP
#define DHT11_HPP
#include <DHT11.h>
#include "ACencor.hpp"

class Dht11 : public ACencor {
  private:
  DHT11 dht11;
  int temperature;
  int humidity;
public:
void readHumidity();
void readTemperature();
public:
  String getDatas() override;
  String serialize() override;
  
  Dht11();
};


// do thing.
#endif