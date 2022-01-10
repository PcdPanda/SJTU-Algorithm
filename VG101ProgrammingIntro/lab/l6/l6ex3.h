class point{public:float x,y;};
class shape
{
	public:
		virtual void draw()=0;
		virtual void move(float mx,float my)=0;
		virtual float area()=0;
		virtual ~shape(){};
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
		void move(float mx,float my);
		void zoom(float scale);
		float area();
	private:point p[3];float r,g,b;					
};
class Orthogon:public shape
{
	public:
		Orthogon(point p1,point p2,float r=0,float g=0,float b=0)
		{
			p[0].x=p1.x;p[0].y=p1.y;p[1].x=p1.x;p[1].y=p2.y;
			p[2].x=p2.x;p[2].y=p1.y;p[3].x=p2.x;p[3].y=p2.y;
		}
		void draw();
		void move(float mx,float my);
		void zoom(float scale);
		float area();
	private:point p[4];	float r,g,b;	
};
class Parallelogram:public shape
{
	public:
		Parallelogram(point p1,point p2,point p3,point p4,float r=0,float g=0,float b=0)
		{
			p[0].x=p1.x;p[0].y=p1.y;
			p[1].x=p2.x;p[1].y=p2.y;
			p[2].x=p3.x;p[2].y=p3.y;
			p[3].x=p4.x;p[3].y=p4.y;
		}
		void draw();
		void move(float mx,float my);
		void zoom(float scale);
		float area();
	private:point p[4];float r,g,b;	
};
class Trapezium:public shape
{
	public:
		Trapezium(point p1,point p2,point p3,point p4,float r=0,float g=0,float b=0)
		{
			p[0].x=p1.x;p[0].y=p1.y;
			p[1].x=p2.x;p[1].y=p2.y;
			p[2].x=p3.x;p[2].y=p3.y;
			p[3].x=p4.x;p[3].y=p4.y;
		}
		void draw();
		void move(float mx,float my);
		void zoom(float scale);
		float area();
	private:point p[4];float r,g,b;	
};
