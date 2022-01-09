#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include "dlist.h"
using namespace::std;
class customer{
	public:
		string name;
		int timestamp,duration,calling;
}; 
void book(Dlist<customer>&C,customer c){
	customer*op=new customer(c);
	C.insertBack(op);
}
int main(int argc,char*argv[]){
	int tick=0,duration=0,i,N;
	string name,state;
	Dlist<customer> R,S,G,P,tmp,tmp1;
	customer c,*temp,*current=NULL;
	cin>>N;
	string status[4]={"platinum","gold","silver","regular"};
	for(i=1;i<=N;i++){
		cin>>c.timestamp>>c.name>>state>>c.duration;
		c.calling=0;
		if(state==status[0])book(P,c);
		if(state==status[1])book(G,c);
		if(state==status[2])book(S,c);
		if(state==status[3])book(R,c);
	}
	while(1){
		cout<<"Starting tick #"<<tick<<endl;
		if(P.isEmpty()&&G.isEmpty()&&S.isEmpty()&&R.isEmpty()&&duration<=0)break;
		for(i=0;i<4;i++){
			tmp1.~Dlist();
			switch (i){
				case 0:tmp=P;break;
				case 1:tmp=G;break;
				case 2:tmp=S;break;
				case 3:tmp=R;break; 
			}	
			while(!tmp.isEmpty()){
				temp=tmp.removeFront();
				if(temp->timestamp==tick&&temp->calling==0){
					cout<<"Call from "<<temp->name<<" a "<<status[i]<<" member\n";
					temp->calling=1;
				}	
				if(duration<=0&&temp->calling==1){
					current=temp;
					duration=temp->duration;
				}
				else tmp1.insertBack(temp);	
			}
			switch (i){
				case 0:P=tmp1;break;
				case 1:G=tmp1;break;
				case 2:S=tmp1;break;
				case 3:R=tmp1;break; 
			}		
		}
		if(duration>0){
			if(duration==current->duration)cout<<"Answering call from "<<current->name<<endl;
			duration--;
			if(duration<=0) delete current;	
		}


		tick++;
	}

		
	return 0;
}
