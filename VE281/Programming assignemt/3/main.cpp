#include <iostream>
#include <fstream>
#include <string>
#include "binary_heap.h"
#include "unsorted_heap.h"
#include "fib_heap.h"
using namespace std;
struct cell{
	int weight;
	int visited;
	int pathcost;
	int x;
	int y;
	int pi=-1;
};
struct compare_t
{
    bool operator()(cell a, cell b) const
    {
	if(a.pathcost<b.pathcost)return true;
	else if(a.pathcost==b.pathcost){
		if(a.x<b.x)return true;
		else if(a.x==b.x&&a.y<b.y)return true;
		else return false;
	}
	else return false;
    }
};
void trace(int start,int end,cell*&c){
	if(end!=start)trace(start,c[end].pi,c);
	cout<<endl<<"("<<c[end].x<<", "<<c[end].y<<")";
}
int main(int argc,char*argv[]){	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	priority_queue<cell, compare_t> *PQ;
	int v=0,i=0,j=0,x=0,y=0,step=0,width,height,startX,startY,endX,endY;
	string V="-v",VERBOSE="--verbose",I="-i", IMPLEMENTATION="--implementation",imp;
	for(i=0;i<argc;i++){
		if(argv[i]==V||argv[i]==VERBOSE)v=1;
		if(argv[i]==I||argv[i]==IMPLEMENTATION)imp=argv[i+1];
	}
	cin>>width>>height>>startX>>startY>>endX>>endY;
	int num=width*height;
	cell *c=new cell[num];
	for(i=0;i<num;i++){	
		cin>>c[i].weight;
		c[i].visited=0;
		c[i].pathcost=0;
		c[i].x=i%width;
		c[i].y=i/width;
	}
	c[startX+width*startY].visited=1;
	c[startX+width*startY].pathcost=c[startX+width*startY].weight;

	if(imp=="BINARY")PQ = new binary_heap<cell, compare_t>;
	if(imp=="UNSORTED")PQ = new unsorted_heap<cell, compare_t>;
	if(imp=="FIBONACCI")PQ = new fib_heap<cell, compare_t>;


	PQ->enqueue(c[startX+width*startY]);
	while(!PQ->empty()){
		cell tmp=PQ->dequeue_min();
		if(v){
			cout<<"Step "<<step<<endl;
			step++;
			cout<<"Choose cell ("<<tmp.x<<", "<<tmp.y<<") with accumulated length "<<tmp.pathcost<<"."<<endl;
		}
		int tmpi=tmp.x+width*tmp.y;
		for(i=1;i<=4;i++){
			switch (i){
				case 1:j=tmpi+1;break;
				case 2:j=tmpi+width;break;
				case 3:j=tmpi-1;break;
				case 4:j=tmpi-width;break;
			}
			if(tmp.x<=0&&i==3)continue;
			if(tmp.x>=width-1&&i==1)continue;
			if(tmp.y<=0&&i==4)continue;
			if(tmp.y>=height-1&&i==2)continue;
			if(j<0||j>=num||c[j].visited)continue;
			c[j].pathcost=c[j].weight+tmp.pathcost;
			c[j].visited=1;	
			c[j].pi=tmpi;
			if(j==endX+width*endY){
				if(v)cout<<"Cell ("<<c[j].x<<", "<<c[j].y<<") with accumulated length "<<c[j].pathcost<<" is the ending point."<<endl;
				cout<<"The shortest path from ("<<startX<<", "<<startY<<") to ("<<endX<<", "<<endY<<") is "<<c[j].pathcost<<"."<<endl<<"Path:";
				trace(startX+width*startY,j,c);
				delete[] c;
				delete PQ; 
				cout<<endl;
				return 0;
			}
			else {
				PQ->enqueue(c[j]);
				if(v)cout<<"Cell ("<<c[j].x<<", "<<c[j].y<<") with accumulated length "<<c[j].pathcost<<" is added into the queue."<<endl;
			}	
		}
		
	}

	delete[] c;
	delete PQ;
	return 0;
} 
