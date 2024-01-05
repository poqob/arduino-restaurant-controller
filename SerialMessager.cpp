#include "WString.h"

#include "SerialMessager.hpp"

SerialMessager::SerialMessager() {
  heading_esp = "esp-";
  color = "color:";      //... color json
  waiter = "waiter:";    //... desk rfid
  attic = "attic:";      // ... 0~1
  log = "log_request";  // ... log json
  automatic_attic = "automatic_attic:";
  heading_ard = "ard-";
}
String SerialMessager::send(String message) {
  return heading_ard + message;
}



String SerialMessager::read(String read) {
  if (read.indexOf(heading_esp) != -1) {
    if (read.indexOf(heading_esp + color) != -1) {
      String sub = read.substring(heading_esp.length() + color.length());
      GlobalArea::color = sub;
      return heading_ard + "color received " + sub;
    } else if (read.indexOf(heading_esp + attic) != -1) {
      int index = read.indexOf(heading_esp + attic);
      char _attic = read.charAt(heading_esp.length() + attic.length());
      char is_automatic = read.charAt(heading_esp.length() + attic.length() + 2);
      // ATTIC
      if (_attic == '0')
        GlobalArea::attic = false;
      else
        GlobalArea::attic = true;
      // AUTOMATIC ATTIC
      if (is_automatic == '0')
        GlobalArea::automatic_attic = false;
      else
        GlobalArea::automatic_attic = true;

      return heading_ard + "attic received " + attic + " automatic " + is_automatic;
    } else if (read.indexOf(heading_esp + waiter) != -1) {
      GlobalArea::buzzer = !GlobalArea::buzzer;
      return heading_ard + "waiter received";
    } else if (read.indexOf(heading_esp + log) != -1) {
      String _log = Log().serialize(GlobalArea::dht, GlobalArea::attic, GlobalArea::isRaining);
      return heading_ard + log + " " + _log;
    }
  }
  return "";
}

String SerialMessager::sendLog(){
  String result="";
  result+=heading_ard;
  result += log;
  result+= Log().serialize(GlobalArea::dht,GlobalArea::attic,GlobalArea::isRaining);
  return result;
}
