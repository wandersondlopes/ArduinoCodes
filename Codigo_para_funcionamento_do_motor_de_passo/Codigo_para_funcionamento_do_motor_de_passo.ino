/*


Codigo para Motor de passo de leitores de CD
e disquete

criado   Nov 2015
por Wanderson D. Lopes
*/




/********************************************



********************************************/

#define BOBINA1A 4
#define BOBINA1B 5
#define BOBINA2A 6
#define BOBINA2B 7

void setup()
{
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  pinMode(BOBINA1A, OUTPUT);
  pinMode(BOBINA1B, OUTPUT);
  pinMode(BOBINA2A, OUTPUT);
  pinMode(BOBINA2B, OUTPUT);
}

void loop()
{
  if (digitalRead(2))
  {
    digitalWrite(BOBINA1A, 1);
    digitalWrite(BOBINA1B, 0);
   
    digitalWrite(BOBINA2A, 0);
    digitalWrite(BOBINA2B, 0);
   
    delay(15);
   
    digitalWrite(BOBINA1A, 0);
    digitalWrite(BOBINA1B, 0);
   
    digitalWrite(BOBINA2A, 1);
    digitalWrite(BOBINA2B, 0);
   
    delay(15);
   
    digitalWrite(BOBINA1A, 0);
    digitalWrite(BOBINA1B, 1);
   
    digitalWrite(BOBINA2A, 0);
    digitalWrite(BOBINA2B, 0);
   
    delay(15);
   
    digitalWrite(BOBINA1A, 0);
    digitalWrite(BOBINA1B, 0);
   
    digitalWrite(BOBINA2A, 0);
    digitalWrite(BOBINA2B, 1);
   
    delay(15);
  }
  else
  {
    digitalWrite(BOBINA1A, 0);
    digitalWrite(BOBINA1B, 1);
   
    digitalWrite(BOBINA2A, 0);
    digitalWrite(BOBINA2B, 0);
   
    delay(15);
   
    digitalWrite(BOBINA1A, 0);
    digitalWrite(BOBINA1B, 0);
   
    digitalWrite(BOBINA2A, 1);
    digitalWrite(BOBINA2B, 0);
   
    delay(15);
   
    digitalWrite(BOBINA1A, 1);
    digitalWrite(BOBINA1B, 0);
   
    digitalWrite(BOBINA2A, 0);
    digitalWrite(BOBINA2B, 0);
   
    delay(15);
   
    digitalWrite(BOBINA1A, 0);
    digitalWrite(BOBINA1B, 0);
   
    digitalWrite(BOBINA2A, 0);
    digitalWrite(BOBINA2B, 1);
   
    delay(15);
  }
 
}
