/* TP_avion
 * archivo.h
 *
 *  Created on: 2 jun. 2019
 *      Author: gabriel
 */

#ifndef HEADERS_ARCHIVO_H_
#define HEADERS_ARCHIVO_H_

#include <stdio.h>
#include <stdlib.h>
#include "../headers/mensaje.h"


void comprobarParametrosInicio(int * argc);

FILE * abrirArchivo(const char * nombreArchivo, const char * modoApertura);

void leerIpPuertoDeArchivo(FILE *, char *, int *);

#endif /* HEADERS_ARCHIVO_H_ */
