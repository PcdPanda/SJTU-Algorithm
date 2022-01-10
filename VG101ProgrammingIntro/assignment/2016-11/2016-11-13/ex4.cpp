#include <iostream>
using namespace std;
void fun1()
{
	int N=0,a;
	cout<<"Please enter a"<<endl;
	cin>>a;
	for(;a!=1;N++)
	{
		if(a%2==0)a/=2;
		else a=3*a+1;
	}
	cout<<"N = "<<N;
}
void fun2()
{
	float M;
	int a,a1,a2,N,n=0;
	cout<<"Please enter the upper bound M"<<endl;
	cin>>M; 
	for(a=2;a<=M;a++)
	{
		for(N=0,a1=a;a1!=1;N++)
		{
			if(a1%2==0)a1/=2;
			else a1=3*a1+1;
		}
		if(N>n)
		{
			a2=a;
			n=N;	
		}	
	}
	cout<<"A is equal to "<<a2;
}
int main()
{
	int n;
	cout<<"Please enter 1 or 2 to choose the function to run"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:fun1();break;
		case 2:fun2();break;
		default: cout<<"error";break;
	} 
	return 0;
}
