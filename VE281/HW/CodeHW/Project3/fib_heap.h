#ifndef FIB_HEAP_H
#define FIB_HEAP_H
#include <algorithm>
#include <cmath>
#include "priority_queue.h"
#include <list>
// OVERVIEW: A specialized version of the 'heap' ADT implemented as a 
//           Fibonacci heap.
template<typename TYPE, typename COMP = std::less<TYPE> >
class fib_heap: public priority_queue<TYPE, COMP> {
public:
  typedef unsigned size_type;

  // EFFECTS: Construct an empty heap with an optional comparison functor.
  //          See test_heap.cpp for more details on functor.
  // MODIFIES: this
  // RUNTIME: O(1)
  fib_heap(COMP comp = COMP());

  // EFFECTS: Deconstruct the heap with no memory leak.
  // MODIFIES: this
  // RUNTIME: O(n)
  ~fib_heap();
  
  // EFFECTS: Add a new element to the heap.
  // MODIFIES: this
  // RUNTIME: O(1)
  virtual void enqueue(const TYPE &val);

  // EFFECTS: Remove and return the smallest element from the heap.
  // REQUIRES: The heap is not empty.
  // MODIFIES: this
  // RUNTIME: Amortized O(log(n))
  virtual TYPE dequeue_min();

  // EFFECTS: Return the smallest element of the heap.
  // REQUIRES: The heap is not empty.
  // RUNTIME: O(1)
  virtual const TYPE &get_min() const;

  // EFFECTS: Get the number of elements in the heap.
  // RUNTIME: O(1)
  virtual size_type size() const;

  // EFFECTS: Return true if the heap is empty.
  // RUNTIME: O(1)
  virtual bool empty() const;
  
private:
  // Note: compare is a functor object
  COMP compare;

private:
  // Add any additional member functions or data you require here.
  // You may want to define a strcut/class to represent nodes in the heap and a
  // pointer to the min node in the heap.
	int n=0;
	struct fipnode{
		TYPE val=TYPE();
		int degree=0;
		std::list<fipnode> child;
	};
	typename std::list<fipnode> root;
	typename std::list<fipnode>::iterator min;
};

// Add the definitions of the member functions here. Please refer to
// binary_heap.h for the syntax.
template<typename TYPE, typename COMP>
fib_heap<TYPE, COMP> :: fib_heap(COMP comp) {
    compare = comp;
    // Fill in the remaining lines if you need.
    n=0;
    root.clear();
	min=root.end();
}

template<typename TYPE, typename COMP>
void fib_heap<TYPE, COMP> :: enqueue(const TYPE &val) {
	// Fill in the body.
	fipnode x;
	x.degree=0;
	x.child.clear();
	x.val=val;
	root.push_back(std::move(x));
	if(!n){	
		min=root.end();
		min--;
	}
	else {
		if(compare(x.val,min->val)){
			min=root.end();
			min--;
		}
	}
	n++;
}
template<typename TYPE, typename COMP>
TYPE fib_heap<TYPE, COMP> :: dequeue_min() {
    // Fill in the body.
	int i,j,d=0,num;
	typename std::list<fipnode>::iterator it,x;
	TYPE key=min->val;
	root.splice(min,min->child); 
	root.erase(min);		
	n--;  	
	if(n>0){
		num=log(n)/log(1.618)+1;
		typename std::list<fipnode>::iterator A[num];					
		for(i=0;i<num;i++)A[i]=root.end();
		for(it=root.begin();it!=root.end();it++){
			x=it;
			d=x->degree;
			if(x==A[d])continue;
			while(A[d]!=root.end()){	
				if(compare(A[d]->val,x->val)){
					A[d]->child.push_back(std::move(*x));//linking
					it=root.erase(x);
					A[d]->degree++;//A[d] is the parent	
					x=A[d];				
				}
				else{
					x->child.push_back(std::move(*A[d]));//linking
					root.erase(A[d]);
					x->degree++;//x is the parent
					it=x;
				}
				A[d]=root.end();
				d++;
			}
			A[d]=x;	
		}		
		min=root.end();
		for(i=0;i<num;i++){
			if(A[i]!=root.end()){
				if(min==root.end())min=A[i];
				else if(compare(A[i]->val,min->val))min=A[i];
			}
		}
	}
	else min=root.end();
	return key;

}

template<typename TYPE, typename COMP>
const TYPE &fib_heap<TYPE, COMP> :: get_min() const {
    // Fill in the body.
    return min->val;
}

template<typename TYPE, typename COMP>
bool fib_heap<TYPE, COMP> :: empty() const {
    // Fill in the body.

    return n==0;
}

template<typename TYPE, typename COMP>
unsigned fib_heap<TYPE, COMP> :: size() const { 
    // Fill in the body.
    return n;
}

template<typename TYPE, typename COMP>
fib_heap<TYPE, COMP> ::~fib_heap(){ 
	n=0;
	while(n>0){
		root.splice(min,min->child); 
		min=root.erase(min);
    		n--;
	}
    // Fill in the body.
    
}
#endif //FIB_HEAP_H
