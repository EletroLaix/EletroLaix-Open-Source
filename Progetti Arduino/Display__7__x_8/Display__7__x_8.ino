const byte N[] = {237, 33, 203, 107, 39, 110, 238, 41, 239, 111, 16};
int numero[8];

const byte data = 2, clock = 0, latch = 1;

bool temp = true;

bool verso = false;

#include <DS1302.h>

//        (RST,DAT,CLK)
DS1302 rtc(  3,  4,  0);

//                     {anno, mese, giorno, ora, minuti, secondi}
unsigned int Start[] = {2017,    1,      1,   0,      0,       0};

long int Ris[6];

int somma;

void setup () {
  for (byte i = 0; i < 5; i++) {
    pinMode ( i, OUTPUT);
  }
  Time t = rtc.time();
  unsigned int Ora[] = {t.yr, t.mon, t.date, t.hr, t.min, t.sec};
  SotData(Ora, Start);
  long int tempMan = ConvSec(Ris);
  SetStart(tempMan);
}

void loop() {

  for (byte i = 0; i < 9; i++) {
    digitalWrite ( latch , LOW  );
    shiftOut     ( data, clock, MSBFIRST, ~(1 << i)      );
    shiftOut     ( data, clock, MSBFIRST, N[numero[i]] );
    digitalWrite ( latch , HIGH );
  }

  Time t = rtc.time();
  
  for (int i = 0; i < 8; i++) {
    somma += numero[i];
  }
  if (!somma) {
    verso = true;
  } else {
    somma = 0;
  }

  if ((t.sec & 1) != temp) {
    if (verso == false) {
      numero[0]--;
    } else {
      numero[0]++;
    } temp = (t.sec & 1);
  }

  for (byte n = 0; n < 8; n++) {
    if (numero[n] >  9  ) {
      numero[n + 1]  += 1 ;
      numero[n]  = 0;
    }
  }
  for (byte n = 0; n < 8; n++) {
    if (numero[n] <  0  ) {
      numero[n + 1]  -= 1 ;
      numero[n]  = 9;
    }
  }
}
