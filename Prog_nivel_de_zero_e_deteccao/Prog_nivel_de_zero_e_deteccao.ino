/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

O circuito ligado ao arduino é constituido por um fotodiodo polarizado apropriadamente com sinal ligado a porta A0 do Arduino.
Também foi montado 3 transistores em paralelo devidamente polarizados ligados a um led. Esse Led quando alimentado devidamente fornece luz
para o fotodiodo. Os pinos ligados a esses transitores são o 8, 9 e 10.
O codigo foi escrito para fazer a leitura do sinal do fotodiodo na porta A0 e ajuste de nível de zero pela Serial. 
Através de comandos pela Serial realiza-se o acionamento de cada transitor em paralelo que alimenta o led.


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
		  

criado   Set 2014
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/




int foto;
int n;

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  Intro();
}

void Intro(){
  Limpa();
  Serial.println(" Escreva quantos transistores deseja escrever");
  Serial.println(" Enviando 0: 0 transistor sera ligado");
  Serial.println(" Enviando 1: 1 transistor sera ligado");
  Serial.println(" Enviando 2: 2 transistores serao ligados");
  Serial.println(" Enviando 3: 3 transistores serao ligados");
  Serial.println(" Enviando qualquer outro caractere entrara no modo de deteccao");
  while(!Serial.available()){}
  n = Serial.read() - 48;
}

void loop() {
  switch(n){
    case 0: Serial.println("Voce digitou 0");
            digitalWrite(8,LOW);
            digitalWrite(9,LOW);
            digitalWrite(10,LOW);
  break;
    case 1: Serial.println("Voce digitou 1");
            digitalWrite(8,HIGH);
            digitalWrite(9,LOW);
            digitalWrite(10,LOW);
  break;
    case 2: Serial.println("Voce digitou 2");
            digitalWrite(8,HIGH);
            digitalWrite(9,HIGH);
            digitalWrite(10,LOW);
  break;
    case 3: Serial.println("Voce digitou 3");
            digitalWrite(8,HIGH);
            digitalWrite(9,HIGH);
            digitalWrite(10,HIGH);
  break;
    default:  Detect();
  }
  Intro();
}

int Detect(){
  Limpa();
  Serial.println("Entrada para o modo de deteccao");
  Serial.println("Ao comando inicia-se a deteccao, precione R para reeiniciar");
  while(!Serial.available());{}
  char op = Serial.read();
  if(op == 'R'){
    return 0;
  }
  Limpa();
  char control;
  bool lup = true;
  while(lup){
    Foto();
    if(Serial.available()){
      control = Serial.read();
      if(control == 'R'){
        return 0;      
      }
      n = int(control) - 48;
      Change();
    }
  }
  Serial.println("Deteccao finalizada");
  return 0;
}

void Limpa(){
 if(Serial.available()){
   int trash;
   while(1 <= Serial.available()){
      trash = Serial.read();
   }  
 }
}

void Foto(){
  foto = analogRead(A0);
  Serial.println(foto);
  delay(200);
}

void Change(){
  switch(n){
    case 0: Serial.println("Voce digitou 0");
            digitalWrite(8,LOW);
            digitalWrite(9,LOW);
            digitalWrite(10,LOW);
  break;
    case 1: Serial.println("Voce digitou 1");
            digitalWrite(8,HIGH);
            digitalWrite(9,LOW);
            digitalWrite(10,LOW);
  break;
    case 2: Serial.println("Voce digitou 2");
            digitalWrite(8,HIGH);
            digitalWrite(9,HIGH);
            digitalWrite(10,LOW);
  break;
    case 3: Serial.println("Voce digitou 3");
            digitalWrite(8,HIGH);
            digitalWrite(9,HIGH);
            digitalWrite(10,HIGH);
  break;
    default: Limpa();
  }
  Limpa();
}
