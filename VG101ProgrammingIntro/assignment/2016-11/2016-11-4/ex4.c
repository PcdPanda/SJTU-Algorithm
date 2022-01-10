#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void root(float a,float b,float c)
{
	float delta=pow(b,2)-4*a*c,r1,r2;
	if(delta<0)
	{
		r1=(-b)/(2*a);
		r2=sqrt(-delta)/(2*a);
		if(a>0)printf("The two complex roots are %g+%gi and %g%gi",r1,r2,r1,-r2); 
		else printf("The two complex roots are %g%gi and %g+%gi",r1,r2,r1,-r2); 
	} 
	else if(delta==0)
	{	
		r1=(-b)/(2*a);
		printf("It has the same root equals to %g",r1); 
	}
	else
	{
		r1=(-b+sqrt(delta))/(2*a);
		r2=(-b-sqrt(delta))/(2*a);
		printf("The big root is %g\nThe small root is %g\n",r1,r2);		
	}
}
void ex4() 
{
	float a,b,c;
	printf("Please enter the coefficients\n");
	scanf("%f %f %f",&a,&b,&c);
	root(a,b,c);
}
