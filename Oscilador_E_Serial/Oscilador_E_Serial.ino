/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Recebe da serial caracteres que são convertidos em variaveis int
Essas variaveis determinam o tempo em milissegundos que o pino 5 estará
em nível alto (+5V) e também em nível baixo (0V).

criado   Nov 2011
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/

unsigned int Thigh;
unsigned int Tlow;

void setup(){
 Serial.begin(9600);
 while(!Serial.available()){;}
 delay(500);
 Thigh = Serial.parseInt(); //Recebe o valor numérico do tempo pela serial
 while(!Serial.available()){;}
 delay(500);
 Tlow= Serial.parseInt(); 
}

void loop(){
    while(!Serial.available()){
    digitalWrite(5,HIGH);
    delay(Thigh);
    digitalWrite(5,LOW);
    delay(Tlow);
  }
  delay(500);
  Thigh = Serial.parseInt(); 
  while(!Serial.available()){;}
  delay(500); 
  Tlow= Serial.parseInt(); 
}
