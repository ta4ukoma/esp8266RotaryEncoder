/////////////////////////////////////////////////////////////////

#include "ESPRotary.h"
#include "Arduino.h"
/////////////////////////////////////////////////////////////////

#define ROTARY_PIN1	D2
#define ROTARY_PIN2	D1

const int ledPin = D8;

/////////////////////////////////////////////////////////////////

ESPRotary r = ESPRotary(ROTARY_PIN1, ROTARY_PIN2);

/////////////////////////////////////////////////////////////////

void rotate(ESPRotary& r);
void showDirection(ESPRotary& r);
//int getPosition(ESPRotary& r);

void setup() {
  Serial.begin(9600);
  delay(50);
  Serial.println("\n\nSimple Counter");
  
  r.setChangedHandler(rotate);
  r.setLeftRotationHandler(showDirection);
  r.setRightRotationHandler(showDirection);
  
}

void loop() {
  r.loop();
  int position = r.getPosition();
  analogWrite(ledPin, position * 10);
}

/////////////////////////////////////////////////////////////////

void rotate(ESPRotary& r) {
   Serial.println(r.getPosition());
}


void showDirection(ESPRotary& r) {
  Serial.println(r.directionToString(r.getDirection()));
}


/////////////////////////////////////////////////////////////////
