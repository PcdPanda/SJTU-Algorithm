#include<iostream>
#include<cstdlib>
#include"p2.h"
using namespace std;
int size(list_t list){
	if(list_isEmpty(list)==1)return 0;
	else return 1+size(list_rest(list));
}
int sum(list_t list){
	if(list_isEmpty(list)==1)return 0;
	else return list_first(list)+sum(list_rest(list));
}
int product(list_t list){
	if(list_isEmpty(list)==1)return 1;
	else return list_first(list)*product(list_rest(list));
}
int accumulate(list_t list, int (*fn)(int, int), int base){
	if(list_isEmpty(list)==1)return base;
	else return fn(list_first(list),accumulate(list_rest(list), fn, base));
}
list_t reverse(list_t list){
	list_t a=list_make();
	if(size(list)<=1)return list;
	else {
		int i=list_first(list);
		a=list_make(i,a);
		a=append(reverse(list_rest(list)),a);
		return a;
	}
}
list_t append(list_t first, list_t second){
	if(size(first)==0)return second;
	if(size(second)==0)return first;
	int i=list_first(first);
	if(size(first)==1)return list_make(i,second);
	else {
		list_t a=list_rest(first);
		a=append(a,second);
		return list_make(i,a);
	}
}
list_t filter_odd(list_t list){
	list_t a=list_make();
	if(size(list)==0)return list;	
	int i=list_first(list);
	if(i%2!=0){
		if(size(list)==1)return list;
		a=list_make(i,a);
		a=append(a,filter_odd(list_rest(list)));
	}
	else a=filter_odd(list_rest(list));
	return a;
}
list_t filter_even(list_t list){
	list_t a=list_make();
	if(size(list)==0)return list;	
	int i=list_first(list);
	if(i%2==0){
		if(size(list)==1)return list;
		a=list_make(i,a);
		a=append(a,filter_even(list_rest(list)));
	}
	else a=filter_even(list_rest(list));
	return a;
}
list_t filter(list_t list, bool (*fn)(int)){
	list_t a=list_make();
	if(size(list)==0)return list;	
	int i=list_first(list);
	if(fn(i)==true){
		if(size(list)==1)return list;
		a=list_make(i,a);
		a=append(a,filter(list_rest(list),fn));
	}
	else a=filter(list_rest(list),fn);
	return a;
}
list_t insert_list(list_t first, list_t second, unsigned int n){
	if(n==0)return append(second,first);
	else {
		int i=list_first(first);
		list_t a=list_make();
		a=list_make(i,a);
		list_t b=insert_list(list_rest(first),second,n-1);
		return append(a,b);
	}
}
list_t chop(list_t list, unsigned int n)
{
	if(n==0)return list;
	else {
		list=reverse(list);
		list=reverse(list_rest(list));
		return chop(list,n-1);
	}
}
int tree_sum(tree_t tree)
{
	if(tree_isEmpty(tree)==1)return 0;
	else return(tree_elt(tree)+tree_sum(tree_left(tree))+tree_sum(tree_right(tree)));
}
bool tree_search(tree_t tree, int key){
	if(tree_isEmpty(tree)==1)return false;
	if(tree_elt(tree)==key||tree_search(tree_left(tree),key)==1||tree_search(tree_right(tree),key)==1) return true;
	else return false;
}
int depth(tree_t tree)
{
	if(tree_isEmpty(tree)==1)return 0;
	if(depth(tree_left(tree))>=depth(tree_right(tree)))return 1+depth(tree_left(tree));
	else return 1+depth(tree_right(tree));
}
int tree_min(tree_t tree){
	int m;
	if(tree_isEmpty(tree_left(tree))==1&&tree_isEmpty(tree_right(tree))==1)m=tree_elt(tree);
	else if(tree_isEmpty(tree_left(tree))==1&&tree_isEmpty(tree_right(tree))==0)m=tree_min(tree_right(tree));
	else if(tree_isEmpty(tree_left(tree))==0&&tree_isEmpty(tree_right(tree))==1)m=tree_min(tree_left(tree));
	else if(tree_min(tree_left(tree))<tree_min(tree_right(tree)))m=tree_min(tree_left(tree));
	else m=tree_min(tree_right(tree));
	if(tree_elt(tree)<m)return tree_elt(tree);
	else return m;
}
list_t traversal(tree_t tree){
	list_t list=list_make();
	if(tree_isEmpty(tree)==0){
		list=list_make(tree_elt(tree),traversal(tree_right(tree)));
		list=append(traversal(tree_left(tree)),list);
	}
	return list;
}
bool tree_hasPathSum(tree_t tree, int sum){
	if(tree_isEmpty(tree))return false;
	else if(tree_isEmpty(tree_left(tree))&&tree_isEmpty(tree_right(tree))){
		if(tree_elt(tree)==sum)return true;
		else return false;
	}
	else{
		sum=sum-tree_elt(tree);
		if(tree_hasPathSum(tree_left(tree),sum)||tree_hasPathSum(tree_right(tree),sum))return true;
	}
}
bool covered_by(tree_t A, tree_t B){
	if(tree_isEmpty(A))return true;
	else if(tree_isEmpty(B)||(tree_elt(A)!=tree_elt(B)))return false;
	if(covered_by(tree_left(A),tree_left(B))&&covered_by(tree_right(A),tree_right(B)))return true;	
	return false; 
} 
bool contained_by(tree_t A, tree_t B){
	if(covered_by(A,B))return true;
	else if(tree_isEmpty(B))return false;
	if(covered_by(A,tree_right(B))&&covered_by(A,tree_right(B)))return true;	
 	return false;
}
tree_t insert_tree(int elt, tree_t tree){
	if(elt<tree_elt(tree))
	{
		if(tree_isEmpty(tree_left(tree))){
			if(tree_isEmpty(tree_right(tree)))tree=tree_make(tree_elt(tree),tree_make(elt,tree_make(),tree_make()),tree_make());
			else tree=tree_make(tree_elt(tree),tree_make(elt,tree_make(),tree_make()),tree_right(tree));
		}
		else tree=tree_make(tree_elt(tree),insert_tree(elt,tree_left(tree)),tree_right(tree));
	}
	else if(elt>tree_elt(tree))
	{
		if(tree_isEmpty(tree_right(tree))){
			if(tree_isEmpty(tree_left(tree)))tree=tree_make(tree_elt(tree),tree_make(),tree_make(elt,tree_make(),tree_make()));
			else tree=tree_make(tree_elt(tree),tree_left(tree),tree_make(elt,tree_make(),tree_make()));
		}
		else tree=tree_make(tree_elt(tree),tree_left(tree),insert_tree(elt,tree_right(tree)));
	}
	return tree;
}

