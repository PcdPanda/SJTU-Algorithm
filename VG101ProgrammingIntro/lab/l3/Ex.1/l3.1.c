#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159 
#define G 6.674e-11
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	double c,r,T,V,M,D;
	printf("Please enter the body circumference = ");
	scanf("%lf",&c);
	printf("Please enter the distance = ");
	scanf("%lf",&r);
	printf("Please enter the period = ");
	scanf("%lf",&T);
	M=(4*pow(PI,2)*pow(r,3))/(G*pow(T,2));
	V=pow(c,3)/(6*pow(PI,2));
	D=M/V;
	printf("The body's density is %lf kg/(m^3)",D);
	return 0;
}
