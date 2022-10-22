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
  Serial.print("Envie um número (0-9). O valor será multiplicado por 100 e determina a frequencia\n");
  while(!Serial.available()){}
  freq = 100*(Serial.read() -48);
  Serial.print("Envie um caracter como entrada. Seu valor na tabela ASCII será multiplicado por 20 e determina a duração do tom em milissegundos\n");
  while(!Serial.available()){}
  temp = Serial.read();
  Serial.print("frequencia: ");
  Serial.print(freq);
  Serial.print("\nTempo: ");
  Serial.println(temp*20);
  tone(piezoeletrico,freq,temp*20); 
  Serial.print("Envie caractere para executar mais uma operacao\n\n\n");
  while(!Serial.available()){}
}
