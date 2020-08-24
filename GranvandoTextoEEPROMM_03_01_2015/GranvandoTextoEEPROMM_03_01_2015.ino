/*
 * EEPROM Write

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
  Serial.println("Escreva para seu txt em ascii para gravar na EEPROM");
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
    Serial.print(letra); //manda a variavel char para a Serial como esta na tabela ASCI
    Serial.println();
    delay(100);  
  }
  address = 0; */
}
