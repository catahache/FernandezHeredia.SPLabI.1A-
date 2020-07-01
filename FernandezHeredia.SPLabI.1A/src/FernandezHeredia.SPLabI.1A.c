/*
 ============================================================================
 Name        : 1A.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "menu.h"
#include "utn.h"
#include "Controller.h"
#include <time.h>

int main(void) {

	char exitOut = 'n';
	int flagText = 0;
	char path[100];
	int flagMap = 0;

	LinkedList* listaPandemia = ll_newLinkedList();
	srand(time(NULL));

	if(listaPandemia != NULL)
	{
		do{
			system("clear");
			switch(menu())
			{
				case 1:
					if(flagText == 0)
					{
						if(!utn_getPath(path, 200, 2, "Ingrese el nombre del archivo con su extension: ", "Error, invalido\n"))
						{
							if(!controller_loadFromText(path, listaPandemia))
							{
								flagText = 1;
							}
						}
					}
					else
					{
						printf("Archivo ya cargado\n");
					}

					break;
				case 2:
					//imprimir
					if(flagText == 1)
					{
						controller_ListPaises(listaPandemia);
					}
					else
					{
						printf("Error. Aun no se cargo ningun archivo.\n");
					}
					break;
				case 3:
					//asignar
					if(flagText == 1)
					{
						controller_map(listaPandemia);
						flagMap = 1;
					}
					else
					{
						printf("Error. Aun no se cargo ningun archivo.\n");
					}
					break;
				case 4:
					//filtrar
					if(flagText == 1 && flagMap == 1)
					{
						controller_filter(listaPandemia);
					}
					else
					{
						printf("Error. Aun no se cargo ningun archivo.\n");
					}
					break;
				case 5:
					//Ordenar
					if(flagText == 1 && flagMap == 1)
					{
						controller_sortPaises(listaPandemia);
					}
					else
					{
						printf("Error. Aun no se cargo ningun archivo.\n");
					}
					break;
				case 6:
					//Informar el nombre del país o países con el mayor número de muertos. Y cuál es ese número.
					if(flagText == 1 && flagMap == 1)
					{
						controller_paisConMasMuertos(listaPandemia);
					}
					else
					{
						printf("Error, primero ordenar por tipo\n");
					}
					break;

				case 7:
					exitOut = 's';
					break;
			}

		}while(exitOut == 'n');
	}

	return EXIT_SUCCESS;
}
