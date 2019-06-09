/*
 * mensaje.h
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#ifndef HEADERS_MENSAJE_H_
#define HEADERS_MENSAJE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG_ORIGEN 20
#define LONG_DESTINO 20
#define LONG_MENSAJE 50
#define LONG_MSG_SERV LONG_ORIGEN+LONG_DESTINO+LONG_MENSAJE+3
#define LONG_MSG_RECIBIDO 100

typedef struct{
	char origen[LONG_ORIGEN+1];
	char destino[LONG_DESTINO+1];
	char mensaje[LONG_MENSAJE+1];
}ST_MENSAJE;


void inicializarST_MENSAJE(ST_MENSAJE * mensaje);

void crearSTMensaje(ST_MENSAJE * msj, const char * ipOrigen, const char * ipDestino, const char * mensaje);

void codificarMensaje(char * msjAServidor, const ST_MENSAJE *msj);

#endif /* HEADERS_MENSAJE_H_ */
