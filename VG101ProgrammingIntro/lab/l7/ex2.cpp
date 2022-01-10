#include <iostream>
#include <cmath> 
#include <GL/freeglut.h>
#include "l7ex2.h"
#include <ctime>
using namespace std;
void TimeStep(int n)
{
	glutTimerFunc(250, TimeStep, 0);glutPostRedisplay();
}
void gldraw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	point p[5];
	p[0]={-0.5,-0.5};
	p[1]={0,0.5};
	p[2]={0.5,0.5};
	p[3]={0,-0.5};
	p[4]={1,-0.5};
	//Triangle static a(p[0],p[1],p[2]);
	Orthogon static a(p[0],p[2]);	
	//Trapezium static a(p[0],p[1],p[2],p[3]);
	//Parallelogram static a(p[0],p[1],p[2],p[4]);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	a.draw();
	//b.draw();
	a.move(0.1,0.1);
	a.zoom(0.8);
	//b.zoom(0.8);
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
	glutTimerFunc(250,TimeStep,0);	
	glutMainLoop();
	return 0;
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
	r=(float)rand()/RAND_MAX;
	g=(float)rand()/RAND_MAX;
	b=(float)rand()/RAND_MAX;
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
	r=(float)rand()/RAND_MAX;
	g=(float)rand()/RAND_MAX;
	b=(float)rand()/RAND_MAX;
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
	r=(float)rand()/RAND_MAX;
	g=(float)rand()/RAND_MAX;
	b=(float)rand()/RAND_MAX;
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
	r=(float)rand()/RAND_MAX;
	g=(float)rand()/RAND_MAX;
	b=(float)rand()/RAND_MAX;
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
