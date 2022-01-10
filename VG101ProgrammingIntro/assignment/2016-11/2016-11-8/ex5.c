#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "assignment.h" 
#define SWAP(a,b) { a ^= b; b ^= a; a ^= b; }
unsigned long int mult(unsigned long int a, unsigned long int b);
int optimal(unsigned long int n);
void ex5() 
{
	unsigned long int a, b;
	srand(time(NULL));
#ifndef TEST
	a=rand(); b=rand();
	printf("%ld*%ld=%ld %ld\n",a,b,mult(a,b), RAND_MAX);
#endif
#ifdef TEST
	int i
	for(i=0; i<1000000;i++)
	{
		a=rand(); b=rand();
		if(mult(a,b)!=a*b) 
		{
			fprintf(stderr,"Error (%d): a=%ld, b=%ld, a*b=%ld, k(a,b)=%ld\n",\
			i,a,b,a*b,mult(a,b));
			exit(-1);
		}
	}
#endif
}
unsigned long int mult(unsigned long int a, unsigned long int b) 
{
	int i, n, N;//define the integer 
	unsigned long int x0,y0,z0,z1=1;//define the long integer
	if(a<b) SWAP(a,b);//let a be the bigger number, and b be the smaller number
	if(b==0) return 0;//If there exists 0 then the product is 0
	//for(n=-1, i = 1; i <= b; i<<=1, n++); /* not optimal */
	//for(N=n; i <= a; i<<=1, N++);//The last two loops calculate the n and N which are equal to the digital number minus one of b and a
	n=optimal(b);//the optimal function is used to replace the original line
	N=optimal(a);//The last two lines calculate the n and N which are equal to the digital number minus one of b and a
	y0=b&((1<<n)-1);//Calculate b-(x^n) to retain the remaining binary number without the first binary digit
	x0=a&((1<<N)-1);//Calculate a-(x^N) to retain the remaining binary number without the first binary digit
	z0=mult(x0,y0);//Use recursion to calculate the product of the remain part of the binary number 
	i=N+n;//Calculate the first binary digit number of the product
	return ((z1<<i)+(x0<<n)+(y0<<N)+z0);//Using the previous result to calculate the sum
}
int optimal(unsigned long int n)
{
	if(n<=1)return 0;
	return 1+optimal(n>>1);
} 

