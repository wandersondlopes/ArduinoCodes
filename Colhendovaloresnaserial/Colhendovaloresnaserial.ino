/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Usando o método parseInt() para receber valores numéricos pela Serial
e imprimir tabela com colunas Tempo e Velocidade pela Serial

criado   08/02/2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


int tmp;
int vel;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.print("Tempo\tVelociadade\n");
  while(!Serial.available()){}
  if(Serial.available()){
    tmp = Serial.parseInt();
    vel = Serial.parseInt();
  }
  Serial.print(tmp);
  Serial.print("\t");
  Serial.println(vel);
}
