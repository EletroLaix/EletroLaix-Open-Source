//By Eletrolaix
//Video: http://youtu.be/joYiMKJd2mc

#include <Wire.h>
#include <UnoJoy.h>

int info[6];
int n     = 0;
int tempo = 1;
 
void setup() {
  
  Wire.begin ();
  Settaggio ();
  
  setupPins();
  setupUnoJoy();
}

void Settaggio() {
  Wire.beginTransmission (0x52);
  Wire.write (0x40);
  Wire.write (0x00);
  Wire.endTransmission ();
}

void loop() {
  Wire.requestFrom (0x52, 6);
  while (Wire.available ()) {
    info[n] = Wire.read ();
    n++;
  }
  n = 0;
  Azzera();
  delay(tempo);
  dataForController_t dati_controller = acquisisci_dati();
  setControllerData(dati_controller);
}


void Azzera() {
  Wire.beginTransmission (0x52);
  Wire.write (0x00);
  Wire.endTransmission ();
}

void setupPins(void){
  for (int i = 2; i <= 12; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }
}

dataForController_t acquisisci_dati(void){
  int j_x = info[0];
  int j_y = info[1];
  int a_x = info[2]; 
  int a_y = info[3]; 
  int a_z = info[4]; 
  int b_z = 1;
  int b_c = 1;
  if ( info[5]       & 1) b_z = 0;
  if ((info[5] >> 1) & 1) b_c = 0;
  if (b_c+b_z == 2) {b_c = 0;}
  else if (b_z == 1){b_c = 1;}
  
  dataForController_t dati_controller = getBlankDataForController();
  
  dati_controller.triangleOn  = !digitalRead(2);
  dati_controller.circleOn    = !digitalRead(3);
  dati_controller.squareOn    = !digitalRead(4);
  dati_controller.crossOn     = !digitalRead(5);
  dati_controller.dpadUpOn    = !digitalRead(6);
  dati_controller.dpadDownOn  = 0;
  dati_controller.dpadLeftOn  = 0;
  dati_controller.dpadRightOn = 0;
  dati_controller.l1On        = b_z;
  dati_controller.r1On        = b_c;
  dati_controller.selectOn    = 0;
  dati_controller.startOn     = 0;
  dati_controller.homeOn      = 0;
  dati_controller.leftStickX  = map(j_x, 0, 223, 0, 255);
  dati_controller.leftStickY  = map(j_y, 0, 223, 0, 255);
  dati_controller.rightStickX = 128;
  dati_controller.rightStickY = 128;
  
  return dati_controller;
}
