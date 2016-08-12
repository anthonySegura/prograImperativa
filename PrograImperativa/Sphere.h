#ifndef SPHERE_H_INCLUDED
#define SPHERE_H_INCLUDED
#include <GL\glut.h>

extern GLdouble radius;

void redisplayFunc(void);
void reshapeFunc(int x, int y);
void idleFunc(void);
void initSphere(int argc , char **argv);

#endif // SPHERE_H_INCLUDED
