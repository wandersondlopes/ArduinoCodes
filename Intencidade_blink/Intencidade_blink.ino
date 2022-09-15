#define led1 10
#define led2 9
#define led3 8


void setup() {
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
}

void loop() {
  for(int i=0; i<255; i = i + 40){
  analogWrite(led1, i);
  delay(200);    
  }
  
  for(int i = 255; i > 0; i = i - 40){
  analogWrite(led1, i);
  delay(200);    
  }
  
}
