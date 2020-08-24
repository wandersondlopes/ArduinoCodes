

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
