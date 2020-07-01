
#include "pais.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "menu.h"
#include "utn.h"
#include "Controller.h"

#define NAME_LEN 128


ePais* pais_new()
{
	return (ePais*) malloc(sizeof(ePais));
}

ePais* pais_newParametros(char* idStr,char* nombre, char* recup, char* infec, char* muertos)
{
	ePais* this = NULL;
	this = pais_new();

	if(this != NULL && idStr != NULL && nombre != NULL && recup != NULL && infec != NULL && muertos != NULL)
	{
		//si estas dan error(-1), no tiene que existir el libro, por eso llamo a delete
		if(pais_setId(this, atoi(idStr)) == -1 ||
		   pais_setNamePais(this, nombre) == -1 ||
		   pais_setRecuperados(this, atoi(recup)) == -1 ||
		   pais_setInfectados(this, atoi(infec)) == -1 ||
		   pais_setMuertos(this, atoi(muertos)) == -1 )
		{
			pais_delete(this);
			this = NULL; //libero, el puntero queda apuntando a null
		}
	}
	return this;
}

int pais_delete(ePais* this)
{
	int retorno = -1;//error
	if(this != NULL)
	{
		free(this);
		this = NULL;
		retorno = 0;//exito
	}
	return retorno;
}


//*****************************************
//************GETTERS Y SETTERS************
//*****************************************


int pais_setId(ePais* this,int id)//numerico
{
	int retorno = -1;//error

	if(this != NULL && id >= 0)
	{
		this->id = id;//me guarda en el id de this el id que le paso por parametros
		retorno = 0;//exito
	}
	return retorno;
}

int pais_getId(ePais* this,int* id)
{
	int retorno = -1;//error

	if(this != NULL && id != NULL)
	{
		*id = this->id;//me guarda en el puntero a id lo que hay en this id
		retorno = 0;//exito
	}
	return retorno;
}

int pais_setNamePais(ePais* this,char* name)
{
	int retorno = -1;//error

	if(this != NULL && name != NULL)
	{
		strncpy(this->nombrePais, name, NAME_LEN);
		retorno = 0;//exito
	}
	return retorno;
}

int pais_getNamePais(ePais* this,char* name)
{
	int retorno = -1;//error

	if(this != NULL && name != NULL)
	{
		strncpy(name, this->nombrePais, NAME_LEN);
		retorno = 0;//exito
	}
	return retorno;
}


int pais_setRecuperados(ePais* this,int recuperados)
{
	int retorno = -1;//error

	if(this != NULL)
	{
		this->recuperados = recuperados;
		retorno = 0;//exito
	}
	return retorno;
}

int pais_getRecuperados(ePais* this,int* recuperados)
{
	int retorno = -1;//error

	if(this != NULL && recuperados != NULL)
	{
		*recuperados = this->recuperados;
		retorno = 0;//exito
	}
	return retorno;
}

int pais_setInfectados(ePais* this,int infectados)
{
	int retorno = -1;//error

	if(this != NULL)
	{
		this->infectados = infectados;
		retorno = 0;//exito
	}
	return retorno;
}

int pais_getInfectados(ePais* this,int* infectados)
{
	int retorno = -1;//error

	if(this != NULL && infectados != NULL)
	{
		*infectados = this->infectados;
		retorno = 0;//exito
	}
	return retorno;
}

int pais_setMuertos(ePais* this,int muertos)
{
	int retorno = -1;//error

	if(this != NULL)
	{
		this->muertos = muertos;
		retorno = 0;//exito
	}
	return retorno;
}

int pais_getMuertos(ePais* this,int* muertos)
{
	int retorno = -1;//error

	if(this != NULL && muertos != NULL)
	{
		*muertos = this->muertos;
		retorno = 0;//exito
	}
	return retorno;
}

//*****************************************
//*****************************************
//*****************************************



int pais_SearchForId(LinkedList* pArrayListPaises, int id)
{
	int retorno = -1;
	int idAux;
	ePais* pPais;

	for(int index = 0; index < ll_len(pArrayListPaises); index++)
	{
		pPais = (ePais*) ll_get(pArrayListPaises, index);

		if(pais_getId(pPais, &idAux) == 0 && idAux == id)
		{
			retorno = index;//devuelvo la posicion de la bicicleta
		}
	}
	return retorno;
}


int pais_printPais(LinkedList* pArrayListPaises, int index)
{
	int retorno = -1;
	ePais* pPais;
	int auxId, auxRecup, auxInfec, auxMuertos;
	char auxNombre[NAME_LEN];

	if(pArrayListPaises != NULL && index >= 0)
	{
		pPais = (ePais*)ll_get(pArrayListPaises, index);
		if(pais_getId(pPais, &auxId) == 0 &&
		   pais_getNamePais(pPais, auxNombre) == 0 &&
		   pais_getRecuperados(pPais, &auxRecup) == 0 &&
		   pais_getInfectados(pPais, &auxInfec) == 0 &&
		   pais_getMuertos(pPais, &auxMuertos) == 0 )
		{
			if(auxId > 0 && auxId < 10)
			{
				printf(" [000%d]    -> %-20s    [%4d]     [%4d]     [%4d]\n", auxId, auxNombre, auxRecup, auxInfec, auxMuertos);
			}
			else if(auxId > 9 && auxId < 100)
			{
				printf(" [00%d]    -> %-20s    [%4d]     [%4d]     [%4d]\n", auxId, auxNombre, auxRecup, auxInfec, auxMuertos);
			}
			else if(auxId > 99 && auxId < 1000)
			{
				printf(" [0%d]    -> %-20s    [%4d]     [%4d]     [%4d]\n", auxId, auxNombre, auxRecup, auxInfec, auxMuertos);
			}
			else
			{
				printf(" [%4d]    -> %-20s    [%4d]     [%4d]     [%4d]\n", auxId, auxNombre, auxRecup, auxInfec, auxMuertos);
			}
			retorno = 0;
		}
		else
		{
			printf("Error\n");
		}

	}
	return retorno;
}



