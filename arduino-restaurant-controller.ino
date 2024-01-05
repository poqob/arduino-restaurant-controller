//
//    FILE: rain_interrupt.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo rain_interrupt digital out
//     URL: https://github.com/RobTillaart/RAIN


#include "fc37.hpp"
#include "dht11.hpp"
#include "Log.hpp"
#include "Attic.hpp"
#include "RGBLed.hpp"
#include "SerialMessager.hpp"
#include "GlobalArea.hpp"
#define ANALOGPIN A0
//#define POWERPIN 7
#define DIGIOUT_IRQ 2
#define BUZZER 7
Fc37 fc37;
Dht11 dht;
//Attic attic;
Servo servo;
RgbLed led;
bool lock;
SerialMessager messager;

void readTemprature() {
  lock = true;
  dht.readTemperature();
  lock = false;
}

void readHumidity() {
  lock = true;
  dht.readHumidity();
  GlobalArea::dht = dht.serialize();
  GlobalArea::isRaining = fc37.isRaining();
  lock = false;
}





static unsigned long previousMillis = 0;
const unsigned long interval = 1000;  // 1000 milliseconds
unsigned long currentMillis = millis();


bool block(int seconds = 1) {
  currentMillis = millis();
  if (currentMillis - previousMillis >= interval * seconds) {
    previousMillis = currentMillis;
    return true;
  } else
    return false;
}
void controlServo() {
  static unsigned long _previousMillis = 0;
  const unsigned long interval = 1000;

  unsigned long _currentMillis = millis();

  if (_currentMillis - _previousMillis >= interval) {
    _previousMillis = _currentMillis;

    // Toggle the servo position
    if (GlobalArea::attic) {
      servo.write(180);  // Move servo to 180 degrees
    } else {
      servo.write(0);  // Move servo to 0 degrees
    }

    //servoState = !servoState;
  }
}



void setup() {
  Serial.begin(115200);
  dht = Dht11();
  fc37 = Fc37();
  //attic = Attic();  // false the attic is closed.
  servo.attach(9);
  led = RgbLed();
  lock = false;
  pinMode(BUZZER, OUTPUT);

  //messager=SerialMessager(global);
  GlobalArea::initialize();
  led.colorify(GlobalArea::color);
  //attachInterrupt(digitalPinToInterrupt(DIGIOUT_IRQ), isr, FALLING);
}
void loop() {

  // work for dht continously;
  while (block(2))
    readTemprature();
  while (block())
    readHumidity();

  while (block(60)) { 
    lock = true;
    Serial.println(messager.sendLog());
    lock = false;
  }
  controlServo();

  // if automatic attic is active, listen rain sensor.
  if (GlobalArea::automatic_attic)
    GlobalArea::attic = fc37.isRaining();

  if (GlobalArea::buzzer == true) {
    tone(BUZZER, 1000);
    while (block()) {
      noTone(BUZZER);
      GlobalArea::buzzer = false;
    }
  }

  // Check for incoming serial data
  if (Serial.available() > 0 && !lock) {
    String line = Serial.readStringUntil('\n');
    String out = messager.read(line);
    if (out.length() > 0)
      Serial.println(out);
    led.colorify(GlobalArea::color);
  }
}




// -- END OF FILE --