#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include "min_heap.h"
using namespace std;
class node{
	public:
	int number,in_degree,D;
	node(int n){
		number=n;
		in_degree=0;
		D=-1;
	};
};
struct node_cpr{
	bool operator()(node*a,node*b)const{
		if(b->D<=-1)return false;
		else return a->D>b->D;
	}
};
struct edge{
	node *start_node;
	node *end_node;
	int weight;
};
int main(int argc,char*argv[]){	

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N,MST=0;
	string str;
	cin>>N;
	std::vector<edge*>edges;//edge set
	std::map<int, node*>nodes;//nodes set

	queue<node*> q;
	queue<node*>order;
	while(!cin.eof()){
		getline(cin,str);//read the input
		if(str.empty())continue;
		stringstream input;
		input.clear();
		input.str(str);
		int start,end,weight;
		input>>start>>end>>weight;//read node information
		edge* newedge=new edge;
		auto it=nodes.find(start);
		if(it==nodes.end()){
			node* newnode=new node(start);
			nodes.insert({start,newnode});
			newedge->start_node=newnode;
		}
		else newedge->start_node=it->second;		

		it=nodes.find(end);
		if(it==nodes.end()){
			node* newnode=new node(end);
			nodes.insert({end,newnode});
			newedge->end_node=newnode;
			newnode->in_degree++;
		}
		else {
			newedge->end_node=it->second;	
			it->second->in_degree++;	
		}
		newedge->weight=weight;
		edges.push_back(newedge);				
	}
	//determine DAG through topological sort
	
	for(auto it=nodes.begin();it!=nodes.end();++it)if(it->second->in_degree==0)q.push(it->second);
	while(!q.empty()){
		auto front=q.front();
		q.pop();
		order.push(front);
		for(auto it=edges.begin();it!=edges.end();++it){
			if((*it)->start_node==front&&(*it)->end_node->in_degree!=0){
				(*it)->end_node->in_degree--;
				if((*it)->end_node->in_degree==0)q.push((*it)->end_node);
			}
		}

	}
	if(order.size()==N)cout<<"The graph is a DAG"<<endl;
	else cout<<"The graph is not a DAG"<<endl;
	

	//calculate the MST weight
	auto tmp=nodes.begin();
	auto start_node=tmp->second;
	bool flag=1;
	node* tmpnode;
	tmp=nodes.erase(tmp);
	start_node->D=0;
	min_heap<node*,node_cpr>V;
	while(!nodes.empty()){	
		V.clear();
		for(auto it=nodes.begin();it!=nodes.end();++it){//for every nodes in T'
			
			for(auto it1=edges.begin();it1!=edges.end();++it1){//traverse all edges
				tmpnode=NULL;
				if((*it1)->start_node==it->second)tmpnode=(*it1)->end_node;
				if((*it1)->end_node==it->second)tmpnode=(*it1)->start_node;
				if(tmpnode!=NULL)if(nodes.find(tmpnode->number)==nodes.end()&&((*it1)->weight<it->second->D||it->second->D==-1))it->second->D=(*it1)->weight;//update D
			}
			if(it->second->D!=-1)V.enqueue(it->second);
		}
		if(V.empty()){
			cout<<"No MST exists!"<<endl;
			flag=0;
			break;
		}
		auto small=V.dequeue_min();
		MST=MST+small->D;
		nodes.erase(nodes.find(small->number));
	}
	if(flag)cout<<"The total weight of MST is "<<MST<<endl;
	//release the memory
	for(auto it=edges.begin();it!=edges.end();++it){
		delete (*it)->start_node;
		delete (*it)->end_node;
		delete (*it);
	}
	return 0;
} 
