
#include <GL\glut.h>
#include "Joystick.h"
#include "Archivos.h"


//Radio de la esfera
GLdouble radius = 0.5;
//Arreglo con las posiciones cargadas en el archivo
float coordenadas[50][6];


///Funcion para dibujar en la ventana
void redisplayFunc(void)
{
	glMatrixMode(GL_MODELVIEW);
	//Limpia la ventana
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//Giro de la esfera sobre sus ejes
	glTranslatef(axisX, axisY, axisZ);
	//Color : Verde
	glColor3f(0.0, 1.0, 0.0);
	//Rotacion sobre el eje x de la esfera
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	//Rotacion sobre el eje y
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// Rotacion sobre el eje z
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	glScalef(1.0, 1.0, 1.0);
	glutSolidSphere(radius, 20, 20);

	glFlush();
	
}


void reshapeFunc(int x, int y)
{
	if (y == 0 || x == 0) return;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);
}

///Funcion para actualizar el contenido de la ventana
void idleFunc(void)
{
	redisplayFunc();
}


///Crea la ventana y la esfera
void initGraphics(int argc, char **argv) {

	int ultima = cargarCoordenadas(coordenadas) - 1;
	axisX = coordenadas[ultima][0];
	axisY = coordenadas[ultima][1];
	xRotated = coordenadas[ultima][3];
	yRotated = coordenadas[ultima][4];
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(1280, 720);
	//Al crear la ventana se le pasa el ID al joystick para cerrarla despues
	WINDOW_ID = glutCreateWindow("Proyecto Programacion Imperativa | Anthony Segura Chaves - Jose Miguel Murillo");
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);	
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//Eventos de Glut
	//Evento del joystick, se actualiza cada 25 milisegundos
	glutJoystickFunc(joystick, 25);
	glutDisplayFunc(redisplayFunc);
	glutReshapeFunc(reshapeFunc);
	glutIdleFunc(idleFunc);
	glutMainLoop();
}


