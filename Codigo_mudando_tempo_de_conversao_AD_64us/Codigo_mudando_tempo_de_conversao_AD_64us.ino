// Variáveia para armazenar os resultados
 
unsigned long tempo_inicio;
 
unsigned long tempo_fim;
 
unsigned long valor;
 
// constante para configuração do prescaler
const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
 
void setup() {
 Serial.begin(9600);
 
 // configura o preescaler do ADC
 ADCSRA &= ~PS_128;  //limpa configuração da biblioteca do arduino
 
 // valores possiveis de prescaler só deixar a linha com prescaler desejado
 // PS_16, PS_32, PS_64 or PS_128
 //ADCSRA |= PS_128; // 64 prescaler
    ADCSRA |= PS_64; // 64 prescaler
 //  ADCSRA |= PS_32; // 32 prescaler
 // ADCSRA |= PS_16; // 16 prescaler
}
 
void loop() {  
 // leitura
   tempo_inicio = micros(); //marca tempo de inicio de leitura
   valor = analogRead(0);  //le valor convertido
   tempo_fim = micros();   //le tempo no fim da conversão
 
   //exibe valor lido e tempo de conversão
   Serial.print("Valor = ");
   Serial.print(valor);
   Serial.print(" -- Tempo leitura = ");
   Serial.print(tempo_fim - tempo_inicio);
   Serial.println(" us");
   delay(500);
}
