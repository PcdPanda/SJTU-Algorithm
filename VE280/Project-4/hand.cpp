#include "hand.h"
Hand::Hand(){
	curValue.count=0;
	curValue.soft=false;
}
void Hand::discardAll(){
	Hand New;
	curValue=New.curValue;
}
void Hand::addCard(Card c){
	if(c.spot==ACE){
		if(curValue.soft==true)curValue.count+=1;
		else {
		curValue.count+=11;
		curValue.soft=true;
		}
	}
	else if(c.spot<=8)curValue.count+=(c.spot+2);
	else curValue.count+=10;
	if(curValue.count>21&&curValue.soft==true)
	{
		curValue.soft=false;
		curValue.count-=10;
	}
}
HandValue Hand::handValue() const{
	 return curValue;
}
