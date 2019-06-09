/*
 * consola.c
 *
 *  Created on: 9 jun. 2019
 *      Author: gabriel
 */

#include "../headers/consola.h"
#include "../headers/avion.h"


void iniciaMenu(){
	int opcion = -1;

	system("clear");

	while(opcion != SALIR_SISTEMA && opcion != ALTA_AVION && opcion != REGISTRAR_AVION && opcion != PEDIR_PISTA && opcion != ESTADO_AVION){
		printf("\tBienvenido al sistema AVION!\n\n");
		printf("[1] - Alta de avion\n");
		printf("[2] - Registrar en torre de control\n");
		printf("[3] - Pedir pista\n");
		printf("[4] - Estado\n");
		printf("[0] - Salir\n\n");
		printf("\tOpcion: ");
		scanf("%d", &opcion);

		switch(opcion){
		case ALTA_AVION:
			//altaAvion();
			break;
		case REGISTRAR_AVION:
			//registracionTorreControl();
			break;
		case PEDIR_PISTA:
			//pedirPista();
			break;
		case ESTADO_AVION:
			//estadoAvion();
			break;
		case SALIR_SISTEMA:
			system("clear");
			printf("Que tenga un buen dia!\n\n");
			break;
		default:
			printf("\nLa opcion elegida es incorrecta!\n\n");
			sleep(3);
			system("clear");
			break;
		}
	}
}
