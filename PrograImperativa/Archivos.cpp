#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

struct coordenada {
	float axisX;
	float axisY;
	float axisZ;
	float esferaX;
	float esferaY;
	float esferaZ;
};

FILE * registroCoordenadas;

void guardarCoordenadas(float axisX, float axisY, float axisZ, float esferaX, float esferaY, float esferaZ) {
	struct coordenada * registro;
	registro = (struct coordenada *) malloc(sizeof(struct coordenada));
	registro->axisX = axisX;
	registro->axisY = axisY;
	registro->axisZ = axisZ;
	registro->esferaX = esferaX;
	registro->esferaY = esferaY;
	registro->esferaZ = esferaZ;

	registroCoordenadas = fopen("Coordenadas.dat", "w+");
	fwrite(registro , sizeof(struct coordenada) , 1 , registroCoordenadas);
	fclose(registroCoordenadas);
}


void verCoordenadas() {

	struct coordenada * buffer;
	buffer = (struct coordenada *) malloc(sizeof(struct coordenada));
	registroCoordenadas = fopen("Coordenadas.dat", "r");
	while (fread(buffer, sizeof(struct coordenada), 1, registroCoordenadas)) {
		printf("Mostrando coordenadas\nEje X : %f EjeY : %f Eje Z : %f EsferaX : %f Esfera Y : % Esfera Z : %\n", buffer->axisX, buffer->axisY, buffer->axisZ,
			buffer->esferaX , buffer->esferaY , buffer->esferaZ);
	}
	fclose(registroCoordenadas);
	getchar();
}

void cargarCoordenadas(float arreglo[][6]) {

	struct coordenada * buffer;
	buffer = (struct coordenada *) malloc(sizeof(struct coordenada));
	registroCoordenadas = fopen("Coordenadas.dat", "r");
	if (!registroCoordenadas) {
		printf("Error al leer el archivo\n");
		return;
	}
	int i = 0;
	while (fread((struct coordenada *)buffer, sizeof(struct coordenada), 1, registroCoordenadas)) {
		arreglo[i][0] = buffer->axisX;
		arreglo[i][1] = buffer->axisY;
		arreglo[i][2] = buffer->axisZ;
		arreglo[i][3] = buffer->esferaX;
		arreglo[i][4] = buffer->esferaY;
		arreglo[i][5] = buffer->esferaZ;
		i++;
	}
	fclose(registroCoordenadas);
}