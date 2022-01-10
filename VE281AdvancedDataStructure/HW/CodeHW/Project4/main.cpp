#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>
#include "market.h"
#include "getopt.h"
using namespace std;
int main(int argc,char*argv[]){	

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	bool verbose=0, median=0, midpoint=0, transfers=0;
	int i=0;
	deque<string>ttt;
	string order; //Option Inputs
	struct option long_options[]={
            {"verbose",0,NULL,'v'},
            {"median",0,NULL,'m'},
            {"midpoint",0,NULL,'p'},
            {"transfers",0,NULL,'t'},
            {"ttt",1,NULL,'g'},
            {NULL,0,NULL,0}
	};
	while((i=getopt_long(argc,argv,"vmptg:",long_options,NULL))!=-1){
		switch (i)
		{
		    case 'v':
		        verbose=true;
		        break;
		    case 'm':
		        median=true;
		        break;
		    case 'p':
		        midpoint=true;
		        break;
		    case 't':
		        transfers=true;
		        break;
		    case 'g':
			ttt.push_back(optarg);
		        break;
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
