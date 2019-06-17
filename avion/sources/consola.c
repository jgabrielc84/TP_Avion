/* TP_avion
 * consola.c
 *
 *  Created on: 9 jun. 2019
 *      Author: gabriel
 */

#include "../headers/consola.h"

void mostrarMenuPrincipal(){
	printf("\t-Menu AVION-\n\n");
	printf("[1] - Registrar en torre de control\n");
	printf("[2] - Pedir pista\n");
	printf("[3] - Estado\n");
	printf("[0] - Salir\n\n");
	printf("\tOpcion: ");
}

void iniciaMenuAvion(ST_AVION * avion, char * msjServidor, const int * servidorTorreControl, const int * bytesRecibidos){
	int opcion = -1;

	while(opcion != MENU_SALIR_SISTEMA && opcion != MENU_REGISTRAR_AVION && opcion != MENU_PEDIR_PISTA && opcion != MENU_ESTADO_AVION){
		system("clear");
		mostrarMenuPrincipal();
		scanf("%d", &opcion);

		switch(opcion){
		case MENU_REGISTRAR_AVION:
			registrarAvion(msjServidor, avion, &opcion, servidorTorreControl);
			//recibirMensaje(&bytesRecibidos, &servidorTorreControl, msjServidor);
			//mostrarMensaje(msjServidor);
			opcion = -1;
			break;
		case MENU_PEDIR_PISTA:
			//pedirPista();
			opcion = -1;
			break;
		case MENU_ESTADO_AVION:
			pedirEstadoAvion(msjServidor, avion, servidorTorreControl);
			opcion = -1;
			break;
		case MENU_SALIR_SISTEMA:
			system("clear");
			printf("Que tenga un buen dia!\n\n");
			break;
		default:
			printf("\nLa opcion elegida es incorrecta!\n\n");
			sleep(3);
			break;
		}
	}
}
