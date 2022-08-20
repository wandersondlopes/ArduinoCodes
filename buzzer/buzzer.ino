/*
        GME - Grupo de Metodos Eletroforeticos


	Desenvolvedor: Wanderson D. Lopes


*/


#define buss 5000
bool buzzctr = true;
char ctr;

void setup(){
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  while(!Serial.available()){
    digitalWrite(8,HIGH);
    delayMicroseconds(buss);
    digitalWrite(8,LOW);
    delayMicroseconds(buss);
  }
  ctr = Serial.read();
  if(ctr == 'c'){ // continua o sinal se recebe c
  }
  else if(ctr == 's' ){ // interrompe o sinal se recebe s
      while(buzzctr){
        if(Serial.read() == 'c'){
        buzzctr = false;
        }
      }
    }
}
