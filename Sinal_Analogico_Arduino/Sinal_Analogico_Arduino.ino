  /*

  O Arduino gera um sinal PWM que com uma shild adicional tem uma saida de sinal de onda senoidal

  Criated Apr 2020
  by Lucas Alexandre
  Modified May 2024
  by Wanderson D. Lopes
  */

  // Sine wave generator simulator

  int outputPWM;
  int x, valor;
  float seno;

  #define outputPWM 11

  void setup(){
  pinMode (outputPWM, OUTPUT);

  }

  void loop(){
    for (x=0; x<255; x++){
    seno = 100+(100*(sin(x*(6/255))));
    valor = int(seno);
    analogWrite(outputPWM, valor);
    delay(30);
    }
  }
