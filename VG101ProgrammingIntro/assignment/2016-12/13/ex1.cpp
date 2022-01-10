#include <iostream>
#include <ctime> 
#include <cstdlib>
#include "ex1car.h"
#include "assignment.h"  
using namespace std;
int ex1()
{
	int a,b,i,j,n=10;//n is the number of cars
	cout<<"Please enter a period of time in 24 hours"<<endl;
	cin>>a>>b;//give the period of time
	srand(time(NULL));
	car c[n];//generate 10 cars
	for(i=0;i<=n-1;i++)c[i].Init(a,b);
	park p;
	for(i=0;i<=(b-a)*60;i++)
	{
		for(j=0;j<=n-1;j++)
		{	
			if(i==c[j].at)
			{
				cout<<"Arrival ticket *******car number: "<<j+1<<" ******\n";
				c[j].Aticket();//generate 10 car tickets
				c[j].Park(&p);
				cout<<"**************************\n";
			}
			if(i==c[j].lt)
			{
				cout<<"Departure ticket *******car number: "<<j+1<<" ******\n";
				c[j].Lticket(&p);
				cout<<"**************************\n\n";
			}
		}
	}	 
} 

