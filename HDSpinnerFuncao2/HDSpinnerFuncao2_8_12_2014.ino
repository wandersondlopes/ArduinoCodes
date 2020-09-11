/*
ideia usar a biblioteca timer one para fazer a leitura e print
e deixar no loop o giro sem nenhuma interferencia de codigo
pode ser que o giro melhore bastante.
*/
int a = 4;
int b = 7;
int c = 8;
int i = 0;
float tempo = 26; // tempo de corrente de estator em ms de inicio
float tmax = tempo; // tempo de referência mínimo gíro
int vel; // tempo de mudança de estator maximo
int registro = 0; // modalidade de delay

void setup(){
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  Serial.print("Rotacao maxima de ");
  Serial.print(10000/1);
  Serial.println(" rpm");
  Serial.println("RPM/s^-1\ttempo_de_estator/ms\tValor_do_potenciometro");
}
  
void loop(){ 
  if(registro < 1){
    for(i;i < 20; i++){
      Rodada();
    }
  }  
  else {
    for(i;i < 60; i++){
      Rodada2();
    }
  }
  Leitura2();
  Mostrar();
  i = 0;
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

void Leitura1(){

  vel = analogRead(A0);  
  if(vel <= 400){
    tempo = map(vel,0,399,tmax,5);
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

void Mostrar(){
  if(registro <1){
    Serial.print(10000/(2*tempo));
    Serial.print("\t");
    Serial.print(tempo);
    Serial.print("\t");
    Serial.println(vel);
  }
  else{
    /*a medida em RPM sera dividia por 2 pelo fato de em uma volta 
    é necessario mandar duas sequencias para os pares de estatores*/
    Serial.print(10000000/(2*tempo));
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
    tempo = map(vel,901,1008,44,40);  
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
    registro = 1;  
       } 
  else{
    tempo = map(vel,0,299,tmax,5);
    registro = 0;    
  }
}
