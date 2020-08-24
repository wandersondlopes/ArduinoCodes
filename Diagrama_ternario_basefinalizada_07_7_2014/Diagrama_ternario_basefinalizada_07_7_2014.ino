
/* 
                      GME - GRUPO DE METODOS ELETROFORETICOS
                      
Função: Função loop que gera o sinal dos leds nos comprimentos de onda red, green e blue para a
base do diagrama ternário. A tambem a leitura do sensor. Todos os valores medidos e gerados
são dispostos em uma tabela enviada pela porta COM.

Criador: Wanderson Domingos Lopes
Local: Goiania, Brasil
Intituto: Instituto de Quimica - UFG
Data: 08 de julho de 2014
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
