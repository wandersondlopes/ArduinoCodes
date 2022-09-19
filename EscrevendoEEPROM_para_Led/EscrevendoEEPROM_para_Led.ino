/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

É escrito na EEPROM inicialmente valores determinados por um laço for
Os valores gravados são lidos como valores de intensidade na função analogWrite()
O pino correspondente alimenta um LED

criado   Nov 2011
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


#include <EEPROM.h>
#define LED 11
void setup() {
for (int i = 0; i < 64; i++) {
EEPROM.write(i, i * i);
}
}
void loop() {
for (int i = 0; i < 64; i++) {
byte leitura = EEPROM.read(i);
analogWrite(LED, leitura);
delay(50);
}
delay(1000);
}
