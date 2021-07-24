#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream> 
using namespace std;
int main()
{
	ofstream File;
	File.open("INCALC");
	srand((unsigned)time(NULL));
	int i,j,k,a,b,c;
	k=rand()%100+50;
	for(i=1;i<=k;i++){
		b=rand()%60-30;
		switch (b){
			case 1:File<<"+";break;
			case 2:File<<"-";break;
			case 3:File<<"*";break;
			case 4:File<<"/";break;
			case 5:File<<"n";break;
			case 6:File<<"d";break;
			case 7:File<<"r";break;
			case 8:File<<"p";break;
			case 9:File<<"c";break;
			case 10:File<<"a";break;
			default:File<<b;break;
		}
		a=rand()%5+1;
		for(j=1;j<=a;j++)File<<" ";
	}
	File<<rand()%52<<" ";
	File<<"q";
	File.close();
	File.open("INCALL");
	k=rand()%20+1;
	File<<k<<endl;
	j=rand()%10+1;
	for(i=1;i<=k;i++){
		a=rand()%10;
		j=j+a;
		File<<j<<" A"<<i<<" ";
		b=rand()%4;
		switch (b){
			case 0:File<<"platinum ";break;
			case 1:File<<"gold ";break;
			case 2:File<<"silver ";break;
			case 3:File<<"regular ";break;
		}
		b=rand()%10+1;
		File<<b<<endl;
	}
	File.close();
	return 0;
}
