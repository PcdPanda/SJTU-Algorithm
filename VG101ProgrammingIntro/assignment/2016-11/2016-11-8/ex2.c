#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
void ex2()
{
	
	int m,D,i,i1;
	char d[10];
	printf("Please input the month number as a integer = \n");
	scanf("%d",&m);
	if(m==2)m=28;
	else if(m==4||m==6||m==9||m==11)m=30;
	else m=31;
	printf("Please enter the name of the first day of the month in lower case\n");
	scanf("%s",&d);	
	if(strcmp(d,"monday")==0)D=0;
	else if(strcmp(d,"tuesday")==0)D=1;
	else if(strcmp(d,"wednesday")==0)D=2;
	else if(strcmp(d,"thursday")==0)D=3;
	else if(strcmp(d,"friday")==0)D=4;
	else if(strcmp(d,"saturday")==0)D=5;
	else if(strcmp(d,"sunday")==0)D=6;
	else 
	{
		printf("You have entered the wrong name.");
		return 0;
	}
	printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");
	for(i=0;i<D;i++)printf("  \t");
	for(i1=1;i1<=m;i1++)
	{
		printf("%d\t",i1);
		if((D+i1)%7==0)printf("\n");
	}	
} 
