/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Função: Fazer um led funcionar ligando e desligando periodicamente porem de maneira não abrupta.
Ganhando intensidade e perdendo intensidade.

criado   Nov 2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


#define led1 10
#define led2 9
#define led3 8


void setup() {
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
}

void loop() {
  for(int i=0; i<255; i = i + 40){
  analogWrite(led1, i);
  delay(200);    
  }
  
  for(int i = 255; i > 0; i = i - 40){
  analogWrite(led1, i);
  delay(200);    
  }
  
}
