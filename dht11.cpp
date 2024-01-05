#include "Arduino.h"
#include "HardwareSerial.h"
#include "dht11.hpp"

String Dht11::getDatas() {
  return "";
}




String Dht11::serialize() {
  String result = "{\"temperature\":";
  result += this->temperature;
  result += ",\"humidity\":";
  result += this->humidity;
  result += "}";
  return result;
}

void Dht11::readHumidity(){
this->humidity= dht11.readHumidity();
}

void Dht11::readTemperature(){
  this->temperature = dht11.readTemperature();

}

Dht11::Dht11() :dht11(2){
  //this->dht11 = &dht11;
  //this.dht11=dht11;
}
