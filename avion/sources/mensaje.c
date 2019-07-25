/* TP_avion
 * mensaje.c
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#include "../headers/mensaje.h"

/**
 *
 */
void liberarBuffer(){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}

/**
 * Limpia el parametro recibido por referencia
 * @param msjServidor
 */
void inicializarMsjServidor(char * msjServidor){
	printf("*inicializarMsjServidor*\n");

	memset(msjServidor, '\0', LONG_MSJ_SERV);
}

/**
 * Recibe la estructura del avion y datos del mismo
 * Recibe un char* por referencia en el cual se concatenan estos datos para ser enviados al Servidor
 * @param msjServidor, avion, combustibleActAvion, combustibleMaxAvcion, estadoAvion, opcionAvion
 */
void concatenarMsjServidor(char * msjServidor, const ST_AVION * avion,const char * combustibleActAvion, const char * combustibleMaxAvion, const char * estadoAvion, const char * opcionAvion){
	printf("*concatenarMsjServidor*\n");

	strcpy(msjServidor, avion->identificador);
	strcat(msjServidor, "|");
	strcat(msjServidor, avion->modelo);
	strcat(msjServidor, "|");
	strcat(msjServidor, combustibleActAvion);
	strcat(msjServidor, "|");
	strcat(msjServidor, combustibleMaxAvion);
	strcat(msjServidor, "|");
	strcat(msjServidor, estadoAvion);
	strcat(msjServidor, "|");
	strcat(msjServidor, opcionAvion);
}

/**
 * Crea punteros de variables de ST_AVION con sus correspondientes reservas de memoria,
 * Rellena esas variables con los datos de la ST_AVION recibida. Llama a concatenarMsjServidor y libera punteros.
 * @param msjServidor, avion, opcion
 */
void formatearMensaje(char * msjServidor, const ST_AVION * avion, const int * opcion){
	printf("*formatearMensaje*\n");

	char * combustibleActAvion = malloc(sizeof(char)*LONG_COMBUSTIBLEAVION); // Crear variables
	char * combustibleMaxAvion = malloc(sizeof(char)*(LONG_COMBUSTIBLEAVION));
	char * estadoAvion = malloc(sizeof(char)*LONG_ESTADOAVION);
	char * opcionAvion = malloc(sizeof(char)*LONG_OPCIONAVION);

	memset(combustibleActAvion, '\0', LONG_COMBUSTIBLEAVION); // Inicializar Variables
	memset(combustibleMaxAvion, '\0', LONG_COMBUSTIBLEAVION);
	memset(estadoAvion, '\0', LONG_ESTADOAVION);
	memset(opcionAvion, '\0', LONG_OPCIONAVION);
	inicializarMsjServidor(msjServidor);

	sprintf(combustibleActAvion, "%d", avion->combustibleActual); // Copiar valores a char
	sprintf(combustibleMaxAvion, "%d", avion->combustibleMaximo);
	sprintf(estadoAvion, "%d", avion->estado);
	sprintf(opcionAvion, "%d", *opcion);

	concatenarMsjServidor(msjServidor, avion, combustibleActAvion, combustibleMaxAvion, estadoAvion, opcionAvion);

	free(combustibleActAvion); // Liberar punteros
	free(combustibleMaxAvion);
	free(estadoAvion);
	free(opcionAvion);
}

/**
 * Recibe el mensaje del Servidor, el cual separa y toma cada dato para ser guardado en
 * la variable correspondiente dentro de la estructura del avion recibida por referencia
 * @param avion, msjServidor
 */
void parsearMensaje(ST_AVION * avion, char * msjServidor){
	printf("*parsearMensaje*\n");

	char * linea = malloc(sizeof(char)*LONG_MSJ_SERV);

	memset(linea, '\0', LONG_MSJ_SERV);
	strcpy(linea, msjServidor);
	inicializarMsjServidor(msjServidor);

	strcpy(avion->identificador, strtok(linea, "|"));
	strcpy(avion->modelo, strtok(NULL, "|"));
	avion->combustibleActual = atoi(strtok(NULL, "|"));
	avion->combustibleMaximo = atoi(strtok(NULL, "|"));
	avion->estado = atoi(strtok(NULL, "|"));
	strcpy(msjServidor, strtok(NULL, "\0"));
}

/**
 * Imprime en pantalla el mensaje recibido del Servidor sin parsear.
 * @param msjServidor
 */
void mostrarMensaje(char * msjServidor){
	printf("*mostrarMensaje*\n");

	printf("Mensaje recibido: %s\n", msjServidor);
}
