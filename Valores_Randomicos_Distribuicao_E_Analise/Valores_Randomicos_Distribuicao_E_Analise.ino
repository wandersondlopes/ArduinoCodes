/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG



criado   04/07/2014
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


long randomVal;
int saidadeloop = 0;
int n = 0;

void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop(){
  while(saidadeloop == 0){
    randomVal = random(300);
    Serial.println(randomVal);
    if (randomVal == 299){
      n = n + 1;
      Serial.print("valor maximo encontrado");
      Serial.print(n);
      Serial.println("\t vezes");
    }
    if (randomVal == 300){ 
      Serial.println("vai ate trezentos");
      saidadeloop = 1;
    }
    delay(200);
  }
}
