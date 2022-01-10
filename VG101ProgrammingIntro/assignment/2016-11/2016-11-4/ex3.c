#include "assignment.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Q2(char n[10])
{
	if(n[0]=='a'||n[0]=='e'||n[0]=='i'||n[0]=='o'||n[0]=='u'||n[0]=='A'||n[0]=='E'||n[0]=='I'||n[0]=='O'||n[0]=='U')printf("The input letter is a vowel");
	else printf("The input letter is a consonant");
} 
void Q3(char b[10])
{
	int n=0,i;
	for(i=0;i<=10;i++)
	{
		if(b[i]<'0'||b[i]>'9')break;
		n=n*10+(int)b[i]-48;
	}
	char n1[10];
	printf("You have chosen the question 2,please entera character which can only be 'b' or 'B'\n%d",n);
	scanf("%s",&n1);
	
	if(n1[0]=='b')switch(n)
	{
		case 8:
			printf("character");
			break;
		case 16:
			printf("short int");
			break;
		case 32:
			printf("int\nlong\nfloat");
			break;
		case 64:
			printf("long long int\ndouble");
			break;
		case 96:
			printf("long double");
			break;
		default:
			printf("There doesn't exist such data types");
			break;	
	}
	else if(n1[0]=='B')switch(n)
	{
		case 1:
			printf("character");
			break;
		case 2:
			printf("short int");
			break;
		case 4:
			printf("int\nlong\nfloat");
			break;
		case 8:
			printf("long long int\ndouble");
			break;
		case 12:
			printf("long double");
			break;
		default:
			printf("There doesn't exist such data types");
			break;	
	}
	else printf("You have enterer the wrong character");
}
void ex3()
{ 

	char n[10]; 
	printf("Please enter a character or a digit to choose the function \n");
	printf("If you enter a letter,the function 2 will judge whether the letter is a vowel.If you enter a digit, the function 3 will require you to enter a b or B again as a unit and print the correspoding data types\n");
	scanf("%s",&n);
	if(n[0]<='9'&&n[0]>='0')Q3(n); 
	else Q2(n);		
}
