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


/* converte o tempo de delay de microsegudos para milesegundos   
 multiplicar pela quantidade de execuções por volta   
 calcular a quantidae de voltas por segundo   
 calcular a quantidade de voltas por minuto */
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
