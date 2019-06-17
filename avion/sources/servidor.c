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
	printf("conectaConexionServ\n");
	if(connect(*servidorTorreControl, (void *) direccionServidor, sizeof(*direccionServidor)) != 0){
		perror("No se pudo conectar al servidor\n");
		exit(EXIT_FAILURE);
	}
}

void enviarMensajeAServidor(const int * servidorTorreControl, const char * msjServidor){
	send(*servidorTorreControl, msjServidor, sizeof(char)*(LONG_MSJ_SERV), 0); //Se envia al servidor el mensaje formateado
}

void recibirMensaje(int * bytesRecibidos, int * servidorTorreControl, char * msjServidor){
	printf("*recibirMensaje*\n");
	*bytesRecibidos = recv(*servidorTorreControl, msjServidor, sizeof(char)*LONG_MSJ_SERV, 0);

	if(*bytesRecibidos < 0){
		printf("Error al recibir mensaje\n");
		exit(EXIT_FAILURE);
	}
}

void registrarAvion(char * msjServidor, ST_AVION * avion, const int * opcion, const int * servidorTorreControl){
	printf("Registrando avion %s en torre de control\n", avion->modelo);

	formatearMensaje(msjServidor, avion, opcion);
	printf("Mensaje a enviar: %s\n", msjServidor); //BORRAR
	enviarMensajeAServidor(servidorTorreControl, msjServidor);

	sleep(5);
}

//METODO NUEVO
void pedirEstadoAvion(char * msjServidor, ST_AVION * avion, const int * servidorTorreControl){
	printf("%s", msjServidor);
	printf("%s", avion->modelo);
	send(*servidorTorreControl, avion, sizeof(ST_AVION), 0);

	recv(*servidorTorreControl, avion, sizeof(ST_AVION), 0);

	printf("El estado del avion: %s \n", avion->identificador );
	printf("Modelo: %s\n", avion->modelo );
	printf("Cantidad de combustible: %d\n", avion->combustibleActual);
	printf("Estado actual: %d\n", avion->estado);



}


