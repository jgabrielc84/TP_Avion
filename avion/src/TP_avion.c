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
#include "../headers/archivo.h"
#include "../headers/consola.h"


int main() {
	system("clear");

	FILE * ptrArchivoConfigServ = NULL;
	struct sockaddr_in direccionServidor;
	char msjAServidor[LONG_MSG_SERV];
	ST_MENSAJE msj;
	int servidorTorreControl = 0;
	char msjRecibido[LONG_MSG_RECIBIDO]; //Se crea la variable que recibe respuesta del servidor

	memset(msjRecibido, '\0', LONG_MSG_RECIBIDO);
	memset(msjAServidor, '\0', LONG_MSG_SERV);
	inicializarST_MENSAJE(&msj);

	printf("Wait windows 1\n\n");
	//abrirArchivoConfigServ(ptrArchivoConfigServ);
	//El archivo se habre en el main porque falla la funcion(no encuentro el error)
	printf("abrirArchivoConfigServ\n");
	if((ptrArchivoConfigServ = fopen("config.txt", "r")) == NULL){
		printf("Error al abrir archivo\n");
		exit(EXIT_FAILURE);
	}else{
		printf("Archivo de configuracion abierto correctamente.\n\n");
	}

	printf("Wait windows 2\n\n");
	direccionServidor = crearServidor(ptrArchivoConfigServ); //Se crea un servidor con los datos del archivo

	//Libera el puntero al archivo de configuracion
	free(ptrArchivoConfigServ);

	servidorTorreControl = socket(AF_INET, SOCK_STREAM, 0); //se pide un socket que devuelve un valor

	conectaConexionServ(&servidorTorreControl, &direccionServidor);

	int bytesRecibidos = recv(servidorTorreControl, msjRecibido, LONG_MSG_RECIBIDO, 0); //Se recibe respuesta del servidor

	if(bytesRecibidos < 0){
		perror("El cliente se ha desconectado del servidor\n\n");
		return 1;
	}else{
		printf("%s\n", msjRecibido);
	}

	//----------------------------------
	iniciaMenu();

	crearSTMensaje(&msj, "127.0.0.1 8081", "127.0.0.1 8080", "123abc45, Boeing 747, 18000");

	codificarMensaje(msjAServidor, &msj);

	printf("Mensaje a enviar: %s\n\n", msjAServidor);

	//Se envia al servidor el mensaje codificado
	send(servidorTorreControl, msjAServidor, sizeof(char)*(LONG_MSG_SERV), 0);

	//Se recibe respuesta del servidor
	memset(msjRecibido, '\0', LONG_MSG_RECIBIDO);//Se setea nuevamente para recibir el mensaje limpio
	bytesRecibidos = recv(servidorTorreControl, msjRecibido, LONG_MSG_RECIBIDO, 0);

	if(bytesRecibidos < 0){
		perror("el cliente se ha desconectado del servidor\n\n");
		return 1;
	}else{
		printf("%s\n", msjRecibido);
	}

	return EXIT_SUCCESS;
}
