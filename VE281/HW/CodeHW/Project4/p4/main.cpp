#include <iostream>
#include <string>
#include "market.h"
using namespace std;
int main(int argc,char*argv[]){	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	bool verbose=0, median=0, midpoint=0, transfers=0;
	int i=0,j=0;
	string V="-v",VERBOSE="--verbose",M="-m",MEDIAN="--median",P="-p";
	string MIDPOINT="--midpoint",T="-t",TRANSFERS="--transfers",G="-g",TTT="--ttt";
	vector<string>ttt;
	string order; //Option Inputs
	j=0;
	for(i=0;i<argc;i++){
		if(argv[i]==V||argv[i]==VERBOSE)verbose=1;
		if(argv[i]==M||argv[i]==MEDIAN)median=1;
		if(argv[i]==P||argv[i]==MIDPOINT)midpoint=1;
		if(argv[i]==T||argv[i]==TRANSFERS)transfers=1;
		if(argv[i]==G||argv[i]==TTT){
			ttt.push_back(argv[i+1]);
			j++;
		}	
	}
	
	market Market(verbose,median,midpoint,transfers,ttt);//initialize the market
	while(!cin.eof()){
		getline(cin,order);//read the input
		if(order.empty())continue;
		Market.work(order);//input the order
	}
	Market.summary();
	return 0;
} 
