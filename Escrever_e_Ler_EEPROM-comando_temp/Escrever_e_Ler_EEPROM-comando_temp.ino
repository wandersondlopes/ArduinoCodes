/*
Eletriclabor Tecnologia

Funcao:Escrever e ler eeprom em periodos determinados pelo comando_temp
Mensagem:Elohim  Yehovah é o nome do Santo
Versão:Sem testar

criado   Nov 2012
por Almir Bispo
modificado set 2022
por Wanderson D. Lopes
*/



#include <EEPROM.h>
void setup ()
{
   Serial.begin(9600);
  while (!Serial) { ; }
  // send an intro:
  Serial.println();
}


void loop ()
{
int posicao;
int periodo;//periodo é o valor em minutos de intervalo 
int c_p;
int tam_memoria;
int  comando_temp;//define temporizacao
int comando_func;//define funcao
//===campos lidos
char valor_lido;
char ocorrencia;
String msg;

tam_memoria=512/2;//tamanho da memoria
if (comando_temp!=0 && comando_func!=0)
{
//muda periodo-(lista de valorores para comando:1=periodo 1 min,2=2 min,3= 3 min) onde os dados serão gravados
if (comando_temp==1){periodo==1;}//1 min
if (comando_temp==2){periodo==2;}//2min
if (comando_temp==3){periodo==3;}//3min
if (comando_temp==4){periodo==60;}//1 hora
if (comando_temp==5){periodo==60*6;}//6 horas
//comandos de escrita na memoria=6 e leitura=7
if (comando_func==1)//inicia escrita na memoria
{
c_p=0; 

for (posicao=tam_memoria;;c_p++)
{
int   valor_ADC = analogRead(A0)/4;// 8 bits (1024/4)=(0-255)
//formato da tabela [valor|periodo]
EEPROM.write(c_p,valor_ADC);//campo do valor da leitura
EEPROM.write(c_p+(tam_memoria+1),(periodo));//campo do periodo
delay((periodo*60)*1000);// a cada 3 minutos (periodo)
}//for write
}//if 1

if (comando_func==2)
{
  c_p=0;
  for (posicao=tam_memoria;;c_p++)
  {
  //formato da tabela [valor|periodo]
valor_lido=EEPROM.read(c_p);//campo do valor da leitura
ocorrencia=EEPROM.read(c_p+(tam_memoria+1));//campo do periodo

msg=String(valor_lido)+";"+String(ocorrencia)+"\n";
//Serial.print(valor_lido);
//Serial.println(ocorrencia);
  }//for read
  Serial.println(msg);//escreve  apos leitura
}//if 2
}// se diferente de zero

}//loop
