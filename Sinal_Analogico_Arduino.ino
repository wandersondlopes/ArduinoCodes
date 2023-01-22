Criated Apr 2020
by Lucas Alexandre
Modified Jan 2023
by Wanderson D. Lopes 

// Sine wave generator simulator
 
 int outputPWM;
 int x, valor;
 float seno;
 
 #define outputPWM 11
 
 void setup() {
  pinMode (outputPWM, OUTPUT);
 
 }
 
 void loop () {
  for (x=0; x<255; x++) {
  seno = 100+(100*(sin(x*(6.28/255))));
  valor = int(seno);
  analogWrite(outputPWM, valor);
  delay(30);
  }
 }