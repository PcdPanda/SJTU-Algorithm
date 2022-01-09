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
	//cout<<endl<<"("<<c[end].x<<", "<<c[end].y<<")";
}
int main(int argc,char*argv[]){	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	priority_queue<cell, compare_t> *PQ;
	int v=0,i=0,j=0,x=0,y=0,step=0,width,height,startX,startY,endX,endY;
	int a=0,b=0;
	double time;
	int imp=3;
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

	if(imp==1)PQ = new binary_heap<cell, compare_t>;
	if(imp==2)PQ = new unsorted_heap<cell, compare_t>;
	if(imp==3)PQ = new fib_heap<cell, compare_t>;

	time=clock();
	for(a=0;a<num;a++)PQ->enqueue(c[a]);
	for(a=0;a<num;a++)PQ->dequeue_min();
	cout<<"time="<<(clock()-time)/CLOCKS_PER_SEC;
	delete[] c;
	delete PQ;
	return 0;
} 
