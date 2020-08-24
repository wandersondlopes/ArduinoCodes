#include <SPI.h>
#define SS_SLAVE 3 // Indica o pino seletor como pino 3 do Arduino
void setup( void ){
pinMode( SS_SLAVE , OUTPUT ) ;
SPI.begin() ; // Inicializa a SPI do periférico.
SPI.setDataMode(SPI_MODE3); // Indica que o quando clock passa de nivel baixo para alto a o bit estara disponivel
                            // e que o nivel de repouso eh o nivel alto
SPI.setBitOrder(MSBFIRST); // Indica que o primeiro bit recebido sera o de maior ordem de grandeza e o ultimo de menor ordem de grandeza
}

void loop( void ){
  
  
}

long Amostra(){
  delay(1);
  unsigned char retorno[ 3 ] ; // Retorno para cada byte.
  digitalWrite( SS_SLAVE , LOW ) ; // Habilita o SS.
  retorno[ 0 ] = SPI.transfer( 0x00 ) ; // Envia 00h e recebe o retorno 0.
  retorno[ 1 ] = SPI.transfer( 0x00 ) ; // Envia 00h e recebe o retorno 1.
  retorno[ 2 ] = SPI.transfer( 0x00 ) ; // Envia 00h e recebe o retorno 2.
  long val = long(retorno); // unifica todos as variaveis do array em uma variavel e converte para variavel apropriada.
  digitalWrite( SS_SLAVE , HIGH ) ; // Desabilita o SS.
  return val;
}


