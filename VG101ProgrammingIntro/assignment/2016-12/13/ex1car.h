using namespace std;
class park
{
	public:
		park()
		{
			for(int i=0;i<=3;i++)for(int j=0;j<=9;j++)pos[i][j]=0; 
		} 
		int pos[4][10];
};
class car
{
	public:
		car()
		{
			t=rand()%4;
		}
		void Init(int a,int b)
		{
			at=rand()%((b-a)*60);//generate the time of arrival
			l=rand()%((b-a)*60-at);//The leave time should be in the period
			lt=at+l;
			m=at%60;//calculate the minute
			h=a+at/60;//calculate the hour
		}
		void Aticket()
		{ 
			cout<<"Time of arrival: "<<h<<":";
			if(m<10)cout<<"0"<<m<<endl;
			else cout<<m<<endl;
			cout<<"Type of vehicle: ";
			switch (t)
			{
				case 0:cout<<"van"<<endl;break;
				case 1:cout<<"car"<<endl;break;
				case 2:cout<<"motorbike"<<endl;break;
				case 3:cout<<"bicycle"<<endl;break;
			}
		}
		void Park(park* p)
		{
			for(f=0;f<=3;f++)for(s=0;s<=2*(f+1);s++)
			{
				if(p->pos[f][s]==0)
				{
					p->pos[f][s]=1;
					cout<<"Slot: floor: "<<(f+1)<<" position: "<<(s+1)<<"\n\n";
					return;
				}			
			}	
		}
		void Lticket(park *p)
		{
			p->pos[f][s]=0;
			cout<<"Time spent in the parking lot : "<<l<<" minutes\n";
			cout<<"Type of vehicle: ";
			switch (t)
			{
				case 0:cout<<"van"<<endl<<"price: "<<0.075*l<<"RMB\n";break;
				case 1:cout<<"car"<<endl<<"price: "<<0.05*l<<"RMB\n";break;
				case 2:cout<<"motorbike"<<endl<<"price: "<<0.025*l<<"RMB\n";break;
				case 3:cout<<"bicycle"<<endl<<"price: "<<0.015*l<<"RMB\n";break;
			}	
		}	
		int at,lt;//whether the car has in it,at=time of arrival,lt=time of leave	 
	private:
		int t,l,f,s,m,h;//t=type,l=time of stay,f=floor,s=slot
};
