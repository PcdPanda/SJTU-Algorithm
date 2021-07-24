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
	bool updated=0;
	node(int n){
		number=n;
		in_degree=0;
		D=0;
		updated=0;
	};
	map<node*,int>neighbour;
};
struct node_cpr{
	bool operator()(node*a,node*b)const{
		if(b->updated==0)return false;
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
	int N,n,MST=0;
	string str;
	cin>>N;
	std::vector<edge*>edges;//edge set
	std::vector<node*>T;
	std::map<int, node*>nodes;//nodes set

	queue<node*> q;
	queue<node*>order;
	while(!cin.eof()){
		getline(cin,str);//read the input
		if(str.empty())continue;
		stringstream input;
		input.clear();
		input.str(str);
		int start,end,weight,old_weight;
		input>>start>>end>>weight;//read node information
		edge* newedge=new edge;
		auto it=nodes.find(start);//it refers to the first node in edge
		if(it==nodes.end()){//the nodes hasn't been insert
			node* newnode=new node(start);
			nodes.insert({start,newnode});
			newedge->start_node=newnode;
		}
		else newedge->start_node=it->second;	

		it=nodes.find(end);
		if(it==nodes.end()){//the nodes hasn't been insert
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
		
		if(newedge->start_node->neighbour.find(newedge->end_node)!=newedge->start_node->neighbour.end()){//the neighbour already exists
			old_weight=newedge->start_node->neighbour.find(newedge->end_node)->second;
			if(old_weight>weight){
				newedge->start_node->neighbour.find(newedge->end_node)->second=weight;
				newedge->end_node->neighbour.find(newedge->start_node)->second=weight;
			}
		}
		else {
			newedge->start_node->neighbour.insert({newedge->end_node,weight});//keep the neighbour and weight 
			newedge->end_node->neighbour.insert({newedge->start_node,weight});//
		}
		edges.push_back(newedge);				
	}
	//determine DAG through topological sort
	n=nodes.size();//the input nodes number

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
	if(order.size()==n)cout<<"The graph is a DAG"<<endl;
	else cout<<"The graph is not a DAG"<<endl;
	

	//calculate the MST weight
	bool flag=1;
	node* small;
	T.push_back(nodes.begin()->second);
	nodes.erase(nodes.begin());//erase the first node from T'
	min_heap<node*,node_cpr>V;//a min heap used to sort the node with smallest D in T'
	V.clear();
	


	while(!nodes.empty()){	//there is still nodes in T'
		small=NULL;
		for(auto it=nodes.begin();it!=nodes.end();++it){//for every nodes in T'
			for(auto it1=it->second->neighbour.begin();it1!=it->second->neighbour.end();++it1){//traverse all neighbour
				if(nodes.find(it1->first->number)==nodes.end()){//the neighbour is not in T' already 
					if(it1->second<it->second->D||it->second->updated==0){
						it->second->D=it1->second;//update D
						it->second->updated=1;
						V.enqueue(it->second);//put the updated value in min heap
					}
					it->second->neighbour.erase(it1);
				}
			}
		}
		while(!V.empty()){
			small=V.dequeue_min();// find the node with smallest D(v)
			if(nodes.find(small->number)!=nodes.end())break;//the node is still in T', so we can use it
			else small=NULL;		
		}
		if(V.empty()&&small==NULL){
			flag=0;
			break;
		}
		MST=MST+small->D;//calculate the MST
		nodes.erase(nodes.find(small->number));//put the node out of T' and put it in T
		T.push_back(small);

	}
	if(flag&&n>=N)cout<<"The total weight of MST is "<<MST<<endl;
	else cout<<"No MST exists!"<<endl;

	//release the memory
	for(auto it=T.begin();it!=T.end();++it)delete (*it);
	for(auto it=nodes.begin();it!=nodes.end();++it)delete it->second;
	for(auto it=edges.begin();it!=edges.end();++it)delete (*it);
	return 0;
} 
