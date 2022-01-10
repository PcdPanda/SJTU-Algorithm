#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct _c
{
	float r,i;
}c;
void product(c n1,c n2)
{
	float a=n1.r*n2.r-n1.i*n2.i,b=n1.r*n2.i+n1.i*n2.r;
	if(b==0)printf("The product is %g",a);
	else if(a==0)
		{ 
			if(b==1)printf("The product is i");
			else if(b==-1)printf("The product is -i");
			else printf("The product is %gi",b);
		}	
	else if(b>0)printf("The product is %g+%gi",a,b);
	else printf("The product is %g%gi",a,b);		
}
void sum(c n1,c n2)
{
	float a=n1.r+n2.r,b=n1.i+n2.i;	
	if(b==0)printf("The sum is %g",a);
	else if(a==0)
	{ 
		if(b==1)printf("The sum is i");
		else if(b==-1)printf("The sum is -i");
		else printf("The sum is %gi",b);
	}	
	else if(b>0)printf("The sum is %g+%gi",a,b);
	else printf("The sum is %g%gi",a,b);		
}
void operation()
{
	c n1,n2;
	char o[1];	
	printf("You need to enter the coefficients of the real part and the imaginary part of the two complex numbers orderly as the requirement\n");
	printf("For example, if you enter 1 2 3 4 + orderly,the function will calcuate the sum of 1+2i and 3+4i and print 4+6i.\n");
	printf("Please enter the real part of the first complex number = \n");
	scanf("%f",&n1.r);
	printf("Please enter the imaginary part of the first complex number = \n");
	scanf("%f",&n1.i);
	printf("Please enter the real part of the second complex number = \n");
	scanf("%f",&n2.r);
	printf("Please enter the imaginary part of the second complex number = \n");
	scanf("%f",&n2.i);
	printf("Please enter the operation + or *\n");
	scanf("%s",&o);
	if(o[0]=='+')sum(n1,n2);	
	else if(o[0]=='*')product(n1,n2);
	else printf("You enter the wrong operation");
}
void ex1()
{
	operation();
} 


