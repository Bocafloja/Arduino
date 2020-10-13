int stp = 1;
int start = 2;
int st = 3;
int s1 = 4;
int s2 = 5;
int s3 = 6;
int err = 7;
int p1 = 8;
int p2 = 9;
int p3 = 10;
int piston1y2[] = {0,1,1,0,0,0};
int p1p2p3[] = {0,1,1,1,1,0};
int fin[] = {1,1,1,1,1,1};

void setup() {
  
  pinMode(stp, INPUT);
  pinMode(start, INPUT);
  pinMode(st, INPUT);
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(err, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);

}

void loop() {

  int vector[] = {digitalRead(stp),digitalRead(start),digitalRead(st),digitalRead(s1),digitalRead(s2),digitalRead(s3)};

  if (vector == piston1y2) {
    p1 = HIGH;
    p2 = HIGH;
    p3 = LOW;
    err = LOW;
    delay(2000);
  }
  else if (vector == p1p2p3) {
    p1 = HIGH;
    p2 = HIGH;
    p3 = HIGH;
    err = LOW;
    delay(2000);
  }
  else if (vector == fin) {
    p1 = LOW;
    p2 = LOW;
    p3 = LOW;
    err = LOW;
    delay(2000);
  }
  else {
    err = HIGH;
    p1 = LOW;
    p2 = LOW;
    p3 = LOW;
    delay(2000);
  }

}
