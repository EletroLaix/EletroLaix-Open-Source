// Video Tutorial: http://youtu.be/QhdOLAkNWD0
// By EletroLaix

int vm = 10  ;
int s  = 0 ;

void setup() {
  pinMode      (1,   INPUT);
  pinMode      (13, OUTPUT);
  pinMode      (12, OUTPUT);
  pinMode      (11, OUTPUT);
  pinMode      (10, OUTPUT);
  pinMode      (9,  OUTPUT);
  pinMode      (8,  OUTPUT);
  pinMode      (7,  OUTPUT);
  pinMode      (6,  OUTPUT);
  pinMode      (5,  OUTPUT);
  pinMode      (4,  OUTPUT);
  pinMode      (3,  OUTPUT);
  pinMode      (2,  OUTPUT);
}

void loop() {
    s = analogRead(1);
    if ( (vm *1)  <s) {digitalWrite (13 ,HIGH);} else {digitalWrite (13 ,LOW);}
    if ( (vm *2)  <s) {digitalWrite (12 ,HIGH);} else {digitalWrite (12 ,LOW);}
    if ( (vm *3)  <s) {digitalWrite (11 ,HIGH);} else {digitalWrite (11 ,LOW);}
    if ( (vm *4)  <s) {digitalWrite (10 ,HIGH);} else {digitalWrite (10 ,LOW);}
    if ( (vm *5)  <s) {digitalWrite (9  ,HIGH);} else {digitalWrite (9  ,LOW);}
    if ( (vm *6)  <s) {digitalWrite (8  ,HIGH);} else {digitalWrite (8  ,LOW);}
    if ( (vm *7)  <s) {digitalWrite (7  ,HIGH);} else {digitalWrite (7  ,LOW);}
    if ( (vm *8)  <s) {digitalWrite (6  ,HIGH);} else {digitalWrite (6  ,LOW);}
    if ( (vm *9)  <s) {digitalWrite (5  ,HIGH);} else {digitalWrite (5  ,LOW);}
    if ( (vm *10) <s) {digitalWrite (4  ,HIGH);} else {digitalWrite (4  ,LOW);}
    if ( (vm *11) <s) {digitalWrite (3  ,HIGH);} else {digitalWrite (3  ,LOW);}
    if ( (vm *12) <s) {digitalWrite (2  ,HIGH);} else {digitalWrite (2  ,LOW);}
  }