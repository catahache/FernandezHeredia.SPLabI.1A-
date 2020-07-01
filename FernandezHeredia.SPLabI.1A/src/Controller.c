#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include "menu.h"
#include "pais.h"

#define NAME_LEN 128
#define TIPO_LEN 128


int controller_loadFromText(char* path , LinkedList* pArrayListPandemia)
{
	int retorno = -1;
	FILE* pFile;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		if(parser_PaisFromText(pFile, pArrayListPandemia) == 0)
		{
			printf("Archivo de texto cargado con exito\n");
			retorno = 0;
		}
		else
		{
			printf("Error parser\n");
		}
	}
	else
	{
		printf("Error null\n");
	}

	fclose(pFile);
    return retorno;
}


int controller_ListPaises(LinkedList* pArrayListPaises)
{
	int retorno = -1;
	if(pArrayListPaises != NULL)
	{
		printf("\n   ID         Pais                   Recuperados      Infectados      Muertos\n");
		printf("o------------------------------------------------------------------------------------o\n");
		for(int i = 0; i < ll_len(pArrayListPaises); i++)
		{
			pais_printPais(pArrayListPaises, i);
		}
		retorno = 0;
	}
	else
	{
		printf("No hay paises cargadas en la lista.\n");
	}

    return retorno;
}


int controller_sortPaises(LinkedList* pArrayListPaises)
{
	int retorno = -1;

	if(pArrayListPaises != NULL)
	{
		if(pais_sort(pArrayListPaises) == 0)
		{
			printf("Paises ordenadas por infectados exitosamente.\n");
		}
	}
	else
	{
		printf("Error\n");
	}

    return retorno;
}



int controller_saveAsText(char* path , LinkedList* pArrayListPaises)
{
	int retorno = -1;

	FILE* pFile;
	int auxId;
	char auxName[NAME_LEN];
	int auxRecup;
	int auxInfec;
	int auxMuertos;
	ePais* pPais;

	if(pArrayListPaises != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			retorno = 0;
			for(int i = 1; i < ll_len(pArrayListPaises); i++)//por cada elemento del array lo escribo en el archivo, desde la pos 1
			{
				pPais = ll_get(pArrayListPaises, i);
				//utilizo los getter para traerme la info
				if(!pais_getId(pPais, &auxId) &&
				   !pais_getNamePais(pPais, auxName) &&
				   !pais_getRecuperados(pPais, &auxRecup) &&
				   !pais_getInfectados(pPais, &auxInfec) &&
				   !pais_getMuertos(pPais, &auxMuertos))
				{
					fprintf(pFile, "%d,%s,%d,%d,%d\n", auxId, auxName, auxRecup, auxInfec, auxMuertos);
				}
			}
			fclose(pFile);
			printf("Archivo guardado!\n");
		}//if fpArchivo NULL
	}//if NULL

    return retorno;
}



int controller_map(LinkedList* pArrayListPaises)
{
	int retorno = -1;

	pArrayListPaises = ll_map(pArrayListPaises, pais_asignarRecuperados);
	pArrayListPaises = ll_map(pArrayListPaises, pais_asignarInfectados);
	pArrayListPaises = ll_map(pArrayListPaises, pais_asignarMuertos);
	if(pArrayListPaises != NULL)
	{
		controller_ListPaises(pArrayListPaises);
		retorno = 0;
	}

	return retorno;
}


int controller_filter(LinkedList* pArrayListPaises)
{
	int retorno = -1;
	LinkedList* listaFiltrada = NULL;

	switch(menuFiltrar())
	{
		case 1:
			listaFiltrada = ll_filter(pArrayListPaises,paises_filtrarExitosos);
			if(!controller_saveAsText("paisesExitosos.csv", listaFiltrada))
			{
				printf("Lista guardada con exito!\n");
			}
			break;
		case 2:
			listaFiltrada = ll_filter(pArrayListPaises,paises_filtrarHorno);
			if(!controller_saveAsText("paisesEnElHorno.csv", listaFiltrada))
			{
				printf("Lista guardada con exito!\n");
			}
			break;
		case 3:
			break;
		default:
			printf("No es una opcion valida \n");

	}
	controller_ListPaises(listaFiltrada);

	return retorno;
}



int controller_paisConMasMuertos(LinkedList* pArrayListPaises)
{
	int retorno = -1;

	if(pArrayListPaises != NULL)
	{
		if(pais_compararPaises(pArrayListPaises) == 0)
		{

		}
		else
		{
			printf("Error en la funcion pais_compararPaises.\n");
		}
	}
	else
	{
		printf("Error\n");
	}

    return retorno;
}
