#include <stdio.h>
#include <stdlib.h>
#include "assignment.h"
void move(int n,int a,int b,FILE*fd,int *m,int temp)
{
	(*m)++;
	if(n==1)
	{
		fprintf(fd,"Moving disc 1 from Peg 1 to Peg 2\n");
		return;	
	}	
	else
	{
		fprintf(fd,"Moving disc %d from Peg %d to Peg %d\n",n,a,b);
		move(n-1,1,3,fd,m,2);
		move(1,1,2,fd,m,0);
		move(n-1,3,2,fd,m,1);
	}
	
}
int M(int n,FILE*fd)
{
	int *m=malloc(sizeof(int));
	*m=0;
	move(n,1,2,fd,m,0);
	return *m;
} 
int main()
{
	int n;
	FILE*fd;
	fd=fopen("output.txt","w");
	printf("Input a number of disks: ");
	scanf("%d",&n);
	printf("Details written in output.txt.\n");
	printf("It took %d moves",M(n,fd));
	fclose(fd);
	return 0;
}
