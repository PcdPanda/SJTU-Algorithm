#include <iostream>
#include <ctime> 
#include <GL/freeglut.h>
#include "group.h"
#include "assignment.h"  
using namespace std;
void TimeStep(int n)
{glutTimerFunc(50, TimeStep, 0);glutPostRedisplay();}
void gldraw()
{
	Prince static a({0.8,0.15});
	Castle static c({-0.5,0.3});
	Line b({-1,0},{1,0},0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	c.draw();
	b.draw();
	if((a.getAnchor()).x>0.1)
	{a.move({-0.025,0});a.draw();}
	glutSwapBuffers();
	glFlush();
}
int ex1(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("PANDA");
	glClearColor(1,1,1,0);
	glutDisplayFunc(gldraw);
	glutTimerFunc(50,TimeStep,0);	
	glutMainLoop();
	return 0;
}
