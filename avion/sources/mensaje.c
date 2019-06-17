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
	memset(msjServidor, '\0', LONG_MSJ_SERV);
}

void concatenarMsjServidor(char * msjServidor, const ST_AVION * avion,const char * combustibleActAvion, const char * combustibleMaxAvion, const char * estadoAvion, const char * opcionAvion){
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
	char * combustibleActAvion = malloc(sizeof(char)*LONG_COMBUSTIBLEAVION);
	char * estadoAvion = malloc(sizeof(char)*LONG_ESTADOAVION);
	char * opcionAvion = malloc(sizeof(char)*LONG_OPCIONAVION);
	char * combustibleMaxAvion = malloc(sizeof(char)*(LONG_COMBUSTIBLEAVION));
	memset(combustibleActAvion, '\0', LONG_COMBUSTIBLEAVION);
	memset(combustibleMaxAvion, '\0', LONG_COMBUSTIBLEAVION);
	memset(estadoAvion, '\0', LONG_ESTADOAVION);
	memset(opcionAvion, '\0', LONG_OPCIONAVION);
	inicializarMsjServidor(msjServidor);

	sprintf(combustibleActAvion, "%d", avion->combustibleActual);
	sprintf(combustibleMaxAvion, "%d", avion->combustibleMaximo);

	sprintf(estadoAvion, "%d", avion->estado);
	sprintf(opcionAvion, "%d", *opcion);

	concatenarMsjServidor(msjServidor, avion, combustibleActAvion, combustibleMaxAvion, estadoAvion, opcionAvion);
}

void mostrarMensaje(char * msjServidor){
	printf("Mensaje recibido:\n\n %s\n", msjServidor);
}
