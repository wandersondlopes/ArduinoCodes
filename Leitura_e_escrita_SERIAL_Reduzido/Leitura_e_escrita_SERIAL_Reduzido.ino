/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Código escrito para colher strings pela serial e imprimir na serial varios tipos de variaveis.

criado   Jan 2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/



void setup() {
  Serial.begin(9600);
  Serial.print("Programa teste de entrada do teclado\n");

}

void loop() {
  Serial.println("envie algum caractere qualquer para ser lido com inteiro");
  while(!Serial.available()){}
  int i = Serial.read();
  Serial.print("Valor lido como inteiro eh");
  Serial.println(i);
  Serial.println("envie algum caractere qualquer para ser lido com caractere");
  while(!Serial.available()){}
  char c = Serial.read();
  Serial.print("Valor lido como inteiro eh");
  Serial.println(c);
  Serial.println("envie algum caractere qualquer para ser lido como byte");
  while(!Serial.available()){}
  byte b = Serial.read();
  Serial.print("Valor lido como inteiro eh");
  Serial.println(b);
  Serial.println();
  Serial.println("Fazendo a conversão para varias tipos impressao");
  Serial.println("Para valores lidos como inteiros:");
  Serial.print("impressao normal: ");
  Serial.println(i);
  Serial.print("impressao decimal: ");
  Serial.println(i,DEC);
  Serial.print("impressao binaria: ");
  Serial.println(i,BIN);
  Serial.print("impressao hexadecimal: ");
  Serial.println(i,HEX);
  Serial.print("impressao octal: ");
  Serial.println(i,OCT);
  Serial.println();
  Serial.println("Para valores lidos como caractere:");
  Serial.print("impressao normal: ");
  Serial.println(c);
  Serial.print("impressao decimal: ");
  Serial.println(c,DEC);
  Serial.print("impressao binaria: ");
  Serial.println(c,BIN);
  Serial.print("impressao hexadecimal: ");
  Serial.println(c,HEX);
  Serial.print("impressao octal: ");
  Serial.println(c,OCT);
  Serial.println();
  Serial.println("Para valores lidos como binarios:");
  Serial.print("impressao normal: ");
  Serial.println(i);
  Serial.print("impressao decimal: ");
  Serial.println(i,DEC);
  Serial.print("impressao binaria: ");
  Serial.println(i,BIN);
  Serial.print("impressao hexadecimal: ");
  Serial.println(i,HEX);
  Serial.print("impressao octal: ");
  Serial.println(i,OCT);
  Serial.println();  
  Serial.println();  
  Serial.println();  
  Serial.println();
}
