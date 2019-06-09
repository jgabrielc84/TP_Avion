/*
 * servidor.c
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#include "../headers/servidor.h"


void leerIpPuerto(FILE * ptrArchivo, char * ip, int * puerto){
	printf("leerIpPuerto\n");
	char * lineaLeida = malloc((sizeof(char))*30);
	char * lineaDescarte = malloc((sizeof(char))*10);
	memset(lineaLeida, '\0', 30);
	memset(lineaDescarte, '\0', 10);
	printf("Wait windows 2.1.1\n\n");
	fgets(lineaLeida, 30, ptrArchivo);
	//fscanf(ptrArchivo, "%s", lineaLeida);

	printf("Wait windows 2.1.2\n\n");
	printf("Linea leida: %s\n", lineaLeida);

	strcpy(lineaDescarte, strtok(lineaLeida, "="));
	printf("Linea descarte: %s\n", lineaDescarte);
	strcpy(ip, strtok(NULL, ";"));
	printf("Ip: %s\n", ip);
	*puerto = atoi(strtok(NULL, ";"));
	printf("Puerto: %d\n", *puerto);

	free(lineaLeida);
	free(lineaDescarte);
}


struct sockaddr_in crearServidor(FILE * ptrArchivo){
	printf("crearServidor\n");
	char * ip = malloc(sizeof(char)*16);
	memset(ip, '\0', 16);
	int puerto = 0;
	printf("Wait windows 2.1\n\n");
	leerIpPuerto(ptrArchivo, ip, &puerto);
	printf("Wait windows 2.2\n\n");
	struct sockaddr_in servidor;

	servidor.sin_family = AF_INET;
	servidor.sin_addr.s_addr = inet_addr(ip);//cambiar a variable ip 127.0.0.1
	servidor.sin_port = htons(puerto);//cambiar a variable puerto

	return servidor;
}

void conectaConexionServ(int * servidorTorreControl, struct sockaddr_in * direccionServidor){
	if(connect(*servidorTorreControl, (void *) direccionServidor, sizeof(*direccionServidor)) != 0){
		perror("No se pudo conectar al servidor");
		exit(EXIT_FAILURE);
	}
}
