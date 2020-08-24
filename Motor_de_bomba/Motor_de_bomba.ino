/* 
                      GME - GRUPO DE METODOS ELETROFORETICOS
                      
Função: Gera uma saida de sinal de 5V na porta 10 para um motor. O programa
manda o sinal apenas uma vez depois de 15 segundos durante um prazo de 1,8
segundo. Esse tempo de envio é o tempo que leva para o pistão ir até o final.

Criador: Wanderson Domingos Lopes
Local: Goiania, Brasil
Intituto: Instituto de Quimica - UFG
Data: 16 de julho de 2014
*/

int Smotor = 10;

void setup(){

  pinMode(Smotor, OUTPUT);
  delay(15000);
  digitalWrite(Smotor, HIGH);
  delay(1800);
  digitalWrite(Smotor, LOW);

}

void loop(){}
