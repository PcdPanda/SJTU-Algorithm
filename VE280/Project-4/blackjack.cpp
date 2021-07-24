#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
#include "deck.h"
#include "card.h"
#include "hand.h"
#include "player.h"
#include "rand.h"
using namespace std;
void randomshuffle(Deck &d,Player* player)
{
	cout << "# Shuffling the deck\n";
	for(int i=1;i<=7;i++)d.shuffle(get_cut());
	player->shuffled();
}
int main(int argc, char*argv[]){
	int i=0,j=0,cut,thishand=1,bankroll=atoi(argv[1]),min=atoi(argv[2]),hand=atoi(argv[3]),wager;
	string str=argv[4],str1="simple",str2="counting",line,str3;
	fstream iFile;
	istringstream string;
	Hand P,D;
	Card c,c1,c2;
	Player* player;
	if(str==str1)player=get_Simple();
	else player=get_Counting();
	Deck d;
	if(argc>=6){
		iFile.open(argv[5]);
		cout << "# Shuffling the deck\n";
		getline(iFile,line);
		string.str(line);
		while(string>>str3){
			d.shuffle(atoi(str3.c_str()));
			player->shuffled();
		} 
		iFile.close();
	}
	else randomshuffle(d,player);
	for(thishand=0;thishand<hand;thishand++){
		if(bankroll<min)break;
		P.discardAll();
		D.discardAll();
		cout<<"# Hand "<<thishand+1<<" bankroll "<<bankroll<<endl;
		if(d.cardsLeft()<20)randomshuffle(d,player);
		wager=player->bet(bankroll,min);
		c=d.deal();
		cout<<"Player dealt "<<SpotNames[c.spot]<<" of "<<SuitNames[c.suit]<<endl;
		player->expose(c);
		P.addCard(c);
		c1=d.deal();
		cout<<"Dealer dealt "<<SpotNames[c1.spot]<<" of "<<SuitNames[c1.suit]<<endl;
		player->expose(c1);
		D.addCard(c1);
		c=d.deal();
		cout<<"Player dealt "<<SpotNames[c.spot]<<" of "<<SuitNames[c.suit]<<endl;
		player->expose(c);
		P.addCard(c);
		c2=d.deal();						//The hole card 	
		D.addCard(c2);	
		if(P.handValue().count==21){
			cout << "# Player dealt natural 21\n";
			bankroll+=(3*wager)/2;
			continue;
		}
		else if(P.handValue().count<21){
			while(player->draw(c1,P)){
				c=d.deal();	
				cout<<"Player dealt "<<SpotNames[c.spot]<<" of "<<SuitNames[c.suit]<<endl;	
				player->expose(c);
				P.addCard(c);
				
			}
			cout << "Player's total is " << P.handValue().count << endl;
		}
		if(P.handValue().count>21){
			cout << "# Player busts\n";
			bankroll-=wager;
			continue;
		}
		cout<<"Dealer's hole card is "<<SpotNames[c2.spot]<<" of "<<SuitNames[c2.suit]<<endl;
		player->expose(c2);
		while(D.handValue().count<17)	{
			c1=d.deal();
			cout<<"Dealer dealt "<<SpotNames[c1.spot]<<" of "<<SuitNames[c1.suit]<<endl;
			player->expose(c1);
			D.addCard(c1);
		}
		cout << "Dealer's total is " << D.handValue().count << endl;		
		if(D.handValue().count>21){
			cout << "# Dealer busts\n";
			bankroll+=wager;
		}
		else if (P.handValue().count==D.handValue().count)cout<< "# Push\n";
		else if (P.handValue().count>D.handValue().count){
			cout << "# Player wins\n";
			bankroll+=wager;	
		}
		else {
			cout << "# Dealer wins\n";	
			bankroll-=wager;
		}
	}
	cout << "# Player has " << bankroll<< " after " << thishand<< " hands\n";
	return 0;
}
