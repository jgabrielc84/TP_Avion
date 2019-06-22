/* TP_avion
 * mensaje.c
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#include "../headers/mensaje.h"


void liberarBuffer(){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

void inicializarMsjServidor(char * msjServidor){
	printf("*inicializarMsjServidor*\n");

	memset(msjServidor, '\0', LONG_MSJ_SERV);
}

void concatenarMsjServidor(char * msjServidor, const ST_AVION * avion,const char * combustibleActAvion, const char * combustibleMaxAvion, const char * estadoAvion, const char * opcionAvion){
	printf("*concatenarMsjServidor*\n");

	strcpy(msjServidor, avion->identificador);
	strcat(msjServidor, "|");
	strcat(msjServidor, avion->modelo);
	strcat(msjServidor, "|");
	strcat(msjServidor, combustibleActAvion);
	strcat(msjServidor, "|");
	strcat(msjServidor, combustibleMaxAvion);
	strcat(msjServidor, "|");
	strcat(msjServidor, estadoAvion);
	strcat(msjServidor, "|");
	strcat(msjServidor, opcionAvion);
}

void formatearMensaje(char * msjServidor, const ST_AVION * avion, const int * opcion){
	printf("*formatearMensaje*\n");

	char * combustibleActAvion = malloc(sizeof(char)*LONG_COMBUSTIBLEAVION); // Crear variables
	char * combustibleMaxAvion = malloc(sizeof(char)*(LONG_COMBUSTIBLEAVION));
	char * estadoAvion = malloc(sizeof(char)*LONG_ESTADOAVION);
	char * opcionAvion = malloc(sizeof(char)*LONG_OPCIONAVION);

	memset(combustibleActAvion, '\0', LONG_COMBUSTIBLEAVION); // Inicializar Variables
	memset(combustibleMaxAvion, '\0', LONG_COMBUSTIBLEAVION);
	memset(estadoAvion, '\0', LONG_ESTADOAVION);
	memset(opcionAvion, '\0', LONG_OPCIONAVION);
	inicializarMsjServidor(msjServidor);

	sprintf(combustibleActAvion, "%d", avion->combustibleActual); // Copiar valores a char
	sprintf(combustibleMaxAvion, "%d", avion->combustibleMaximo);
	sprintf(estadoAvion, "%d", avion->estado);
	sprintf(opcionAvion, "%d", *opcion);

	concatenarMsjServidor(msjServidor, avion, combustibleActAvion, combustibleMaxAvion, estadoAvion, opcionAvion);

	free(combustibleActAvion); // Liberar punteros
	free(combustibleMaxAvion);
	free(estadoAvion);
	free(opcionAvion);
}

void parsearMensaje(ST_AVION * avion, char * msjServidor){
	printf("*parsearMensaje*\n\n");

	char * linea = malloc(sizeof(char)*LONG_MSJ_SERV);

	memset(linea, '\0', LONG_MSJ_SERV);
	strcpy(linea, msjServidor);
	inicializarMsjServidor(msjServidor);

	strcpy(avion->identificador, strtok(linea, "|"));
	strcpy(avion->modelo, strtok(NULL, "|"));
	avion->combustibleActual = atoi(strtok(NULL, "|"));
	avion->combustibleMaximo = atoi(strtok(NULL, "|"));
	avion->estado = atoi(strtok(NULL, "|"));
	strcpy(msjServidor, strtok(NULL, "\0"));
}

void mostrarMensaje(char * msjServidor){
	printf("*mostrarMensaje*\n");

	printf("Mensaje recibido: %s\n", msjServidor);
}
