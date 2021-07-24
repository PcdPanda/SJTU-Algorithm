#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace::std;
template <class T> bool Dlist<T>::isEmpty()const{
	if(first==NULL||last==NULL)return true;
	else return false;
}
template <class T> void Dlist<T>::insertFront(T *op){
	node *np=new node;
	np->next=first;
	np->prev=NULL;
	np->op=op;
	if(isEmpty())last=np;
	else first->prev=np;
	first=np;
}
template <class T> void Dlist<T>::insertBack(T *op){
	node *np=new node;
	np->prev=last;
	np->next=NULL;
	np->op=op;
	if(isEmpty())first=np;
	else last->next=np;
	last=np; 
}
template<class T> T* Dlist<T>::removeFront(){
	if(isEmpty()){
		emptyList l;
		throw l;
	}	
	node* victim=first;
	T* tmp=victim->op;
	first=first->next;
	if(first!=NULL)first->prev=NULL;
	delete victim;
	return tmp;
}
template<class T> T* Dlist<T>::removeBack(){
	if(isEmpty()){
		emptyList l;
		throw l;
	}	
	node* victim=last;
	T* tmp=victim->op;
	last=victim->prev;
	if(last!=NULL)last->next=NULL;
	delete victim;
	return tmp;
}
template<class T>Dlist<T>::Dlist(){
	first=NULL;
	last=NULL;
}
template<class T>Dlist<T>::Dlist(const Dlist &l){
	first=NULL;
	last=NULL;
	copyAll(l);
}
template<class T>Dlist<T> &Dlist<T>::operator=(const Dlist &l){
	if(this!=&l){
		removeAll();
		copyAll(l);
	}
	return *this;
}
template<class T>void Dlist<T>::removeAll(){while(!isEmpty())delete removeFront();}
template<class T>Dlist<T>::~Dlist(){removeAll();}
template<class T>void Dlist<T>::copyAll(const Dlist &l){
	node* tmp=l.first; 
	while(tmp!=NULL){
		T*temp=new T(*tmp->op);
		insertBack(temp);
		tmp=tmp->next;
	}
}

