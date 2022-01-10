#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct c1 {float r,i;}car;//struct for cartesian
typedef struct c2{float r,a;}polar;//struct for polar coordinate 
void c2p(car*n) //change cartesian numbers to polar coordinate
{
	float a,r,i=0;
	while(i<=3)
	{
		printf("%g+%gi = ",(*n).r,(*n).i);
		r=sqrt(pow((*n).r,2)+pow((*n).i,2));
		a=atan((*n).r/(*n).i);
		printf("%g*e^%g\n",r,a);
		n++;
		i++;
	}
	
}
void p2c(polar*n)//change polar coordinate to cartesian numbers to
{
	float r,i,j=0;
	while(j<=1)
	{
		printf("%g*e^%g = ",(*n).r,(*n).a);
		r=(*n).r*cos((*n).a);
		i=(*n).r*sin((*n).a);
		printf("%g+%gi\n",r,i);
		n++;
		j++;
	}
}
void ex1()
{
	car *c=malloc(4*sizeof(car));
	polar*p=malloc(2*sizeof(polar));	//alloc memory
	*c=(car){3,4.0/5};  
	*(c+1)=(car){0,log10(4)};
	*(c+2)=(car){45.245,0.235};
	*(c+3)=(car){4*cos(M_PI/9),4*sin(M_PI/9)};
	*p=(polar){3,M_PI/17};
	*(p+1)=(polar){1,M_PI/12};//input the data
	c2p(c);//change the form
	p2c(p);
	free(c);//free the pointers
	free(p);
} 

