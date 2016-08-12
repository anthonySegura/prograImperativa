#include <stdio.h>
#include <stdlib.h>
#include <GL\glut.h>

int UNO = 0x01;
int DOS = 2;
int TRES = 3;
int CUATRO = 4;
int ARRIBA = 5;
int ABAJO = 6;
int IZQUIERDA = 7;
int DERECHA = 8;
double axisX = 0.0, axisY = 0.0, axisZ = -4.5;
GLfloat xRotated = 0, yRotated = 0, zRotated = 0;

void joystick(unsigned int buttonmask, int x, int y, int z) {
	int *px = &x;
	if (buttonmask & 0x1) {
		printf("Button 1 pressed\n");
		yRotated += 1;
		axisX -= 0.01;
	}
	else if (buttonmask & 0x4) {
		yRotated -= 1;
		axisX += 0.01;
		
	}
	else if (buttonmask & 0x2) {
		
	}
}