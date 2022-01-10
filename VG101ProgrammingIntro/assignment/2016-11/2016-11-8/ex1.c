#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
void ex1()
{
	int n,i,i1,i2;
	printf("Please enter the upper bound = ");
	scanf("%d",&n);
	if(n==1)
	{
		printf("There doesn't primes smaller than the bound.");
		return;
	}
	int a[n];//a[n] is the array contains the all the numbers less than n
	for(i=2;i<=n-1;i++)a[i]=i;//Let a[n]=n
	for(i=2;i<=n-1;i++)//Decide whether the number is a prime
	{
		for(i1=2;i1<=i;i1++)
		{
			if(a[i]%i1==0&&(a[i]!=i1))//if a[i] isn't a prime then delet it
			{
				for(i2=i;i2<=n;i2++)a[i2]=a[i2+1];
				n--;
				break;
			}
		} 
	}
	for(i=2;i<=n-1;i++)printf("%d \n",a[i]);
} 

