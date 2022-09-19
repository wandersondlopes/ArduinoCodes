/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Escreve caracteres vindos da serial na EEPROM.
Opçõ sw e imprimir pela serial comentada

criado   03/01/2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


#include <EEPROM.h>

// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
//int address = 0;
//byte value; // v
int addr = 0; // variavel posição na EEPROM
char var1;

void setup()
{
  Serial.begin(9600);
}

void loop(){
  Serial.println("Escreva um texto com até 512 caracteres para ser gravado na EEPROM");
  delay(30000); 
  while(Serial.available()){ 
      var1 = Serial.read();  
      EEPROM.write(addr, var1);
      addr = addr +1;
      if(addr >= 511)
        addr = 0;    
  }
/*  Serial.println("Agora vamos escrever o que esta gravado");
  delay(500); 
  for(address; address < 30; address++){
    // read a byte from the current address of the EEPROM
    value = EEPROM.read(address);
    char letra = char(value);
    Serial.print(address);
    Serial.print("\t");
    Serial.print(letra); //escreve a variavel char para a Serial como esta na tabela ASCI
    Serial.println();
    delay(100);  
  }
  address = 0; */
}
