
int ledPin = 13;
int a = 2;
int vcalc = 3;

void setup() {
  
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  Serial.print("Valor antes");
  Serial.print("\t");
  Serial.print("Valor add");
  Serial.print("\t");
  Serial.print("Valor calculado");
  Serial.print("\n");
}

void loop() {
  if (Serial.available() > 0){
  Serial.print(vcalc); // manda valor inicial
  Serial.print("\t");
  Serial.print(a); // manda valor adicionado
  Serial.print("\t"); 
  vcalc = vcalc + a ;
  Serial.print(vcalc); // manda valor calculado
  Serial.print("\n");    
  a = a + 1;
  delay(400); // com uma luz fala se um numero vcalc eh maior
  }
}
