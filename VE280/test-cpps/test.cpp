#include <iostream>
#include <fstream>
#include <string> 
#include <sstream>
#include <cassert>
using namespace std;
int fac(int i)
{
	int j=1,k=1;
	if(i<0)throw i;
	for(j=1;j<=i;j++)
	{
		k*=j;
	}
}
int main(int argc,char* argv[])
{
	assert(2<1);
	return 0;
}


