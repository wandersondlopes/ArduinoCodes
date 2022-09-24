/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Codigo escrito para gerar sinais para transdutores piezoelétricos.
O sinal pode ser interrompido via serial quando recebe 's', 
o sinal pode iniciar novamente após a serial receber 'c' 

criado   Nov 2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/



#define buss 5000
bool buzzctr = true;
char ctr;

void setup(){
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  while(!Serial.available()){ // loop while responsável por produzir sinal para a membrana piezoelétrica
    digitalWrite(8,HIGH);
    delayMicroseconds(buss);
    digitalWrite(8,LOW);
    delayMicroseconds(buss);
  }
  ctr = Serial.read(); // variavel ctr recebe byte da serial e limpa o buffer da serial
  if(ctr == 'c'){ // se variavel é 'c' segue a rotina if e entra novamente no loop while
  }
  else if(ctr == 's' ){ // se variavel crt é 's' segue a rotina if, se é outra string volta para o loop while que gera sinal para o a membrana piezoelétrica
      while(buzzctr){
        if(Serial.read() == 'c'){ // se mantém no loop while até receber 'c'
        buzzctr = false;
        }
      }
    }
}
