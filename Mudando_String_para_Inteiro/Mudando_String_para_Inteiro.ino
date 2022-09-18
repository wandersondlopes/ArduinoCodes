/*


Código que recebe bytes pela serial que correspondem a algarismos de um número
Converte a String em uma variavel int que é utilizada para determinar a quantidade
de vezes que um led deve ligar e desligar.

criado   Mar 2019
por Matheus Costa
modificado set 2022
por Wanderson D. Lopes
*/



int Byte_recebido;
int valor_inteiro;
String valor_string;
#define led 13


void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}
void loop() {
  if(Serial.available()>0){
    Byte_recebido = Serial.read() - 48; //diminui 48 por causa da tabela ascii
    //ele só adiciona os valores na string se for diferentes de 18 (B em maiusculo)
    if(Byte_recebido != 18){
      valor_string = valor_string + Byte_recebido;
    }
  }
  //se ele receber B confirma o final da string
  if(Byte_recebido == 18){
    Serial.println(valor_string);
    Byte_recebido = 0;
    valor_inteiro = valor_string.toInt();
    for(int i = 0; i<valor_inteiro; i++){
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
    delay(500);
    }
    //reseta  o valor da string
    valor_string = "";
  }
}
