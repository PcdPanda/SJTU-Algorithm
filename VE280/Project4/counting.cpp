#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream> 
using namespace std;
int main()
{
	ofstream File;
	File.open("IN");
	srand((unsigned)time(NULL));
	int k=rand()%20+1;
	for(int i=1;i<=k;i++)
	File<<rand()%52<<" ";
	k=rand()%5;
	for(int i=1;i<=k;i++)File<<" ";
	File.close();
	return 0;
}
