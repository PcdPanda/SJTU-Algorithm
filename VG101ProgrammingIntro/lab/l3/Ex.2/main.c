#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sum.h" 
#include "prod.h"
#include "exp.h"
#include "quorem.h" 
#define QUOREM 
#define SUM
#define PROD
#define MPOW
int main()
{
	int a, b;
	printf("Enter two integers: ");
	scanf("%d %d",&a, &b);
	#ifdef QUOREM
	printf("Quotient: %d\n",quo(a,b));
	printf("Remainder: %d\n",rem(a,b));
	#endif
	#ifdef SUM
	printf("Sum: %d\n",sum(a,b));
	#endif
	#ifdef PROD
	printf("Product: %d\n",prod(a,b));
	#endif
	#ifdef MPOW
	printf("Exponent: %ld\n",mpow(a,b));
	#endif
	return 0;
}
	
