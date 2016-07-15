//By EletroLaix
//Video Tutorial:http://youtu.be/hiKGKxl0So0

int TemperaturaKelvin  = 0;

int TemperaturaCelsius = 0;

long Sensore           = 0;

void setup() {
  
  Serial.begin(9600);

}
 
void loop() {
  
  Sensore = analogRead(A0);
  
  TemperaturaKelvin =  Sensore*500/1023;
  
  TemperaturaCelsius = TemperaturaKelvin-273;
  
  Serial.print ("  Temperatura rillevata:  ");
  
  Serial.print (TemperaturaCelsius);
  
  Serial.println (" 'C");
  
  delay (1000);

}