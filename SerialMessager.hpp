#if !defined(SERIAL_MESSAGER)
#define SERIAL_MESSAGER

#include "WString.h"
#include "Log.hpp"
#include "GlobalArea.hpp"
class SerialMessager {
public:
   String heading_esp;
   String heading_ard;
   String color;   //... color json
   String waiter;  //... desk rfid
   String attic;   // ... 0~1
   String log;     // ... log json
   String automatic_attic; // 0~1
public:
  SerialMessager();
   String send(String);
   String sendLog();
   String read(String);
};

#endif  // SERIAL_MESSAGER
