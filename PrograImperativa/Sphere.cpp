#include <GL\glut.h>
#include "Joystick.h"
#include "Archivos.h"
#include <stdio.h>

GLdouble radius = 0.5;
float coordenadas[50][6];

void redisplayFunc(void)
{
	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT);
	// clear the identity matrix.
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	glTranslatef(axisX, axisY, axisZ);
	// Green color used to draw.
	glColor3f(0.0, 1.0, 0.0);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(radius, 20, 20);
	// Flush buffers to screen

	glFlush();
	
}

void reshapeFunc(int x, int y)
{
	if (y == 0 || x == 0) return;  //Nothing is visible then, so return
								   //Set a new projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Angle of view:40 degrees
	//Near clipping plane distance: 0.5
	//Far clipping plane distance: 20.0

	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  //Use the whole window for rendering
}


void idleFunc(void)
{
	redisplayFunc();
}

void initSphere(int argc, char **argv) {

	cargarCoordenadas(coordenadas);
	axisX = coordenadas[0][0];
	axisY = coordenadas[0][1];
	xRotated = coordenadas[0][3];
	yRotated = coordenadas[0][4];
	
	//Initialize GLUT
	glutInit(&argc, argv);
	//double buffering used to avoid flickering problem in animation
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// window size
	glutInitWindowSize(1280, 720);
	// create the window 
	WINDOW_ID = glutCreateWindow("Proyecto Programacion Imperativa | Anthony Segura Chaves - Jose Miguel Murillo");
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//Assign  the function used in events
	glutJoystickFunc(joystick, 25);
	glutDisplayFunc(redisplayFunc);
	glutReshapeFunc(reshapeFunc);
	glutIdleFunc(idleFunc);
	//Let start glut loop
	glutMainLoop();
}


