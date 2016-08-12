#ifndef JOYSTICK_H_INCLUDED
#define JOYSTICK_H_INCLUDED
#include <GL\glut.h>

extern int WINDOW_ID;
extern double axisX, axisY, axisZ;
extern GLfloat xRotated, yRotated, zRotated;

void joystick(unsigned int buttonmask, int x, int y, int z);


#endif // JOYSTICK_H_INCLUDED