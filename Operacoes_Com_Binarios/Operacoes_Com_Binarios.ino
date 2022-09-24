/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG
	
Nesse programa são feitas operacoes com binarios.
Observa-se seu valor pela serial
  

criado   04/01/2015
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/



byte y = 0b00000011;
byte c;
int k = 3;
int l = 2;

void setup(){
  
  Serial.begin(9600); 
  c = 0b00000000;
  c = y |= (1 << 4);
  c |= (1<< 5);
  c |= (1<< 3);
 
  // or composto forca os bits a serem marcados com 1
  c |= (1<< l);  
  //and composto negado.
  c &= ~(1<< k);   
  // xor composto
  c ^= (1<< d);

  Serial.print(char(c));  
  delay(100);
  
}


void loop(){
  
  Serial.println(char(c));  

  k = k + 1;
  l = l +1;
  if(k>6)
    k = k -7;  
  if(l>6)
    l = l-7;  
  
  delay(100);
}
