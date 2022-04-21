#include <stdlib.h> 
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

const int square = 1;

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glViewport(0, 0, 500, 500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLdouble)500 / (GLdouble)500, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glNewList(square, GL_COMPILE);
		glBegin(GL_POLYGON);
			glColor3f(1, 0, 0);
			glVertex3f(-1, 1, 0);
			glVertex3f(-1, -1, 0);
			glVertex3f(1, -1, 0);
			glVertex3f(1, 1, 0);
		glEnd();
	glEndList();

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
	glOrtho(-5, 5, -5, 5, 0, 5);
	// glColor3f(1, 1, 1);

	glCallList(square);
	glutSwapBuffers();
	glFlush();
	
}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500, 500);

	glutCreateWindow("Square");
	init();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}


void makeCube(void){
	float right[] = {0,1,0,0,-1,0,0,0,0,0,1,0,0,0,0,1};
	float left[] = {0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1};
	float down[] = {1,0,0,0,0,0,-1,0,0,1,0,0,0,0,0,1};
	float up[] = {1,0,0,0,0,0,1,0,0,-1,0,0,0,0,0,1};
	float move[] = {1,0,0,2,0,1,0,2,0,0,1,2,0,0,0,1};


	glNewList(1,GL_COMPILE);
	glLoadIdentity();
	glLoadMatrixf(right);
	//glutDisplayFunc
	glLoadIdentity();
	glLoadMatrixf(left);
	//glutDisplayFunc
	glLoadIdentity();
	glLoadMatrixf(down);
	//glutDisplayFunc
	glLoadIdentity();
	glLoadMatrixf(up);
	//glutDisplayFunc
	glLoadMatrixf(move);
	//glutDisplayFunc
	glLoadIdentity();
	glEndList();
	

}