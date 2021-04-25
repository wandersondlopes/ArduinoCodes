/*
Protocolo para 8 sensores digitais. A comunicação é feita entre
um arduino com 8 botoes digitais e outro arduino com 8 leds

Esse codigo é para o arduino com 8 botoes

*/

int digital[] = {4,5,6,7,8,9,10,11};

byte contents = 0;


void setup() {
  Serial.begin(115200);

  for(int i=0; i<8; i+=1)
    pinMode(digital[i], INPUT_PULLUP);

}

void loop() {
  
  for(int i=0; i<8; i+=1)
    contents = contents | (digitalRead(digital[i]) << i); //opreracao bit a bit

  Serial.write(contents);
  contents = 0;

}
