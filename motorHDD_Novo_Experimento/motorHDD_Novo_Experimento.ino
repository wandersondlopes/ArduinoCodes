/*
  GME - Grupo de Metodos Eletroforéticos
  Instituto de Quimica - UFG
  
  Utilizamos um arduino para gerar sinais para um driver que alimenta um motor brushless de HDD.
  Utilizamos as portas 4, 7 e 8. Codigo otimizado. A porta A0 recebe tensões de +5V a 0V por um potenciometro
  Os valores de ddp convertidos em valores numéricos determinam o periodo de ciclo de alimentação dos estatores
  
                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |         GND/RST2  [ ][ ]            |
         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |   C5 
         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |   C4 
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                    SCK/13[ ] |   B5
         | [ ]v.ref                 MISO/12[ ] |   .
         | [ ]RST                   MOSI/11[ ]~|   .
         | [ ]3V3    +---+               10[ ]~|   .
         | [ ]5v     | A |                9[ ]~|   .
         | [ ]GND   -| R |-               8[ ] |   B0
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[ ] |   D7
         |          -| I |-               6[ ]~|   .
         | [ ]A0    -| N |-               5[ ]~|   .
         | [ ]A1    -| O |-               4[ ] |   .
         | [ ]A2     +---+           INT1/3[ ]~|   .
         | [ ]A3                     INT0/2[ ] |   .
         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   .
         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   D0
         |            [ ] [ ] [ ]              |
         |  UNO_R3    GND MOSI 5V  ____________/
          \_______________________/
		  
		
criado   05/09/2014
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/
  
  
/* 23ms eh o tempo mínimo para arranque no giro slow e 4ms eh o tempo 
minimo para giro rapido*/

int a = 4;
int b = 7;
int c = 8;
int i = 0;
int tempo = 23; // tempo de corrente fornecido ao estator por giro em microsegundos
int tmax = 23;
int vel; // tempo de mudança de estator maximo
int tmin = 2; // tempo de mudança de estator mínimo

void setup(){

  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  Serial.print("Rotacao maxima de ");
  Serial.print(10000/tmin);
  Serial.println(" rpm");
  Serial.println("Rotacao/RPM\ttempo_de_estator/ms\tValor_do_potenciometro");
  digitalWrite(12, HIGH);
}
  

void loop(){
  
  vel = analogRead(A0);
  tempo = map(vel,0,1008,tmax,tmin);    
          
  Estator(1);
  delay(tempo);
  Estator(2);
  delay(tempo);
  Estator(3);
  delay(tempo);
  
  i = i+1;
  Leitura();
}

void Leitura(){

if(i = 1000){   
    Serial.print(10000/tempo);
    Serial.print("\t");
    Serial.println(tempo);
    i = 0;
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
