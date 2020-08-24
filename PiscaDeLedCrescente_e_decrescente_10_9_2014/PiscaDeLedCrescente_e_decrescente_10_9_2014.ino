

int pin = 13;
int A = 100;
int B = 50;


void setup(){

  pinMode(pin,OUTPUT);
  Serial.begin(9600);

}

void loop(){

  digitalWrite(pin,HIGH);
  delay(A);
  digitalWrite(pin,LOW);
  delay(B);

    A = A - 1;
    B = B + 1;

  if(B == 100){    
    while(B > 50){
      digitalWrite(pin,HIGH);
      delay(A);
      digitalWrite(pin,LOW);
      delay(B);     
        A = A + 1;
        B = B - 1;
      }      
   }
}
