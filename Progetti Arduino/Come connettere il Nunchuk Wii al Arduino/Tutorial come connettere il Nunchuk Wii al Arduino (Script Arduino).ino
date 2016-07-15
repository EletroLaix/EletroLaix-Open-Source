//Video Tutorial: http://youtu.be/i2RR-zN3oAQ
//By EletroLaix

#include <Wire.h>

int info[6];
int n = 0;
int tempo=10;
 
void setup()
{
    Serial.begin (9600);
    Wire.begin ();
    Settaggio ();
    Serial.print ("Acquisizione Dati:\n");
}

void Settaggio()
{
    Wire.beginTransmission (0x52);
    Wire.write (0x40);
    Wire.write (0x00);
    Wire.endTransmission ();
}

void Azzera()
{
    Wire.beginTransmission (0x52);
    Wire.write (0x00);
    Wire.endTransmission ();
}

void loop()
{
  Wire.requestFrom (0x52, 6);
  while (Wire.available ()) {
    info[n] = Wire.read ();
    n++;
  }
  n = 0;
  Azzera();
  Scrividati();
  delay(tempo);
}
 
void Scrividati()
{
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
  
  Serial.print ("\t");
 
  Serial.print ("X: ");
  Serial.print (j_x, DEC);
  Serial.print ("\t");
  
  Serial.print ("Y: ");
  Serial.print (j_y, DEC);
    
  Serial.print ("\t");
  Serial.print ("\t");

  Serial.print ("X: ");
  Serial.print (a_x, DEC);
  
  Serial.print ("\t");
  
  Serial.print ("Y: ");
  Serial.print (a_y, DEC);
  
  Serial.print ("\t");
  
  Serial.print ("Z: ");
  Serial.print (a_z, DEC);
    
  Serial.print ("\t");
  Serial.print ("\t");
  
  Serial.print (b_z, DEC);
  
  Serial.print ("\t");
  
  Serial.print (b_c, DEC);
  Serial.print ("\n");

}