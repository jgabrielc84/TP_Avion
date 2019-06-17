/* TP_avion
 * avion.c
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#include "../headers/avion.h"
#include "../headers/mensaje.h"


void inicializarAvion(ST_AVION * avion, char** argv){
	printf("*inicializarAvion*\n");
	int combustibleAvion = 0;
	memset(avion->modelo, '\0', LONG_MODELO);
	memset(avion->identificador, '\0', LONG_IDENTIFICADOR);
	avion->estado = AVION_HANGAR;
	avion->combustible = 0;
	strcpy(avion->identificador, argv[1]);
	strcpy(avion->modelo, argv[2]);
	sscanf(argv[3], "%d", &combustibleAvion);
	avion->combustible = combustibleAvion;
	printf("%s\n", avion->identificador); //BORRAR
	printf("%s\n", avion->modelo); //BORRAR
	printf("%d\n", avion->combustible); //BORRAR
}



void comprobarAvion(ST_AVION * avion){
	printf("*comprobarAvion*\n");
	FILE * ptrArchivo;
	ST_AVION * avionAComprobar = malloc(sizeof(ST_AVION));

	if ((ptrArchivo = fopen("avion.bin","rb")) == NULL){
		printf("No se pudo abrir el archivo. Se crea archivo avion.bin\n");

		if((ptrArchivo = fopen("avion.bin","wb")) == NULL){
			printf("No se pudo crear el archivo.\n");
			exit(EXIT_FAILURE);
		}else{
			printf("%s", avion->modelo);
			fwrite(avion, sizeof(ST_AVION), 1, ptrArchivo);
		}
	}else{
		fread(avionAComprobar, sizeof(ST_AVION), 1, ptrArchivo);
		if(strcmp(avion->identificador, avionAComprobar->identificador) ==0 && strcmp(avion->modelo, avionAComprobar->modelo) ==0){
		   printf("Los datos del avion son correctos.\n");
		}
		else{
		   printf("Los datos del avion son incorrectos.\n");
		   exit(EXIT_FAILURE);
		}
	}
}
