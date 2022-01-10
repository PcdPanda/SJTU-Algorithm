#include <iostream>
#include <iomanip>
#include "assignment.h"
using namespace std;
void ex2()
{
	cout<<"Please choose your option first"<<endl;
	cout<<"if you enter U the funtion will change dollars to RMB"<<endl;
	cout<<"if you enter R it will change RMB to dollars,else the function is invalid."<<endl;
	char a;
	float n,p;
	cin>>a;
	if(a=='U')
	{
		cout<<"Your original currency is dollars"<<endl<<"Please enter the amount and the precision"<<endl;
		cin>>n>>p;
		n*=6.02350;
		cout<<"It equals to "<<setprecision(p)<<n<<" CNY"; 
	}
	else if(a=='R')
	{
		cout<<"Your original currency is RMB"<<endl<<"Please enter the amount and the precision"<<endl;
		cin>>n>>p;
		n/=6.02350;
		cout<<"It equals to "<<setprecision(p)<<n<<" dollars"; 	 	
	}
	else cout<<"Error";
} 
