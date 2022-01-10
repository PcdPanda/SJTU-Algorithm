#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define swap(a,b) a=a+b;b=a-b;a=a-b;
void ex5()
{
	float a,b;
	printf("Please enter your two numbers\n");
	scanf("%f %f",&a,&b);
	swap(a,b);
	printf("a=%g,b=%g\na=a+b=%g\nb=a-b=%g\na=a-b=%g\na=%g,b=%g",b,a,(a+b),b,a,a,b);
}

