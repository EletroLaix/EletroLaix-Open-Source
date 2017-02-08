//Sottraggo due date (Data1 < Data2)
void SotData(int* Data1,  int* Data2) {
  
  // Faccio in modo che la data piu grossa sia inserita nel vettore Data2
  for (int i = 0; i < 6; i++) {
    if (Data1[i] > Data2[i]) {
      int* tra = Data2;
      Data2 = Data1;
      Data1 = tra;
      i = 10;
      verso = true;
    } else if (Data1[i] < Data2[i]) {
      i = 10;
      verso = false;
    }
  }

  const int Rip[] = {12, 0, 24, 60, 60};
  const int RipMese[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  //Trasformo i mei in giorni per tener conto della differenza in giorni dei vari mesi
  for (int i = 0; i < Data2[1] - 1; i++) {
    Data2[2] += RipMese[i];
  }
  Data2[1] = 0;

  for (int i = 0; i < Data1[1] - 1; i++) {
    Data1[2] += RipMese[i];
  }
  Data1[1] = 0;

  //Faccio la sottrazione tenendo conto dei riporti
  for (int i = 5; i >= 0; i--) {
    if (Data2[i] < Data1[i]) {
      for (int f = 1; f <= i; f++) {
        if (Data2[i - f] != 0) {
          for (int z = f; z > 0; z--) {
            if (i - z == 1) {
              Data2[i - z + 1] += RipMese[Data2[i - z] - 1 ];
              Data2[i - z] -= 1;
              f = 10;
            }
            else {
              Data2[i - z] -= 1; Data2[i - z + 1] += Rip[i - z]; f = 10;
            }
          }
        }
      }
    }

    Ris[i] = Data2[i] - Data1[i];

  }
  //Trasformo gli eventuali mesi generati sal riporto in giorni
      for (int i = 0; i < Ris[1]; i++) {
      Ris[2] += RipMese[i];
    }
    Ris[1] = 0;
}


//Converto in secondi la data
long int ConvSec(long int* Start) {
  long int sec =
    (Start[0] * 31536000) +
    (Start[2] *    86400) +
    (Start[3] *     3600) +
    (Start[4] *       60) +
    (Start[5]           ) ;
  return sec;
}


//Divido le cifre nel vettore
void SetStart(long int sec) {
  const long int pot[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
  for (int i = 7; i >= 0; i--) {
    numero[i] = (sec / pot[i]);
    sec = sec % pot[i];
  }
}



