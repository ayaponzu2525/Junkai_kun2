const int turnbk = 1500;

void right_clank(){
  forward();
  delay(1000);
  right();
  delay(turnbk);
  forward();
  delay(1000);
  left();
  delay(turnbk);
  forward();
  delay(1000);
}

void left_clank(){
  forward();
  delay(1000);
  left();
  delay(turnbk);
  forward();
  delay(1000);
  right();
  delay(turnbk);
  forward();
  delay(1000);
}