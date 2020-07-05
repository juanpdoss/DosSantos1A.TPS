#include "Employee.h"
/** \brief para cargar los empleados desde el archivo data.csv
 *
 * \param puntero al array que contiene la ruta al archivo
 * \param puntero al linked list
 * \return retorna 1 en caso de exito
           retorna 0 si no se puede abrir el archivo
*          retorna 0 si alguno de los punteros esta vacio
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief  para cargar los empleados desde el archivo data.bin
 *
 *
 * \param puntero al array que contiene la ruta al archivo
 * \param puntero al linked list
 * \return retorna 1 en caso de exito
           retorna 0 si no se puede abrir el archivo
           retorna 0 si alguno de los punteros pasados como parametros esta vacio
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief para agregar un empleado en el linked list
 *
 * \param puntero al linkedlist
 * \return retorna 1 en caso de exito
           retorna 0 si el puntero al linkedlist esta vacio
           retorna 0 si no se puede realizar el alta correctamente(datos ingresados invalidos, no se pudo reservar espacio en memoria dinamica)
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief para modificar los campos de un empleado en el linked list en la posicion indicada
 *
 * \param el puntero al linkedlist
 * \return retorna 1 en caso de exito
           retorna 0 si la posicion indicada esta vacia
           retorna 0 si el puntero al linkedlist esta vacio
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief para quitar un empleado del linked list en la posicion indicada
 *
 * \param puntero al linkedlist
 * \return retorna 1 en caso de exito
           retorna 0 si el puntero al linkedlist esta vacio
           retorna 0 si no hay empleados en la posicion indicada
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief para mostrar los empleados en el linkedlist por consola usando la funcion
           controller_ListEmployee
 *
 * \param puntero al linkedlist
 * \return retorna 1 en caso de exito
           retorna 0 si el puntero al linkedlist esta vacio
 *
 */

int controller_ListEmployees(LinkedList* pArrayListEmployee);
/** \brief  para mostrar un empleado por consola
 *
 * \param puntero a la estructura empleado
 * \param
 * \return retorna 1 en caso de exito
           retorna 0 si el puntero pasado esta vacio
 *
 */

int controller_ListEmployee(Employee* empleado);
/** \brief para ordenar los empleados en el linkedlist
 *
 * \param puntero al linkedlist
 * \return vacio
 *
 */
void controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief para guardar los datos en el linkedlist como un archivo.csv
 *
 * \param puntero a la cadena que tiene la ruta del archivo
 * \param puntero al linkedlist
 * \return
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief para guardar los datos en el linkedlist como un archivo.bin
 *
 * \param puntero a la cadena que tiene la ruta del archivo
 * \param puntero al likedlist
 * \return retorna 1 en caso de exito
           retorna 0 si algunos de los punteros esta vacio
           retorna 0 si no se puede abrir el archivo
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief para mostrar al usuario el menu de modificaciones
 *
 * \param vacio
 * \param vacio
 * \return retorna la opcion elegida por el usuario
 *
 */

int opcionModifica(void);
/** \brief para mostrar por consola el menu principal al usario
 *
 * \param vacio
 * \param vacio
 * \return retorna la opcion elegida por el usuario
 *
 */


int menu(void);
/** \brief para comprar dos empleados por sus ids
 *
 * \param puntero al primer empleado
 * \param puntero al segundo empleado
 * \return retorna 0 si ambos valores son iguales
           retorna 1 si el valor en el campo del puntero a es el mayor
           retorna -1 si el valor en el campo del puntero b es el mayor

 *
 */

int cmpId(void* a,void* b);
/** \brief para comparar dos empleados por su sueldo
 *
 * \param puntero al primer empleado
 * \param puntero al segundo empleado
 * \return retorna 0 si ambos valores son iguales
           retorna 1 si el valor en el campo del puntero a es el mayor
           retorna -1 si el valor en el campo del puntero b es el mayor


 *
 */

int cmpSueldo(void* a,void*b);
/** \brief para comprar dos empleados por sus nombres
 *
 * \param puntero al primer empleado
 * \param puntero al segundo empleado
 * \return retorna 0 si ambos valores son iguales
           retorna 1 si el valor en el campo del puntero a es el mayor
           retorna -1 si el valor en el campo del puntero b es el mayor

 *
 */

int cmpNombre(void* a,void*b);
/** \brief para comparar dos empleados por sus horas trabajadas
 *
 * \param puntero al primer empleado
 * \param puntero al segundo empleado
 * \return retorna 0 si ambos valores son iguales
           retorna 1 si el valor en el campo del puntero a es el mayor
           retorna -1 si el valor en el campo del puntero b es el mayor
 *
 */

int cmpHoras(void* a,void* b);
/** \brief para mostrar por consola al usuario el menu de ordenamiento
 *
 * \param vacio
 * \param vacio
 * \return retorna la opcion ingresada por el usuario

 *
 */

int menuOrdenaPor(void);

