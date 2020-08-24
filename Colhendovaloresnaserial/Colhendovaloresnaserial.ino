int tmp;
int vel;

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.print("Tempo\tVelociadade\n");
  while(!Serial.available()){}
  if(Serial.available()){
    tmp = Serial.parseInt();
    vel = Serial.parseInt();
  }
  Serial.print(tmp);
  Serial.print("\t");
  Serial.println(vel);
}
