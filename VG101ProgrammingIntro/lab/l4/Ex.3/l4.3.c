#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include<math.h> 
#define g 9.81
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float f(float x)
{
	return 1.5+tan(30*M_PI/180)*x-(g/(2*pow(30*cos(30*M_PI/180),2)))*pow(x,2); 
}
float F(float x0,float x1)
{
	float x;
	x=(x0*f(x1)-x1*f(x0))/(f(x1)-f(x0));
	if(abs(f(x))<FLT_EPSILON)return x;
	F(x,x0);
}
int main() 
{
	float t=F(75,85)/(30*cos(30*M_PI/180));
	printf("The projectile touches the ground after %f seconds",t);
	return 0;
}
