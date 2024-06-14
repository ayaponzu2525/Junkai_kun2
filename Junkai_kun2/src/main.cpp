#include <Arduino.h>

const int mt1Pin1 = 3;
const int mt1Pin2 = 5;
const int mt2Pin1 = 6;
const int mt2Pin2 = 9;

void setup() {
  pinMode( mt1Pin1, OUTPUT );
  pinMode( mt1Pin2, OUTPUT );
  pinMode( mt2Pin1, OUTPUT );
  pinMode( mt2Pin2, OUTPUT );
}

void loop() {
  analogWrite( mt1Pin1, 255 );
  analogWrite( mt1Pin2, 0 );
  analogWrite( mt2Pin1, 255 );
  analogWrite( mt2Pin2, 0 );
  delay(1000);
  analogWrite( mt1Pin1, 0 );
  analogWrite( mt1Pin2, 255 );
  analogWrite( mt2Pin1, 0 );
  analogWrite( mt2Pin2, 255 );
  delay(1000);
}

