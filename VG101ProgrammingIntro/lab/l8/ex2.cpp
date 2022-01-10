#include <iostream>
#include <cmath> 
#include <ctime>
#include <GL/freeglut.h>
#include "l8ex2.h"
#define PI 3.1415926535
using namespace std;
void TimeStep(int n)
{
	glutTimerFunc(25, TimeStep, 0);glutPostRedisplay();
}
void gldraw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	point p[4];
	p[0]={-0.5,0};
	Car static *a=new Car(p[0]); 
	int static k=0;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	a->draw(); 
	if(k==0)
	{ 
		a->move(0.01,0);
		if(a->z.x>0)k=1;
	}
	else 
	{
		a->move(-0.01,0);
		if(a->z.x<-1)k=0;	
	}
	glutSwapBuffers();
	glFlush();
}
int main(int argc, char *argv[])
{
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutCreateWindow("PANDA");
	glClearColor(1,1,1,0);
	glutDisplayFunc(gldraw);
	glutTimerFunc(25,TimeStep,0);	
	glutMainLoop();
	return 0;
}
Car::Car(point P)
{
	z=p[0]=P;
	p[1].x=p[0].x+1;p[1].y=p[0].y-0.25;
	s[0]=new Orthogon(p[0],p[1],1,1,0);
	p[2].x=p[0].x+0.25;p[2].y=p[0].y-0.25;
	p[3].x=p[2].x+0.5;p[3].y=p[2].y;
	s[1]=new Circle(p[2],0.075,1,0.5,0);s[2]=new Circle(p[3],0.075,1,0.5,0);
	p[4].x=p[0].x+0.05;p[4].y=p[0].y+0.25;
	p[5].x=p[4].x+0.5;p[5].y=p[4].y;
	p[6].x=p[0].x+0.75;p[6].y=p[0].y;
	s[3]=new Parallelogram(p[0],p[4],p[5],p[6],0.5,0,1);
}
void Circle::draw()
{
	int n=500;
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
	for(int i=0;i<n;i++)glVertex2f(p.x+radius*cos(2*PI*i/n),p.y+radius*sin(2*PI*i/n));
	glEnd();
}
void Triangle::move(float mx,float my)
{
	for(int i=0;i<=2;i++)
	{
		p[i].x+=mx;
		p[i].y+=my;
	}
} 
void Triangle::draw ()
{	
	glColor3f(r,g,b);
	glBegin(GL_TRIANGLES);
	for(int i=0;i<=2;i++)glVertex2f(p[i].x,p[i].y);
	glEnd();
}
void Triangle::zoom(float scale)
{
	int i=0;float x=0,y=0;
	for(;i<=2;i++)
	{
		x+=p[i].x/3;
		y+=p[i].y/3;
	}
	for(i=0;i<=2;i++)
	{
		p[i].x=x+(p[i].x-x)*scale;
		p[i].y=y+(p[i].y-y)*scale;
	}
} 
float Triangle::area()
{
	return abs((0.5)*(p[0].x*p[1].y+p[1].x*p[2].y+p[2].x*p[0].y-p[0].x*p[2].y
	-p[1].x*p[0].y-p[2].x*p[1].y));
}
void Orthogon::draw()
{	
	glColor3f(r,g,b);
	glBegin(GL_QUADS);
	for(int i=0;i<=3;i++)glVertex2f(p[i].x,p[i].y);
	glEnd();	
}
void Orthogon::move(float mx,float my)
{
	for(int i=0;i<=3;i++)
	{
		p[i].x+=mx;
		p[i].y+=my;
	}
} 
void Orthogon::zoom(float scale)
{
	int i=0;float x=0,y=0;
	for(;i<=3;i++)
	{
		x+=p[i].x/3;
		y+=p[i].y/3;
	}
	for(i=0;i<=3;i++)
	{
		p[i].x=x+(p[i].x-x)*scale;
		p[i].y=y+(p[i].y-y)*scale;
	}
} 
float Orthogon::area()
{
	int i=0;float x0=0,y0=0;
	for(i=0;i<=3;i++)
	{
		x0+=p[i].x/3;
		y0+=p[i].y/3;
	}
	return 4*abs((p[0].x-x0)*(p[0].y-y0));
}

void Parallelogram::draw()
{	
	glColor3f(r,g,b);
	glBegin(GL_QUADS);
	for(int i=0;i<=3;i++)glVertex2f(p[i].x,p[i].y);
	glEnd();	
}
void Parallelogram::move(float mx,float my)
{
	for(int i=0;i<=3;i++)
	{
		p[i].x+=mx;
		p[i].y+=my;
	}
} 
void Parallelogram::zoom(float scale)
{
	int i=0;float x=0,y=0;
	for(;i<=3;i++)
	{
		x+=p[i].x/3;
		y+=p[i].y/3;
	}
	for(i=0;i<=3;i++)
	{
		p[i].x=x+(p[i].x-x)*scale;
		p[i].y=y+(p[i].y-y)*scale;
	}
} 
float Parallelogram::area()
{
	int i=0;float x0=0,y0=0;
	for(i=0;i<=3;i++)
	{
		x0+=p[i].x/3;
		y0+=p[i].y/3;
	}
	return 4*abs((p[0].x-x0)*(p[0].y-y0));
}
void Trapezium::draw()
{	
	glColor3f(r,g,b);
	glBegin(GL_QUADS);
	for(int i=0;i<=3;i++)glVertex2f(p[i].x,p[i].y);
	glEnd();	
}
void Trapezium::move(float mx,float my)
{
	for(int i=0;i<=3;i++)
	{
		p[i].x+=mx;
		p[i].y+=my;
	}
} 
void Trapezium::zoom(float scale)
{
	int i=0;float x=0,y=0;
	for(;i<=3;i++)
	{
		x+=p[i].x/3;
		y+=p[i].y/3;
	}
	for(i=0;i<=3;i++)
	{
		p[i].x=x+(p[i].x-x)*scale;
		p[i].y=y+(p[i].y-y)*scale;
	}
} 
float Trapezium::area()
{
	int i;
	for(i=1;i<=3;i++)if(p[i].y==p[0].y)break;
	switch(i)
	{
		case 1:return abs((p[2].y-p[0].y)*(abs(p[0].x-p[1].x)+abs(p[2].x-p[3].x)))/2;break;
		case 2:return abs((p[1].y-p[0].y)*(abs(p[0].x-p[2].x)+abs(p[1].x-p[3].x)))/2;break;
		case 3:return abs((p[1].y-p[0].y)*(abs(p[0].x-p[3].x)+abs(p[1].x-p[2].x)))/2;break;	
	}
}
