/* Tea pot example
 * Got from
 * http://math.hws.edu/bridgeman/courses/324/s06/doc/opengl.html
 *
 * Note "windows.h" is neccessary to for students
 * using windows to compile
 * Keep it there no mater what the ide tells you
 */
//#include <windows.h>
#include <GL/freeglut.h>
#include <GL/gl.h>


void display () {

    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);

    /* draw scene */
    //glutSolidTeapot(.5);

    /* flush drawing routines to the window */
    //glFlush();
}

int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the
       program */
    glutInit(&argc,argv);
    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
	glutInitDisplayMode(GLUT_RGB);
   	glutCreateWindow("shapes");
    glutDisplayFunc(display);
    /* tell GLUT to wait for events */
    glutMainLoop();
}
