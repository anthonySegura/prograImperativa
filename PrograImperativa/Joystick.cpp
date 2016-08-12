#include <stdio.h>
#include <stdlib.h>
#include <GL\glut.h>

int UNO = 1;
int DOS = 2;
int TRES = 3;
int CUATRO = 4;
int ARRIBA = 5;
int ABAJO = 6;
int IZQUIERDA = 7;
int DERECHA = 8;
GLfloat xRotated = 0, yRotated = 0, zRotated = 0;

void joystick(unsigned int buttonmask, int x, int y, int z) {
	if (buttonmask & 0x1) {
		printf("Button 1 pressed\n");
		xRotated += 1;
	}
	else if (buttonmask & 0x4) {
		printf("Button 2 pressed\n");
		yRotated += 1;
	}
	else if (buttonmask & 0x2) {
		zRotated += 1;
	}

}