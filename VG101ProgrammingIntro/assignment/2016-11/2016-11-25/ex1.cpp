#include <iostream>
#include "assignment.h"
using namespace std;
void ex1()
{
	int a,b,c,d;
	cout<<"Please enter the current year :"<<endl;
	cin>>a;
	cout<<"Please enter your current age :"<<endl;
	cin>>b;
	cout<<"Please enter another year :"<<endl;
	cin>>c;
	d=b+c-a;
	if(d>b)cout<<"You will be "<<d<<" years old in "<<c<<endl;
	else if (d==b)cout<<"You are "<<d<<" years old in "<<c<<endl;
	else if (d<0)cout<<"You were "<<d<<" years old in "<<c<<" which means you weren't born yet.'"<<endl;
	else if (d<b)cout<<"You were "<<d<<" years old in "<<c<<endl;
} 
