#include <stdio.h>
#include <stdlib.h>
#include <GL\glut.h>

int UNO = 1;
int DOS = 2;
int TRES = 4;
int CUATRO = 8;
double axisX = 0.0, axisY = 0.0, axisZ = -4.5;
//Ejes de la esfera
GLfloat xRotated = 0, yRotated = 0, zRotated = 0;
float bordeIzq = -2.330000;
float bordeDer =  2.330000;
float bordeSup = -1.100000;
float bordeInf =  1.100000;

void joystick(unsigned int buttonmask, int x, int y, int z) {
	int *px = &x;
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
	//printf("boton %d\n" , buttonmask);
}