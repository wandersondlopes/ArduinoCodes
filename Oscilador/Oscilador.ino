 unsigned int Thigh;
 unsigned int Tlow;

void setup(){
 Serial.begin(9600);// put your setup code here, to run once:
  while(!Serial.available()){;}
  delay(100);
  Thigh = Serial.parseInt(); //Recebe o tempo multiplicado por 1000
  Tlow= Serial.parseInt(); 
}

void loop(){
    while(!Serial.available()){
    digitalWrite(5,HIGH);
    delay(Thigh);
    digitalWrite(5,LOW);
    delay(Tlow);
  }
   Thigh = Serial.parseInt(); //Recebe o tempo multiplicado por 1000
   Tlow= Serial.parseInt(); 
}
