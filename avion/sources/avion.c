/* TP_avion
 * avion.c
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#include "../headers/avion.h"
#include "../headers/mensaje.h"

#define TRUE 1
#define FALSE 0

/**
 * Recibe la estructura del avion, la limpia y la inicializa con los datos pasados por linea de comando
 * @param avion, argv
 */
void inicializarAvion(ST_AVION * avion, char** argv){
	printf("*inicializarAvion*\n");
	int combustibleAvion = 0;
	memset(avion->modelo, '\0', LONG_MODELO);
	memset(avion->identificador, '\0', LONG_IDENTIFICADOR);
	avion->combustibleActual = 0;
	avion->combustibleMaximo=0;
	avion->estado = AVION_HANGAR;
	strcpy(avion->identificador, argv[1]);
	strcpy(avion->modelo, argv[2]);
	sscanf(argv[3], "%d", &combustibleAvion);
	avion->combustibleActual = combustibleAvion;
	avion->combustibleMaximo = combustibleAvion;
}

/**
 * Abre el archivo avion.bin o lo crea en su defecto.
 * Registra los datos del avion o chequea si coinciden con los datos del archivo.
 * Comprueba que una terminal solo pueda registrar un avion
 *@param avion
*/
void comprobarAvion(ST_AVION * avion){
	printf("*comprobarAvion*\n");
	FILE * ptrArchivo;
	ST_AVION * avionAComprobar = malloc(sizeof(ST_AVION));
	int encontrado = FALSE;

	if ((ptrArchivo = fopen("avion.bin","rb")) == NULL){
		printf("No se pudo abrir el archivo. Se procede a crea archivo avion.bin\n");

		if((ptrArchivo = fopen("avion.bin","wb")) == NULL){
			printf("No se pudo crear el archivo.\n");
			exit(EXIT_FAILURE);
		}else{
			printf("Archivo avion.bin creado correctamente.\nVelva a iniciar.");
			exit(EXIT_FAILURE);
		}
	}
	fseek(ptrArchivo, 0, SEEK_SET);
	fread(avionAComprobar, sizeof(ST_AVION), 1, ptrArchivo);
	while(!feof(ptrArchivo) && encontrado == FALSE){
		if(strcmp(avion->identificador, avionAComprobar->identificador) == 0){
		   encontrado = TRUE;
		}
		fread(avionAComprobar, sizeof(ST_AVION), 1, ptrArchivo);
	}
	if(!feof(ptrArchivo) && encontrado == TRUE){
		printf("Los datos del avion son correctos.\n");
		printf("%s", avion->identificador);  //BORRAR
	}else{
		fseek(ptrArchivo, 0, SEEK_SET);
		fwrite(avion, sizeof(ST_AVION), 1, ptrArchivo);
		printf("Los datos del avion se ingresaron al archivo.\n");
		printf("%s", avion->identificador);  //BORRAR
	}

	fclose(ptrArchivo);
}

/**
 * Recibe el estado del avion y lo imprime en pantalla con un formato legible para el usuario
 * @param estado
 */
void mostrarEstado(enum AVIONESTADO estado){
	switch(estado){
	case AVION_HANGAR:
		printf("Estado: HANGAR\n\n");
		break;
	case AVION_LISTO_HANGAR:
		printf("Estado: LISTO / HANGAR\n\n");
		break;
	case AVION_LISTO_DESPEGAR:
		printf("Estado: LISTO / DESPEGAR\n\n");
		break;
	case AVION_DESPEGANDO:
		printf("Estado: DESPEGANDO\n\n");
		break;
	case AVION_EN_VUELO:
		printf("Estado: EN VUELO\n\n");
		break;
	case AVION_ESPERA_ATERRIZAR:
		printf("Estado: ESPERA / ATERRIZAR\n\n");
		break;
	case AVION_ATERRIZANDO:
		printf("Estado: ATERRIZANDO\n\n");
		break;
	}
}

/**
 * Imprime en pantalla el mensaje del Servidor y el estado del avion: id, modelo, combustible.
 * @param avion, msjServidor
 */
void mostrarEstadoAvion(ST_AVION * avion, char * msjServidor){
	printf("*mostrarEstadoAvion*\n");

	mostrarMensaje(msjServidor);
	printf("Identificador: %s\n", avion->identificador );
	printf("Modelo: %s\n", avion->modelo );
	printf("Combustible actual: %d\n", avion->combustibleActual);
	mostrarEstado(avion->estado);
}
