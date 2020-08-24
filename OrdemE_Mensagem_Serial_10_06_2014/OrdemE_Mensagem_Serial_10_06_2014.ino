
int ledPin = 13;
int a = 2;
int valorcalculado = 3;


void setup() {
  
  pinMode(ledPin,OUTPUT);
//  3 + a = valorcalculado;
  Serial.begin(9600);
  
}

void loop() {

  if ( valorcalculado > a)
  digitalWrite(ledPin, HIGH);
    
  else
  digitalWrite(ledPin, LOW);
  
  delay (1000);// com uma luz fala se um numero vcalc eh maior
  
  digitalWrite(ledPin, LOW);
  delay(10000);
  
  valorcalculado = valorcalculado + 1 ;
  Serial.println(valorcalculado); // manda o valor de vcalc para serial
  
  
  
}
