/* TP_avion
 * consola.h
 *
 *  Created on: 9 jun. 2019
 *      Author: gabriel
 */

#ifndef HEADERS_CONSOLA_H_
#define HEADERS_CONSOLA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../headers/avion.h"
#include "../headers/mensaje.h"
#include "../headers/servidor.h"

enum MENUOPCION{
	MENU_SALIR_SISTEMA,						/**< Opcion para salir del menu de la consola */
	MENU_REGISTRAR_AVION,					/**< Envia una peticion al servidor para registrarse en torre de control */
	MENU_PEDIR_PISTA,						/**< Peticiona para usar la pista, según su estado actual para despegar o aterrizar */
	MENU_ESTADO_AVION						/**< Opcion para recibir el estado actual del avion */
};

void iniciarMenuAvion(ST_AVION *, char *, const int *, int *);

#endif /* HEADERS_CONSOLA_H_ */
