#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
int main(int argc,char*argv[]){	
	srand(time(0));
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N=5,W=10,i=0,j=0,k=0;
	N=atoi(argv[1]),W=atoi(argv[2]);
	cout<<N<<endl;
	for(i=0;i<N;i++){
		k=rand()%5;
		for(j=0;j<k;j++){
			int d=rand()%N;
			if(d<=i)continue;
			cout<<i<<" "<<d<<" "<<rand()%10+1<<endl;
		}
	}
	return 0;
} 
