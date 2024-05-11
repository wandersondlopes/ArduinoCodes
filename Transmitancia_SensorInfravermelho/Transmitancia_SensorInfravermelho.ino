/*
Leitura de fotodiodo IR e conversão em absorvancia e transmitância

Criado 26/02/2015
por Wanderson Domingos Lopes


*/








int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
unsigned int a = 1;
int r = true;
int Absorvance;
int Calibration = 0;
int tsimple = 200; //time of simple
//int intensled = 10;
int ledPin = 9;

void setup(){
  Serial.begin(9600);
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
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop(){ 
  char inp = Serial.read();
  if (inp == 'a'){
    Leitura();
  }
  else{
    while(inp == 'r'){
    Serial.println("Waiting simple value");
    r = false;
    }
  }
}

void Leitura(){
  sensorValue = analogRead(sensorPin);
  Serial.print(a);
  Serial.print("\t");
  Serial.print(millis());
  Serial.print("\t");
  Serial.println("100%");
  Serial.print(sensorValue);
  Serial.print("\t");
  Absorvance = sensorValue - Calibration;
  Serial.print(Absorvance);
  Serial.print("\t");
  float Transmitance = (100.00*1023)/Absorvance;
  Serial.println(Transmitance);
  a++;
  delay(tsimple);
}
