/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

O sinal ao precionar um botão é ruidoso e pode não executar sua função se for lido sem tratamento.
Utilizamos esse código para evitar o ruido e utiliza-lo de maneira satisfatória

criado   09/06/2014
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/



int ledPin = 13;
int botaoLigar = 8;
int botaoPrecionado = 0; // armazena o estado do pino de entrada
boolean ligar = false;
int anterior = 0;
void setup ()  {
  pinMode(ledPin,OUTPUT);
  pinMode(botaoLigar,INPUT);
}


void loop () {
  botaoPrecionado = digitalRead(botaoLigar);
  
  // verificar se o botao está pressionado
  if ((botaoPrecionado == HIGH) && (anterior == LOW)) {
   if (ligar = false)
       ligar = true;
    else
       ligar = false; 
       delay(10);
  }
   anterior = botaoPrecionado;
   
  if (ligar == false)
    digitalWrite(ledPin,HIGH);
  else
    digitalWrite(ledPin,LOW);


}
