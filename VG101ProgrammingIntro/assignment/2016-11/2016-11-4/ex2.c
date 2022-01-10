#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int GCD(int a,int b,int c)
{
	if(a%c==0&&b%c==0)return c;
	else return GCD(a,b,c-1);
}
void ex2() 
{
	int a,b;
	printf("Please enter two integers = ");
	scanf("%d %d",&a,&b);
	printf("The GCD is %d",GCD(a,b,a<=b?a:b));
}
