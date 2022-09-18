
/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Utilizamos um arduino para gerar sinais para um driver que alimenta um motor brushless de HDD.
A porta A0 recebe tensões de +5V a 0V por um potenciometro. Os valores de ddp convertidos em 
valores numéricos determinam o periodo de ciclo de alimentação dos estatores.

criado   Nov 2011
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
  Serial.begin(9600);
  Serial.print("Rotacao maxima de ");
  Serial.print(10000/tmin);
  Serial.println(" rpm");
  Serial.println("Rotacao/RPM\ttempo_de_estator/ms\tValor_do_potenciometro");
  }

void loop(){

    vel = analogRead(A0);
    tempo = map(vel,0,1008,tmax,tmin);
    Serial.print(10000/tempo);
    Serial.print("\t");
    Serial.print(tempo);
    Serial.print("\t");
    Serial.println(vel);
    
           
    digitalWrite(a, HIGH);
    delay(tempo);
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    delay(tempo);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    delay(tempo);
    digitalWrite(c, LOW);
    
}
