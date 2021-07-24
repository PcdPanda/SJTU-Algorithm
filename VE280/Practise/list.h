#ifndef LIST_H
#define LIST_H
#include <cstdlib>
class emptylist{
};
template <class T> 
class list{
	public:
		void isempty();
		void insert(T in);
		T* kick();
		list();
		list(const list &L);
		list& operator=(const list &L);
		~list();
	private:
		struct node{
			node* next;
			T* value;
		};
		node *first;
		node *last;
		void removeall();
		void copyall(list<T> L);
};

template <class T>
void list<T>::isempty(){return !first;}
template <class T>
void list<T>::insert(T in){
	node *tmp=new node;
	tmp->value=new T(in);
	tmp->next=first;
	first=tmp; 
}
template <class T>
T* list<T>::kick(){
	T* out;
	node* victim=first;
	first=victim->next;
	out=victim->value;
	delete victim;
	return out;
}
template <class T>
list<T>::list(){first=last=NULL;}
template <class T>
list<T>::list(const list<T> &L){copyall(L);}
template <class T>
list<T>&list<T>::operator=(const list<T>&L){
	if(this!=&L){
		removeall();
		copyall(L);
	}
}
list<T>::~list(){removeall();}
#endif
