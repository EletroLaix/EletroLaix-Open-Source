// Video Tutorial : http://youtu.be/kZmtUwBVMn0
// By EletroLaix

int triggerPort = 7;
int echoPort    = 8;
 
void setup() {
  pinMode( triggerPort, OUTPUT );
  pinMode( echoPort, INPUT );
  Serial.begin( 9600 );
}
 
void loop() {
  digitalWrite ( triggerPort, LOW  );
  
  digitalWrite ( triggerPort, HIGH );
  delayMicroseconds( 10 );
  digitalWrite ( triggerPort, LOW  );
  
  long durata = pulseIn( echoPort, HIGH );
  
  long r = 0.0343 * durata / 2;
  
  Serial.print ("Distanza: ");
  Serial.print (r);
  Serial.println (" cm");
  delay ( 100 );
}