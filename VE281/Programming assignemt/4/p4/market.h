#ifndef MARKET_H
#define MARKET_H
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class client{
	public:
		client(string n,int b,int s){
			name=n;
			buyamount=0;
			sellamount=0;
			net=0;
		}
		string name;
		int buyamount;
		int sellamount;
		int net;
};
class order{
	public:
		string name;
		int expiretime;
		int price;
		int quantity;
		int id;
		int duration;

		order(string n,int E,int P,int Q,int D,int ID){
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
		vector<int>tradeprice;
		string name;
		int ttt=0,selltime,sellprice,buyprice,buytime,init=0;
		priority_queue<order*,vector<order*>,order::buyer_order_compare> buyer_orders;
		priority_queue<order*,vector<order*>,order::seller_order_compare> seller_orders;
		stock(string n,int T,int i){
			name=n;
			ttt=T;
			selltime=-1;
			sellprice=-1;
			buytime=-1;
			buyprice=-1;
			init=i;
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
		void addorder(order* newer,string buy_or_sell){
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
		map<string, stock*>stocks;
		map<string, client>clients;
		vector<string>ttt;
	public:
		market(bool v, bool m, bool p, bool t,vector<string>T){
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
		~market(){
				
		};
		void trade(order*buyer_order,order*seller_order,int amount,string equity_symbol,bool v,stock* tmp){
			int price;
			if(buyer_order->id<seller_order->id)price=buyer_order->price;
			else price=seller_order->price;

			buyer_order->quantity-=amount;
			seller_order->quantity-=amount;
			if(v)cout<<buyer_order->name<<" purchased "<<amount<<" shares of "<<equity_symbol<<" from "<<seller_order->name<<" for $"<<price<<"/share"<<endl;
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

		void work(string &inputbook){
			stringstream input;
			
			int timestamp,price,quantity,duration,amount;
			string client_name,buy_or_sell,equity_symbol,Price,Quantity;
			
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
			//matching

			if(timestamp!=current_timestamp)print(timestamp);

			if(stockit!=stocks.end()){//the stock exists, try to match the order first
				stock* tmp=stockit->second;
				order* seller_order;
				order* buyer_order;
				tmp->init=1;


				if(buy_or_sell=="BUY"){//find the seller_order
											
					if(newer->price>tmp->sellprice||tmp->sellprice==-1){
						tmp->sellprice=newer->price;
						tmp->selltime=timestamp;

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
								/*while(1){
									if(tmp->seller_orders.empty())break;
									auto top=tmp->seller_orders.top();
									if(top->expiretime<=current_timestamp&&top->expiretime!=-1){
										tmp->seller_orders.pop();
										delete top;
										continue;
									}
									if(top->name==seller_order->name&&top->price==seller_order->price){
										if(top->quantity+amount<=newer->quantity){
											amount=amount+top->quantity;
											tmp->seller_orders.pop();
											delete top;
											continue;
										}
										else {
											top->quantity=top->quantity-newer->quantity+amount;
											amount=newer->quantity;
											break;
										}
									}
									else break;
								}*/
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
				else {//find the buyer_order

					if(newer->price<tmp->buyprice||tmp->buyprice==-1){
						tmp->buyprice=newer->price;
						tmp->buytime=timestamp;
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
								/*while(1){
									if(tmp->buyer_orders.empty())break;
									auto top=tmp->buyer_orders.top();
									if(top->expiretime<=current_timestamp&&top->expiretime!=-1){
										tmp->buyer_orders.pop();
										delete top;
										continue;
									}
									if(top->name==buyer_order->name&&top->price==buyer_order->price){
										if(top->quantity+amount<=newer->quantity){
											amount=amount+top->quantity;
											tmp->buyer_orders.pop();
											delete top;
											continue;
										}
										else {
											top->quantity=top->quantity-newer->quantity+amount;
											amount=newer->quantity;
											break;
										}
									}
									else break;
								}*/
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
				if(find(ttt.begin(),ttt.end(),equity_symbol)!=ttt.end())newstock=new stock(equity_symbol,1,1);
				else newstock=new stock(equity_symbol,0,1);
				stocks.insert({equity_symbol,newstock});
				if(buy_or_sell=="BUY"){				
					newstock->sellprice=newer->price;
					newstock->selltime=timestamp;
				}	
				else {
					newstock->buyprice=newer->price;
					newstock->buytime=timestamp;
				}	
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
					sort(it->second->tradeprice.begin(),it->second->tradeprice.end());
					if(n%2==1)medianprice=it->second->tradeprice[n/2];
					else medianprice=(it->second->tradeprice[n/2]+it->second->tradeprice[n/2-1])/2;
				}
				cout<<"Median match price of "<<it->second->name<<" at time "<<current_timestamp<<" is $"<<medianprice<<endl;
			}
			if(midpoint)for(auto it=stocks.begin();it!=stocks.end();++it){
				if(it->second->init==0)continue;
				int highest,lowest;
				cout<<"Midpoint of "<<it->second->name<<" at time "<<current_timestamp<<" is ";
				if(it->second->buyer_orders.empty())highest=-1;
				else highest=it->second->buyer_orders.top()->price;

				if(it->second->seller_orders.empty())lowest=-1;
				else lowest=it->second->seller_orders.top()->price;
				if(highest==-1||lowest==-1)cout<<"undefined"<<endl;
				else cout<<"$"<<(highest+lowest)/2<<endl;

			}

			current_timestamp=timestamp;
			for(auto it=stocks.begin();it!=stocks.end();++it){//delete expired order
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
			}
		}
		void summary(){
			for(auto it=stocks.begin();it!=stocks.end();++it){//delete expired order
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
			}
			print(current_timestamp);
			cout<<"---End of Day---"<<endl;
			cout<<"Commission Earnings: $"<<earning<<endl;
			cout<<"Total Amount of Money Transferred: $"<<transfer<<endl;
			cout<<"Number of Completed Trades: "<<transfernumber<<endl;
			cout<<"Number of Shares Traded: "<<shareamount<<endl;
			for(auto it=clients.begin();it!=clients.end();++it){
				if(transfers)cout<<it->second.name<<" bought "<<it->second.buyamount<<" and sold "<<it->second.sellamount<<" for a net transfer of $"<<it->second.net<<endl;

			}
			for(auto it=stocks.begin();it!=stocks.end();++it){
				if(it->second->ttt==1)cout<<"Time travelers would buy "<<it->second->name<<" at time: "<<it->second->buytime<<" and sell it at time: "<<it->second->selltime<<endl;
				delete it->second;
			}

		};	
};
#endif
