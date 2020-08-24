

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
