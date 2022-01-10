#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
void swap (int*a,int*b)//A function to swap the value
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void ex3()
{
	int n,t,a,b,i,k;
	int x[100][100],y[100][100];
	string s; 
	ifstream fd1("matrices.txt");
	ofstream fd2("result.txt"); //define the pointers and variables
	getline(fd1,s);
	for(b=0;;b++)
	{
		a=0;t=0;	
		for(n=0;;n++)
		{
			if(s[n]<'0'||s[n]>'9')
			{
				x[b][a]=t;
				t=0;
				if(s[n+1]<'0'||s[n+1]>'9')break;
				a++;
			}
			else t=t*10+(int)s[n]-48;
		}
		getline(fd1,s); 
		if(s[0]<'0'||s[0]>'9')break;
	}
	for(n=0;n<=b;n++)for(t=0;t<=a;t++)fd1>>y[n][t];//read the matrix from the file
	for(n=0;n<=b;n++)
	{
		for(t=0;t<=a;t++)fd2<<x[n][t]+y[n][t]<<" ";//calculate and output the sum of two matrixes
		fd2<<endl;
	}
	fd2<<endl;
	for(n=0;n<=b;n++)
	{
		for(t=0;t<=a;t++)
		{
			for(k=0,i=0;i<=a;i++)k=k+x[n][i]*y[i][t];//calculate and output the product of two matrixes
			fd2<<k<<" ";		
		}	
		fd2<<endl;
	} 
	fd2<<endl;
	swap(&a,&b);
	for(n=0;n<=a;n++)
	{
		for(t=0;t<=b;t++)
		{
			for(k=0,i=0;i<=a;i++)k=k+x[i][n]*y[t][i];//calculate and output the product of two transpose matrixes
			fd2<<k<<" ";	
		}	
		fd2<<endl;
	} 
	fd1.close();fd2.close();//free the pointers	
} 
