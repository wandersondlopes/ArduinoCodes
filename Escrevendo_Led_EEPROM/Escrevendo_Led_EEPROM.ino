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
