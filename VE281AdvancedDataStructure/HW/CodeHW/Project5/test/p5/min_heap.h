#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <algorithm>

// OVERVIEW: A specialized version of the 'heap' ADT implemented as a binary
//           heap.
template<typename TYPE, typename COMP = std::less<TYPE> >
class min_heap{
public:
	typedef int size_type;

	min_heap(COMP comp = COMP());
	virtual void clear();
	virtual void percolate_up(int id);

	virtual void percolate_down(int id);

	virtual void enqueue(const TYPE &val);



	virtual TYPE dequeue_min();


	virtual const TYPE &get_min() const;


	virtual size_type size() const;


	virtual bool empty() const;

private:
  // Note: This vector *must* be used in your heap implementation.
  std::vector<TYPE> data;
  // Note: compare is a functor object
  COMP compare;

private:
  // Add any additional member functions or data you require here.
};

template<typename TYPE, typename COMP>
min_heap<TYPE, COMP> :: min_heap(COMP comp) {
	compare = comp;
	data.push_back(TYPE());
}

template<typename TYPE, typename COMP>
void min_heap<TYPE, COMP> :: clear() {
	data.clear();
}


template<typename TYPE, typename COMP>
int min_heap<TYPE, COMP> :: size() const { 
    return data.size()-1;
}

template<typename TYPE, typename COMP>
bool min_heap<TYPE, COMP> :: empty() const {

    return size()<=0;
}

template<typename TYPE, typename COMP>
void min_heap<TYPE, COMP> :: percolate_up(int id) {
	while(id>1&&compare(data[id/2],data[id])){
		std::swap(data[id/2],data[id]);
		id=id/2;
	}
}

template<typename TYPE, typename COMP>
void min_heap<TYPE, COMP> :: percolate_down(int id) {
	for(auto j=2*id;j<=size();j=2*id){
		if(j<size()&&compare(data[j],data[j+1]))j++;
		if(!compare(data[id],data[j]))break;
		std::swap(data[id],data[j]);
		id=j;
	}
}



template<typename TYPE, typename COMP>
void min_heap<TYPE, COMP> :: enqueue(const TYPE &val) {
	if(data.empty())data.push_back(val);
	data.push_back(val);
	percolate_up(size());
}

template<typename TYPE, typename COMP>
TYPE min_heap<TYPE, COMP> :: dequeue_min() {
	if(this->empty())return data[0];

	std::swap(data[1],data[size()]);
	auto item=data[size()];
	data.pop_back();
	percolate_down(1);
	
	return item;	
}

template<typename TYPE, typename COMP>
const TYPE &min_heap<TYPE, COMP> :: get_min() const {
    // Fill in the body.
    if(this->empty())return data[0];
    else return data[1];
}





#endif //min_heap_H
