#ifndef __FIGURES_H__
#define __FIGURES_H__
class Point { public: double x,y; };
class Shape 
{
	public: virtual void draw() = 0; virtual ~Shape();
};
class Rectangle : public Shape 
{
	public:
	Rectangle(Point pt1={-.5,-.5}, Point pt2={.5,.5},
	float red=0, float green=0, float blue=0);
	void draw();
	private: Point p1,p2; float r, g, b;
};
class Triangle : public Shape 
{
	public:
	Triangle(Point pt1={-.5,-.5}, Point pt2={.5,-.5},
	Point pt3={0,.5}, float red=0, float green=0, float blue=0);
	void draw();
	private: Point p1,p2,p3; float r, g, b;
};
#endif
