/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG



criado   03/01/2015
por Wanderson D. Lopes
modificado Out 2022
por Wanderson D. Lopes
*/


#include <EEPROM.h>

// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
//int address = 0;
//byte value; // variavel da EEPROM
int addr = 0; // variavel posição na EEPROM
char var1;
char letra;


void setup(){
  Serial.begin(9600);
}

void loop(){

  for(i = 0; i < 8 ; i++){
    

  Serial.print();
  Serial.println("Escreva um texto com 63 caracteres para ser gravado na EEPROM");
  delay(10000);  
  while(Serial.available()){ 
      var1 = Serial.read(); 
      Serial.println(var1);
      EEPROM.write(addr, var1);
    //address = addr
      addr = addr +1;
      if(addr >= 125) {
        Serial.print("63 caracteres foram gravados"); } 
  }


  }


  Serial.println("Agora vamos escrever o que esta gravado");
  delay(500);
  addr = 0;  
  for(addr; addr < 512; addr++){
    // read a byte from the current address of the EEPROM
    letra = EEPROM.read(addr);
    Serial.print(addr);
    Serial.print("\t");
    Serial.println(letra); //escreve a variavel char para a Serial como esta na tabela ASCI
    delay(10);
  }
  addr = 0; 
  
}
