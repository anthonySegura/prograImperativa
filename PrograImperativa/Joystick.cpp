#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL\glut.h>
#include <GLFW\glfw3.h>
#include "Archivos.h"

//Codigos de los botones del Joystick
int BORRAR_DATOS = 512;
int SALIR = 256;
int WINDOW_ID = 0;
//Ejes de la ventana
double axisX = 0.0, axisY = 0.0, axisZ = -4.5;
//Ejes de la esfera
GLfloat xRotated = 0, yRotated = 0, zRotated = 0;
//Coordenadas de los bordes de la pantalla para una pantalla de 1280x720
float bordeIzq = -2.330000;
float bordeDer =  2.330000;
float bordeSup = -1.100000;
float bordeInf =  1.100000;

GLdouble radio = 0.5;
//Arreglo de coordenadas
float puntos[50][6];

bool compare_float(float f1, float f2)
{
	return fabs(f1 - f2) < 1.0 / 1000000;
}

///Desplaza la esfera desde la posicion actual hasta la posicion (x,y)
void mover(float x, float y) {
	//Incrementa o decrementa los valores de los ejes hasta que coincidad con x , y
	while (!(compare_float(axisX , x)) || !(compare_float(axisY , y))) {
		if (axisX < x) {
			yRotated -= 0.1;
			axisX += 0.001;
		}
		else {
			yRotated += 0.1;
			axisX -= 0.001;
		}
		if (axisY < y) {
			xRotated += 0.1;
			axisY += 0.001;
		}
		else {
			xRotated -= 0.1;
			axisY -= 0.001;
		}
		//Se dibuja la esfera de nuevo.
		glMatrixMode(GL_MODELVIEW);		
		glClear(GL_COLOR_BUFFER_BIT);		
		glLoadIdentity();	
		glTranslatef(axisX, axisY, axisZ);		
		glColor3f(0.0, 1.0, 0.0);
		glRotatef(xRotated, 1.0, 0.0, 0.0);
		glRotatef(yRotated, 0.0, 1.0, 0.0);	
		glRotatef(zRotated, 0.0, 0.0, 1.0);
		glScalef(1.0, 1.0, 1.0);
		glutSolidSphere(radio, 20, 20);
		glFlush();
	}
}

///Mueve la esfera por las coordenadas del arreglo
void seguirCoordenadas(float coordenadas[][6] , int n) {
	float x = 0, y = 0;
	//Posiciona la esfera en la primera posicion del arreglo
	axisX = coordenadas[0][0];
	axisY = coordenadas[0][1];
	//La esfera avanza por las demas posiciones del arreglo
	for (int i = 1; i < n; i++) {
		x = coordenadas[i][0];
		y = coordenadas[i][1];
		mover(x, y);
	}
}

///Funcion para los eventos del joystic
void joystick(unsigned int buttonmask, int x, int y, int z) {
	
	int buttonCount;
	const unsigned char * buttons = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &buttonCount);
	//Mueve la esfera hacia la izquierda
	if (GLFW_PRESS == buttons[15]) {
		yRotated += 1;
		if(axisX > bordeIzq) axisX -= 0.01;
	}
	//Mueva la esfera hacia la derecha
	else if (GLFW_PRESS == buttons[13]) {
		yRotated -= 1;
		if(axisX < bordeDer) axisX += 0.01;
	}
	//Mueva la esfera hacia abajo
	else if (GLFW_PRESS == buttons[14]) {
		xRotated -= 1;
		if(axisY > bordeSup) axisY -= 0.01;
	}
	//Mueve la esfera hacia arriba
	else if (GLFW_PRESS == buttons[12]) {
		xRotated += 1;
		if(axisY < bordeInf)axisY += 0.01;
	}
	//Carga las coordenadas del archivo y muestra la animacion
	else if (GLFW_PRESS == buttons[3]) {
		int n = cargarCoordenadas(puntos);
		if (n > 0) seguirCoordenadas(puntos, n);
		else
			printf("No hay coordenadas guardadas\n");
	}
	//Guarda la posicion actual de la esfera y el valor de sus ejes en el archivo.
	else if (GLFW_PRESS == buttons[1]) {
		guardarCoordenadas(axisX, axisY, axisZ, (float)xRotated, (float)yRotated, (float)zRotated);
		printf("Coordenadas guardadas\n");
	}
	//Elimina el archivo de coordenadas.
	else if (buttonmask & BORRAR_DATOS) {
		borrarCoordenadas();
	}
	//Cierra la ventana.
	else if (buttonmask & SALIR) {
		glutDestroyWindow(WINDOW_ID);
	}

}