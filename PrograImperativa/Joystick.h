#ifndef JOYSTICK_H_INCLUDED
#define JOYSTICK_H_INCLUDED
#include <GL\glut.h>

extern int UNO;
extern int DOS;
extern int TRES;
extern int CUATRO;
extern int ARRIBA;
extern int ABAJO;
extern int IZQUIERDA;
extern int DERECHA;
extern double axisX, axisY, axisZ;
extern GLfloat xRotated, yRotated, zRotated;



void joystick(unsigned int buttonmask, int x, int y, int z);


#endif // JOYSTICK_H_INCLUDED