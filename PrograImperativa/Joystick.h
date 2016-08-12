#ifndef JOYSTICK_H_INCLUDED
#define JOYSTICK_H_INCLUDED
extern int UNO;
extern int DOS;
extern int TRES;
extern int CUATRO;
extern int ARRIBA;
extern int ABAJO;
extern int IZQUIERDA;
extern int DERECHA;

void getButtonPressed(int * button);
int joystickPresent();


#endif // JOYSTICK_H_INCLUDED