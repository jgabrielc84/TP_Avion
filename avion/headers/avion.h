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


enum AVIONESTADO{
	AVION_HANGAR,
	AVION_LISTO_HANGAR,
	AVION_LISTO_DESPEGAR,
	AVION_DESPEGANDO,
	AVION_EN_VUELO,
	AVION_ESPERA_ATERRIZAR,
	AVION_ATERRIZANDO,
};

typedef struct{
	char identificador[LONG_IDENTIFICADOR+1];
	char modelo[LONG_MODELO+1];
	int combustible;
	enum AVIONESTADO estado;
}ST_AVION;


void inicializarST_AVION(ST_AVION * avion, char** argv);

void comprobarAvion(ST_AVION *avion);



#endif /* HEADERS_AVION_H_ */