int pais_sort(LinkedList* pArrayListPaises)
{
	int retorno = -1;

	if(pArrayListPaises != NULL && ll_isEmpty(pArrayListPaises) == 0)
	{
		printf("-> Espere unos segundos, por favor.\n");
		//por infectados, descendente
		if(!ll_sort(pArrayListPaises, pais_sortByInfectados, 0) &&
		   !controller_ListPaises(pArrayListPaises) )
		{
			retorno = 0;
		}

	}
	return retorno;
}


//Se deberá mostrar por pantalla un listado de los países
//ordenados por cantidad de infectados descendente.
int pais_sortByInfectados(void* firstPais, void* secondPais)
{
	int retorno = 0;//si son iguales
	int firstInfec;
	int secondInfec;

	pais_getInfectados(firstPais, &firstInfec);
	pais_getInfectados(secondPais, &secondInfec);

	if(firstInfec > secondInfec)
	{
		retorno = 1;
	}
	else if(firstInfec < secondInfec)
	{
		retorno = -1;
	}

	return retorno;
}



void* pais_asignarRecuperados(void* pais)
{
	ePais* auxPais = NULL;

	if(pais != NULL)
	{
		auxPais = (ePais*) pais;//casteo
		//random
		pais_setRecuperados(auxPais, getRandomRecup());
	}
	return auxPais;
}

int getRandomRecup()
{
    int aleatorio;
    //50000 y 1000000
    aleatorio = rand()%(50001) + 950000;

    return aleatorio;
}

void* pais_asignarInfectados(void* pais)
{
	ePais* auxPais = NULL;

	if(pais != NULL)
	{
		auxPais = (ePais*) pais;//casteo
		//random
		pais_setInfectados(auxPais, getRandomInfectados());
	}
	return auxPais;
}

int getRandomInfectados()
{
    int aleatorio;
    //40000 y 2000000
    aleatorio = rand()% (40001) + 1960000;

    return aleatorio;
}

void* pais_asignarMuertos(void* pais)
{
	ePais* auxPais = NULL;

	if(pais != NULL)
	{
		auxPais = (ePais*) pais;//casteo
		//random
		pais_setMuertos(auxPais, getRandomMuertos());
	}
	return auxPais;
}

int getRandomMuertos()
{
    int aleatorio;
    //1000 y 50000
    aleatorio = rand()%(1001) + 49000;

    return aleatorio;
}

/*Se deberá generar un archivo igual al original, pero donde solo
aparezcan países con menos de 5000 muertos.*/

int paises_filtrarExitosos(void* pais)
{
	int auxReturn = 0;
	ePais* auxPais = (ePais*) pais;

	if(pais != NULL)
	{
		auxPais = (ePais*) pais;
		if(auxPais->muertos < 5000)
		{
			auxReturn = 1;
		}
	}
	return auxReturn;
}

/* Se deberá generar un archivo igual al original, pero donde
solo aparezcan países donde la cantidad de infectados triplique a la de recuperados.*/
int paises_filtrarHorno(void* pais)
{
	int auxReturn = 0;
	ePais* auxPais = (ePais*) pais;
	int recuperados;
	int infectados;
	int tripleRecuper;

	if(pais != NULL)
	{
		auxPais = (ePais*) pais;
		pais_getRecuperados(auxPais, &recuperados);
		pais_getInfectados(auxPais, &infectados);
		tripleRecuper = infectados * 3;

		if(infectados >= tripleRecuper)
		{
			auxReturn = 1;
		}
	}
	return auxReturn;
}


int pais_compararPaises(LinkedList* pArrayListPaises)
{
	int retorno = -1;
	int auxId;
	ePais* pPaisMasMuertos = NULL;
	int index;

	if(pArrayListPaises != NULL && ll_isEmpty(pArrayListPaises) == 0)
	{
		printf("-> Espere unos segundos, por favor.\n");
		//pais con mas muertos
		pPaisMasMuertos = (ePais*) ll_declareMax(pArrayListPaises, pais_compararPaisConMasMuertos);

		if(pPaisMasMuertos != NULL)
		{
			pais_getId(pPaisMasMuertos, &auxId);
			index = pais_SearchForId(pArrayListPaises, auxId);
			if(index > -1)
			{
				printf("El pais con mas muertos es: \n");
				pais_printPais(pArrayListPaises, index);
				retorno = 0;
			}
			else
			{
				printf("Error\n");
			}
		}

	}
	return retorno;
}

int pais_compararPaisConMasMuertos(void* firstPais, void* secondPais)
{
	int retorno = 0;//si son iguales
	int firstInfec;
	int secondInfec;

	pais_getMuertos(firstPais, &firstInfec);
	pais_getMuertos(secondPais, &secondInfec);

	if(firstInfec > secondInfec)
	{
		retorno = 1;
	}
	else if(firstInfec < secondInfec)
	{
		retorno = -1;
	}

	return retorno;
}
