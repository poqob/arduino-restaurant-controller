#include "WString.h"
#include "Arduino.h"
#include "RGBLed.hpp"

void RgbLed::colorify(String jsonString) {
  // Find the positions of key-value pairs
  int statusStart = jsonString.indexOf("\"status\":") + 9;
  int redStart = jsonString.indexOf("\"red\":") + 6;
  int greenStart = jsonString.indexOf("\"green\":") + 8;
  int blueStart = jsonString.indexOf("\"blue\":") + 7;

  // Extract substrings containing values
  String statusStr = jsonString.substring(statusStart, jsonString.indexOf(",", statusStart));
  String redStr = jsonString.substring(redStart, jsonString.indexOf(",", redStart));
  String greenStr = jsonString.substring(greenStart, jsonString.indexOf(",", greenStart));
  String blueStr = jsonString.substring(blueStart, jsonString.indexOf("}", blueStart));

  // Convert strings to integers
  int status = statusStr.toInt();
  int red = redStr.toInt();
  int green = greenStr.toInt();
  int blue = blueStr.toInt();
  color = "r:" + String(red) +" g:"+ String(green)+" b:"+String (blue);
  
  // Use the parsed values as needed
  led_status = status == 0 ? 0 : 1;
  if (led_status != 0)
    setColor(red, green, blue);
  else
    colorify(" {\"status\": 1, \"red\": 0, \"green\": 0, \"blue\": 0}");
}

RgbLed::RgbLed() {
  //  Set the RGB LED pins as OUTPUTs
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  led_status=false;
}

void RgbLed::setColor(int red, int green, int blue) {
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}

String RgbLed::getDatas(){return color;}
String RgbLed::serialize(){return "serialize";}
bool RgbLed::getLedStatus(){return led_status;}
