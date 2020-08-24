
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
  
  // put your setup code here, to run once:
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
  // put your main code here, to run repeatedly:

}
