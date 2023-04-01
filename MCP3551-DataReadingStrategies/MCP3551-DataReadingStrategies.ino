/*


Esse código é um exemplo de uso com 3 maneiras diferentes de receber os bits do MCP3551
O protocolo de comunicação é SPI
pins: 
 cs=8
 sdo/rdy=12
 sck=13

criado   2021
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


#include <SPI.h>

unsigned char sspin=8; //cs pin

//Variaveis de Reading2()
int bitvalue[4];
long bytevalue;
int signBit = 1;
int overFlow = 0;


union{
	int32_t value;
	uint8_t aa[4];
} c ;



void setup(){
  pinMode(12,INPUT);  //to check ready pin
  pinMode(sspin,OUTPUT);
  digitalWrite(sspin,HIGH);//for single conversion
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE3);
  SPI.setClockDivider(SPI_CLOCK_DIV16);//max. speed of chip is 5 Mhz
  Serial.begin(9600);  
}

void loop(){

  Reading1();
  Reading2();
  Reading3();
}

void Reading1(){
digitalWrite(sspin,LOW);
while(digitalRead(12)){
  digitalWrite(sspin,LOW);
	}
c.aa[2]=SPI.transfer(0x00);
c.aa[1]=SPI.transfer(0x00);
c.aa[0]=SPI.transfer(0x00);
c.aa[3]=0x00;
digitalWrite(sspin,HIGH);
//check if overflow has occured
if((c.aa[2]&(1<<6))|(c.aa[2]&(1<<7))){
  c.aa[2]&=~(1<<6);
  Serial.println(c.value);
}
//check if sign bit is affected. if so, since it is two's compliment,
// substract it from 2^N
else if(c.aa[2]&(1<<5)){
c.value=0x400000-c.value;
Serial.println(c.value);
}
else{
Serial.println(c.value);
}
  delay(10);
}

void Reading2(){
  signBit = 1;
  overFlow = 0;
  digitalWrite(sspin, LOW);
  delay(10);
  for (int i = 0; i < 4; i++)
  {
    bitvalue[i] = 0;
    bitvalue[i] = SPI.transfer(0);
  }
  digitalWrite(sspin, HIGH);

  bytevalue = 0;
  if (bitvalue[0] & 0x40 | bitvalue[0] & 0x80)
  {
    bitvalue[0] = 0x3F & bitvalue[0];
    overFlow = 1;
    Serial.println("Error");
  }
  else if (bitvalue[0] & 0x20)
  {
    bitvalue[0] = 0x1F & bitvalue[0];
    signBit = -1;
  }
  bytevalue = bitvalue[0];
  bytevalue = (bytevalue << 8) | bitvalue[1];
  bytevalue = (bytevalue << 8) | bitvalue[2];

  bytevalue = (signBit * bytevalue);
  singnBit = 1;

  Serial.print(bytevalue*1.192/1000000, 6);

  Serial.println(" Volts");
}

float Reading3(){

}

}
