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
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define LONG_IDENTIFICADOR 8
#define LONG_MODELO 20

typedef struct{
	char identificador[LONG_IDENTIFICADOR+1];
	char modelo[LONG_MODELO+1];
	int combustible;
	char estado;
}ST_AVION;



int main(void) {

	    struct sockaddr_in direccionServidor;
	    direccionServidor.sin_family = AF_INET;
	    direccionServidor.sin_addr.s_addr = INADDR_ANY;
	    direccionServidor.sin_port = htons(8080);

	    int cliente = socket(PF_INET, SOCK_STREAM, 0);


	    //Linea para poder probar el socket sin que el sistema te deje en espera por 2 min
	    int activado = 1;
	    setsockopt(cliente, SOL_SOCKET, SO_REUSEADDR, &activado, sizeof(activado));


	    int choice = 0;





	     do{
		     printf("Menu\n\n");
		     printf("1. Conectar a aeropuerto\n");
		     printf("2. Pedir pista\n");
		     printf("3. Exit\n");
		     printf("4. ENviar mensaje\n");
		     scanf("%d",&choice);

	    	 switch (choice) {
				 case 1:
					 if(connect(cliente, (void  *) &direccionServidor, sizeof(direccionServidor)) != 0){
							 perror("No se pudo conectar");
							 return 1;
					 }
					 printf("Conectado");

					  break;
				 case 2:
					 printf("TOdavia no\n");
					  break;
				 case 3:
					 printf("Goodbye\n");
					  break;
				 case 4:
					    while (1) {
					        char mensaje[1000];
					        scanf("%s", mensaje);

					        send(cliente, mensaje, strlen(mensaje), 0);

					    }
					 break;
				 default: printf("Wrong Choice. Enter again\n");
					  break;
			 }


	     } while (choice != 3);








	    return 0;
	}


