#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
typedef struct _card
{
	int num,suit;
}card;
void disp(card c[52])
{
	int i;
	for(i=0;i<=51;i++)
		{
			switch(c[i].suit)
				{
					case 0:printf("S");break;
					case 1:printf("H");break;
					case 2:printf("D");break;
					case 3:printf("C");break;
				}
				if(c[i].num<=10)printf("%d\t",c[i].num);
				else switch(c[i].num)
				{
					case 11:printf("J\t");break;
					case 12:printf("Q\t");break;
					case 13:printf("K\t");break;
					case 14:printf("A\t");break;
				}	
			if(i%13==12)printf("\n");
		}			
}
void ex3()
{
	int i,t;
	card c[52],k;
	printf("Each card is demonstrated by a letter and the number\nFor suit: S means spades,H means hearts,D means Diamonds and C means clubs\n");
	printf("For number:J means Jack,Q means Queen,K means King and A means Ace\n");
	for(i=0;i<=51;i++)
	{
		c[i].suit=i/13;
		c[i].num=(i)%13+2;
	}
	disp(c);
	srand(time(0));
	for(i=0;i<=51;i++)
	{
		t=rand()%51;
		k=c[t];
		c[t]=c[i];
		c[i]=k;
	}
	printf("The deck has been shuffled,please press enter to continue\n");
	while(1)if(getch()==13)break;
	disp(c);
	printf("The deck has been sorted again,please press enter to continue\n");
	while(1)if(getch()==13)break;
	for(i=0;i<=51;i++)
	{
		c[i].suit=i/13;
		c[i].num=(i)%13+2;
	}
	disp(c);
}
