/*
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

enum ESTADOAVION{
	SALIR_SISTEMA,
	ALTA_AVION,
	REGISTRAR_AVION,
	PEDIR_PISTA,
	ESTADO_AVION
};

void iniciaMenu();

#endif /* HEADERS_CONSOLA_H_ */
