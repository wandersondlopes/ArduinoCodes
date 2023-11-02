/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Escreve variavel boolean na serial

criado   11/01/2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


void setup() {
  Serial.begin(9600);
  boolean a = false;
  boolean b = true;
  Serial.println(a,BIN);
  Serial.println(b,BIN);
}

void loop() {

}
