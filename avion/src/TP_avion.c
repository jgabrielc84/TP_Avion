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
	comprobarParametrosInicio(&argc);

	system("clear");

	//VARIABLES
	FILE * ptrArchivoConfigServ = NULL;
	struct sockaddr_in direccionServidor;
	int servidorTorreControl = 0;
	int bytesRecibidos = 0;
	int puertoServidor = 0;
	char * ipServidor = malloc(sizeof(char)*LONG_IP_SERV);
	char * msjServidor = malloc(sizeof(char)*LONG_MSJ_SERV); //Variable que envia/recive respuesta servidor
	ST_AVION * avion = malloc(sizeof(ST_AVION));

	//INICIALIZAR VARIABLES
	inicializarMsjServidor(msjServidor);
	memset(ipServidor, '\0', LONG_IP_SERV);
	inicializarAvion(avion, argv);

	comprobarAvion(avion);

	//abrirArchivoConfigServ(ptrArchivoConfigServ);
	//-------------El archivo se habre en el main porque falla la funcion(no encuentro el error)
	printf("*abrirArchivoConfigServ*\n");
	if((ptrArchivoConfigServ = fopen("config.txt", "r")) == NULL){
		printf("Error al abrir archivo\n");
		exit(EXIT_FAILURE);
	}else{
		printf("Archivo de configuracion abierto correctamente.\n");
	}
	//-------------

	leerIpPuertoDeArchivo(ptrArchivoConfigServ, ipServidor, &puertoServidor);

	direccionServidor = crearServidor(ipServidor, &puertoServidor); //Se crea un servidor con los datos recuperados del archivo

	free(ptrArchivoConfigServ); //Libera el puntero de archivo de configuracion

	servidorTorreControl = socket(AF_INET, SOCK_STREAM, 0); //se pide un socket que devuelve un valor

	conectarConServidor(&servidorTorreControl, &direccionServidor);

	//recibirMensaje(&bytesRecibidos, &servidorTorreControl, msjServidor);
	//mostrarMensaje(msjServidor);

	sleep(5);

	iniciaMenuAvion(avion, msjServidor, &servidorTorreControl, &bytesRecibidos);

	free(msjServidor); //Libera punteros
	free(ipServidor);
	free(avion);

	return EXIT_SUCCESS;
}
