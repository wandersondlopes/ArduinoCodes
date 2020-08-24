void setup() {
  Serial.begin(9600);
}

void loop() {
  while(!Serial.available()){}
  int valornum = Serial.read() -48;
  Serial.println(valornum);
}
