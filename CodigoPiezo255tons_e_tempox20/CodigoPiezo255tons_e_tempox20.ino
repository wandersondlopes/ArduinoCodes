/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG



criado   6/2/2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


#define piezoeletrico 9

byte freq = 1046;
int temp = 100000;

void setup() {
  Serial.begin(9600);
  pinMode(piezoeletrico,OUTPUT);
}

void loop() {
  Serial.print("Envie um valor um caracter como entrada para frequencia\n");
  while(!Serial.available()){}
  freq = Serial.read();
  Serial.print("Envie um caracter como entrada para valor do tempo\n");
  while(!Serial.available()){}
  temp = Serial.read();
  Serial.print("frequencia: ");
  Serial.print(freq);
  Serial.print("\nTempo: ");
  Serial.println(temp*20);
  tone(piezoeletrico,freq,temp*20); 
  Serial.print("Envie 'r' para executar mais uma operacao\n\n\n");
  while(!Serial.available() || Serial.read()!='r'){}
}
