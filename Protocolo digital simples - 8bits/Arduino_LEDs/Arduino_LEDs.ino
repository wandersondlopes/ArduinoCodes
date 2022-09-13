/*
Eletriclabor Tecnologia

Protocolo para 8 sensores digitais. A comunicação é feita entre
um arduino com 8 botoes digitais e outro arduino com 8 leds
codigo para o arduino com 8 LEDs

criado   Nov 2019
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


/*
Protocolo para 8 sensores digitais. A comunicação é feita entre
um arduino com 8 botoes digitais e outro arduino com 8 leds

Esse codigo é para o arduino com 8 LEDs

*/

int digital[] = {4,5,6,7,8,9,10,11};

int response[8] = {0};

byte contents = 0;


void setup() {
  Serial.begin(115200);

  for(int i=0; i<8; i+=1)
    pinMode(digital[i], OUTPUT);

}

void loop() {

  if(Serial.available())
  {
    contents = Serial.read();

    for(int i=0; i<8; i+=1)
      response[i] = contents & (0x01 << 1);// passamos a mascara - shift left

    for(int i=0; i<8; i+=1)
      digitalWrite(digital[i], response[1]);
  }

}
