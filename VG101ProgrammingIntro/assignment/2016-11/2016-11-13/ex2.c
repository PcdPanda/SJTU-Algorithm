#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
void ex2()
{ 
	char*a=malloc(500*sizeof(char));
	int n,s=0,t=0,max=0,r,num;
	int *i=malloc(500*sizeof(int));//allocate memory and define variables
	printf("Please input the number of integers n = ");
	scanf("%d\0",&num);
	getchar();	
	printf("Please enter your integers with spaces separating them :\n");
	gets(a); //input the integer nmber and the integers
	for(n=0;;n++)
	{
		if('0'>*(a+n)||'9'<*(a+n))//find the spaces
		{
			*(i+s)=t;
			t=0;
			if(s>=num-1)break;
			s++;
		}
		else t=t*10+(int)*(a+n)-48;
	}
	for(t=0;t<=s;t++)if(*(i+t)>max)max=*(i+t);//find the max number
	printf("There are %d numbers and %d spaces\n",s+1,s);//read the integers in strings by using pointers
	srand(time(0));
	r=rand()%max;//genrate a random number
	printf("The random number is %d and the max is %d\n",r,max);
	for(t=0;t<=s;t++)if(*(i+t)>r)printf("%d ",*(t+i));//output the numbers larger than the random number
	free(a);
	free(i);//set the pointers free
} 
