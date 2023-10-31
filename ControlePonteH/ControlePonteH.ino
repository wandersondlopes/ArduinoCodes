/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Codigo escrito para com a finalidade de controlar uma ponte H
responsável por determinar o sentido de rotação de um motor pequeno

criado   Nov 2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


#define pin1 9
#define pin2 8

void setup() {
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
}

void loop() {
digitalWrite(pin1,LOW);
digitalWrite(pin2,HIGH);
delay(3000);

pararMotor();

digitalWrite(pin1,HIGH);
digitalWrite(pin2,LOW);
delay(3000);

pararMotor();
}

void pararMotor(){
  digitalWrite(pin1,LOW);
  digitalWrite(pin1,LOW);
  delay(3000);
}

