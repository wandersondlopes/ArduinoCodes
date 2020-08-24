void setup() {
  Serial.begin(9600);
}

void loop() { 
  if (Serial.available()) {
    int entrada = Serial.available();
    for(int i=0; i<entrada ;i++){
      char trash = Serial.read();
    }  
  }
}
