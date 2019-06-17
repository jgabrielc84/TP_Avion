/* TP_avion
 * archivo.c
 *
 *  Created on: 2 jun. 2019
 *      Author: gabriel
 */


#include "../headers/archivo.h"

#define LONG_LINEALEIDA 30


void abrirArchivoConfigServ(FILE * ptrArchivoConfigServ){
	printf("*abrirArchivoConfigServ*\n");
	if((ptrArchivoConfigServ = fopen("config.txt", "r")) == NULL){
		printf("Error al abrir archivo\n");
		exit(EXIT_FAILURE);
	}else{
		printf("Archivo de configuracion abierto correctamente.\n");
	}
}

void leerIpPuertoDeArchivo(FILE * ptrArchivoConfigServ, char * ip, int * puerto){
	printf("*leerIpPuerto*\n");
	char * lineaLeida = malloc((sizeof(char))*LONG_LINEALEIDA);
	memset(lineaLeida, '\0', LONG_LINEALEIDA); //Se inicializa la variable

	fgets(lineaLeida, LONG_LINEALEIDA, ptrArchivoConfigServ);

	strtok(lineaLeida, "=");
	strcpy(ip, strtok(NULL, " "));
	*puerto = atoi(strtok(NULL, ";"));

	free(lineaLeida);
}
