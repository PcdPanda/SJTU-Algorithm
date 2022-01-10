#define PI 3.1415926535
#include <cmath>
class point{public:float x,y;};
class shape
{
	public:
		virtual void draw()=0;
		virtual void move(float mx,float my)=0;
		virtual void zoom(float scale)=0;
		virtual void rotate(float angle,point P)=0;
		virtual float area()=0;
		virtual ~shape(){};
};
class Car
{
	public:
		Car(point P={0,0});
		~Car(){for(int i=0;i<=3;i++)delete s[i];}
		void rotate(float angle=PI/8)
		{
			point P1=p[0];P1.x+=0.5;
			for(int i=0;i<=3;i++)s[i]->rotate(angle,P1);
		}
		void draw()
		{
			for(int i=0;i<=3;i++)s[i]->draw();
		}
		void move(float mx,float my)
		{
			z.x+=mx;z.y+=my;
			for(int i=0;i<=3;i++)s[i]->move(mx,my);
		}		
		void zoom(float scale)
		{
			for(int i=0;i<=3;i++)s[i]->zoom(scale);
		}
		point z;
	private:
		float r,g,b;
		shape *s[4];
		point p[7];	
};
class Circle:public shape
{
	public:
		Circle(point p1={0,0},float rad=0.1,float R=0,float G=0,float B=0)
		{
			r=R;g=G;b=B;
			p=p1;radius=rad;
		}
		void draw();
		void move(float mx,float my)
		{
			p.x+=mx;p.y+=my;
		}
		void rotate(float angle,point P)
		{
			float x0,y0;
			x0=(p.x-P.x)*cos(angle)-(p.y-P.y)*sin(angle)+P.x;
			y0=(p.x-P.y)*sin(angle)+(p.y-P.y)*cos(angle)+P.y;
			p.x=x0;p.y=y0;
		}	
		void zoom(float scale)
		{
			radius*=scale;
		}
		float area()
		{
			return PI*pow(radius,2); 
		}
	private:
		point p;float radius,r,g,b;
}; 
class Triangle:public shape
{
	public:
		Triangle(point p1,point p2,point p3,float R=0,float G=0,float B=0)
		{
			r=R;g=G;b=B;
			p[0]=p1;p[1]=p2;p[2]=p3;
		}
		void draw();
		void rotate(float angle,point P)
		{
			float x0,y0;
			for(int i=0;i<=2;i++)
			{
				x0=(p[i].x-P.x)*cos(angle)-(p[i].y-P.y)*sin(angle)+P.x;
				y0=(p[i].x-P.y)*sin(angle)+(p[i].y-P.y)*cos(angle)+P.y;
				p[i].x=x0;p[i].y=y0;
			}
		}	
		void move(float mx,float my);
		void zoom(float scale);
		float area();
	private:point p[3];float r,g,b;					
};
class Orthogon:public shape
{
	public:
		Orthogon(point p1,point p2,float R=0,float G=0,float B=0)
		{
			r=R;g=G;b=B;	
			p[0].x=p1.x;p[0].y=p1.y;p[1].x=p2.x;p[1].y=p1.y;
			p[2].x=p2.x;p[2].y=p2.y;p[3].x=p1.x;p[3].y=p2.y;
		}
		void draw();
		void move(float mx,float my);
		void rotate(float angle,point P)
		{
			float x0,y0;
			for(int i=0;i<=3;i++)
			{
				x0=(p[i].x-P.x)*cos(angle)-(p[i].y-P.y)*sin(angle)+P.x;
				y0=(p[i].x-P.y)*sin(angle)+(p[i].y-P.y)*cos(angle)+P.y;
				p[i].x=x0;p[i].y=y0;				
			}
		}		
		void zoom(float scale);
		float area();
	private:point p[4];	float r,g,b;	
};
class Parallelogram:public shape
{
	public:
		Parallelogram(point p1,point p2,point p3,point p4,float R=0,float G=0,float B=0)
		{
			r=R;g=G;b=B;	
			p[0].x=p1.x;p[0].y=p1.y;
			p[1].x=p2.x;p[1].y=p2.y;
			p[2].x=p3.x;p[2].y=p3.y;
			p[3].x=p4.x;p[3].y=p4.y;
		}
		void draw();
		void move(float mx,float my);
		void rotate(float angle,point P)
		{
			float x0,y0;
			for(int i=0;i<=3;i++)
			{
				x0=(p[i].x-P.x)*cos(angle)-(p[i].y-P.y)*sin(angle)+P.x;
				y0=(p[i].x-P.y)*sin(angle)+(p[i].y-P.y)*cos(angle)+P.y;
				p[i].x=x0;p[i].y=y0;				
			}
		}	
		void zoom(float scale);
		float area();
	private:point p[4];float r,g,b;	
};
class Trapezium:public shape
{
	public:
		Trapezium(point p1,point p2,point p3,point p4,float R=0,float G=0,float B=0)
		{
			r=R;g=G;b=B;	
			p[0].x=p1.x;p[0].y=p1.y;
			p[1].x=p2.x;p[1].y=p2.y;
			p[2].x=p3.x;p[2].y=p3.y;
			p[3].x=p4.x;p[3].y=p4.y;
		}
		void draw();
		void move(float mx,float my);
		void rotate(float angle,point P)
		{
			float x0,y0;
			for(int i=0;i<=3;i++)
			{
				x0=(p[i].x-P.x)*cos(angle)-(p[i].y-P.y)*sin(angle)+P.x;
				y0=(p[i].x-P.y)*sin(angle)+(p[i].y-P.y)*cos(angle)+P.y;
				p[i].x=x0;p[i].y=y0;				
			}
		}	
		void zoom(float scale);
		float area();
	private:point p[4];float r,g,b;	
};
