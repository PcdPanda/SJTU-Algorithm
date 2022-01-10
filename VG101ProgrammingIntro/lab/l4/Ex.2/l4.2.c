#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float mean(float b[10])
{
	float m=0;
	int i;
	for(i=1;i<=10;i++)m=m+b[i]/10;
	return m;
}
float median(float b[10])
{
	int i,I;
	float m,p;
	for(I=9;I>=1;I--)
	{
		for(i=1;i<=I;i++)
		{
			if(b[i]>b[i+1])
			{
				p=b[i];
				b[i]=b[i+1];
				b[i+1]=p;
			}
		}
	}
	m=(b[5]+b[6])/2;
	return m;
}
float variance(float b[10])
{
	float m=0;
	int i;
	for(i=1;i<=10;i++)m=m+pow(b[i]-mean(b),2);
	m=m/10; 
	return m;
}
float sd(float b[10])
{
	return pow(variance(b),0.5);
}
int main() 
{
	int i;
	float a[10];
	printf("Please enter your 10 marks\n");
	for(i=1;i<=10;i++)
	{
		scanf("%f",&a[i]);
	}
	printf("The mean value is %lf\n",mean(a));
	printf("The median value is %lf\n",median(a));
	printf("The variance value is %lf\n",variance(a));
	printf("The median value is %lf\n",sd(a));
	return 0;
}

