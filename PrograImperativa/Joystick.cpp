#include <stdio.h>
#include <stdlib.h>
#include <GL\glut.h>
#include <math.h>

//Codigos de los botones del Joystick
int UNO = 1;
int DOS = 2;
int TRES = 4;
int CUATRO = 8;
int GUARDAR = 32;
int ANIMACION = 128;
int BORRAR_DATOS = 512;
int SALIR = 256;
int WINDOW_ID = 0;
double axisX = 0.0, axisY = 0.0, axisZ = -4.5;
//Ejes de la esfera
GLfloat xRotated = 0, yRotated = 0, zRotated = 0;
//Coordenadas de los bordes de la pantalla para una resolucion de 1280x720
float bordeIzq = -2.330000;
float bordeDer =  2.330000;
float bordeSup = -1.100000;
float bordeInf =  1.100000;

GLdouble radio = 0.5;

bool compare_float(float f1, float f2)
{
	return fabs(f1 - f2) < 1.0 / 10000000;
}


void mover(float x, float y) {

	while (!(compare_float(axisX , x)) || !(compare_float(axisY , y))) {
		if (axisX < x) {
			yRotated -= 0.2;
			axisX += 0.001;
		}
		else {
			yRotated += 0.2;
			axisX -= 0.001;
		}
		if (axisY < y) {
			xRotated += 0.2;
			axisY += 0.001;
		}
		else {
			xRotated -= 0.2;
			axisY -= 0.001;
		}
		printf("Eje x : %f Eje y %f\n", axisX, axisY);
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
		glutSolidSphere(radio, 20, 20);
		// Flush buffers to screen

		glFlush();
	}
}

void joystick(unsigned int buttonmask, int x, int y, int z) {

	if (buttonmask & UNO) {
		yRotated += 1;
		if(axisX > bordeIzq) axisX -= 0.01;
	}
	else if (buttonmask & TRES) {
		yRotated -= 1;
		if(axisX < bordeDer) axisX += 0.01;
	}
	else if (buttonmask & DOS) {
		xRotated -= 1;
		if(axisY > bordeSup) axisY -= 0.01;
	}
	else if (buttonmask & CUATRO) {
		xRotated += 1;
		if(axisY < bordeInf)axisY += 0.01;
	}
	else if (buttonmask & ANIMACION) {
		mover(0.000000, 0.000000);
	}
	
	else if (buttonmask & SALIR) {
		glutDestroyWindow(WINDOW_ID);
	}

	printf("Eje x : %f Eje y : %f\n", axisX, axisY);
	
}