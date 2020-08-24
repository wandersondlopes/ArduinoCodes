#define car 12


void setup()
{
  pinMode(car,OUTPUT);
  Serial.begin(9600);
  digitalWrite(car,LOW);
}

void loop()
{
  while(!Serial.available()){}
  Leitura();
  int limpBuffer = Serial.read();
}
  
void Leitura()
{
  int var[500];
  long marca[2];
  int medidainicial;
  marca[0] = micros();
  medidainicial = analogRead(A0);
  digitalWrite(car,HIGH);
  for(int i = 0;i < 500;i++){
    var[i] = analogRead(A0);
  }
  marca[1]=micros();
  digitalWrite(car,LOW);
  Serial.println(marca[1]-marca[0]);
  Serial.println("Amostra\tLeitura");
  Serial.print(0);
  Serial.print("\t");
  float voltage = float(medidainicial*5.00000/1023.000);
  Serial.println(voltage);
  for(int i = 0;i < 500;i++){
    Serial.print(i+1);
    Serial.print("\t");
    voltage = float(var[i]*5.00000/1023.000);
    Serial.println(voltage);
    }
}
