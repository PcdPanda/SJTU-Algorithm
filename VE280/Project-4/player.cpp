#include "player.h"
#include <iostream>
using namespace std;
class SimplePlayer:public Player{
	public:
		SimplePlayer(){}
		int bet(unsigned int bankroll,unsigned int minimum){
			int wager=minimum;
			cout << "# Player bets " << wager << endl;
			return wager;
		}
		bool draw(Card dealer,const Hand &player){
			if (player.handValue().soft==false){
				if(player.handValue().count<=11)return true;
				else if(player.handValue().count==12){
					if (dealer.spot>=2&&dealer.spot<=4)return false;
					else return true;
				}
				else if(player.handValue().count<=16){
					if (dealer.spot>=0&&dealer.spot<=4)return false;
					else return true;					
				}
				else return false;
			}
			else {
				if(player.handValue().count<=17)return true;
				else if (player.handValue().count==18){
					if (dealer.spot==0||dealer.spot==5||dealer.spot==6)return false;
					else return true;
				}
				else return false;
			}
		}
		void expose(Card c){}
		void shuffled(){}
};

class CountingPlayer : public Player{
	int fav;//variable for counting 
	public:
		CountingPlayer (){fav=0;}
		int bet(unsigned int bankroll,unsigned int minimum){
			int wager;
			if(fav>=2&&bankroll>=2*minimum)wager=2*minimum;
			else wager=minimum;
			cout << "# Player bets " << wager << endl;
			return wager;
		}
		bool draw(Card dealer,const Hand &player){
			if (player.handValue().soft==false){
				if(player.handValue().count<=11)return true;
				else if(player.handValue().count==12){
					if (dealer.spot>=2&&dealer.spot<=4)return false;
					else return true;
				}
				else if(player.handValue().count<=16){
					if (dealer.spot>=0&&dealer.spot<=4)return false;
					else return true;					
				}
				else return false;
			}
			else {
				if(player.handValue().count<=17)return true;
				else if (player.handValue().count==18){
					if (dealer.spot==0||dealer.spot==5||dealer.spot==6)return false;
					else return true;
				}
				else return false;
			}
		}
		void expose(Card c){
			if(c.spot>=0&&c.spot<=4)fav++;
			if(c.spot>=8&&c.spot<=12)fav--;
		}
		void shuffled(){
			fav=0;	
		}
};
extern Player *get_Simple(){
	static SimplePlayer sp;
	return &sp;
}
extern Player *get_Counting()
{
	static CountingPlayer cp;
	return &cp;
}
