/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Código blink modificado. Ele apresenta a possibilidade de modificar o 
intervalo em que o led permanece ligado e o intervalo que permanece desligado

criado   Set 2014
por Wanderson D. Lopes
modificado Set 2022
por Wanderson D. Lopes
*/

int pin = 13;
int A = 100;
int B = 50;


void setup(){

  pinMode(pin,OUTPUT);
  Serial.begin(9600);

}

void loop(){

  digitalWrite(pin,HIGH);
  delay(A);
  digitalWrite(pin,LOW);
  delay(B);

    A = A - 1;
    B = B + 1;

  if(B == 100){    
    while(B > 50){
      digitalWrite(pin,HIGH);
      delay(A);
      digitalWrite(pin,LOW);
      delay(B);     
        A = A + 1;
        B = B - 1;
      }      
   }
}
