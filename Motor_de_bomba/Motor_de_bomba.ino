/* 
                      GME - GRUPO DE METODOS ELETROFORETICOS
                      
Função: Gera um sinal de 5V na porta 10 para driver que alimenta um motor.
O sinal é fornecido apenas uma vez depois de 15 segundos durante um prazo de 1,8
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
