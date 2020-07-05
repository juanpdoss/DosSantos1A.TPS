#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo; //la variable sueldo vino declarada como int en la cascara.
}Employee;
#include "LinkedList.h"

//recibo todo los parametros enteros como chars para poder aplicarles validacion con mi biblioteca utn dentro de los setters.

/** \brief para reservar espacio en memoria dinamica para una estructura de tipo Employee
 *
 * \param vacio
 * \param vacio
 * \return retorna un puntero del tipo employee en donde empiece el archivo en memoria dinamica
 *
 */

Employee* employee_new();
/** \brief para reservar espacio en memoria dinamica para un empleado e inicializar sus campos
 *
 * \param puntero a cadena de id
 * \param puntero a cadena de nombre
 * \param puntero a cadena de horas
 * \param puntero a cadena de sueldo
 * \return retorna un puntero del tipo Employee en caso de exito
           retorna NULL si no se consiguio memoria dinamica o si no se pudo escribir en alguno de los campos
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
/** \brief para liberar un empleado de memoria dinamica
 *
 * \param puntero a la estructura Employee a liberar
 * \return vacio
 *
 */

void employee_delete(Employee* thiss);
/** \brief para establecer un valor en el campo id de un empleado
 *
 * \param puntero a la estructura
 * \param puntero a la cadena que contiene el valor
 * \return retorna 1 en caso de exito
           retorna 0 si alguno de los punteros estan vacios
 *
 */


int employee_setId(Employee* thiss,char* id);
/** \brief para guardar el valor del campo Id del empleado en la variable int que apunta el puntero pasado como parametro
 * \param puntero a la estructura
 * \param el puntero de la variable donde se guardara el valor
 * \return retorna 1 en caso de exito
           retorna 0 si alguno de los punteros estan vacios
 *
 */

int employee_getId(Employee* thiss,int* id);
/** \brief para establecer un nombre en el campo nombre de la estructura pasada como parametro
 *
 * \param puntero a la estructura
 * \param puntero a la cadena que se copiara en el campo nombre del empleado
 * \return retorna 1 en caso de exito
           retorna 0 si los punteros estan vacios
           retorna 0 si en la cadena nombre hay caracteres que no sean letras
 *
 */


int employee_setNombre(Employee* thiss,char* nombre);
/** \brief para copiar en una cadena el campo nombre de la estructura pasada como parametro
 *
 * \param puntero a la estructura
 * \param array donde se guardara el nombre del empleado
 * \return retorna 1 en caso de exito
           retorna 0 si alguno de los punteros estan en null
 *
 */


int employee_getNombre(Employee* thiss,char* nombre);
/** \brief para establecer un valor en el campo horasTrabajadas del empleado
 *
 * \param  Puntero a la estructura
 * \param  puntero a la cadena que contiene el valor a establecer
 * \return retorna 1 en caso de exito
           retorna 0 si hay letras en la cadena
           retorna 0 si los punteros estan vacios

 *
 */


int employee_setHorasTrabajadas(Employee* thiss,char* horasTrabajadas);
/** \brief para guardar el valor del campo horasTrabajadas del empleado en la variable int que apunta el puntero pasado como parametro
 *
 * \param puntero a la estructura
 * \param puntero a la variable donde se guardaran las horas trabajadas
 * \return retorna 1 en caso de exito
           retorna 0 si los punteros estan vacios

 *
 */

int employee_getHorasTrabajadas(Employee* thiss,int* horasTrabajadas);
/** \brief para establecer un valor en el campo sueldo de un empleado
 * \param  puntero a la estructura
 * \param  puntero a la cadena que contiene el valor a establecer
 * \return retorna 1 en caso de exito
           retorna 0 si en la cadena hay letras
           retorna 0 si los punteros estan vacios
 *
 */


int employee_setSueldo(Employee* thiss,char* sueldo);
/** \brief para guardar el valor del campo sueldo del empleado en la variable int que apunta el puntero pasado como parametro
 *
 * \param puntero a la estructura
 * \param el puntero a la variable donde se guardara el valor del campo sueldo
 * \return retorna 1 en caso de exito
           retorna 0 si alguno de los punteros estan en null
 *
 */

int employee_getSueldo(Employee* thiss,int* sueldo);





#endif // employee_H_INCLUDED
