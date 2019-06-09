/*
 * servidor.h
 *
 *  Created on: 15 may. 2019
 *      Author: gabriel
 */

#ifndef HEADERS_SERVIDOR_H_
#define HEADERS_SERVIDOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>


struct sockaddr_in crearServidor(FILE * ptrArchivo);

void conectaConexionServ(int * servidorTorreControl, struct sockaddr_in * direccionServidor);


#endif /* HEADERS_SERVIDOR_H_ */
