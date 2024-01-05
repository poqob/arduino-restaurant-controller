#include "Log.hpp"

Log::Log(String dht_map,bool attic_status, bool rain_status):attic(attic_status), rain(rain_status), dht11(dht_map){}
Log::Log(){}
String Log::serialize(){
  String res="{\"dht\":";
  res+= dht11;
  res+=",\"attic\":";
  res+= attic?'1':'0';
  res+=",\"rain\":";
  res+= rain?'1':'0';
  return res+"}";
}


String Log::serialize(String dht_map, bool attic_status, bool rain_status){
  String res="{\"dht\":";
  res+= dht_map;
  res+=",\"attic\":";
  res+= attic_status?'1':'0';
  res+=",\"rain\":";
  res+= rain_status?'1':'0';
  return res+"}";
}