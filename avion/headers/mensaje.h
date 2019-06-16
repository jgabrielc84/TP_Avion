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
#include "../headers/avion.h"

#define LONG_MSG_SERV 100+1
#define LONG_COMBUSTIBLE 10+1
#define LONG_OPCIONAVION 1+1

void liberaBuffer();

void formatearMensaje(char *, const ST_AVION *, const int *);

#endif /* HEADERS_MENSAJE_H_ */
