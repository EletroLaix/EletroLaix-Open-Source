//Sottraggo due date (Data1 < Data2)
void SotData(int* Data1,  int* Data2) {
  
  for (int i = 0;i<6;i++){
    if(Data1[i]>Data2[i]){
      int* tra = Data2;
      Data2 = Data1;
      Data1 = tra;
      i = 10;
      verso = true;
      } else if (Data1[i]<Data2[i]){i = 10; verso = false;}
  }
  
  int Rip[]={12,30,24,60,60};
  
  for(int i = 5; i>=0; i--){
    if(Data2[i]<Data1[i]) {
      for(int f = 1; f<=i;f++){
        if(Data2[i-f] != 0){
          for(int z = f; z >0; z--) {
            Data2[i-z] -= 1; Data2[i-z+1] += Rip[i-z]; f = 10;}
          }
      }
      }
    Ris[i]= Data2[i]-Data1[i];}
}


//Converto in secondi la data
long int ConvSec(long int* Start) {
  long int sec =
  (Start[0] * 31557600) + 
  (Start[1] *  2629800) +
  (Start[2] *    86400) +
  (Start[3] *     3600) +
  (Start[4] *       60) +
  (Start[5]           ) ;
  return sec;
}


//Divido le cifre nel vettore
void SetStart(long int sec) {
 long int pot[] = {1,10,100,1000,10000,100000,1000000,10000000};
 for (int i =7; i>=0; i--) { numero[i] = (sec/pot[i]); sec = sec % pot[i];}
}



