#ifndef MARKET_H
#define MARKET_H
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
class client{
	public:
		client(std::string n,int b,int s){
			name=n;
			buyamount=0;
			sellamount=0;
			net=0;
		}
		std::string name;
		int buyamount;
		int sellamount;
		int net;
};
class order{
	public:
		std::string name;
		int expiretime;
		int price;
		int quantity;
		int id;
		int duration;
		order(std::string n,int E,int P,int Q,int D,int ID){
			name=n;
			expiretime=E;
			price=P;
			quantity=Q;
			duration=D;
			id=ID;
			if(D==-1)expiretime=-1;
		};
		struct buyer_order_compare{
			bool operator()(order* a,order* b)const{
				if(a->price<b->price)return true;
				else if(a->price==b->price)return a->id>b->id;
				else return false;
			}
		};
		struct seller_order_compare{
			bool operator()(order* a,order* b)const{
				if(a->price>b->price)return true;
				else if(a->price==b->price)return a->id>b->id;
				else return false;
			}
		};
};
class stock{
	public:
		std::vector<int>tradeprice;
		std::string name;
		std::priority_queue<order*,std::vector<order*>,order::buyer_order_compare> buyer_orders;
		std::priority_queue<order*,std::vector<order*>,order::seller_order_compare> seller_orders;
		bool ttt=0,init=0;
		int selltime,sellprice,buyprice,buytime,profit,bestbuytime,bestselltime;
		stock(std::string n,bool T,bool i){
			name=n;
			ttt=T;
			selltime=-1;
			sellprice=-1;
			buytime=-1;
			bestbuytime=-1;
			bestselltime=-1;
			buyprice=-1;
			init=i;
			profit=0;
		}
		~stock(){
			while(!buyer_orders.empty()){
				auto victim=buyer_orders.top();
				delete victim;
				buyer_orders.pop();
			}
			while(!seller_orders.empty()){
				auto victim=seller_orders.top();
				delete victim;
				seller_orders.pop();
			}
		}
		void addorder(order* newer,std::string buy_or_sell){
			if(buy_or_sell=="BUY")buyer_orders.push(newer);
			else seller_orders.push(newer);
		};
}; 
class market{
	private:
		bool verbose=0;
		bool median=0;
		bool midpoint=0;
		bool transfers=0;
		int current_timestamp=0;
		int ID=0;
		int earning=0;
		int transfer=0;
		int shareamount=0;
		int transfernumber=0;
		std::map<std::string, stock*>stocks;
		std::map<std::string, client>clients;
		std::deque<std::string>ttt;
	public:
		market(bool v, bool m, bool p, bool t,std::deque<std::string>T){
			verbose=v;
			median=m;
			midpoint=p;
			transfers=t;
			ID=0;
			earning=0;
			transfer=0;
			shareamount=0;
			transfernumber=0;
			ttt=T;
			for(auto it=ttt.begin();it!=ttt.end();++it){
				auto newstock=new stock(*it,1,0);
				stocks.insert({*it,newstock});
			}
		};
		~market(){};
		void trade(order*buyer_order,order*seller_order,int amount,std::string equity_symbol,bool v,stock* tmp){
			int price;
			if(buyer_order->id<seller_order->id)price=buyer_order->price;
			else price=seller_order->price;
			buyer_order->quantity-=amount;
			seller_order->quantity-=amount;
			if(v)std::cout<<buyer_order->name<<" purchased "<<amount<<" shares of "<<equity_symbol<<" from "<<seller_order->name<<" for $"<<price<<"/share"<<std::endl;
			shareamount+=amount;
			transfer+=amount*price;
			earning+=(amount*price)/100+(amount*price)/100;
			transfernumber++;
			auto clientit=clients.find(buyer_order->name);
			clientit->second.buyamount+=amount;
			clientit->second.net-=amount*price;
			clientit=clients.find(seller_order->name);
			clientit->second.sellamount+=amount;
			clientit->second.net+=amount*price;
			tmp->tradeprice.push_back(price);//determine the median

		};
		void work(std::string &inputbook){
			std::stringstream input;	
			int timestamp,price,quantity,duration,amount;
			std::string client_name,buy_or_sell,equity_symbol,Price,Quantity;
			input.clear();
			input.str(inputbook);
			input>>timestamp>>client_name>>buy_or_sell>>equity_symbol>>Price>>Quantity>>duration;
			price=strtol(Price.c_str()+1,NULL,10);
			quantity=strtol(Quantity.c_str()+1,NULL,10);
			auto newer=new order(client_name,timestamp+duration,price,quantity,duration,ID);//define the new order
			auto stockit=stocks.find(equity_symbol);
			client newclient(client_name,0,0);
			auto clientit=clients.find(client_name);
			if(clientit==clients.end())clients.insert({client_name, newclient});//add clients
			if(timestamp!=current_timestamp)print(timestamp);
			if(stockit!=stocks.end()){//the stock exists, try to match the order first
				stock* tmp=stockit->second;
				order* seller_order;
				order* buyer_order;
				tmp->init=1;
				if(buy_or_sell=="BUY"){//find the seller_order			
					if(tmp->ttt&&tmp->buytime!=-1){//TTT
						if(tmp->selltime==-1){//the first chance to sell
							tmp->selltime=timestamp;
							tmp->sellprice=newer->price;
							tmp->profit=tmp->sellprice-tmp->buyprice;
							tmp->bestbuytime=tmp->buytime;
							tmp->bestselltime=tmp->selltime;
						}
						else {
							int tmp_profit=newer->price-tmp->buyprice;
							if(tmp_profit>tmp->profit){//more profit
								tmp->selltime=timestamp;
								tmp->sellprice=newer->price;
								tmp->profit=tmp_profit;
								tmp->bestbuytime=tmp->buytime;
								tmp->bestselltime=tmp->selltime;
							}
						}
					}
					while(!tmp->seller_orders.empty()){
						seller_order=tmp->seller_orders.top();
						if(seller_order->expiretime<=current_timestamp&&seller_order->expiretime!=-1){
							tmp->seller_orders.pop();
							delete seller_order;
							continue;
						}
						if(seller_order->price>newer->price)break;//the trade won't happen
						else {

							if(seller_order->quantity<newer->quantity){//buyer_order wants more
								amount=seller_order->quantity;
								tmp->seller_orders.pop();
								trade(newer,seller_order,amount,tmp->name,verbose,tmp);
								delete seller_order;
							}
							else {//buyer_order wants less
								amount=newer->quantity;
								trade(newer,seller_order,amount,tmp->name,verbose,tmp);
								if(seller_order->quantity==newer->quantity){
									tmp->seller_orders.pop();
									delete seller_order;							
								}
							}
						}
						if(newer->quantity==0)break;	
					}
					if(newer->quantity!=0&&newer->duration!=0)tmp->addorder(newer,buy_or_sell); //read the order
					else delete newer;
				}
				else {//find the buyer_order because this is a sell order
					if(tmp->ttt){//TTT
						if(tmp->buytime==-1){
							tmp->buytime=timestamp;
							tmp->buyprice=newer->price;
						}
						else if(newer->price<tmp->buyprice){
							tmp->buytime=timestamp;
							tmp->buyprice=newer->price;
						}
					}
					while(!tmp->buyer_orders.empty()){
						buyer_order=tmp->buyer_orders.top();
						if(buyer_order->expiretime<=current_timestamp&&buyer_order->expiretime!=-1){
							tmp->buyer_orders.pop();
							delete buyer_order;
							continue;
						}
						if(buyer_order->price<newer->price)break;
						else {
							if(buyer_order->quantity<newer->quantity){//buyer_order wants less
								amount=buyer_order->quantity;
								tmp->buyer_orders.pop();
								trade(buyer_order,newer,amount,tmp->name,verbose,tmp);
								delete buyer_order;
							}
							else {//buyer_order wants more
								amount=newer->quantity;
								trade(buyer_order,newer,amount,tmp->name,verbose,tmp);
								if(buyer_order->quantity==newer->quantity){
									tmp->buyer_orders.pop();
									delete buyer_order;
								}
							}
						}
						if(newer->quantity==0)break;	
					}
					if(newer->quantity!=0&&newer->duration!=0)tmp->addorder(newer,buy_or_sell); //read the order
					else delete newer;
				}	
			}
			else {//it can't be matched so it need to be inserted into the book 
				stock* newstock;
				if(find(ttt.begin(),ttt.end(),equity_symbol)!=ttt.end()){
					newstock=new stock(equity_symbol,1,1);//TTT
					if(buy_or_sell=="SELL"){
						newstock->buytime=timestamp;
						newstock->buyprice=newer->price;
					}
				}
				else newstock=new stock(equity_symbol,0,1);
				stocks.insert({equity_symbol,newstock});
				if(newer->duration!=0)newstock->addorder(newer,buy_or_sell);//read the order
				else delete newer;	
			}	
			ID++;
		};
		void print(int timestamp){
			int medianprice;
			if(median)for(auto it=stocks.begin();it!=stocks.end();++it){
				int n=it->second->tradeprice.size();
				if(n==0||it->second->init==0)continue;
				else {
					std::sort(it->second->tradeprice.begin(),it->second->tradeprice.end());
					if(n%2==1)medianprice=it->second->tradeprice[n/2];
					else medianprice=(it->second->tradeprice[n/2]+it->second->tradeprice[n/2-1])/2;
				}
				std::cout<<"Median match price of "<<it->second->name<<" at time "<<current_timestamp<<" is $"<<medianprice<<std::endl;
			}
			if(midpoint)for(auto it=stocks.begin();it!=stocks.end();++it){
				if(it->second->init==0)continue;
				int highest,lowest;
				std::cout<<"Midpoint of "<<it->second->name<<" at time "<<current_timestamp<<" is ";
				highest=-1;
				while(!it->second->buyer_orders.empty()){
					auto victim=it->second->buyer_orders.top();
					if(victim->expiretime<=current_timestamp&&victim->expiretime!=-1){
						it->second->buyer_orders.pop();
						delete victim;
					}
					else{
						highest=victim->price;
						break;
					}
				}
				lowest=-1;
				while(!it->second->seller_orders.empty()){
					auto victim=it->second->seller_orders.top();
					if(victim->expiretime<=current_timestamp&&victim->expiretime!=-1){
						it->second->seller_orders.pop();
						delete victim;
					}
					else{
						lowest=victim->price;
						break;
					}
				}
				if(highest==-1||lowest==-1)std::cout<<"undefined"<<std::endl;
				else std::cout<<"$"<<(highest+lowest)/2<<std::endl;

			}
			current_timestamp=timestamp;
			/*for(auto it=stocks.begin();it!=stocks.end();++it){//delete expired order
				while(!it->second->buyer_orders.empty()){
					auto buyer_order=it->second->buyer_orders.top();
					if(buyer_order->expiretime<=current_timestamp&&buyer_order->expiretime!=-1){
						it->second->buyer_orders.pop();
						delete buyer_order;
					}
					else break;
				}
				while(!it->second->seller_orders.empty()){
					auto seller_order=it->second->seller_orders.top();
					if(seller_order->expiretime<=current_timestamp&&seller_order->expiretime!=-1){
						it->second->seller_orders.pop();
						delete seller_order;
					}
					else break;
				}
			}*/
		}
		void summary(){
			print(current_timestamp);
			std::cout<<"---End of Day---"<<std::endl;
			std::cout<<"Commission Earnings: $"<<earning<<std::endl;
			std::cout<<"Total Amount of Money Transferred: $"<<transfer<<std::endl;
			std::cout<<"Number of Completed Trades: "<<transfernumber<<std::endl;
			std::cout<<"Number of Shares Traded: "<<shareamount<<std::endl;
			if(transfers)for(auto it=clients.begin();it!=clients.end();++it){
				std::cout<<it->second.name<<" bought "<<it->second.buyamount<<" and sold "<<it->second.sellamount<<" for a net transfer of $"<<it->second.net<<std::endl;
			}
			for(auto it=ttt.begin();it!=ttt.end();++it){
				auto equity_symbol=*it;
				auto stockit=stocks.find(equity_symbol);
				if(stockit!=stocks.end()){
					std::cout<<"Time travelers would buy "<<equity_symbol<<" at time: "<<stockit->second->bestbuytime;
					std::cout<<" and sell it at time: "<<stockit->second->bestselltime<<std::endl;
				}
			}
			for(auto it=stocks.begin();it!=stocks.end();++it)delete it->second;
		};	
};
#endif
