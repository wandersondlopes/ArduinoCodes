/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Codigo escrito para estudar a recursividade em liguagem C/C++ em um arduino.
Utiliza-se a função impressao() de maneira recursiva. Quando a variavel inicio é incrementada até ter valor maior que finzin
a recursividade para de ser realizada na função.

criado   Jan 2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


void impressao(int inicio, int finzin){
  if(inicio<=finzin){
    Serial.print("Funcao recurciva - Valores sao: ") ;
    Serial.println(inicio);
    impressao(inicio+1,finzin);
  }
}


void setup() {
  int inicio = 0;
  int finzin = 10;
  
  Serial.begin(9600);
  impressao(inicio,finzin);
  //boolean a = false;
  //boolean b = true;
  Serial.print("Imprimdos valores depois de recursividade:\nInicio=");
  Serial.println(inicio,DEC);
  Serial.print("Fim= ");
  Serial.println(finzin,DEC);
}

void loop() {

}
