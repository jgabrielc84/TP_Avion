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


int main(int argc, char * argv[]) {
	if(argc != 4){
		printf("Error al ejecutar el archivo!\n\n");
		exit(EXIT_FAILURE);
	}

	system("clear");

	//sacar luego
	while(*argv){
		printf("%s\n", *argv);
		argv++;
	}

	printf("\n\n");

	//VARIABLES
	FILE * ptrArchivoConfigServ = NULL;
	struct sockaddr_in direccionServidor;
	int servidorTorreControl = 0;
	int bytesRecibidos = 0;
	int puertoServidor = 0;
	char * ipServidor = malloc(sizeof(char)*LONG_IP_SERV);
	char * msjServidor = malloc(sizeof(char)*LONG_MSG_SERV); //Variable que envia/recive respuesta servidor
	ST_AVION * avion = malloc(sizeof(ST_AVION));

	//INICIALIZAR VARIABLES
	memset(msjServidor, '\0', LONG_MSG_SERV);
	memset(ipServidor, '\0', LONG_IP_SERV);
	inicializarST_AVION(avion);

	printf("Wait windows 1\n\n");

	//abrirArchivoConfigServ(ptrArchivoConfigServ);
	//-------------El archivo se habre en el main porque falla la funcion(no encuentro el error)
	printf("abrirArchivoConfigServ\n");
	if((ptrArchivoConfigServ = fopen("config.txt", "r")) == NULL){
		printf("Error al abrir archivo\n");
		exit(EXIT_FAILURE);
	}else{
		printf("Archivo de configuracion abierto correctamente.\n\n");
	}
	//--------------------------

	printf("Wait windows 2\n\n");
	leerIpPuertoDeArchivo(ptrArchivoConfigServ, ipServidor, &puertoServidor);

	direccionServidor = crearServidor(ipServidor, &puertoServidor); //Se crea un servidor con los datos recuperados del archivo

	//Libera el puntero al archivo de configuracion
	free(ptrArchivoConfigServ);

	servidorTorreControl = socket(AF_INET, SOCK_STREAM, 0); //se pide un socket que devuelve un valor

	conectaConexionServ(&servidorTorreControl, &direccionServidor);

	bytesRecibidos = recv(servidorTorreControl, msjServidor, LONG_MSG_SERV, 0); //Se recibe bytes de respuesta del servidor

	if(bytesRecibidos < 0){
		perror("El cliente se ha desconectado del servidor\n\n");
		return 1;
	}else{
		printf("%s\n", msjServidor);
	}

	//----------------------------------



	//----------------------------------

	iniciaMenuAvion(avion, msjServidor, &servidorTorreControl);
	/*
	//Se recibe respuesta del servidor
	memset(msjRecibido, '\0', LONG_MSG_RECIBIDO);//Se setea nuevamente para recibir el mensaje limpio
	bytesRecibidos = recv(servidorTorreControl, msjRecibido, LONG_MSG_RECIBIDO, 0);

	if(bytesRecibidos < 0){
		perror("el cliente se ha desconectado del servidor\n\n");
		return 1;
	}else{
		printf("%s\n", msjRecibido);
	}
	*/

	free(msjServidor); //Libera punteros
	free(avion);

	return EXIT_SUCCESS;
}

