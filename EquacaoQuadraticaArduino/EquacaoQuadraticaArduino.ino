/*
Curso Química Computacional- IQ/UFG



criado   
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/



//float delt(double a, double b, double c);

void setup()
{
  float a,b,c,Delta,x[2];
  Serial.begin(9600);
  Serial.println("Enter the a value a from a*x^2 + b*x + c = 0 equation");
  delay(5000);
  a = Serial.read();
  Serial.println("Enter the a value b from a*x^2 + b*x + c = 0 equation");
  delay(5000);
  b = Serial.read();
  Serial.println("Enter the a value c from a*x^2 + b*x + c = 0 equation");
  delay(5000);
  c = Serial.read();
  
  /*
  Serial.println("Enter the a,b and c values from a a*x^2 + b*x + c = 0 equation");
  delay(5000);
  c = Serial.read();
  
 
  for(int i; i <3;i++){
  
  }
    
    
  float D;
  D = pow(b,2) - 4*a*c;
  
  
  Delta=delt(a,b,c);

  if(Delta<0.0e+0){
    printf("There are no real roots \n");
    return 1;
  }else if(Delta == 0.0e+0){
    printf("The equation admits one root\n");
    x[0] = -b/(2*a);
    printf("x = %lf \n",x[0]);
  }else {
    printf("The equation admits two roots \n");
    x[0] = ( -b + sqrt(Delta) )/(2*a);
    x[1] = ( -b - sqrt(Delta) )/(2*a);
    printf("x1 = %lf , x2 = %lf \n",x[0],x[1]);
  }
  
  */

}

void loop()
{

}

/*
void delt(double a,double b,double c)
{

}
*/
