/*
 * mensaje.c
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#include "../headers/mensaje.h"


void inicializarST_MENSAJE(ST_MENSAJE * mensaje){
	memset(mensaje->origen, '\0', LONG_ORIGEN+1);
	memset(mensaje->destino, '\0', LONG_DESTINO+1);
	memset(mensaje->mensaje, '\0', LONG_MENSAJE+1);
}

void crearSTMensaje(ST_MENSAJE * msj, const char * ipOrigen, const char * ipDestino, const char * mensaje){
	strcpy(msj->origen, ipOrigen);
	strcpy(msj->destino, ipDestino);
	strcpy(msj->mensaje, mensaje);
}

void codificarMensaje(char * msjAServidor, const ST_MENSAJE *msj){
	strcpy(msjAServidor, msj->origen);
	strcat(msjAServidor, ";");
	strcat(msjAServidor, msj->destino);
	strcat(msjAServidor, ";");
	strcat(msjAServidor, msj->mensaje);
}
