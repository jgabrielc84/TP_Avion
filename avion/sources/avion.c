/* TP_avion
 * avion.c
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#include "../headers/avion.h"
#include "../headers/mensaje.h"


void inicializarAvion(ST_AVION * avion, char** argv){
	printf("*inicializarAvion*\n");
	int combustibleAvion = 0;
	memset(avion->modelo, '\0', LONG_MODELO);
	memset(avion->identificador, '\0', LONG_IDENTIFICADOR);
	avion->estado = AVION_HANGAR;
	avion->combustibleActual = 0;
	avion->combustibleMaximo=0;
	strcpy(avion->identificador, argv[1]);
	strcpy(avion->modelo, argv[2]);
	sscanf(argv[3], "%d", &combustibleAvion);
	avion->combustibleActual = combustibleAvion;
	avion->combustibleMaximo = combustibleAvion;
}

void comprobarAvion(ST_AVION * avion){
	printf("*comprobarAvion*\n");
	FILE * ptrArchivo;
	ST_AVION * avionAComprobar = malloc(sizeof(ST_AVION));

	if ((ptrArchivo = fopen("avion.bin","rb")) == NULL){
		printf("No se pudo abrir el archivo. Se crea archivo avion.bin\n");

		if((ptrArchivo = fopen("avion.bin","wb")) == NULL){
			printf("No se pudo crear el archivo.\n");
			exit(EXIT_FAILURE);
		}else{
			printf("%s", avion->modelo);  //BORRAR
			fwrite(avion, sizeof(ST_AVION), 1, ptrArchivo);
		}
	}else{
		fread(avionAComprobar, sizeof(ST_AVION), 1, ptrArchivo);
		if(strcmp(avion->identificador, avionAComprobar->identificador) ==0 && strcmp(avion->modelo, avionAComprobar->modelo) ==0){
		   printf("Los datos del avion son correctos.\n");
		   return;
		}
		else{
		   printf("Los datos del avion son incorrectos.\n");
		   exit(EXIT_FAILURE);
		}
	}
	fclose(ptrArchivo);
}

void mostrarEstado(enum AVIONESTADO estado){
	switch(estado){
	case AVION_HANGAR:
		printf("Estado: Hangar\n\n");
		break;
	case AVION_LISTO_HANGAR:
		printf("Estado: Listo / Hangar\n\n");
		break;
	case AVION_LISTO_DESPEGAR:
		printf("Estado: Listo / Despegar\n\n");
		break;
	case AVION_DESPEGANDO:
		printf("Estado: Despegando\n\n");
		break;
	case AVION_EN_VUELO:
		printf("Estado: En Vuelo\n\n");
		break;
	case AVION_ESPERA_ATERRIZAR:
		printf("Estado: Espera / Aterrizar\n\n");
		break;
	case AVION_ATERRIZANDO:
		printf("Estado: Aterrizando\n\n");
		break;
	}
}

void mostrarEstadoAvion(ST_AVION * avion, char * msjServidor){
	printf("*mostrarEstadoAvion*");

	mostrarMensaje(msjServidor);
	printf("Identificador: %s\n", avion->identificador );
	printf("Modelo: %s\n", avion->modelo );
	printf("Cantidad de combustible: %d\n", avion->combustibleActual);
	mostrarEstado(avion->estado);
}
