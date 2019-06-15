/*
 * servidor.c
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#include "../headers/servidor.h"


struct sockaddr_in crearServidor(const char * ip, const int * puerto){
	printf("crearServidor\n");
	struct sockaddr_in servidor;

	servidor.sin_family = AF_INET;
	servidor.sin_addr.s_addr = inet_addr(ip);//cambiar a variable ip 127.0.0.1
	servidor.sin_port = htons(*puerto);//cambiar a variable puerto

	return servidor;
}

void conectaConexionServ(int * servidorTorreControl, struct sockaddr_in * direccionServidor){
	if(connect(*servidorTorreControl, (void *) direccionServidor, sizeof(*direccionServidor)) != 0){
		perror("No se pudo conectar al servidor");
		exit(EXIT_FAILURE);
	}
}

void registrarAvion(char * msjServidor, ST_AVION * avion, const int * opcion, const int * servidorTorreControl){
	printf("Registrando avion %s en torre de control\n\n", avion->modelo);

	formatearMensaje(msjServidor, avion, opcion);

	printf("Mensaje a enviar: %s\n\n", msjServidor);

	send(*servidorTorreControl, msjServidor, sizeof(char)*(LONG_MSG_SERV), 0); //Se envia al servidor el mensaje formateado


}
