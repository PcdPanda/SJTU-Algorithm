#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include "dlist.h"
using namespace::std;
void push(Dlist<int> &C,int i){
	int*op=new int(i);
	C.insertBack(op);
}
void print(const Dlist<int>&C,int a){
	Dlist<int> tmp=C;
	int *tmp1;
	while(!tmp.isEmpty()){
		tmp1=tmp.removeBack();
		if(a!=0)cout<<*tmp1<<" ";
		delete tmp1;
		if(a==2)break;	
	}
	cout<<endl;
}
void opreand(Dlist<int>&C,int a){
	int *tmp1,tmp;
	try{tmp1=C.removeBack();}
	catch(emptyList l){
		cout<<"Not enough operands\n";
		return;
	}
	tmp=*tmp1;
	switch (a){
		case 1:{
				tmp*=-1;
			push(C,tmp);
			break;
		}
		case 2:{
			push(C,tmp);
			push(C,tmp);
			break;
		}
	}
	delete tmp1;
}
void opreand2(Dlist<int>&C,int a){
	int *tmp1,*tmp2,tmp;
	try{tmp1=C.removeBack();}
	catch (emptyList l){
		cout<<"Not enough operands\n";
		return;
	}
	try{tmp2=C.removeBack();}
	catch (emptyList l){
		cout<<"Not enough operands\n";
		if(tmp1!=NULL){
			push(C,*tmp1);
			delete tmp1;
		}
		return;
	}
	switch (a){
		case 1:tmp=*tmp1+*tmp2;break;
		case 2:tmp=*tmp2-*tmp1;break;
		case 3:tmp=(*tmp1)*(*tmp2);break;
		case 4:{
			if(*tmp1==0){
				cout<<"Divide by zero\n";
				push(C,*tmp2);
				push(C,*tmp1);
				delete tmp1;
				delete tmp2;
				return;
			}
			else tmp=(*tmp2)/(*tmp1);
			break;
		}
		case 5:{
			push(C,*tmp1);
			push(C,*tmp2);
			delete tmp1;
			delete tmp2;
			return;
			break;
		}
	}
	push(C,tmp);
	delete tmp1;
	delete tmp2;
}
int main(int argc, char*argv[]){
	Dlist<int> C;
	string in;
	int i;
	while(1){
		cin>>in;
		if(atoi(in.c_str())){
			i=atoi(in.c_str());
			push(C,i);
		}
		else{
			if(in=="0")push(C,0);
			else if(in=="q")break; 
			else if(in=="+")opreand2(C,1);
			else if(in=="-")opreand2(C,2);
			else if(in=="*")opreand2(C,3);
			else if(in=="/")opreand2(C,4);
			else if(in=="n")opreand(C,1);
			else if(in=="d")opreand(C,2);
			else if(in=="r")opreand2(C,5);
			else if(in=="c")print(C,0);
			else if(in=="a")print(C,1);
			else if(in=="p")print(C,2);
			else cout<<"Bad input\n"; 
		}
	}
	return 0;
} 
