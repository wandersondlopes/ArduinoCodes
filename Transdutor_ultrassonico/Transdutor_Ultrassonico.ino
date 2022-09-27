/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Codigo para Arduino escrito para fazer medidas de distância
utilizando um detector ultrassônico HC-SR04

criado   Abr 2016
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


int gatilho = 9;
int echo = 8;
float tempo;
float distancia_cm;
 


void setup() {
  pinMode(gatilho,OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(gatilho,LOW);
  delayMicroseconds(10);
  Serial.begin(9600);
  }

void loop() {
  digitalWrite(gatilho,HIGH);
  delayMicroseconds(10);
  digitalWrite(gatilho,LOW);
  
  tempo = pulseIn(echo,HIGH);
  distancia_cm = (tempo/58.0);
  Serial.print("Distância: ");
  Serial.print(distancia_cm);
  Serial.println(" cm");

  delay(200);

}
