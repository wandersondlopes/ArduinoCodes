void setup() {
  word var = 16;
  Serial.begin(9600);// put your setup code here, to run once:
  Serial.print("O valor da variavel word é: ");
  Serial.println(var);
  Serial.print("A quantidade de bytes que ela ocupa é: ");
  Serial.print(sizeof(var));
}

void loop() {
  // put your main code here, to run repeatedly:

}
