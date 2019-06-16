/*
 * avion.c
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#include "../headers/avion.h"
#include "../headers/mensaje.h"


void inicializarST_AVION(ST_AVION * avion, char** argv){
	int combustibleAvion = 0;
	memset(avion->modelo, '\0', LONG_MODELO);
	memset(avion->identificador, '\0', LONG_IDENTIFICADOR);
	avion->estado = AVION_HANGAR;
	avion->combustible = 0;
	strcpy(avion->identificador, argv[1]);
	strcpy(avion->modelo, argv[2]);
	sscanf(argv[3], "%d", &combustibleAvion);
	avion->combustible = combustibleAvion;
	printf("%s\n", avion->identificador);
	printf("%s\n", avion->modelo);
	printf("%d\n", avion->combustible);

}



void comprobarAvion(ST_AVION *avion){
	FILE *archivo;
	ST_AVION * avionAComprobar = malloc(sizeof(ST_AVION));

	   if ((archivo = fopen("avion.bin","rb")) == NULL){
	       printf("No se pudo abrir el archivo. Se crea archivo.Nuevo avion");
	       if((archivo = fopen("avion.bin","wb")) == NULL){
	       	   printf("No se pudo crear el archivo.");
	       	   exit(EXIT_FAILURE);
	       }
	       else{
	    	   printf("%s", avion->modelo);
	    	   fwrite(avion, sizeof(ST_AVION), 1, archivo);
	       }
	   }

	   else{

		   fread(avionAComprobar, sizeof(ST_AVION), 1, archivo);
	       if(strcmp(avion->modelo, avionAComprobar->modelo) ==0 && strcmp(avion->identificador, avionAComprobar->identificador) ==0){
	    	   printf("Los datos del avion son correctos");
	       }
	       else{
	    	   printf("Los datos del avion son incorrectos");
	       }
	   }
}
