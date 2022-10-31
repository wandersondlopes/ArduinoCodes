/*
Curso Química Computacional- IQ/UFG



criado   
por Wanderson D. Lopes
modificado set 2022
por Wanderson D. Lopes
*/


#include<stdio.h>
#include<math.h>

float delt(double a, double b, double c);

int main()
{
  double a,b,c,Delta,x[2];

  printf("Enter the a,b and c\n values from a a*x^2 + b*x + c = 0 equation\n");
  scanf("%lf %lf %lf",&a,&b,&c);
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

  return 0;
}


double delt(double a,double b,double c){
  double D;
  D = pow(b,2) - 4*a*c;
  return D;
  
}
