#include <stdio.h>
#include <stdlib.h>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Joystick.h"

int main() {

	if (glfwInit() == false) {
		printf("Error al cargar GLFW\n");
		return -1;
	}

	//Configuracion de la ventana
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR , 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow * window;
	window = glfwCreateWindow(640, 480, "Ventana de Prueba", NULL, NULL);
	if (!window) {
		printf("Error al iniciar la ventana");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true;

	if (glewInit() != GLEW_OK) {
		printf("Error al cargar GLEW\n");
		glfwTerminate();
		return -1;
	}

	do {

		if (joystickPresent() == 1) {
			int buttonPressed;
			getButtonPressed(&buttonPressed);
			if (buttonPressed == UNO) {
				printf("button 1 pressed\n");
			}
			else if (buttonPressed == DOS) {
				printf("button 2 pressed\n");
			}
			else if (buttonPressed == TRES) {
				printf("button 3 pressed\n");
			}
			else if (buttonPressed == CUATRO) {
				printf("button 4 pressed\n");
			}
			else if (buttonPressed == ARRIBA) {
				printf("up\n");
			}
			else if (buttonPressed == ABAJO) {
				printf("down\n");
			}
			else if (buttonPressed == DERECHA) {
				printf("right\n");
			}
			else if (buttonPressed == IZQUIERDA) {
				printf("left\n");
			}
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
		
	} while (!glfwWindowShouldClose(window));

	return 0;
}