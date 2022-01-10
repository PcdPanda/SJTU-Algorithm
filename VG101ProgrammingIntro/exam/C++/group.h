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

class Castle:public Group
{
	public:
		Castle(Vec v={0,0})
		{
			Vec p[5];anchor=v;
			p[0]={-0.5,0};p[1]=v+p[0];
			p[0]={0.5,-0.3};p[2]=v+p[0];
			s[0]=new Orthogon(p[1],p[2],0.5,0.5,0.5);
			p[0]={0,0.15};p[1]=p[1]+p[0];
			p[0]={0.25,-0.15};p[2]=p[1]+p[0];
			s[1]=new Orthogon(p[1],p[2],0.5,0.5,0.5);
			p[0]={0.75,0};p[1]=p[1]+p[0];p[2]=p[2]+p[0];
			s[2]=new Orthogon(p[1],p[2],0.5,0.5,0.5);
			p[0]={-0.5,0.2};p[1]=v+p[0];
			p[0]={0.05,-0.05};p[2]=p[1]+p[0];
			s[3]=new Orthogon(p[1],p[2],0.5,0.5,0.5);
			p[0]={0.1,0};p[1]=p[1]+p[0];p[2]=p[2]+p[0];
			s[4]=new Orthogon(p[1],p[2],0.5,0.5,0.5);
			p[0]={0.1,0};p[1]=p[1]+p[0];p[2]=p[2]+p[0];
			s[5]=new Orthogon(p[1],p[2],0.5,0.5,0.5);
			p[0]={0.55,0};p[1]=p[1]+p[0];p[2]=p[2]+p[0];
			s[6]=new Orthogon(p[1],p[2],0.5,0.5,0.5);
			p[0]={0.1,0};p[1]=p[1]+p[0];p[2]=p[2]+p[0];
			s[7]=new Orthogon(p[1],p[2],0.5,0.5,0.5);
			p[0]={0.1,0};p[1]=p[1]+p[0];p[2]=p[2]+p[0];
			s[8]=new Orthogon(p[1],p[2],0.5,0.5,0.5);
			p[0]={-0.1,0};p[1]=v+p[0];
			p[0]={0.2,0.25};p[2]=p[1]+p[0];
			s[9]=new Orthogon(p[1],p[2],0,0,0);
			p[0]={-0.2,0};p[1]=p[2]+p[0];
			p[0]={0,0.5};p[3]=v+p[0];
			s[10]=new Triangle(p[1],p[2],p[3],0,0,0);
		}
		~Castle(){for(int i=0;i<=10;i++)delete s[i];}
		void draw(){for(int i=0;i<=10;i++)s[i]->draw();}
		void move(Vec v){}
		void zoom(float scale){}
		void rotate(float angle){}
	private:ColoredFig* s[11];
};

class Prince:public Group
{
	public:
		Prince(Vec v={0,0})
		{
			Vec p[5];anchor=v;
			p[0]={-0.05,0.05};
			p[1]=v+p[0];p[2]=v-p[0];
			s[0]=new Orthogon(p[1],p[2],0.9,0.9,0.9);
			p[0]={-0.025,0};p[1]=p[2]+p[0];
			p[0]={0.025,-0.1};p[2]=p[1]+p[0];
			s[1]=new Orthogon(p[1],p[2],0,0,0);
			p[0]={-0.075,0};p[1]=p[1]+p[0];p[2]=p[2]+p[0];
			s[2]=new Orthogon(p[1],p[2],0,0,0);
			p[0]={-0.075,0.05};
			p[1]=v+p[0];p[0]={0.025,-0.08};p[2]=p[1]+p[0];
			s[3]=new Orthogon(p[1],p[2],0,1,0);
			p[0]={0.075,0.05};
			p[1]=v+p[0];p[0]={-0.025,-0.08};p[2]=p[1]+p[0];
			s[4]=new Orthogon(p[1],p[2],0,1,0);
			p[0]={-0.15,0};p[2]=p[1]+p[0];
			p[0]={0,0.125};p[3]=v+p[0];
			s[5]=new Triangle(p[1],p[2],p[3],1,0.5,0);
			s[6]=new Circle(p[3],0.04,1,0.8,0);	
		}
		~Prince(){for(int i=0;i<=6;i++)delete s[i];}
		void draw(){for(int i=0;i<=6;i++)s[i]->draw();}
		void move(Vec v){for(int i=0;i<=6;i++)s[i]->move(v);anchor=anchor+v;}
		void zoom(float scale){}
		void rotate(float angle){}
	private:ColoredFig* s[7];
};
