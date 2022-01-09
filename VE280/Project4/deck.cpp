#include "deck.h"
#include <iostream>
using namespace std;
Deck::Deck()
 {
 	int i,j;
 	next=0;
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			switch(i){
				case 0:deck[i*13+j].suit=SPADES;break;
				case 1:deck[i*13+j].suit=HEARTS;break;
				case 2:deck[i*13+j].suit=CLUBS;break; 						
				case 3:deck[i*13+j].suit=DIAMONDS;break;			
			 }
			switch(j){
				case 0:deck[i*13+j].spot=TWO;break;
				case 1:deck[i*13+j].spot=THREE;break;
				case 2:deck[i*13+j].spot=FOUR;break;
				case 3:deck[i*13+j].spot=FIVE;break;
				case 4:deck[i*13+j].spot=SIX;break;
				case 5:deck[i*13+j].spot=SEVEN;break;
				case 6:deck[i*13+j].spot=EIGHT;break;
				case 7:deck[i*13+j].spot=NINE;break;
				case 8:deck[i*13+j].spot=TEN;break;
				case 9:deck[i*13+j].spot=JACK;break;
				case 10:deck[i*13+j].spot=QUEEN;break;	
				case 11:deck[i*13+j].spot=KING;break;
				case 12:deck[i*13+j].spot=ACE;break;		
			 }
		 }
	 }
 }
 void Deck::reset(){
 	Deck New;
 	next=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			deck[i*13+j]=New.deck[i*13+j];						
		 }
	}
}
void Deck::shuffle(int n){
	cout<<"cut at "<<n<< endl;
	next=0;
	Deck New;
	int i=0;
	if(n<=26){
		for(i=0;i<n;i++){
			New.deck[2*i]=deck[n+i];
			New.deck[2*i+1]=deck[i]; 
		} 
		n=n+i;
		for(i=2*i;i<DeckSize;i++){
			New.deck[i]=deck[n];
			n++;
		} 
	}
	else {
		for(i=0;i<DeckSize-n;i++){
			New.deck[2*i]=deck[n+i];
			New.deck[2*i+1]=deck[i]; 
		}
		n=i;
		for(i=2*i;i<DeckSize;i++){
			New.deck[i]=deck[n];
			n++;
		} 
	}
	for(i=0;i<DeckSize;i++)deck[i]=New.deck[i];						
}
Card Deck::deal(){
	if(next>=DeckSize)throw "DeckEmpty";
	next++;
	return deck[next-1];
}
int Deck::cardsLeft()
{
	return DeckSize-next; 
} 
