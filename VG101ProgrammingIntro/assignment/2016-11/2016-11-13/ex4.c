#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
void swap (int*a,int*b)//A function to swap the value
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void ex4()
{
	FILE*fd1,*fd2;
	int n,t,a,b,i,j,k;
	int x[100][100],y[100][100],mult[100][100],tran[100][100];
	char *s=malloc(500);
	fd1=fopen("matrices.txt","r");
	fd2=fopen("result.txt","w"); //define the pointers and variables
	fgets(s,500,fd1); 
	for(b=0;;b++)
	{
		a=0;t=0;	
		for(n=0;;n++)
		{
			if(*(s+n)<'0'||*(s+n)>'9')
			{
				x[b][a]=t;
				t=0;
				if(*(s+n+1)<'0'||*(s+n+1)>'9')break;
				a++;
			}
			else t=t*10+(int)*(s+n)-48;
		}
		fgets(s,500,fd1); 
		if(*s<'0'||*s>'9')break;
	}
	for(n=0;n<=b;n++)for(t=0;t<=a;t++)fscanf(fd1,"%d",&y[n][t]);//read the matrix from the file
	for(n=0;n<=b;n++)
	{
		for(t=0;t<=a;t++)fprintf(fd2,"%d ",x[n][t]+y[n][t]);//calculate and output the sum of two matrixes	
		fprintf(fd2,"%\n");
	}
	fprintf(fd2,"%\n");
	for(n=0;n<=b;n++)
	{
		for(t=0;t<=a;t++)
		{
			for(k=0,i=0;i<=a;i++)k=k+x[n][i]*y[i][t];//calculate and output the product of two matrixes
			fprintf(fd2,"%d ",k);		
		}	
		fprintf(fd2,"%\n");
	} 
	fprintf(fd2,"%\n");
	swap(&a,&b);
	for(n=0;n<=a;n++)
	{
		for(t=0;t<=b;t++)
		{
			for(k=0,i=0;i<=a;i++)k=k+x[i][n]*y[t][i];//calculate and output the product of two transpose matrixes
			fprintf(fd2,"%d ",k);	
		}	
		fprintf(fd2,"%\n");
	} 
	fclose(fd1);fclose(fd2);free(s);//free the pointers	
} 
