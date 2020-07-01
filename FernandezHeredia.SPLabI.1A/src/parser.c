#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pais.h"
#include "parser.h"


int parser_PaisFromText(FILE* pFile , LinkedList* pArrayListPandemia)
{
	int retorno = -1;//error
	ePais* pPais;
	char id[200];
	char name[200];
	char recup[200];
	char infect[200];
	char muertos[200];

	if(pFile != NULL && pArrayListPandemia != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, name, recup, infect, muertos);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, name, recup, infect, muertos) == 5)
			{
				//imprime mientras fscanf devuelva 5
				pPais = pais_newParametros(id, name, recup, infect, muertos);

				if(pPais != NULL)//osea si pudo cargar
				{
					ll_add(pArrayListPandemia, pPais);
					retorno = 0;//exito
				}
			}
			else
			{
				break;//salgo de do while
			}

		}while(feof(pFile) == 0); //lee todo el archivo
	}

    return retorno;
}
