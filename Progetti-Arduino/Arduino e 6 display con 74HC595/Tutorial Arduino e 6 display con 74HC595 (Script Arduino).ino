// Video Tutorial : http://youtu.be/3ns-o_wKzHI
// By EletroLaix

//Variabili per la comunicazione seriale
int data1 = 10;
int data2 = 8 ;
int clock = 12;
int latch1 = 11;
int latch2 = 9;

//Variabili per la determinazione delle cifre
int u  = 0;
int d  = 0;
int c  = 0;
int um = 0;
int dm = 0;
int cm = 0;
int n  = 0;

//Variabili per la determinazione del tempo
int z  = 1;
int di = 0;
int y  = 0;
int t  = 1000;
int ti = 1;

void setup () {
  pinMode ( data1 , OUTPUT);
  pinMode ( data2 , OUTPUT);
  pinMode ( clock , OUTPUT);
  pinMode ( latch1, OUTPUT);
  pinMode ( latch2, OUTPUT);
}

void loop () {
  for (y = 0; y < t; y += ti) {
  switch (z) {
    case 1: N(u ); di = 2  ;      break;
    case 2: N(d ); di = 4  ;      break;
    case 3: N(c ); di = 8  ;      break;
    case 4: N(um); di = 16 ;      break;
    case 5: N(dm); di = 32 ;      break;
    case 6: N(cm); di = 64 ; z=0; break;
  }
  
  digitalWrite ( latch2 , LOW  );
  shiftOut     ( data2, clock, MSBFIRST, di );
  digitalWrite ( latch2 , HIGH );
  z += 1;
  delay (ti);
  }
  
  u += 1;
  if (u  > 9 ) {d  += 1 ; u  = 0;}
  if (d  > 9 ) {c  += 1 ; d  = 0;}
  if (c  > 9 ) {um += 1 ; c  = 0;}
  if (um > 9 ) {dm += 1 ; um = 0;}
  if (dm > 9 ) {cm += 1 ; dm = 0;}
  if (cm > 9 ) {cm  = 0 ; dm = 0; um = 0; c = 0; d = 0; u  = 0;}
}

void N(int n) {
     S();
  digitalWrite(latch1,LOW);
    switch (n) {
    case 0: shiftOut(data1, clock, MSBFIRST, 16 ); break;
    case 1: shiftOut(data1, clock, MSBFIRST, 219); break;
    case 2: shiftOut(data1, clock, MSBFIRST, 40 ); break;
    case 3: shiftOut(data1, clock, MSBFIRST, 136); break;
    case 4: shiftOut(data1, clock, MSBFIRST, 194); break;
    case 5: shiftOut(data1, clock, MSBFIRST, 132); break;
    case 6: shiftOut(data1, clock, MSBFIRST, 4  ); break;
    case 7: shiftOut(data1, clock, MSBFIRST, 216); break;
    case 8: shiftOut(data1, clock, MSBFIRST, 0  ); break;
    case 9: shiftOut(data1, clock, MSBFIRST, 128); break;
    }
  digitalWrite (latch1,HIGH);
}

void S() {
   digitalWrite ( latch2, LOW );
   shiftOut     ( data2, clock, MSBFIRST, 0);
   digitalWrite ( latch2, HIGH);
  }
