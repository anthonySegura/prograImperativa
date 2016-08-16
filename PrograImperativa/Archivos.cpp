#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

struct registro {
	float axisX;
	float axisY;
	float axisZ;
	float esferaX;
	float esferaY;
	float esferaZ;
};

//Puntero al archivo
FILE * registroCoordenadas;


void guardarCoordenadas(float axisX, float axisY, float axisZ, float esferaX, float esferaY, float esferaZ) {
	struct registro * registro;
	registro = (struct registro *) malloc(sizeof(struct registro));
	registro->axisX = axisX;
	registro->axisY = axisY;
	registro->axisZ = axisZ;
	registro->esferaX = esferaX;
	registro->esferaY = esferaY;
	registro->esferaZ = esferaZ;

	registroCoordenadas = fopen("Coordenadas.dat", "a+");
	fwrite(registro , sizeof(struct registro) , 1 , registroCoordenadas);
	fclose(registroCoordenadas);
}


void verCoordenadas() {

	struct registro * buffer;
	buffer = (struct registro *) malloc(sizeof(struct registro));
	registroCoordenadas = fopen("Coordenadas.dat", "r");
	while (fread(buffer, sizeof(struct registro), 1, registroCoordenadas)) {
		printf("Mostrando coordenadas\nEje X : %f EjeY : %f Eje Z : %f EsferaX : %f Esfera Y : % Esfera Z : %\n", buffer->axisX, buffer->axisY, buffer->axisZ,
			buffer->esferaX , buffer->esferaY , buffer->esferaZ);
	}
	fclose(registroCoordenadas);
}

//Elimina el archivo
void borrarCoordenadas() {
	if (remove("Coordenadas.dat") != 0) {
		printf("No se pudo borrar los datos\n");
	}
	else {
		printf("Datos Eliminados\n");
	}
}

//Carga todas las coordenadas almacenadas en el archivo en un arreglo
//Retorna el numero de coordenadas guardadas en el archivo
int cargarCoordenadas(float arreglo[][6]) {

	struct registro * buffer;
	buffer = (struct registro *) malloc(sizeof(struct registro));
	registroCoordenadas = fopen("Coordenadas.dat", "r");
	if (!registroCoordenadas) {
		printf("Aun no se han guardado coordenadas\n");
		return -1;
	}
	int i = 0;
	while (fread((struct registro *)buffer, sizeof(struct registro), 1, registroCoordenadas)) {
		arreglo[i][0] = buffer->axisX;
		arreglo[i][1] = buffer->axisY;
		arreglo[i][2] = buffer->axisZ;
		arreglo[i][3] = buffer->esferaX;
		arreglo[i][4] = buffer->esferaY;
		arreglo[i][5] = buffer->esferaZ;
		i++;
	}
	fclose(registroCoordenadas);
	return i;
}