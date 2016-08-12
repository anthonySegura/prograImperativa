
#include <GLFW\glfw3.h>

int UNO = 1;
int DOS = 2;
int TRES = 3;
int CUATRO = 4;
int ARRIBA = 5;
int ABAJO = 6;
int IZQUIERDA = 7;
int DERECHA = 8;

/*
	Detecta si el Joystick esta conectado
	Retorna 1 si esta conectado
*/
int joystickPresent() {
	return glfwJoystickPresent(GLFW_JOYSTICK_1);
}

/*
	Obtiene el valor del boton presionado
*/
void getButtonPressed(int * button) {
	int buttonCount;
	//Se obtiene un arreglo con los botones disponibles
	const unsigned char * buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
	if (GLFW_PRESS == buttons[0]) {
		*button = UNO;
	}
	else if (GLFW_PRESS == buttons[1]) {
		*button = DOS;
	}
	else if (GLFW_PRESS == buttons[2]) {
		*button = TRES;
	}
	else if (GLFW_PRESS == buttons[3]) {
		*button = CUATRO;
	}
	else if (GLFW_PRESS == buttons[12]) {
		*button = ARRIBA;
	}
	else if (GLFW_PRESS == buttons[13]) {
		*button = DERECHA;
	}
	else if (GLFW_PRESS == buttons[14]) {
		*button = ABAJO;
	}
	else if (GLFW_PRESS == buttons[15]) {
		*button = IZQUIERDA;
	}

}
