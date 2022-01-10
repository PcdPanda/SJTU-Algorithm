#include <cmath>
#define PI 3.1415926535
using namespace std;
class Vec // Vector can be both vector or point
{
	public:
		float x,y;	
		Vec(float _x=0, float _y=0) {x = _x; y = _y;}
		Vec operator+(Vec v){return Vec{x+v.x,y+v.y};}//returns the sum of 2 Vec 
		Vec operator-(Vec v){return Vec{x-v.x,y-v.y};}//returns the difference of 2 Vec
		Vec operator*(float scale) {return Vec(x*=scale,y*=scale);}//return current Vector scaled by k
		float operator*(Vec v){return x*v.x+y*v.y;}//returns the inner product of 2 Vec
		Vec rotate(float angle,Vec v)//return current vector rotated counter clockwise
		{
			if(x==v.x&&y==v.y)return v;
			double x0,y0;
			x0=(x-v.x)*cos(angle)-(y-v.y)*sin(angle)+v.x;
			y0=(x-v.x)*sin(angle)+(y-v.y)*cos(angle)+v.y;
			return Vec(x0,y0);
		}
};
class Figure 
{
	protected:Vec anchor; 
	public:
		Figure():anchor(0,0){}
		Vec getAnchor() {return anchor;}
		void setAnchor(Vec a) {anchor = a;}
		virtual void draw()=0;
		virtual void move(Vec v)=0;
		virtual void rotate(float angle)=0;
		virtual void zoom(float scale)=0;
		virtual ~Figure(){}	
};
class ColoredFig:public Figure
{
	public:
		void Color()
			{
				r=(float)rand()/RAND_MAX;
				g=(float)rand()/RAND_MAX;
				b=(float)rand()/RAND_MAX;
			}
		void SetColor(float R=0,float G=0,float B=0){r=R;g=G;b=B;}
	protected:float r,g,b;
};
class Line:public ColoredFig
{
	public:
		Line(Vec p1={-0.5,-0.5},Vec p2={0.5,0.5},float R=0,float G=0,float B=0)
		{
			anchor={0,0};
			r=R;g=G;b=B;			
			p[0]=p1;p[1]=p2;
			for(int i=0;i<=1;i++)anchor=anchor+p[i];
			anchor.x/=2;anchor.y/=2;
		}
		void draw()
		{
			glColor3f(r,g,b);
			glBegin(GL_LINES);
			for(int i=0;i<=1;i++)glVertex2f(p[i].x,p[i].y);
			glEnd();
		}
		void rotate(float angle){for(int i=0;i<=3;i++)p[i]=p[i].rotate(angle,anchor);}	
		void move(Vec v){for(int i=0;i<=1;i++)p[i]=p[i]+v;anchor=anchor+v;}
		void zoom(float scale)
		{
			for(int i=0;i<=1;i++)
			{
				p[i].x=anchor.x+(p[i].x-anchor.x)*scale;
				p[i].y=anchor.y+(p[i].y-anchor.y)*scale;
			}	
		}		
	private:Vec p[2];		
};
class Circle:public ColoredFig
{
	public:
		Circle(Vec p1={0,0},float rad=0.1,float R=0,float G=0,float B=0)
		{r=R;g=G;b=B;radius=rad;anchor=p1;p[0]=p1;}
		void draw()
		{
			glColor3f(r,g,b);
			glBegin(GL_POLYGON);
			for(float i=0;i<=2*PI;i+=0.001)
			{glVertex2f(p[0].x+radius*cos(i),p[0].y+radius*sin(i));}
			glEnd();
		}
		void move(Vec v){anchor=anchor+v;p[0]=p[0]+v;}
		void rotate(float angle){p[0]=p[0].rotate(angle,anchor);}	
		void zoom(float scale){radius*=scale;}
	private:float radius;Vec p[1];
};
class Triangle:public ColoredFig
{
	public:
		Triangle(Vec p1={-1,0},Vec p2={1,0},Vec p3={0,1},float R=0,float G=0,float B=0)
		{
			anchor={0,0};
			r=R;g=G;b=B;p[0]=p1;p[1]=p2;p[2]=p3;
			for(int i=0;i<=2;i++)anchor=anchor+p[i];
			anchor.x/=3;anchor.y/=3;
		}
		void draw()
		{
			glColor3f(r,g,b);
			glBegin(GL_TRIANGLES);
			for(int i=0;i<=2;i++)glVertex2f(p[i].x,p[i].y);
			glEnd();
		}
		void rotate(float angle){for(int i=0;i<=2;i++)p[i]=p[i].rotate(angle,anchor);}	
		void move(Vec v)
		{
			for(int i=0;i<=2;i++)p[i]=p[i]+v;
			anchor=anchor+v;
		}
		void zoom(float scale)
		{
			for(int i=0;i<=2;i++)
			{
				p[i].x=anchor.x+(p[i].x-anchor.x)*scale;
				p[i].y=anchor.y+(p[i].y-anchor.y)*scale;
			}	
		}		
	private:Vec p[3];					
};
class Orthogon:public ColoredFig
{
	public:
		Orthogon(Vec p1={-0.5,-0.5},Vec p2={0.5,0.5},float R=0,float G=0,float B=0)
		{
			anchor={0,0};
			r=R;g=G;b=B;			
			p[0].x=p1.x;p[0].y=p1.y;p[1].x=p2.x;p[1].y=p1.y;
			p[2].x=p2.x;p[2].y=p2.y;p[3].x=p1.x;p[3].y=p2.y;
			for(int i=0;i<=3;i++)anchor=anchor+p[i];
			anchor.x/=4;anchor.y/=4;
		}
		void draw()
		{
			glColor3f(r,g,b);
			glBegin(GL_QUADS);
			for(int i=0;i<=3;i++)glVertex2f(p[i].x,p[i].y);
			glEnd();
		}
		void rotate(float angle){for(int i=0;i<=3;i++)p[i]=p[i].rotate(angle,anchor);}	
		void move(Vec v)
		{
			for(int i=0;i<=3;i++)p[i]=p[i]+v;
			anchor=anchor+v;
		}
		void zoom(float scale)
		{
			for(int i=0;i<=3;i++)
			{
				p[i].x=anchor.x+(p[i].x-anchor.x)*scale;
				p[i].y=anchor.y+(p[i].y-anchor.y)*scale;
			}	
		}		
	private:Vec p[4];					
};
