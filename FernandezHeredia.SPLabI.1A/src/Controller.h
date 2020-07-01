/*
 * \brief Carga los datos de los libros desde el archivo data.csv (modo texto).
 * \param path char*, path al archivo a cargar
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPandemia);


/*
 * \brief Lista los libros de la LinkedList
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_ListPaises(LinkedList* pArrayListPaises);

/*
 * \brief Ordena los libros de la LinkedList
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_sortPaises(LinkedList* pArrayListPaises);

/*
 * \brief Guarda los datos en el archivo data.csv (modo texto).
 * \param path char*: path al archivo a guardar
 * \param pArrayListBook LinkedList*, LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPaises);


int controller_map(LinkedList* pArrayListPaises);

int controller_filter(LinkedList* pArrayListPaises);

int controller_paisConMasMuertos(LinkedList* pArrayListPaises);

