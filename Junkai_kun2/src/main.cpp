#include <Arduino.h>

const int mt1Dir = 2;
const int mt1Pwm = 3;
const int mt2Dir = 4;
const int mt2Pwm = 5;

const int Cw = 0;
const int Ccw = 1;

void forward();
void back();
void right();
void left();
void brake();

void setup() {
  pinMode( mt1Dir, OUTPUT );
  pinMode( mt1Pwm, OUTPUT );
  pinMode( mt2Dir, OUTPUT );
  pinMode( mt2Pwm, OUTPUT );
}

void loop(){
    forward();
}

void forward(){
    digitalWrite(mt1Dir, Cw);
    digitalWrite(mt2Dir, Cw);

    analogWrite(mt1Pwm, 255);
    analogWrite(mt2Pwm, 255);
}

void back(){
    digitalWrite(mt1Dir, Ccw);
    digitalWrite(mt2Dir, Ccw);

    analogWrite(mt1Pwm, 255);
    analogWrite(mt2Pwm, 255);
}

void right(){
    digitalWrite(mt1Dir, Ccw);
    digitalWrite(mt2Dir, Cw);

    analogWrite(mt1Pwm, 255);
    analogWrite(mt2Pwm, 255);
}
void left(){
    digitalWrite(mt1Dir, Cw);
    digitalWrite(mt2Dir, Ccw);

    analogWrite(mt1Pwm, 255);
    analogWrite(mt2Pwm, 255);
}

void brake(){
    analogWrite(mt1Pwm, 255);
    analogWrite(mt2Pwm, 255); 
}