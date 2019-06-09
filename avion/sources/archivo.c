/*
 * archivo.c
 *
 *  Created on: 2 jun. 2019
 *      Author: gabriel
 */


#include <stdio.h>
#include <stdlib.h>
#include "../headers/archivo.h"


void abrirArchivoConfigServ(FILE * ptrArchivoConfigServ){
	printf("abrirArchivoConfigServ\n");
	if((ptrArchivoConfigServ = fopen("config.txt", "r")) == NULL){
		printf("Error al abrir archivo\n");
		exit(EXIT_FAILURE);
	}else{
		printf("Archivo de configuracion abierto correctamente.\n\n");
	}
}
