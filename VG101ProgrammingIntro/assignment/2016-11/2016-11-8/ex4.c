#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ex4()
{
	char a[500],b[100];
	printf("Input the sentence : ");
	gets(a);
	printf("Input the string : ");
	gets(b);
	int l1=strlen(a),l2=strlen(b),i,j,t=0;
	for(i=0;i<=l1;i++)
	{
		if(a[i]==b[0])
		{
			t++;
			for(j=1;j<=l2-1;j++)
			{
				if(a[i+j]!=b[j]||a[i+j]=="\0")
				{
					t--;
					break;
				}
			}
		}
	}
	printf("The string '%s' occurs %d times.",b,t);
}
