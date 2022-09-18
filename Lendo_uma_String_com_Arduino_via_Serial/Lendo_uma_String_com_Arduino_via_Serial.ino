/*
GME - Grupo de Metodos Eletroforéticos
Instituto de Quimica - UFG

Código responsavel por receber string pela Serial e concatenar
em uma string utilizando a função concat()

criado   
por Paulo Trentin
modificado set 2022
por Wanderson D. Lopes
*/


int led = 13;
  
void setup() { 
 pinMode(led, OUTPUT); 
 Serial.begin(9600);
}
  
/**
 * Função que lê uma string da Serial
 * e retorna-a
 */
String leStringSerial(){
  String conteudo = "";
  char caractere;
  
  // Enquanto receber algo pela serial
  while(Serial.available() > 0) {
    // Lê byte da serial
    caractere = Serial.read();
    // Ignora caractere de quebra de linha
    if (caractere != '\n'){
      // Concatena valores
      conteudo.concat(caractere);
    }
    // Aguarda buffer serial ler próximo caractere
    delay(10);
  }
    
  Serial.print("Recebi: ");
  Serial.println(conteudo);
    
  return conteudo;
}
  
void loop() {
  // Se receber algo pela serial
  if (Serial.available() > 0){
    // Lê toda string recebida
    String recebido = leStringSerial();
      
    if (recebido == "LED1:1"){
      digitalWrite(led, HIGH);
    }
      
    if (recebido == "LED1:0"){
      digitalWrite(led, LOW);
    }
  }
}
