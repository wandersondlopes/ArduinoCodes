/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

O circuito ligado ao arduino é constituido por um fotodiodo polarizado apropriadamente com sinal ligado a porta A0 do Arduino.
Também foi montado 3 transistores em paralelo devidamente polarizados ligados a um led. Esse Led quando alimentado devidamente fornece luz
para o fotodiodo.
O codigo foi escrito para fazer a leitura do sinal do fotodiodo na porta A0 e ajuste de nível de zero pela Serial. 
Através de comandos pela Serial realiza-se o acionamento de cada transitor em paralelo que alimenta o led.

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
