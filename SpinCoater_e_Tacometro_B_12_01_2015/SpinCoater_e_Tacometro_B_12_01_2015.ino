/*
        GME - Grupo de Metodos Eletroforeticos
        Desenvolvedor: Wanderson D. Lopes
*/



#include <TimerOne.h>

//variaveis do spin coater
int a = 4;
int b = 7;
int c = 8;
int i = 0;
int tempo = 26; // tempo de corrente fornecido ao estator por giro em microsegundos
int tmc = 26; // tempo minimo de envio de corrente para canal
int vel; // tempo de mudança de estator maximo
boolean registro = 0; // adequa a modalidade atrazo em milisegundos ou em microssegundos
// variaveis do tacometro
long conta = 0; // controle de passagem de trocaca de nivel alto e baixo para auxilio na contagem de diros
boolean face; //registrador da passagem ou nivel de luz
byte pinle = 11; // pino de leitura do modulo de leitura do tacometro
int giro = 0; // registrador da contagem de giros
int t = 1; //tempo em segundos para refresh do giro
int rpm = 0; // valor de rotacoes por minuto medido


void setup(){
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(pinle,INPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  // Cabecalho da saida de dados no terminal
  Serial.println("RPM esperado/s^-1\tRPM/s^-1\ttempo de canal/ms\tValor_do_potenciometro");
 //Inicializa o contador num intervalo de t segundos
 // (1 segundos = 1000 milisegundos = 1000000 microsegundos);
  Timer1.initialize(t*1000000);
 //Associa o contador à função do Tacometro:  
  Timer1.attachInterrupt(RPM);

}
  
void loop(){ 
  if(registro < 1){
    for(i;i < 20; i++){
      Rodada();
      Tac();
    }
  }  
  else {
    for(i;i < 60; i++){
      Rodada2();
      Tac();
    }
  }
  i = 0; // zera a contagem
  Leitura2();
  Tac();
  Mostrar();

}

void Rodada(){
  Estator(1);
  delay(tempo);
  Estator(2);
  delay(tempo);
  Estator(3);
  delay(tempo);
}

void Rodada2(){
  Estator(1);
  delayMicroseconds(tempo);
  Estator(2);
  delayMicroseconds(tempo);
  Estator(3);
  delayMicroseconds(tempo);
}

void Leitura()
{
  vel = analogRead(A0);  
  if(vel <= 400){
    tempo = map(vel,0,399,tmc,5);
    registro = 0;
  }
  else if(vel <= 700) {
    tempo = map(vel,401,699,10,7);
    tempo = tempo*500; 
    registro = 1;  
  } 
  else{
    tempo = map(vel,701,1008,14,8);  
    tempo = tempo*250; 
    registro = 1;   
  }
}

void Mostrar()
{
  if(registro <1){
    Serial.print(10000/(2*tempo));
    Serial.print("\t");
    Serial.println(rpm);
    Serial.print("\t");
    Serial.print(tempo);
    Serial.print("\t");
    Serial.println(vel);
  }
  else{
    /*a medida em RPM sera dividia por 2 pelo fato de em uma volta 
    ser necessario mandar duas sequencias de comandos*/
    Serial.print(10000000/(2*tempo));
    Serial.print("\t");
    Serial.println(rpm);
    Serial.print("\t");    
    float f = tempo/1000;
    Serial.print(f,5);
    Serial.print("\t");
    Serial.println(vel);
  } 
}

void Estator(int estado){
  switch(estado){ 
     case 1:  digitalWrite(a, HIGH);
              digitalWrite(b, LOW);
              digitalWrite(c, LOW);
     break;                              
     case 2:  digitalWrite(a, LOW);
              digitalWrite(b, HIGH);
              digitalWrite(c, LOW);
     break;                              
     case 3:  digitalWrite(a, LOW);
              digitalWrite(b, LOW);
              digitalWrite(c, HIGH);
     break;                              
     case 4:  digitalWrite(a, HIGH);
              digitalWrite(b, HIGH);
              digitalWrite(c, LOW);
     break;                  
     case 5:  digitalWrite(a, LOW);
              digitalWrite(b, HIGH);
              digitalWrite(c, HIGH);
     break; 
     case 6:  digitalWrite(a, HIGH);
              digitalWrite(b, LOW);
              digitalWrite(c, HIGH);           
     break;             
     }                      
}

void Leitura2(){
  vel = analogRead(A0);  
  if (vel >= 900){
    tempo = map(vel,901,1008,48,40);  
    tempo = tempo*62; 
    registro = 1;
  } 
  else if (vel >= 800){
         tempo = map(vel,801,899,24,22);  
         tempo = tempo*125; 
         registro = 1;
       }     
       else if(vel >= 600){
              tempo = map(vel,601,799,16,12);  
              tempo = tempo*250; 
              registro = 1;    
            }
            else if(vel >= 300){
                    tempo = map(vel,301,599,10,8);
                    tempo = tempo*500; 
                    registro = 1;  // modalidade de tempo em microssegundos
                 } 
                else{
                    tempo = map(vel,0,299,tmc,5);
                    registro = 0;    // modalidade de tempo em milissegundos
                }
}

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
  int rpm = giro*30/t;
  giro = 0;
}
