/* ============================================================

   Curso de Arduino
   
   Leitura Profissional de Botões

   Compilador: Arduino IDE 1.8.4

   MCU: Atmega328p
   Autor: Eng. Wagner Rambo
   Data:  Abril de 2020


============================================================ */


// ============================================================
// --- Mapeamento de Hardware ---
#define   bt1   (1<<4)
#define   led   (1<<5)


// ============================================================
// --- Variáveis Globais ---
boolean  bt1_f = 0x00;


// ============================================================
// --- Programa Principal ---
void setup()
{
   DDRB  &=  ~bt1;     //configura entrada para o botão
   PORTB |=   bt1;     //habilita o pull-up interno
   DDRB  |=   led;     //configura saída para o led


   while(1)
   {
      if(!(PINB&bt1)) bt1_f = 0x01;

      if((PINB&bt1) && bt1_f)
      {
         bt1_f = 0x00;

         PORTB ^= led;
        
      } //end if bt1
    
 
   } //end while
    
} //end setup
 





























// ============================================================
// --- FINAL DO PROGRAMA ---

