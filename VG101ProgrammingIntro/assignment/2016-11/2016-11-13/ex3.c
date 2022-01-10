#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void ex3()
{
	FILE *fd1,*fd2,*fd3;
	int n=0,i,j=0,l1,l2;
	char*w1=malloc(500*sizeof(char)),*w2=malloc(100*sizeof(char));
	fd1=fopen("sentence.txt","r+");
	fd2=fopen("word.txt","r");
	fd3=fopen("count.txt","w");//define the variables and the pointers
	fgets(w1,500,fd1);
	fgets(w2,500,fd2); //read the string from the files
	l1=strlen(w1);
	l2=strlen(w2);//calculate the length of the strings
	for(i=0;i<=l1-1;i++)
	{
		if(*(w1+i)==*(w2+j)) 
		{
			j++;
			if(j>l2-1)
			{
				n++;
				j=0;
			}	
		}	
		else j=0;
	}//calculate the how many times the word occurs
	fprintf(fd3,"The word occurs %d times in the sentence.",n);//output
	fclose(fd1);
	fclose(fd2);
	fclose(fd3);
	free(w1;free(w2); //free the pointers
}
