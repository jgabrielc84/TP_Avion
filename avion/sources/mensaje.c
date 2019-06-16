/*
 * mensaje.c
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#include "../headers/mensaje.h"



void liberaBuffer(){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

void formatearMensaje(char * msjServidor, const ST_AVION * avion, const int * opcion){
	char * combustibleAvion = malloc(sizeof(char)*LONG_COMBUSTIBLE);
	char * opcionAvion = malloc(sizeof(char)*LONG_OPCIONAVION);
	memset(combustibleAvion, '\0', LONG_COMBUSTIBLE);
	memset(opcionAvion, '\0', LONG_OPCIONAVION);

	sprintf(combustibleAvion, "%d", avion->combustible);
	sprintf(opcionAvion, "%d", *opcion);


	strcpy(msjServidor, avion->identificador);
	strcat(msjServidor, "|");
	strcat(msjServidor, avion->modelo);
	strcat(msjServidor, "|");
	strcat(msjServidor, combustibleAvion);
	strcat(msjServidor, "|");
	strcat(msjServidor, opcionAvion);
}
