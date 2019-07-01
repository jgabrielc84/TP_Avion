/* TP_avion
 * avion.h
 *
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#ifndef HEADERS_AVION_H_
#define HEADERS_AVION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG_IDENTIFICADOR 8+1			/**< El identificador no puede exceder los 8 caracteres */
#define LONG_MODELO 20+1				/**< El modelo no puede exceder los 20 caracteres */


enum AVIONESTADO{
	AVION_HANGAR,						/**< El avion ha sido registrado en la torre de control. */
	AVION_LISTO_HANGAR,					/**< El avion tiene el suficiente combustible para despegar. */
	AVION_LISTO_DESPEGAR,				/**< El avion ha pedido pista  y espera para usarla. */
	AVION_DESPEGANDO,					/**< El avion está usando la pista para despegar. */
	AVION_EN_VUELO,						/**< El avion se encuentra en vuelo. */
	AVION_ESPERA_ATERRIZAR,				/**< El avion esta en vuelo y ha pedido el uso de la pista. */
	AVION_ATERRIZANDO,					/**< El avion ha sido autorizado y está utilizando la pista para aterrizar.  */
};

/**
 * Se define la estructura del avion, con un identificador para poder ser registrado en torre de control,
 * un modelo para saber que tipo de avion es, su capacidad de combustible y un registro de la cantidad actual,
 * y una enumeracion de posibles estados en que se pueda encontrar.
 */
typedef struct{
	char identificador[LONG_IDENTIFICADOR];    /**< Codigo identificador unico del avion. */
	char modelo[LONG_MODELO];				   /**< Tipo de avion. */
	int combustibleActual;    					/**< Cantidad de combustible en tanque. */
	int combustibleMaximo;						/**< Capacidad maxima de combustible que el avion puede tener. */
	enum AVIONESTADO estado;					/**< Situacion actual del avion. */
}ST_AVION;


void inicializarAvion(ST_AVION *, char**);

void comprobarAvion(ST_AVION *);

void mostrarEstadoAvion(ST_AVION *, char *);


#endif /* HEADERS_AVION_H_ */
