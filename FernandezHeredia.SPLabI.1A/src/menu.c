/*
 * menu.c
 *
 *  Created on: Jun 12, 2020
 *      Author: catalina
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "utn.h"

//menu opciones principal
int menu()
{
	int option;

	system("clear");

	printf("                ***** M E N U  P A N D E M I A *****\n\n\n");
	printf("  (1)  Cargar archivo (modo texto).\n\n");
	printf("  (2)  Imprimir lista pandemia\n\n");
	printf("  (3)  Asignar recuperados infectados y muertos\n\n");
	printf("  (4)  Filtrar \n\n");
	printf("  (5)  Ordenar por infectados\n\n");
	printf("  (6)  Pais mas castigado\n\n");
	printf("  (7)  Salir\n\n\n");

	utn_getEntero(&option, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 7);
	return option;
}


//menu filtrar
int menuFiltrar()
{
	int option;

	system("clear");

	printf("***** F I L T R A R  P O R  G R A V E D A D *****\n\n");
	printf("  1. Paises exitosos\n");
	printf("  2. Paises en el horno\n");
	printf("  3. Salir\n\n");

	utn_getEntero(&option, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 3);

	return option;
}



