/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Simple DAC sine wave test on Teensy 3.1

criado   Jan 2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/




float phase = 0.0;
float twopi = 3.14159 * 2;
elapsedMicros usec = 0;

void setup() {
  analogWriteResolution(12);
}

void loop() {
  float val = sin(phase) * 2000.0 + 2050.0;
  analogWrite(A14, (int)val);
  phase = phase + 0.02;
  if (phase >= twopi) phase = 0;
  while (usec < 500) ; // wait
  usec = usec - 500;
}
