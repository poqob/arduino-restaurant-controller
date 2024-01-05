#include "Attic.hpp"

String Attic::getDatas() {
  return "data";
}
String Attic::serialize() {
  return attic_status ? "1" : "0";
}

void Attic::open() {
  servo.write(pos++);
  attic_status = true;
}
void Attic::close() {
  servo.write(pos--);
  attic_status = false;
}

// +-1* 90 degree rotation.
void Attic::move(int direction) {
 
}
Attic::Attic() {
  attic_status =false;
  pos = 0;
  servo.attach(9);
}

bool Attic::getStatus(){return attic_status;}