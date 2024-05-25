/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Leitura de fotodiodo IR e conversão em absorvancia e transmitância

Criado 26/02/2015
por Wanderson Domingos Lopes
modificado 25/05/2024
por Wanderson D. Lopes
*/


int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
bool Cabecalio = true;
unsigned int a = 1;
int Absorbance;
int Calibration = 0;
int tsimple = 200; //time of simple
//int intensled = 10;
int ledPin = 9;
char inp;

void setup(){
  Serial.begin(9600);
  Serial.println("Please type A to read a simple value");
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop(){
  if (Cabecalio == true){
    Serial.print("Simple");
    Serial.print("\t");
    Serial.print("Time/10^-1 s");
    Serial.print("\t");
    Serial.print("Intensity_led");
    Serial.print("\t");
    Serial.print("SensorIntensity_10bits");
    Serial.print("\t");
    Serial.print("Absorvance");
    Serial.print("\t");
    Serial.println("Transmitance");
    Cabecalio = false;
  }
  inp = Serial.read();
  if (inp == 'A'){
    Leitura();
  }
  inp = 'a';
}

void Leitura(){
  sensorValue = analogRead(sensorPin);
  Serial.print(a);
  Serial.print("\t");
  Serial.print(millis());
  Serial.print("\t");
  Serial.print("100%");
  Serial.print("\t");
  Serial.print(sensorValue);
  Serial.print("\t");
  Absorbance = sensorValue - Calibration;
  Serial.print(Absorbance);
  Serial.print("\t");
  float Transmitance = (100.00*1023)/Absorbance;
  Serial.println(Transmitance);
  a++;
  delay(tsimple);
}
