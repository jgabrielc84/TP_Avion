/* TP_avion
 * consola.c
 *
 *  Created on: 9 jun. 2019
 *      Author: gabriel
 */

#include "../headers/consola.h"
#include "../headers/mensaje.h"

void mostrarMenuPrincipal(){
	printf("\t-Menu AVION-\n\n");
	printf("[1] - Registrar en torre de control\n");
	printf("[2] - Pedir pista\n");
	printf("[3] - Estado\n");
	printf("[0] - Salir\n\n");
	printf("\tOpcion: ");
}

void iniciarMenuAvion(ST_AVION * avion, char * msjServidor, const int * servidorTorreControl, int * bytesRecibidos){
	int * opcion = malloc(sizeof(int));
	*opcion = -1;
	system("clear");
	while(*opcion != MENU_SALIR_SISTEMA && *opcion != MENU_REGISTRAR_AVION && *opcion != MENU_PEDIR_PISTA && *opcion != MENU_ESTADO_AVION){
		mostrarMenuPrincipal();
		scanf("%d", opcion);
		liberarBuffer();

		switch(*opcion){
		case MENU_REGISTRAR_AVION:
			registrarAvion(msjServidor, avion, opcion, servidorTorreControl);
			recibirMensaje(bytesRecibidos, servidorTorreControl, msjServidor);
			parsearMensaje(avion, msjServidor);
			system("clear");
			mostrarMensaje(msjServidor);
			*opcion = -1;
			break;
		case MENU_PEDIR_PISTA:
			//pedirPista();
			recibirMensaje(bytesRecibidos, servidorTorreControl, msjServidor);
			parsearMensaje(avion, msjServidor);
			system("clear");
			mostrarMensaje(msjServidor);
			*opcion = -1;
			break;
		case MENU_ESTADO_AVION:
			pedirEstadoAvion(msjServidor, avion, opcion, servidorTorreControl);
			recibirMensaje(bytesRecibidos, servidorTorreControl, msjServidor);
			parsearMensaje(avion, msjServidor);
			system("clear");
			mostrarEstadoAvion(avion, msjServidor);
			*opcion = -1;
			break;
		case MENU_SALIR_SISTEMA:
			system("clear");
			printf("Que tenga un buen dia!\n\n");
			break;
		default:
			printf("\nLa opcion elegida es incorrecta!\n\n");
			sleep(1);
			break;
		}
	}
}
