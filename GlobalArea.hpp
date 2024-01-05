#if !defined(GLOBAL_AREA)
#define GLOBAL_AREA

#include "WString.h"

class GlobalArea {
public:
  static String color;  // color json
  static bool attic;    // true or false
  static bool automatic_attic;
  static bool buzzer;
  static bool isRaining;
  static String dht;

  // Additional members or methods can be added here if needed.

  // Ensure that no instances of GlobalArea can be created.
  GlobalArea() = delete;

  // Optional: Method to initialize global variables
  static void initialize() {
    color = "{\"status\": 1, \"red\": 0, \"green\": 0, \"blue\": 0}";
    attic = false;
    automatic_attic = false;
    buzzer = false;
    isRaining = false;
    dht = "";
  }
};


#endif  // GLOBAL_AREA
