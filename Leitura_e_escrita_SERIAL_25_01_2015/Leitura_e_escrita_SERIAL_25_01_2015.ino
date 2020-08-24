
void setup() {
  Serial.begin(9600);
  Serial.print("Programa teste de entrada do teclado\n\n\n");
}

void loop() {
  Serial.println("Envie algum caractere qualquer para ser lido com inteiro");
  while(!Serial.available()){}
  int i = Serial.read();
  Serial.print("Valor lido como inteiro escrito normal: ");
  Serial.println(i);
  Serial.println("envie algum caractere qualquer para ser lido com caractere");
  while(!Serial.available()){}
  char c = Serial.read();
  Serial.print("Valor lido como caracter escrito normal: ");
  Serial.println(c);
  Serial.println("envie algum caractere qualquer para ser lido como byte");
  while(!Serial.available()){}
  byte b = Serial.read();
  Serial.print("Valor lido como byte escrito normal: ");
  Serial.println(b);
  Serial.println("envie algum caractere qualquer para ser lido com boolean");
  while(!Serial.available()){}
  boolean bo = Serial.read();
  Serial.print("Valor lido como boolean escrito normal: ");
  Serial.println(bo);
  Serial.println("envie algum caractere qualquer para ser lido com bool");
  while(!Serial.available()){}
  bool bol = Serial.read();
  Serial.print("Valor lido como boolean escrito normal: ");
  Serial.println(bol);
  delay(1000);
  Serial.println();
  Serial.println("Fazendo a conversao para varias tipos impressao\n\n");
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
  Serial.println(b);
  Serial.print("impressao decimal: ");
  Serial.println(b,DEC);
  Serial.print("impressao binaria: ");
  Serial.println(b,BIN);
  Serial.print("impressao hexadecimal: ");
  Serial.println(b,HEX);
  Serial.print("impressao octal: ");
  Serial.println(b,OCT);
  Serial.println();
  Serial.println("Para valores lidos como booleano:");
  Serial.print("impressao normal: ");
  Serial.println(bo);
  Serial.print("impressao decimal: ");
  Serial.println(bo,DEC);
  Serial.print("impressao binaria: ");
  Serial.println(bo,BIN);
  Serial.print("impressao hexadecimal: ");
  Serial.println(bo,HEX);
  Serial.print("impressao octal: ");
  Serial.println(bo,OCT);
  Serial.println();
  Serial.println("Para valores lidos como bool:");
  Serial.print("impressao normal: ");
  Serial.println(bol);
  Serial.print("impressao decimal: ");
  Serial.println(bol,DEC);
  Serial.print("impressao binaria: ");
  Serial.println(bol,BIN);
  Serial.print("impressao hexadecimal: ");
  Serial.println(bol,HEX);
  Serial.print("impressao octal: ");
  Serial.println(bol,OCT);
  Serial.print("\n\n\n\n");  
}
