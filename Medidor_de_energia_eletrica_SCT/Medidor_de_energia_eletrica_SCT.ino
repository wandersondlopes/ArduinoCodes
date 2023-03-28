/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Medidor de corrente e potência elétrica aparente com Arduino e SCT-013.
Baseado no programa exemplo da biblioteca EmonLib

criado  11/02/2015
por FILIPEFLOP (Adilson Thomsen)
modificado Dez 2022
por Wanderson D. Lopes
*/

#include "EmonLib.h" 
#include <LiquidCrystal.h>
 
EnergyMonitor emon1;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
//Tensao da rede eletrica
int rede = 220.0;
 
//Pino do sensor SCT
int pino_sct = 1;
 
void setup() 
{
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);   
  //Pino, calibracao - Cur Const= Ratio/BurdenR. 1800/62 = 29. 
  emon1.current(pino_sct, 29);
  //Informacoes iniciais display
  lcd.setCursor(0,0);
  lcd.print("Corr.(A):");
  lcd.setCursor(0,1);
  lcd.print("Pot. (VA):");
} 
  
void loop() 
{ 
  //Calcula a corrente  
  double Irms = emon1.calcIrms(1480);
  //Mostra o valor da corrente
  Serial.print("Corrente : ");
  Serial.print(Irms); // Irms
  lcd.setCursor(10,0);
  lcd.print(Irms);
   
  //Calcula e mostra o valor da potencia
  Serial.print(" Potencia : ");
  Serial.println(Irms*rede);
  lcd.setCursor(10,1);
  lcd.print("      ");
  lcd.setCursor(10,1);
  lcd.print(Irms*rede,1);
   
  delay(500);
}
