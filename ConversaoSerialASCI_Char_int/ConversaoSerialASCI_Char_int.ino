/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Função loop que recebe valoers numéricos pela Serial
Os valores obtidos são da tabela ASCI e são convertidos para
valores numericos respectivamente.
Os valores são é impressos pela Serial

criado   25/01/2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


void setup() {
  Serial.begin(9600);
}

void loop() {
  while(!Serial.available()){}
  int valornum = Serial.read() -48;
  Serial.println(valornum);
}
