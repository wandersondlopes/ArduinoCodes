/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

software que utiiza a variavel word e biblioteca Serial

criado   Aug 2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/



void setup() {
  word var = 16;
  Serial.begin(9600);
  Serial.print("O valor da variavel word é: ");
  Serial.println(var);
  Serial.print("A quantidade de bytes que ela ocupa é: ");
  Serial.print(sizeof(var));
}

void loop() {

}
