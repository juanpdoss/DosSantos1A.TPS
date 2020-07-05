#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED

typedef struct
{
   int id;
   char nombre[200];
   int fuerza;
   float peso;

}sPokemon;

#endif // POKEMON_H_INCLUDED
/** \brief para mostrar el menu por pantalla
 *
 * \param no recibe nada
 * \param
 * \return retorna la opcion elegida por el usuario
 *
 */

int menu(void);
/** \brief para cargar los datos desde el archivo binario
 *
 * \param la linkedlist
 * \param
 * \return retorna 0 en caso de error ( punteros nulos, o si no se pudo abrir el archivo)
           retorna 1 en caso de exito
 *
 */
 int cargarDesdeBinario(LinkedList* lista);
 /** \brief para cargar los datos desde un archivo de texto
  *
  * \param la linkedlist
  * \param
  * \return retorna 0 en caso de error ( punteros nulos, o si no se pudo abrir el archivo)
  *         retorna 1 en caso de exito
  *
  */

int cargarDesdeTexto(LinkedList* lista);
/** \brief para reservar espacio en memoria dinamica para una estructura del tipo pokemon

 *
 * \param no recibe nada
 * \param
 * \return retora un puntero a la estructura creada
 *
 */

sPokemon* new_pokemon(void);
/** \brief para liberar de memoria dinamica una estructura de tipo pokemon
 *
 * \param el puntero a la estructura a liberar
 * \param
 * \return no retorna nada
 *
 */

void destroy_pokemon(sPokemon* unPokemon);
/** \brief para reservar espacio en memoria dinamica para una estructura del tipo pokemon y establecer valores en sus campos
 *
 * \param el array a establecer en el campo "nombre" de la estructura
 * \param el array a establecer en el campo "fuerza" de la estructura
 * \param el array a establecer en el campo "peso" de la estructura
 * \return retorna un puntero a la estructura creada en caso de exito
 *         retorna null si algun campo no pudo ser establecido con los parametros recibidos o si no se consiguio espacio en memoria dinamica
 */

sPokemon* new_pokemonparam(char* nombre,char* fuerza,char* peso);
/** \brief id autoincremental a ser establecido en el campo "id" de una estructura de tipo pokemon
 *
 * \param el puntero a la estructura de tipo pokemon
 * \param
 * \return retorna 1 en caso de exito
 *         retorna 0 si la estructura es nula
 */

int pokemon_setId(sPokemon* unPokemon);
/** \brief para establecer un nombre en el campo "nombre" de la estructura pokemon
 *
 * \param el puntero a la estructura de tipo pokemon
 * \param el nombre a ser cargado
 * \return retorna 1 en caso de exito
 *         retorna 0 si los punteros son nulos
                   o si el array nombre tiene caracteres no alfabeticos


 */

int pokemon_setNombre(sPokemon* unPokemon,char* nombre);
/** \brief para establecer un valor en el campo fuerza de la estructura pokemon
 *
 * \param el puntero a la estructura pokemon
 * \param el array que contiene el valor a establecer
 * \return retorna 1 en caso de exito
           retorna 0 si el array "fuerza" contiene caracteres no numericos
                   o si los punteros  son nulos
 *
 */

int pokemon_setFuerza(sPokemon* unPokemon,char* fuerza);
/** \brief para establecer un valor en el campo peso de la estructura pokemon
 *
 * \param el puntero a la estructura de tipo pokemon
 * \param el array que contiene el valor a establecer
 * \return retorna 1 en caso de exito
           retorna 0 si el array "peso" contiene caracteres no numericos
                   o si los punteros  son nulos

 *
 */

int pokemon_setPeso(sPokemon* unPokemon,char* peso);
/** \brief para obtener el campo nombre de una estructura de tipo pokemon
 *
 * \param el puntero a la estructura de tipo pokemon
 * \param el array donde se cargara el nombre
 * \return retorna 1 en caso de exito
           retorna 0 si los punteros son nulos
 *
 */

int pokemon_getNombre(sPokemon* unPokemon,char* nombre);
/** \brief para obtener el campo fuerza de una estructura de tipo pokemon
 *
 * \param el puntero a la estructura de tipo pokemon
 * \param el puntero a la variable donde se cargara el valor del campo "fuerza"
 * \return retorna 1 en caso de exito
           retorna 0 si los punteros son nulos
 *
 */

int pokemon_getFuerza(sPokemon* unPokemon,int* fuerza);
/** \brief para obtener el campo peso de una estructura de tipo pokemon
 *
 * \param el puntero a la estructura de tipo pokemon
 * \param el puntero a la variable donde se cargara el valor del campo "peso"
 * \return retorna 1 en caso de exito
           retorna 0 si los punteros son nulos
 *
 */

int pokemon_getPeso(sPokemon* unPokemon,float* peso);
/** \brief para obtener el campo id de una estructura de tipo pokemon
 *
 * \param el puntero a la estructura de tipo pokemon
 * \param el puntero a la variable donde se cargara el valor del campo "id"
 * \return retorna 1 en caso de exito
           retorna 0 si los punteros son nulos
 *
 */

