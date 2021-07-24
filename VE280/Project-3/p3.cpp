#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
#include "world_type.h"
#include "simulation.h"
int main(int argc,char*argv[]){	
	world_t world;
	int v=0,i=1,rounds=0;
	
	string str1="v",str2="verbose",str3=" ";
	if(argc<4){
		cout<<"Error: Missing arguments!"<<endl;
		cout<<"Usage: ./p3 <species-summary> <world-file> <rounds> [v|verbose]";
		return 0;												//check the number of the arguments
	}
	if(argc>=5)str3=argv[4];
	rounds=atoi(argv[3]);
	if(rounds<0){
		cout<<"Error: Number of simulation rounds is negative!"<<endl;	
		return 0;												//check whether the rounds is negative
	}
	if(!read_file(argv[1],argv[2],world))return 0;
	if(str3==str1||str3==str2)v=1;
	cout<<"Initial state"<<endl;
	printgrid(world.grid);
	for(i=1;i<=rounds;i++)
	{
		cout<<"Round "<<i<<endl;
		day(world,v);
	}
	return 0;
	
} 
