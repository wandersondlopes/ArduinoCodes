
/*

Programa de monitoramento da rotação do Spinner

*/


int pfont=8;
byte conta = 0;
byte face;
byte pinle = 8



void setup(){
  
  Serial.begin(9600);
  pinMode(pfont, OUTPUT); 
  pinMode(pinle,INPUT); 
  digitalWrite(pfont, HIGH);
}

void loop(){



}

void Leitura(){
  
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