int pokemon_getId(sPokemon* unPokemon,int* id);
/** \brief para mostrar una estructura del tipo pokemon por pantalla
 *
 * \param el puntero a la estructura pokemon
 * \param
 * \return retorna 1 en caso de exito
           retorna 0 si el puntero es nulo o si los getters fallan
 *
 */

int list_pokemon(sPokemon* unPokemon);
/** \brief para mostrar todos los pokemones en el sistema por pantalla
 *
 * \param el puntero a la linkedlist
 * \param
 * \return retorno vacio
 *
 */


void list_pokemons(LinkedList* lista);
/** \brief para agregar un pokemon al sistema a traves del linkedlist
 *
 * \param el puntero al linkedlist
 * \param
 * \return retorna 1 en caso de exito
           retorna 0 si el púntero es nulo
           o si no se consiguio espacio en memoria dinamica para una estructura pokemon

 *
 */

int add_pokemon(LinkedList* lista);
/** \brief para guardar los pokemones en el sistema en un archivo.csv
 *
 * \param el puntero al linkedlist
 * \param
 * \return retorna 1 en caso de exito
           retorna 0 si los punteros utilizados son nulos
           o si no se logro escribir el archivo
 *
 */
int guardarPokemonesCsv(LinkedList* lista);
/** \brief para guardar los pokemones en el sistema en un archivo.bin
 *
 * \param el puntero al linkedlist
 * \param
 * \return retorna 1 en caso de exito
           retorna 0 si los punteros utilizados en la funcion son nulos
           o si no se logro escribir el archivo
 *
 */
int guardarPokemonesBin(LinkedList* lista);
/** \brief para imprimir el menu de modificaciones por pantalla
 *
 * \param no recibe nada
 * \param
 * \return retorna la opcion elegida por el usuario
 *
 */
int menuModifica(void);
/** \brief para modificar un pokemon dentro de la lista linkedlist
 *
 * \param el puntero a linkedlist
 * \param
 * \return retorna 1 en caso de exito
           retorna 0 si los punteros estan en null
           o si el usuario decide cancelar la modificacion
           o si el id ingresado no esta en el sistema
 *
 */

int modificaPokemon(LinkedList* lista);
/** \brief  para eliminar una estructura pokemon del linkedlist y de memoria dinamica
 *
 * \param puntero a linkedlist
 * \param
 * \return retorna 1 en caso de exito
           retorna 0 si los punteros en la funcion son nulos
           o si el usuario cancela la baja
           o si la posicion elegida no pertenece a una estructura en el sistema
 *
 */
int bajaPokemon(LinkedList* lista);
/** \brief para comparar dos nombres de dos estructuras pokemon
 *
 * \param puntero a la primer estructura
 * \param puntero a la segunda estructura
 * \return retorna 0 si son iguales
           retorna un valor negativo si el primer puntero a estructura es menor al segundo
           retorna un valor positivo si el primer puntero a estructura es mayor al segundo
 *
 */

int cmpNombre(void* a,void* b);
/** \brief para comparar los valores en los campos "fuerza" de dos estructuras pokemon
 *
 * \param puntero a la primer estructura
 * \param puntero a la segunda estructura
 * \return retorna 0 si ambos valores son iguales
           retorna 1 si el primer valor es mayor al segundo
           retorna -1 si el segundo valor es mayor al primero
 *
 */
int cmpFuerza(void* a,void* b);
 /** \brief para comparar los valores en los campos "peso" de dos estructuras pokemon
  *
  * \param puntero a la primer estructura
  * \param puntero a la segunda estructura
  * \return retorna 0 si ambos valores son iguales
            retorna 1 si el primer valor es mayor al segundo
            retorna -1 si el segundo valor es mayor al primero
  *
  */
int cmpPeso(void* a,void* b);
/** \brief para imprimir por pantalla el menu de ordenamientos
 *
 * \param no recibe nada
 * \param
 * \return retorna la opcion elegida por el usuario
 *
 */
int menuOrdena(void);
/** \brief para ordenar las estructuras de pokemones en el linkedlist
 *
 * \param puntero al linkedlist
 * \param
 * \return retorna 1 en caso de exito
           retorna 0 si el puntero a linkedlist es null
           retorna 0 si no se consigue ordenar el linkedlist
 *
 */


int ordenaPokemons(LinkedList* lista);
/** \brief para guardar un archivo.bin de seguridad antes de salir del programa
 *
 * \param  el puntero a la linkedlist que se clonara y se guardara
 * \param
 * \return retorna 1 en caso de exito
           retorna 0 si los punteros utilizados en la funcion son nulos
           retorna 0 si todos los elementos de la lista no estan contenidos en la lista clonada
           retorna 0 si no se puede escribir el archivo.bin
 *
 */
int crearCopiaBinaria(LinkedList* lista);
/** \brief para crear una copia de un linkedlist en los rangos especificados
 *
 * \param puntero al linkedlist que se usara para crear la copia
 * \param
 * \return retorna el linkedList clonado;
 *
 */
LinkedList* crearCopiaRango(LinkedList* lista);





