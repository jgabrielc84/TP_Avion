
/* TP_avion
 * servidor.c
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#include "../headers/servidor.h"


struct sockaddr_in crearServidor(const char * ip, const int * puerto){
	printf("*crearServidor*\n");
	struct sockaddr_in servidor;

	servidor.sin_family = AF_INET;
	servidor.sin_addr.s_addr = inet_addr(ip);
	servidor.sin_port = htons(*puerto);

	return servidor;
}

void conectarConServidor(int * servidorTorreControl, struct sockaddr_in * direccionServidor){
	printf("*conectaConexionServ*\n");
	if(connect(*servidorTorreControl, (void *) direccionServidor, sizeof(*direccionServidor)) != 0){
		perror("No se pudo conectar al servidor\n");
		exit(EXIT_FAILURE);
	}
}

void enviarMensajeAServidor(const int * servidorTorreControl, const char * msjServidor){
	printf("*enviarMensajeAServidor*\n");
	printf("Mensaje a enviar: %s\n", msjServidor); // BORRAR
	send(*servidorTorreControl, msjServidor, sizeof(char)*LONG_MSJ_SERV, 0); //Se envia el mensaje formateado al servidor
}

void recibirMensaje(int * bytesRecibidos, const int * servidorTorreControl, char * msjServidor){
	printf("*recibirMensaje*\n");
	*bytesRecibidos = 0;
	inicializarMsjServidor(msjServidor);

	while(*bytesRecibidos == 0){
		*bytesRecibidos = recv(*servidorTorreControl, msjServidor, sizeof(char)*LONG_MSJ_SERV, 0);

		if(*bytesRecibidos <= 0){
			printf("Error al recibir mensaje.\n");
		}
	}
	printf("Mensaje recibido: %s\n", msjServidor); // BORRAR
}

void enviarSolicitudAServidor(char * msjServidor, ST_AVION * avion, const int * opcion, const int * servidorTorreControl){
	printf("*registrarAvion*\n");

	formatearMensaje(msjServidor, avion, opcion);

	enviarMensajeAServidor(servidorTorreControl, msjServidor);
}
