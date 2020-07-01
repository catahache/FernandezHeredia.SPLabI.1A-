#ifndef book_H_INCLUDED
#define book_H_INCLUDED

#include "LinkedList.h"
#define NAME_LEN 128
#define TIPO_LEN 128

typedef struct
{
    int id_bike;
    char nombre[NAME_LEN];
    char tipo[TIPO_LEN];//cuatro tipos
    int tiempo;
}eBicicleta;

typedef struct
{
    int id;
    char nombrePais[NAME_LEN];
    int recuperados;
    int infectados;
    int muertos;

}ePais;

/*
 * \brief Pide memoria con malloc
 * \param
 * \return Retorna un puntero a Book
 */
ePais* pais_new();

/*
 * \brief Llama a los setters que cargan los campos del libro
 * \param IdStr, cadena de caracteres de id del libro
 * \param nameB, cadena de caracteres de nombre del libro
 * \param author, cadena de caracteres de autor del libro
 * \param price, cadena de caracteres de precio del libro
 * \param year, cadena de caracteres de anio de publicacion del libro
 * \return Retorna un puntero a Book
 */
ePais* pais_newParametros(char* idStr,char* nombre, char* recup, char* infec, char* muertos);

/*
 * \brief Elimina un libro
 * \param this, puntero a lirbo
 * \return -1 en caso de error, o 0 en caso de exito
 */
int pais_delete(ePais* this);

/*
 * \brief Valida y carga el id en el campo del libro
 * \param this, puntero a libro
 * \param id, id a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int pais_setId(ePais* this,int id);

/*
 * \brief Carga el id del libro en el puntero que se pase por parametros
 * \param this, puntero a libro
 * \param id, puntero a la variable en la que la funcion cargara el id
 * \return -1 en caso de error, o 0 en caso de exito
 */
int pais_getId(ePais* this,int* id);

/*
 * \brief Valida y carga el nombre en el campo nameB del libro
 * \param this, puntero a libro
 * \param nameB, cadena de caracteres de nombre del libro a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int pais_setNamePais(ePais* this,char* name);

/*
 * \brief Carga el nombre del libro en el puntero que pasemos por parametros
 * \param this, puntero al libro
 * \param nameB, cadena de caracteres en la que la funcion cargara el nombre del libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int pais_getNamePais(ePais* this,char* name);

/*
 * \brief Valida y carga el nombre del autor en el campo author del libro
 * \param this, puntero a libro
 * \param author, cadena de caracteres de nombre del autor a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int pais_setRecuperados(ePais* this,int recuperados);

/*
 * \brief Carga el nombre del autor en el puntero que pasemos por parametros
 * \param this, puntero al libro
 * \param author, cadena de caracteres en la que la funcion cargara el nombre del autor del libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int pais_getRecuperados(ePais* this,int* recuperados);

/*
 * \brief Valida y carga el precio en el campo price del libro
 * \param this, puntero al libro horasTrabajadas
 * \param price, float de precio a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int pais_setInfectados(ePais* this,int infectados);

/*
 * \brief Carga las horas trabajadas del empleado en el puntero que pasemos por parametros
 * \param this, puntero al libro
 * \param price, puntero a la variable en la que la funcion cargara el precio del libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int pais_getInfectados(ePais* this,int* infectados);

int pais_setMuertos(ePais* this,int muertos);

int pais_getMuertos(ePais* this,int* muertos);

/*
 * \brief Busca un libro por id
 * \param pArrayListBook, LinkedList
 * \param id, id a buscar en la lista
 * \return -1 en caso de error, o el index del empleado en caso de exito
 */
int pais_SearchForId(LinkedList* pArrayListPaises, int id);

/*
 * \brief Imprime un libro
 * \param pArrayListBook, LinkedList
 * \param index, indice donde se encuentra el libro
 * \return -1 en caso de error, o 0 en caso de exito
 */
int pais_printPais(LinkedList* pArrayListPaises, int index);




/*
 * \brief Switchea entre los cases de ordenamiento
 * \param pArrayListBook, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int pais_sort(LinkedList* pArrayListPaises);


/*
 * \brief Compara los precios de dos libros
 * \param firstBook, puntero a primer libro a comparar
 * \param secondBook, puntero a segundo libro a comparar
 * \return 1 si el precio del primer libro es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int bike_sortByTiempo(void* firstBike, void* secondBike);

void* pais_asignarRecuperados(void* pais);

int getRandomRecup();

void* pais_asignarInfectados(void* pais);

int getRandomInfectados();

void* pais_asignarMuertos(void* pais);

int getRandomMuertos();

int paises_filtrarExitosos(void* pais);

int paises_filtrarHorno(void* pais);

int pais_sortByInfectados(void* firstPais, void* secondPais);



#endif // book_H_INCLUDED
