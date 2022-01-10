#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "assignment.h"
typedef struct _trapezium//struct
{
	float b,B,h;
}trap;
float area(trap a)//calculate the area
{
	float s;
	s=(a.b+a.B)*a.h/2;
	return s;
}
trap * gen(int n)//generate n trapeziums
{
	int i=0;
	trap*a=malloc(n*sizeof(trap));
	for(;i<n;i++)
	{
		(a+i)->b=rand()%101;
		(a+i)->B=rand()%101;
		(a+i)->h=rand()%101;
	}
	return a;
}

void find(trap*a,int i,int j,int n)//return the largest area
{
	int t=0,k=0;
	float s=0;
	trap*b[5];
	b[0]=a+i*n+j;
	b[1]=a+(i-1)*n+j;
	b[2]=a+i*n+j+1;
	b[3]=a+(i+1)*n+j;
	b[4]=a+i*n+j-1;//find the pointer of the trapezium around the input position
	printf("The area of trapezium at (%d %d) is %g\n",i+1,j+1,area(*b[0]));//show the area at (i,j)
	for(t;t<5;t++)//find the biggest area
	{
		if(area(*b[t])>s)
		{	
			if(i==0&&t==1)continue;
			if(i==n&&t==3)continue;
			if(j==n&&t==2)continue;
			if(j==0&&t==4)continue;
			s=area(*b[t]);
			k=t;
		}
	}
	i++;
	j++;
	switch(k)
	{	
		case 1:i--;break;
		case 2:j++;break;
		case 3:i++;break;
		case 4:j--;break; 
	}
	printf("The largest area is %g and its postion is (%d,%d)",s,i,j);
}
void ex1()
{
	int n,i,j;
	srand(time(NULL));
	printf("Please enter n = ");
	scanf("%d",&n);
	trap*a=malloc(pow(n,2)*sizeof(trap));
	a=gen(pow(n,2)); 
	printf("Please enter i and j : \n");
	scanf("%d %d",&i,&j);
	find(a,i-1,j-1,n);
	return 0;
}
