/*

Programa de monitoramento da rotação do Spinner

*/
#include <TimerOne.h>

long conta = 0;
boolean face;
byte pinle = 7;
int giro = 0;
int t = 1; //tempo em segundos para refresh do giro

void setup(){
  
  Serial.begin(9600);
  pinMode(pinle,INPUT);
  Serial.println("RPM");//resolver

 //Inicializa o contador num intervalo de t segundos
 // (1 segundos = 1000 milisegundos = 1000000 microsegundos);
  Timer1.initialize(t*1000000);

 //Associa o contador à função do Tacometro:  
  Timer1.attachInterrupt(RPM);
}

void loop(){
  Tac();
}
//função leitura vai somando o valor de voltas independente do tempo
void Tac(){  
  face = digitalRead(pinle);
  if (face > 0){
    conta = conta +1;
    if(conta < 2){
      giro = giro + 1;    
    }
  }
  else{
    conta = 0;  
  }
}

void RPM(){  
  int rpm = giro*30/t; //multiplica por 60 para converter para minutos, temos 30 porque sao 2 furos
  giro = 0;
  Serial.println(rpm);
}
