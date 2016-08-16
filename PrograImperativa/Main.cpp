#include <stdio.h>
#include <GLFW\glfw3.h>
#include "Graphics.h"


int main(int argc, char **argv)
{
	if (glfwInit() == false) {
		printf("Error al inicializar Glfw");
	}

	initGraphics(argc , argv);
	return 0;
} 