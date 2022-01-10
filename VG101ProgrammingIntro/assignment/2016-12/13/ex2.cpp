#include <iostream>
#include <cmath> 
#include <ctime>
#include <GL/freeglut.h>
#include "group.h"
#define PI 3.1415926535
#include "ex1car.h" 
void TimeStep(int n)
{glutTimerFunc(10, TimeStep, 0);glutPostRedisplay();}
void Init(int A[10])
{
	int static k=0;int i;Vec v;float m;
	UFO static U[10];Slot static S[10];Rocket static R[10];
	if(k==0)
	{
		for(i=0;i<=4;i++)
		{
			m=i;v={-0.5+0.3*m,-0.5};
			U[i].move(v);S[i].move(v);R[i].move(v);
		}
		for(i=5;i<=9;i++)
		{
			m=i-5;v={-0.5+0.3*m,0.7};
			U[i].move(v);S[i].move(v);R[i].move(v);R[i].rotate(PI); 
		}	
	}		
	for(i=0;i<=9;i++)
	{
		switch (A[i])
		{
			case 1:U[i].draw();U[i].rotate();break;
			case 2:R[i].draw();R[i].zoom();break;
			case 3:S[i].draw();break;
		}
	}
	k=1;
}
void Drive(Car*c,int A[10])
{
	float static a=0,b=0;
	int i=0;
	if(a==0)
	{c->move({0,0.05});if((c->getAnchor()).y>-0.2)a=1;}
	if(a==1){c->rotate(-PI/30);b+=PI/30;if(b>PI/2)a=2;}
	for(i=0;i<=9;i++)if(A[i]==0)break;
	if(i<=4&&a==2)
	{c->move({0.05,0});if((c->getAnchor()).x>-0.35+i*0.3)a=3;}
	if(i<=4&&a==3)
	{c->move({-0.02,0});if((c->getAnchor()).x<-0.45+i*0.3)a=4;b=0;}
	if(i<=4&&a==4)
	{c->rotate(PI/30);b+=PI/30;if(b>PI/2)a=5;}
	if(i<=4&&a==5)
	{c->move({0,-0.02});if((c->getAnchor()).y<-0.5)a=6;}
	if(i>=5&&a==2)
	{c->move({0.05,0});if((c->getAnchor()).x>0.75)a=3;b=0;}
	if(i>=5&&a==3)
	{c->rotate(PI/30);b+=PI/30;if(b>PI/2)a=4;}
	if(i>=5&&a==4)
	{c->move({0,0.05});if((c->getAnchor()).y>0.35)a=5;b=0;}
	if(i>=5&&a==5)
	{c->rotate(PI/30);b+=PI/30;if(b>PI/2)a=6;}
	if(i>=5&&a==6)
	{c->move({-0.05,0});if((c->getAnchor()).x<-2.15+i*0.3)a=7;}
	if(i>=5&&a==7)
	{c->move({0.02,0});if((c->getAnchor()).x>-2.05+i*0.3)a=8;b=0;}
	if(i>=5&&a==8)
	{c->rotate(PI/30);b+=PI/30;if(b>PI/2)a=9;}
	if(i>=5&&a==9)
	{c->move({0,0.02});if((c->getAnchor()).y>0.7)a=10;}
}
void gldraw()
{
	int static k=0,A[10];int i=0;
	Park static a;
	if(k==0)
	{
		for(i=0;i<=9;i++){A[i]=rand()%4;if(A[i]==0)k=1;}
		if(k==0){k=rand()%10;A[k]=0;k=1;}
	}
	Car static c({-0.8,-0.875});
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	if((c.getAnchor()).y<-0.2&&(c.getAnchor()).x<-0.5)a.open();
	else {a.close();}
	a.draw();
	Init(A); 	
	Drive(&c,A);
	c.draw();
	glutSwapBuffers();
	glFlush();
}
int ex2(int argc, char* argv[])
{
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("PANDA");
	glClearColor(1,1,1,0);
	glutDisplayFunc(gldraw);
	glutTimerFunc(10,TimeStep,0);	
	glutMainLoop();
	return 0;
}
