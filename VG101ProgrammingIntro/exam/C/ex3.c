#include <stdio.h>
#include <stdlib.h>
#include "assignment.h"
void ex3()
{
	int n,i=1,j=1,t=0,k=0,m=0,a=0,b=0,c;
	printf("Please an integer n = ");
	scanf("%d",&n);
	for(t=1;t<n;)
	{
		if(m==0)
		{
			k++;
			m=1;
			if(a==0)
			{
				i++;
				a=1;
			}
			else
			{
				j++;
				a=0;
			}
			t++;
		}
		else 
		{
			for(c=1;c<=k;c++,t++)
			{
				if(t>=n)break;
				m=0;
				if(b==0)
				{
					j++;i--;
					
				}
				else
				{
					j--;i++;	
				}	
			}
			if(b==1)b=0;
			if(b==0)b=1;
		}
	}
	printf("The %dth Cnaor number is %d/%d",n,j,i);
	return 0;
}
