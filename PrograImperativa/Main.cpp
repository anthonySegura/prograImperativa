#include <stdio.h>
#include <stdlib.h>
#include <GLFW\glfw3.h>

int main() {

	if (glfwInit() == false) {
		printf("Error al cargar GLFW");
		return -1;
	}

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

	do {
		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (!glfwWindowShouldClose(window));

	return 0;
}