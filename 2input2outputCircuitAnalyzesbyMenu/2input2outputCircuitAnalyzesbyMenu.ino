/*
        GME - Grupo de Metodos Eletroforeticos


*/

bool estateA,estateB,loY,loX;
int anaY,anaX;
int portA = 12;
int portB = 11;

void setup(){
  Serial.begin(9600);
  Serial.print("Level logic of gates: 1 = high e 0 = Low\n\n");
  Serial.println("Type the value logic of canal A ");
  while(!Serial.available()){}
  estateA = Serial.read() - 48;
  Serial.print("A has a value: ");
  Serial.println(estateA);
  Serial.println("Type the value logic of canal B");
  while(!Serial.available()){}
  estateB = Serial.read() - 48;
  Serial.print("B has a value: ");
  Serial.println(estateB);
  pinMode(portA,OUTPUT);
  pinMode(portB,OUTPUT);
  digitalWrite(portA,estateA);
  digitalWrite(portB,estateB);
}

void loop(){
  menu(estateA,estateB,loY,loX,anaY,anaX);
}
  
void SetLogic(bool &estA, bool &estB){
  Serial.print("Type 1 or 0 to set canal A the High ou Low values.\n");
  while(!Serial.available()){}
  estA = Serial.read() - 48;
  switch(estA){
     case 1:  Serial.println("The canal A was difine High");
              digitalWrite(portA,HIGH);                 
     break;                              
     case 0:  Serial.println("The canal A was difine Low");
              digitalWrite(portA,LOW); 
     break;              
     default: Serial.println("Invalid option, The canal A was difine High");
              digitalWrite(portA,HIGH);
   }
   Serial.print("Type 1 or 0 to set canal B the High ou Low values.\n");
   while(!Serial.available()){}
   estB = Serial.read() - 48;
   switch(estB){
     case 1:  Serial.println("The canal B was difine High");
              digitalWrite(portB,HIGH);
                 
     break;                              
     case 0:  Serial.println("The canal B was difine Low");
              digitalWrite(portB,LOW); 
     break;              
     default: Serial.println("Invalid option, The canal B was difine High");
              digitalWrite(portB,HIGH);
   }
}
void ScanAnalog(int &analogY, int &analogX){
  analogY = analogRead(A0);
  analogX = analogRead(A1);
  Serial.println("The scan analogic was made");
}

void ScanDigi(bool &logicY,bool &logicX){
  logicY = digitalRead(A0);
  logicX = digitalRead(A1);
  Serial.println("The scan digital was made");
}

void menu(bool &estA, bool &estB, bool &logicY, bool &logicX, int &analogY, int &analogX){
  Serial.println("\t\t\t\tMenu\n\n1: Define status inputs A e B\n2: Read analogic values\n3: Read logic values\n4: Resume\n\n");
  while(!Serial.available()){}
  int opcao = Serial.read() - 48;
  switch(opcao){
    case 1: SetLogic(estA, estB);
      break; 
    case 2: ScanAnalog(analogY, analogX);
      break;
    case 3: ScanDigi(logicY,logicX);
      break;
    case 4: Show();
      break;
    default: Serial.print("Invalid option!");
  }
}

void Show(){
  Serial.print("Canal A: ");
  Serial.print(estateA);
  Serial.print("  Analogic output Y: ");
  Serial.print(anaY);
  Serial.print("  Digital output Y: ");
  Serial.println(loY);
  Serial.print("Canal B: ");
  Serial.print(estateB);
  Serial.print("  Analogic output X: ");
  Serial.print(anaX);
  Serial.print("  Digital output X: ");
  Serial.println(loX);
}
