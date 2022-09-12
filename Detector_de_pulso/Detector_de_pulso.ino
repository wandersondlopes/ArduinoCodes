/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Com esse código podemos usar um Arduino para medir o intervalo de um sinal PWM

criado   Abr 2016
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/





unsigned long interval;

void setup(){
  Serial.begin(9600);
  pinMode(7,INPUT);
  Serial.println("As medida do intervalo sao:");
}

void loop(){
  interval = pulseIn(7,HIGH);
  delay(200);
  Serial.println(interval);
}
