/** \brief para cargar el linkedlist de empleados con los datos en el archivo data.csv
 * \param puntero al linkedlist de empleados
 * \param vacio
 * \return retorna 1 en caso de exito
           retorna 0 si alguno de los punteros estan vacios
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief para cargar el linkedlist de empleados con los datos en el archivo data.csv
 *
 * \param puntero allinkedlist de empleados
 * \param
 * \return retorna 1 en caso de exito
           retorna 0 si alguno de los punteros estan vacio
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
