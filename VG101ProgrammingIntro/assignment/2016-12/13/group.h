#include "figures.h"
class Group:public Figure
{// A Group of figure "has" other figures.
	public:
		virtual void draw()=0; // Draw out all its figures
		virtual void move(Vec v)=0; // Move all its figures
		virtual void rotate(float angle=PI/8)=0; // Rotate the group as a whole.
		virtual void zoom(float scale=1)=0; // Zoom the group as a whole.
		~Group() {}
};
class Park:public Group
{
	public:
		Park(Vec v={0,0.1})
		{
			int i;anchor=v;Vec p[10];
			p[0]={-0.6,0.1};p[1]=v+p[0];p[2]=v-p[0];
			s[1]=new Orthogon(p[1],p[2],0.4,0.4,0.4);
			p[0]={-0.65,-0.8};p[1]=v+p[0];
			p[0]={0.95,-0.8};p[2]=v+p[0];
			s[2]=new Line(p[1],p[2],0,0,0);
			p[0]={0,1.6};p[1]=p[2]+p[0];
			s[3]=new Line(p[2],p[1],0,0,0);
			p[0]={-1.9,0};p[2]=p[1]+p[0];
			s[4]=new Line(p[1],p[2],0,0,0);	
			p[0]={0,-1.65};p[1]=p[2]+p[0];
			s[5]=new Line(p[2],p[1],0,0,0);	
			p[0]={0.3,0};p[2]=p[1]+p[0];
			p[0]={-0.28,0};p[1]=p[2]+p[0];
			s[0]=new Line(p[1],p[2],1,0,0);//RED	
			p[0]={0,0.35};p[1]=p[2]+p[0];
			s[6]=new Line(p[1],p[2],0,0,0);	
			p[0]={0,0.05};p[2]=p[2]+p[0];
			for(i=1;i<=5;i++)
			{
				p[0]={0.3,0};p[1]=p[1]+p[0];p[2]=p[2]+p[0];
				s[6+i]=new Line(p[1],p[2],0,0,0);	
			}
			p[0]={-1.8,1.3};p[1]=p[1]+p[0];p[2]=p[2]+p[0];
			for(i=1;i<=6;i++)
			{
				p[0]={0.3,0};p[1]=p[1]+p[0];p[2]=p[2]+p[0];
				s[11+i]=new Line(p[1],p[2],0,0,0);	
			}
			for(i=0;i<=15;i++)s[i]->setAnchor(anchor);
		}
		~Park(){for(int i=0;i<=17;i++)delete s[i];}
		void draw(){for(int i=0;i<=17;i++)s[i]->draw();}
		void move(Vec v){for(int i=0;i<=17;i++)s[i]->move(v);}
		void zoom(float scale=0){}
		void rotate(float angle){}
		void open(){s[0]->SetColor(1,1,1);}
		void close(){s[0]->SetColor(1,0,0);}
	private:
		ColoredFig*s[18];
};
class Rocket:public Group
{
	public:
		Rocket(Vec v={0,0})
		{
			anchor=v;
			Vec p[10];k=1;p[0]={-0.04,0.11};
			p[4]=v+p[0];p[5]=v-p[0];
			s[0]=new Orthogon(p[4],p[5],1,0.9,0);
			p[0]={-0.01,0.02};p[1]=v+p[0];
			p[0]={0.01,-0.02};p[2]=v+p[0];
			s[1]=new Orthogon(p[1],p[2],0.2,0.2,1);
			p[0]={-0.025,0.07};p[1]=v+p[0];
			p[0]={-0.01,0.05};p[2]=v+p[0];
			s[2]=new Orthogon(p[1],p[2],1,0,0.9);
			p[0]={0.025,0.07};p[1]=v+p[0];
			p[0]={0.01,0.05};p[2]=v+p[0];
			s[3]=new Orthogon(p[1],p[2],1,0,0.9);
			p[0]={0.08,0};p[1]=p[4]+p[0];
			p[0]={0.04,0.07};p[2]=p[4]+p[0];
			s[4]=new Triangle(p[4],p[1],p[2],0.8,1,0.5);
			p[0]={0.05,0};p[1]=p[5]+p[0];
			p[0]={0,0.1};p[2]=p[5]+p[0];
			s[5]=new Triangle(p[5],p[1],p[2],1,0.5,0);
			p[0]={-0.13,0};p[5]=p[5]+p[0];
			p[0]={0.05,0};p[1]=p[5]+p[0];
			p[0]={0,0.1};p[2]=p[1]+p[0];
			s[6]=new Triangle(p[5],p[1],p[2],1,0.5,0);
			p[0]={0.02,0};p[1]=p[1]+p[0];
			p[0]={0.04,0};p[2]=p[1]+p[0];
			p[0]={0.01,-0.02};p[3]=p[2]+p[0];
			p[0]={-0.01,-0.02};p[4]=p[1]+p[0];
			s[7]=new Quad(p[1],p[2],p[3],p[4],0,0,0);
			for(int i=0;i<=7;i++)s[i]->setAnchor(anchor);
		}
		~Rocket(){for(int i=0;i<=7;i++)delete s[i];}
		void draw(){for(int i=0;i<=7;i++)s[i]->draw();}
		void move(Vec v){for(int i=0;i<=7;i++)s[i]->move(v);}
		void zoom(float scale=0)
		{
			int static i=0;
			if(k>=1)i=1;
			if(k<=0.5)i=0;
			if(i==0)zoomout();
			else zoomin();
		}
		void rotate(float angle)
		{for(int i=0;i<=7;i++)s[i]->rotate(angle);}
	private:
		ColoredFig* s[8];float k;
		void zoomout(){for(int i=0;i<=7;i++)s[i]->zoom(1.05);k*=1.05;}
		void zoomin(){for(int i=0;i<=7;i++)s[i]->zoom(0.95);k*=0.95;}
};
class Car:public Group
{
	public:
		Car(Vec v={0,0})
		{
			anchor=v;Vec p[5];
			p[0]={-0.04,0.11};
			p[1]=v+p[0];p[2]=v-p[0];
			s[0]=new Orthogon(p[1],p[2],1,0.7,0);
			p[0]={-0.09,0.03};p[1]=v+p[0];
			p[0]={0,-0.06};p[2]=p[1]+p[0];
			p[0]={0.05,-0.04};p[3]=p[2]+p[0];
			p[0]={0,0.14};p[4]=p[3]+p[0];
			s[1]=new Quad(p[1],p[2],p[3],p[4],0.5,0,1);
			p[0]={0.04,0.05};p[1]=v+p[0];
			p[0]={0,-0.1};p[2]=p[1]+p[0];
			s[2]=new Circle(p[1],0.02,1,0.3,0);
			s[3]=new Circle(p[2],0.02,1,0.3,0);			
			for(int i=0;i<=3;i++)s[i]->setAnchor(anchor);
		}
		~Car(){for(int i=0;i<=4;i++)delete s[i];}
		void draw(){for(int i=0;i<=3;i++)s[i]->draw();}
		void move(Vec v){for(int i=0;i<=3;i++)s[i]->move(v);anchor=anchor+v;}
		void zoom(float scale){}
		void rotate(float angle=PI/8){for(int i=0;i<=3;i++)s[i]->rotate(angle);}
	private:ColoredFig* s[4]; 
};
class UFO:public Group
{
	public:
		UFO(Vec v={0,0})
		{
			Vec p[10];anchor=v;
			p[0]=v;p[0].x=v.x+0.1;
			s[0]=new SemiCircle(anchor,p[0],0.1,0,0,1);
			p[1]=p[2]=p[5]=p[6]=v; 
			p[1].x=v.x-0.03;p[5].x=v.x+0.03;
			p[2].x=v.x-0.09;p[6].x=v.x+0.09;
			v={0.01,-0.03};p[4]=p[1]+v;p[7]=p[6]+v;
			v={-0.01,-0.03};p[3]=p[2]+v;p[8]=p[5]+v;
			s[1]=new Quad(p[1],p[2],p[3],p[4],1,1,0);
			s[2]=new Quad(p[5],p[6],p[7],p[8],1,1,0);
			p[1]={-0.1*cos(PI/4),0.1*sin(PI/4)};p[1]=p[1]+anchor;
			p[2]={-0.05*cos(PI/6),0.05*sin(PI/6)};p[2]=p[2]+p[1];
			p[5]={0.005,0.005};p[3]=p[1]+p[5];p[4]=p[2]+p[5];
			s[3]=new Quad(p[1],p[3],p[4],p[2],1,0.5,0);
			p[1]={0.1*cos(PI/4),0.1*sin(PI/4)};p[1]=p[1]+anchor;
			p[2]={0.05*cos(PI/6),0.05*sin(PI/6)};p[2]=p[2]+p[1];
			p[5]={-0.005,0.005};p[3]=p[1]+p[5];p[4]=p[2]+p[5];
			s[4]=new Quad(p[1],p[3],p[4],p[2],1,0.5,0);
			for(int i=0;i<=4;i++)s[i]->setAnchor(anchor);	
		}
		~UFO(){for(int i=0;i<=4;i++)delete s[i];}
		void draw(){for(int i=0;i<=4;i++)s[i]->draw();}
		void move(Vec v){for(int i=0;i<=4;i++)s[i]->move(v);}
		void zoom(float scale){}
		void rotate(float angle=PI/8){for(int i=0;i<=4;i++)s[i]->rotate(angle);}
	private:ColoredFig* s[5];
};
class Slot:public Group
{
	public:
		Slot(Vec v={0,0})
		{
			Vec p[2];
			p[0]=p[1]=anchor=v;
			Vec P={0.1,-0.19};
			p[0]=p[0]-P;
			p[1]=p[1]+P;
			o=new Orthogon(p[0],p[1]);
		}
		~Slot(){delete o;}
		void draw()
		{o->Color();o->draw();}
		void move(Vec v){o->move(v);}
		void zoom(float scale){}
		void rotate(float angle){}
	private:ColoredFig* o;
};
