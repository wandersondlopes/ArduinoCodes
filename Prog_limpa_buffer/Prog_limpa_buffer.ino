/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Em algumas situações podemos ter a necessidade limpar o buffer responsável por armazenar dados da Serial
O código a seguir apresenta uma maneira de remover esses dados do buffer

criado   Nov 2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


void setup() {
  Serial.begin(9600);
}

void loop() { 
  if (Serial.available()) {
    int entrada = Serial.available();
    for(int i=0; i<entrada ;i++){
      char trash = Serial.read();
    }  
  }
}
