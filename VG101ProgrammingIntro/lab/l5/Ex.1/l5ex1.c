#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{	
	char *a=malloc(500),d,e;
	int c,i,n;
	printf("Input a string: ");
	gets(a);
	n=strlen(a); 
	printf("\nChoose 1 to replace a character or 2 to delete a character: ");
	scanf("%d",&c);	
	
	if(c==1)
	{
		
		printf("\nReplace character :");
		scanf(" %c",&d);
		printf("\nwith: ");
		scanf(" %c",&e);
		for(i=0;i<=n;i++)if(*(a+i)==d)*(a+i)=e;
	}
	else if(c==2)
	{
		printf("\nDelete character :");
		scanf(" %c",&d);
		for(i=0;i<=n;i++)
		{
			if(*(a+i)==d)
			{
				memmove(a+i,a+i+1,n-1-i); 
				*(a+n-1)=' ';
				n--;
			}
			if(*(a+i)==d)i--;
		}
	}
	else 
	{
		printf("error");
		return 0;
	} 	
	printf("New string: %s",a);
	
	return 0;
}
