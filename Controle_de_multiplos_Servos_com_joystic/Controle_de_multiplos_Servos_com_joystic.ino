/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Utilizamos a leitura de um joystick para determina a posição
de 3 servo moteres

criado   01/05/2016
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/

 
//incluindo biblioteca para controle do servomotor
#include "Servo.h"
 
//Criando um objeto da classe Servo
Servo servoMotorObjX;
Servo servoMotorObjY;
Servo servoMotorObjZ;
 
//pino digital (PWM) associado ao controle do servomotor
int const servoMotorX = 3;
int const servoMotorY = 5;
int const servoMotorZ = 6;
 
//Variável que armazena a posição lida
//nos eixos do joystick
int joystickX = 0;
int joystickY = 0;
int joystickZ = 0;
 
//Atribuindo o pino analógico A0 a variável eixoX
int eixoX = A0;
 
//Atribuindo o pino analógico A1 a variável eixoY
int eixoY = A1;
 
//Atribuindo o pino digital 2 a variável eixoZ
int eixoZ = 2;
 
void setup() {
  //associando o pino digital de controle do
  //servo ao objeto da classe Servo
  servoMotorObjX.attach(servoMotorX);
  servoMotorObjY.attach(servoMotorY);
  servoMotorObjZ.attach(servoMotorZ);
 
  //Definindo eixoZ como um pino de entrada
  pinMode(eixoZ, INPUT);
   
  servoMotorObjX.write(90);
  servoMotorObjY.write(90);
  servoMotorObjY.write(180);
 
  //Ativando o Serial Monitor que exibirá os
  //valores lidos no Joystick
  Serial.begin(9600);
}
 
void loop() {
  //Lê o valor do eixoX
  joystickX = analogRead(eixoX);
 
  //Lê o valor do eixoY
  joystickY = analogRead(eixoY);
 
  //Lê o valor do eixoZ
  joystickZ = digitalRead(eixoZ);
 
  imprimeEixos();     
 
  //mapeando o valor lido no joystick para a escala do
  //servo (entre 0 e 180)
  joystickX = map(joystickX, 0, 1023, 0, 180);
  joystickY = map(joystickY, 0, 1023, 0, 180);
  joystickZ = map(joystickZ, 0, 1, 0, 180);   
 
  //definindo o valor/posição do servomotor
  servoMotorObjX.write(joystickX);
  servoMotorObjY.write(joystickY);
  servoMotorObjZ.write(joystickZ);
 
  //espera 20 milisegundos.
  delay(20);
}
 
//Este método é responsável apenas por imprimir no
//Serial Monitor os valores dos eixos X, Y e Z.
void imprimeEixos() {
  //imprime o valor do eixoX
  Serial.print("  X=");
  Serial.print(joystickX);
 
  //imprime o valor do eixoY
  Serial.print("   Y=");
  Serial.print(joystickY);
 
  //imprime o valor do eixoZ
  Serial.print("   Z=");
  Serial.println(joystickZ);
}
