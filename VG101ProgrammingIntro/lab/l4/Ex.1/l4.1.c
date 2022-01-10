#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	int a,b;
	printf("Please enter your upper bound = ");
	scanf("%d",&a) ;
	srand(time(0));
	b=rand()%a;
	while(1)
	{
		printf("Please enter your guess number = ");
		scanf("%d",&a) ;
		if(a==b)break;
		if(a>b)printf("larger\n");
		if(a<b)printf("smaller\n");
	}
	printf("win! The random number is %d",b);
	return 0; 
}
