#ifndef UTN_BIBLIOTECA_H_INCLUDED
#define UTN_BIBLIOTECA_H_INCLUDED
#endif // UTN_BIBLIOTECA_H_INCLUDED
/*
* \brief para validar que lo ingresado por el usuario sea un numero entero
* \param el puntero donde se guardara el numero en caso de exito
* \param la cantidad de veces que el usuario puede intentar ingresar el dato
* \param el mensaje que se le mostrara al usuario
* \param el mensaje que se le mostrara al usuario en caso de error
* \param el limite inferior del numero a ingresar
* \param el limite superior del numero a ingresar
*
* \return retorna -1 en caso de error(puntero vacio,intentos agotados, caracter no numerico) retorna 0 en caso de exito
*
*/

int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,int max);
/*
*  \brief para validar que lo ingresado por el usuario sea un numero entero o flotante
*  \param la cantidad de veces que el usuario puede intentar ingresar datos
*  \param el mensaje que se le mostrara al usuario
*  \param el mensaje que se le mostrara al usuario en caso de error (punteros vacios,supero la cantidad de intentos, o caracteres no numericos)
*  \param el limite inferior del numero a ingresar
*  \param el limite superior del numero a ingresar
*  \return retorna -1 en caso de error(puntero vacio,intentos agotados, caracter no numerico) retorna 0 en caso de exito
*/
int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max);
/*
*
* \brief para capturar una cadena del usuario que no supere el limite ingresado
* \param el puntero donde se guardara la cadena
* \param el limite que la cadena no puede superar
* \return retorna -1 en caso de error(punteros vacios o cadena mas larga que el limite) retorna 0 en caso de exito
*
*/
int getCadena(char* pAux,int limite);
/*
*
*  \brief para capturar un numero ingresado por el usuario
*
*  \param el puntero donde se  guardara el numero
*
*  \return retorna -1 en caso de error (lo ingresado no es un numero) o en caso de exito, retorna 0
*
*/
int getInt(int* pAux);
/*
*
* \brief para validar que la cadema que recibe la funcion no contenga caracteres no numericos dentro
*
* \param la cadena a validar
*
* \return retorna -1 en caso de error (caracteres no numericos dentro de la cadena)
*
*/

int isInt(char *pAux);
/*
*   \brief para validar que una cadena ingresada sea un numero entero o flotante
*   \param puntero de la cadena a validar
*   \return retorna -1 en caso de ser una cadena con caracteres no numericos o con mas de un punto ('.'), retorna 0 en caso de exito
*
*/

int isFloat(char* pAux);
/*
*
*  \brief para transformar una cadena de caracteres a numero flotante
*  \param el puntero a la cadena donde se va a guardar el numero flotante
*  \return retorna -1 en caso de error(cadena demasiado grande, caracteres no numericos en la cadena) o 0 en caso de exito
*
*/
int getFloat(float*pAux);
/*
*
* \brief para validar que una cadena ingresada contenga solo caracteres no numericos
* \param el limite de caracteres que puede contener la cadena
* \param la cantidad de reintentos que se le da al usuario
* \param el mensaje que se le muestra al usuario
* \param el mensaje que se le muestra al usuario en caso de error
* \return -1 en caso de error (puntero vacio, limite o reintentos negativos, o caracteres numericos en la cadena) retorna 0 en caso de exito
*/
int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError);
/*
*
* \brief para validar que una cadena solo contenga caracteres del tipo no numerico
* \brief el puntero a la cadena a validar
* \return -1 en caso de error(puntero vacio, cadena con carecteres numericos en ella) retorna 0 en caso de exito
*
*/
int isLetras(char*pAux);
// todas las funcionas las copie del profesor Davila, estas todavia no las use nunca
/*
*  \brief para validar que una bandera este en true (uno)
*  \param el puntero a la bamdera
*  \param el mensaje que se le muestra al usuario en caso de error
*  \return retorna -1 en caso de error(puntero vacio, o bandera en otro valor que no sea uno) o 0 en caso de exito
*
*/
int validateFlag(int* flag, char* msgError);
/*
* \brief para validar que la cadena sea un mail
* \param el puntero de la cadena a validar
* \return retorna -1 en caso de error(puntero vacio o cadena sin o con mas de un arroba), retorna 0 en caso de exito
*/
int validarMail(char *pAux);
/*
* \brief para obtener y validar un mail ingresado por el usuario
* \param puntero de la cadena donde se va a guardar el email
* \param el tamaño que puede tener el mail
* \param cantidad de veces que el usuario tiene para ingresar el mail
* \param mensaje que se le muestra al usuario
* \param mensaje que se le muestra al usuario en caso de error
* \return -1 en caso de error(punteros vacios, limite o reintentos negativos, cadena que no es un mail) retorna 0 en caso de exito
*/
int utn_getEmail(char* pString, int limite, int reintentos, char* msg, char* msgError);

