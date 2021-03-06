/*
 ============================================================================
 Name        : avion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : avion in C, tp_aeropuerto
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "../headers/servidor.h"
#include "../headers/mensaje.h"
#include "../headers/avion.h"


int main() {
	//Se crea un servidor con los siguientes datos:
	struct sockaddr_in direccionServidor = crearServidor("127.0.0.1", "8080");
	//direccionServidor = crearServidor("127.0.0.1", "8080");

	//se pide un socket que devuelve un valor
	int servidorTorreControl = socket(AF_INET, SOCK_STREAM, 0);

	if(connect(servidorTorreControl, (void *) &direccionServidor, sizeof(direccionServidor)) != 0){
		perror("No se pudo conectar");
		return 1;
	}


	//----------------------------------
	char msjAServidor[LONG_MSG_SERV];
	memset(msjAServidor, '\0', LONG_MSG_SERV);

	ST_MENSAJE msj;
	inicializarST_MENSAJE(&msj);

	crearSTMensaje(&msj, "127.0.0.1 8081", "127.0.0.1 8080", "123abc45, Boeing 747, 18000");

	printf("Se envia origen: %s\n", msj.origen);
	printf("Se envia destino: %s\n", msj.destino);
	printf("Se envia mensaje: %s\n", msj.mensaje);

	strcpy(msjAServidor, msj.origen);
	strcat(msjAServidor, ";");
	strcat(msjAServidor, msj.destino);
	strcat(msjAServidor, ";");
	strcat(msjAServidor, msj.mensaje);

	printf("Mensaje: %s\n", msjAServidor);

	send(servidorTorreControl, msjAServidor, sizeof(char)*(LONG_MSG_SERV), MSG_WAITALL);

	return EXIT_SUCCESS;
}
