#include "WString.h"
#if !defined(LOG)
#define LOG
#include "Arduino.h"
class Log
{
String dht11;
bool attic;
bool rain;
public:
    Log(String,bool,bool);// dht map, attic, rain
    Log();
    String serialize();
    static String serialize(String,bool,bool);
};

#endif // Log
