/*
 * avion.h
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#ifndef HEADERS_AVION_H_
#define HEADERS_AVION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG_IDENTIFICADOR 8
#define LONG_MODELO 20


enum ESTADO_AVION{
	HANGAR,
	LISTO
};

typedef struct{
	char identificador[LONG_IDENTIFICADOR+1];
	char modelo[LONG_MODELO+1];
	int combustible;
	char estado;
}ST_AVION;




#endif /* HEADERS_AVION_H_ */
