const int pwm3 = 3;
const int pwm5 = 5;
const int pwm6 = 6;
const int pwm9 = 9;

#include <Arduino.h>

const int mt1Dir = 2;
const int mt1Pwm = 3;
const int mt2Dir = 4;
const int mt2Pwm = 5;

const int Cw = 0;
const int Ccw = 1;

int speed = 0;
int maxspeed = 101;

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
  delay(5000);//モーターに電源を入れてからspresense(モバ充)の電源を入れるとバグるの防止待機時間
}

void loop(){
    forward();
}

void forward(){
  digitalWrite(mt1Dir, Cw);
  digitalWrite(mt2Dir, Ccw);
  for (speed; speed < maxspeed; speed++){
    analogWrite(mt1Pwm, speed);
    analogWrite(mt2Pwm, speed);
    delay(10);
  }
  analogWrite(mt1Pwm, maxspeed);
  analogWrite(mt2Pwm, maxspeed);
}

void back(){
    digitalWrite(mt1Dir, Ccw);
    digitalWrite(mt2Dir, Cw);

    for (speed; speed < maxspeed; speed++){
    analogWrite(mt1Pwm, speed);
    analogWrite(mt2Pwm, speed);
    delay(10);
  }

    analogWrite(mt1Pwm, maxspeed);
    analogWrite(mt2Pwm, maxspeed);
}

void right(){
    digitalWrite(mt1Dir, Ccw);
    digitalWrite(mt2Dir, Ccw);

    analogWrite(mt1Pwm, maxpeed);
    analogWrite(mt2Pwm, maxpeed);
}
void left(){
    digitalWrite(mt1Dir, Cw);
    digitalWrite(mt2Dir, Cw);

    analogWrite(mt1Pwm, maxspeed);
    analogWrite(mt2Pwm, maxspeed);
}

void brake(){
    analogWrite(mt1Pwm, 0);
    analogWrite(mt2Pwm, 0); 
}