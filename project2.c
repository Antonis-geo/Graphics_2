
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>



void myinit(void)
{
 
/* attributes */
glEnable(GL_BLEND);
 	  glClearColor(1.0, 1.0, 1.0, 0.0); /* white background */
	   glColor3f(1.0, 0.0, 0.0); /* draw in red */

	/* set up viewing */
	/* 500 x 500 window with origin lower left */

	   glMatrixMode(GL_PROJECTION);
	   glLoadIdentity();
	   gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	   glMatrixMode(GL_MODELVIEW);
}

void display( void )
{

/* define a point data type */

    typedef GLfloat point2[2];     

    point2 vertices[3]={{0.0,0.0},{250.0,500.0},{500.0,0.0}}; /* A triangle */



    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */

     glFlush(); /* clear buffers */
 }

void main(int argc, char** argv)
{

/* Standard GLUT initialization */

	    glutInit(&argc,argv);
	    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); /* default, not needed */
	    glutInitWindowSize(500,500); /* 500 x 500 pixel window */
	    glutInitWindowPosition(0,0); /* place window top left on display */
	    glutCreateWindow("Magic Cube"); /* window title */
	   glutDisplayFunc(display); /* display callback invoked when window opened */

     myinit(); /* set attributes */

	 glutMainLoop();
}