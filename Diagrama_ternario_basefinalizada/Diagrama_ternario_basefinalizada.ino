/*
                      GME - GRUPO DE METODOS ELETROFORETICOS
                      Instituto de Quimica - UFG

Função: Função loop que gera o sinal dos leds nos comprimentos de onda red, green e blue.
A intensidade do sinal na função analogRead() para cada led é indicado em um diagrama ternário.
O valor 0 corresponde a 0% e 255 corresponde a 100%
Há tambem a leitura do sensor. Todos os valores medidos 
são dispostos em uma tabela enviada pela Serial.

criado   07/07/2014
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/



int ledR = 11;
int ledG = 10;
int ledB = 9;
int v;
int var;
int sinal;

void setup() {
  
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT); 
  Serial.begin(9600);
}


void loop() {
  
  for (int i = 0; i <= 255; i++){
  analogWrite(ledR, i);
  v = 255 - i;
  for (int x = 0; x <= v; x++){ 
  analogWrite(ledG, x);
  var = v - x;
  analogWrite(ledB, var);  
  delay(10000); 
  sinal = analogRead(A0);
  Serial.print(i);
  Serial.print("\t");
  Serial.print(v);
  Serial.print("\t");
  Serial.println(sinal);
  delay(50000); 
     } 
  }
 analogWrite(ledR, 0);
}
