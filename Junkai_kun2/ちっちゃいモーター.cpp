#include <Arduino.h>

const int mt1Pin1 = 3;
const int mt1Pin2 = 5;
const int mt2Pin1 = 6;
const int mt2Pin2 = 9;

void forward();
void free();
void back();
void brake();
void right();
void left();

void setup() {
  pinMode( mt1Pin1, OUTPUT );
  pinMode( mt1Pin2, OUTPUT );
  pinMode( mt2Pin1, OUTPUT );
  pinMode( mt2Pin2, OUTPUT );
}

void loop() {
forward();
}

void forward(){
  analogWrite( mt1Pin1, 255 );
  analogWrite( mt1Pin2, 0 );
  analogWrite( mt2Pin1, 255 );
  analogWrite( mt2Pin2, 0 );
}

void free(){
  analogWrite( mt1Pin1, 0 );
  analogWrite( mt1Pin2, 0 );
  analogWrite( mt2Pin1, 0 );
  analogWrite( mt2Pin2, 0 );
}

void back(){
  analogWrite( mt1Pin1, 0 );
  analogWrite( mt1Pin2, 255 );
  analogWrite( mt2Pin1, 0 );
  analogWrite( mt2Pin2, 255 );
}

void brake(){
  analogWrite( mt1Pin1, 255 );
  analogWrite( mt1Pin2, 255 );
  analogWrite( mt2Pin1, 255 );
  analogWrite( mt2Pin2, 255 );
}

void right(){
  analogWrite( mt1Pin1, 255 );
  analogWrite( mt1Pin2, 0 );
  analogWrite( mt2Pin1, 0 );
  analogWrite( mt2Pin2, 255 );
}

void left(){
  analogWrite( mt1Pin1, 0 );
  analogWrite( mt1Pin2, 255 );
  analogWrite( mt2Pin1, 255 );
  analogWrite( mt2Pin2, 0 );
}

