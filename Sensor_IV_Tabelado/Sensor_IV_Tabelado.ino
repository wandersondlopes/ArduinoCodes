/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Código escrito para fazer medidas de um fototransistor de infravermelho
Os valores medidos são impressos no pelo Serial

criado   Jun 2014
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int a = 1;
int b;

void setup() {
  Serial.begin(9600);
  Serial.print("Amostra");
  Serial.print("\t");
  Serial.print("Tempo/segundos");
  Serial.print("\t");
  Serial.print("Sinal");
  Serial.print("\n");
}

void loop() { 
  if (Serial.available() > 0){
  sensorValue = analogRead(sensorPin);
  Serial.print(a);
  Serial.print("\t");
  b = micros()
  Serial.print(b);
  Serial.print("\t");
  Serial.println(sensorValue);
  a = a + 1;
  delay(1000);  
  }
}
