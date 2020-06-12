//****************************************************************************************
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto) y los cuenta.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param idSave int*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee,int* idSave);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario) y los cuenta.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 *\param idSaveBin
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee,int* idSaveBin);


/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int id);


/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/**\brief Ordenar por Id
 *
 *\param thisA void*
 *\param thisB void*
 *\return order
 */
int order_byId(void* thisA,void* thisB);


/**\brief Ordenar por Nombre
 *
 *\param thisA void*
 *\param thisB void*
 *\return order
 */
int order_byName(void* thisA,void* thisB);


/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (0 si sale todo ok.)(-1 si no sale todo ok)
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
//****************************************************************************************


