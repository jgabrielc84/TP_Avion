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
#include "../headers/mensaje.h"
#include "../headers/avion.h"

#define LONG_IP_SERV 15+1
#define LONG_PUERTO_SERV 5+1



struct sockaddr_in crearServidor(const char *, const int *);

void conectaConexionServ(int *, struct sockaddr_in *);

void registrarAvion(char *, ST_AVION *, const int *, const int *);

#endif /* HEADERS_SERVIDOR_H_ */
