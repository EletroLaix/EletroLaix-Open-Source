const byte N[] = {237, 33, 203, 107, 39, 110, 238, 41, 239, 111, 16};
int numero[8];

#include <DS3232RTC.h>             
#include <TinyWireM.h>   
#define NOSERIALE

const byte data = 4, clock = 3, latch = 1;

bool temp = true;

bool verso = false;

//                     {anno, mese, giorno, ora, minuti, secondi}
int Start[] = {2018,    1,      1,   0,      0,       0};

long int Ris[6];

int somma;
time_t t = now();
void setup () {
    #ifndef NOSERIALE
  Serial.begin(9600);
  #endif
  
  for (byte i = 0; i < 5; i++) {
    pinMode ( i, OUTPUT);
  }
  setSyncProvider(RTC.get);
   t = now();
  int Ora[] = { year(t),month(t),day(t),hour(t), minute(t), second(t)};
    #ifndef NOSERIALE
  printData(Ora);
  #endif
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
  
 setSyncProvider(RTC.get);
  t = now();
  for (int i = 0; i < 8; i++) {
    somma += numero[i];
  }
  if (!somma) {
    verso = true;
  } else {
    somma = 0;
  }

  if (( second(t) & 1) != temp) {
    if (verso == false) {
      numero[0]--;
    } else {
      numero[0]++;
    } temp = ( second(t) & 1);
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
