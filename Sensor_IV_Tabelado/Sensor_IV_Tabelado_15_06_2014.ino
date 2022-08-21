/*
        GME - Grupo de Metodos Eletroforeticos

        Desenvolvedor: Wanderson D. Lopes
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
