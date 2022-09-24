/*
  GME - Grupo de Metodos Eletroforéticos
  Instituto de Quimica - UFG
  
  Utilizamos um arduino para gerar sinais para um driver de potência que proporciona a potência necessária
  para um motor brushless de HDD. Utilizamos as portas 4, 7 e 8 do Arduino.


                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |         GND/RST2  [ ][ ]            |
         |       MOSI2/SCK2  [ ][ ]  A5/SCL[ ] |   C5 
         |          5V/MISO2 [ ][ ]  A4/SDA[ ] |   C4 
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                    SCK/13[ ] |   B5
         | [ ]v.ref                 MISO/12[ ] |   .
         | [ ]RST                   MOSI/11[ ]~|   .
         | [ ]3V3    +---+               10[ ]~|   .
         | [ ]5v     | A |                9[ ]~|   .
         | [ ]GND   -| R |-               8[ ] |   B0
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[ ] |   D7
         |          -| I |-               6[ ]~|   .
         | [ ]A0    -| N |-               5[ ]~|   .
         | [ ]A1    -| O |-               4[ ] |   .
         | [ ]A2     +---+           INT1/3[ ]~|   .
         | [ ]A3                     INT0/2[ ] |   .
         | [ ]A4/SDA  RST SCK MISO     TX>1[ ] |   .
         | [ ]A5/SCL  [ ] [ ] [ ]      RX<0[ ] |   D0
         |            [ ] [ ] [ ]              |
         |  UNO_R3    GND MOSI 5V  ____________/
          \_______________________/
		  
		
  
  Desenvolvedor: Wanderson D. Lopes
*/




int pinA = 4;
int pinB = 7;
int pinC = 8;
unsigned long steppingDelay=20000;
unsigned long preTimeDelay=0, preTimeLoop=0;

int vel1 = 1100, vel2 = 700;
int aux = 0, some = 200, mais = 2;

void setup() { 
 	//Serial.begin(9600);
  	pinMode(pinA, OUTPUT);  
	pinMode(pinB, OUTPUT);  
	pinMode(pinC, OUTPUT);
	digitalWrite(pinA, 0);  
	digitalWrite(pinB, 0);
	digitalWrite(pinC, 0);   
}


void espera(unsigned long x){ 
	preTimeDelay=micros();  
	while((micros()-preTimeDelay) < x);
}


void RPM(){
	if(steppingDelay < 10000){   
		float vpm = (1000/((steppingDelay/1000)*6))*60;     
		Serial.println(vpm);
	}
}


void roda(){
	preTimeLoop=millis();
	do{
		stepping(1);
		espera(steppingDelay);    
		stepping(2);      
		espera(steppingDelay);      
		stepping(3);   
		espera(steppingDelay);
	}while((millis()-preTimeLoop)<aux);  
	if((steppingDelay <= vel1) && (steppingDelay > vel2)){
		steppingDelay--;
		aux+=some;     
		if(some>1){        
			some-=some-mais; 
		}  
	}else     
		if((steppingDelay <=3000)&&(steppingDelay > vel1)){  
			steppingDelay--;     
		}else        
			if(steppingDelay > 3000){           
				steppingDelay-=100;
			}
}


void loop() {
	//RPM();
	roda();
}


void stepping(int stage){ 
    	switch(stage){
      		case 1:    
      			digitalWrite(pinC, 0);
      			digitalWrite(pinA, 1);    
      			digitalWrite(pinB, 0);    
      			break;  
      		case 2:    
      			digitalWrite(pinA, 0);    
      			digitalWrite(pinB, 1);    
      			digitalWrite(pinC, 0);    
      			break;  
      		default:    
      			digitalWrite(pinA, 0);    
      			digitalWrite(pinB, 0);   
      			digitalWrite(pinC, 1);    
      			break;  
    	}  
}
