#include "pokemon.h"
#include "utn_biblioteca.h"

int menu(void)
{
    int opcion;
    printf("         pokedek      \n\n");
    printf("1 cargar pokemones desde archivo csv\n");
    printf("2 cargar pokemones desde archivo bin\n");
    printf("3 alta pokemon\n");
    printf("4 modificar pokemon\n");
    printf("5 baja pokemon\n");
    printf("6 listar pokemones\n");
    printf("7 ordenar pokemones\n");
    printf("8 guardar pokemones en archivo csv\n");
    printf("9 guardar pokemones en archivo bin\n");
    printf("10 clonar lista en los rangos especificados\n");
    printf("11 salir\n");
    utn_getEntero(&opcion,100,"opcion:","Error.Opcion invalida\n",1,11);

    return opcion;


}
//funcion privada
int obtenerId(int* id)
{
    int error=1;
    *id=1000;

    FILE* f;
    f=fopen("proximoId.bin","rb");
    if(f!=NULL)
    {
        fread(id,sizeof(int),1,f);
        fclose(f);
        error=0;

    }

    return error;

}
//funcion privada
int actualizarId(int id)
{
    int error=1;
    id++;

    FILE* f=fopen("proximoId.bin","wb");
    if(f!=NULL)
    {
        fwrite(&id,sizeof(int),1,f);

        fclose(f);
        error=0;

    }

    return error;

}

sPokemon* new_pokemon(void)
{
//    sPokemon* auxPokemon;
//
//    auxPokemon=(sPokemon*)malloc(sizeof(sPokemon));
//    if(auxPokemon!=NULL)
//    {
//        auxPokemon->fuerza=0;
//        auxPokemon->peso=0;
//        auxPokemon->id=0;
//        strcpy(auxPokemon->nombre,"");
//
//    }


    return (sPokemon*)malloc(sizeof(sPokemon));

}
void destroy_pokemon(sPokemon* unPokemon)
{
    free(unPokemon);

}
sPokemon* new_pokemonparam(char* nombre,char* fuerza,char* peso)
{

    sPokemon* unPokemon=new_pokemon();


    if(unPokemon!=NULL&&nombre!=NULL&&fuerza!=NULL&&peso!=NULL)
    {
        if(pokemon_setPeso(unPokemon,peso)
                &&pokemon_setNombre(unPokemon,nombre)
                &&pokemon_setFuerza(unPokemon,fuerza)
                &&pokemon_setId(unPokemon))
        {



            return unPokemon;


        }


    }
    destroy_pokemon(unPokemon);

    return NULL;



}
int pokemon_setId(sPokemon* unPokemon)
{
    int id;
    int retorno=0;
    if(unPokemon!=NULL)
    {
        obtenerId(&id);
        unPokemon->id=id;
        actualizarId(id);
        retorno=1;


    }

    return retorno;
}


int pokemon_setNombre(sPokemon* unPokemon,char* nombre)
{
    int retorno=0;

    if(unPokemon!=NULL&&nombre!=NULL&&!isLetras(nombre))
    {
        strcpy(unPokemon->nombre,nombre);
        retorno=1;

    }

    return retorno;
}
int pokemon_setFuerza(sPokemon* unPokemon,char* fuerza)
{
    int retorno=0;

    if(unPokemon!=NULL&&fuerza!=NULL&&!isInt(fuerza))
    {

        unPokemon->fuerza=atoi(fuerza);
        retorno=1;


    }


    return retorno;

}
int pokemon_setPeso(sPokemon* unPokemon,char* peso)
{
    int retorno=0;

    if(unPokemon!=NULL&&peso!=NULL&&!isFloat(peso))
    {

        unPokemon->peso=atof(peso);
        retorno=1;


    }

    return retorno;
}
int pokemon_getId(sPokemon* unPokemon,int* id)
{
    int retorno=0;
    if(unPokemon!=NULL&&id!=NULL)
    {

        *id=unPokemon->id;
        retorno=1;


    }

    return retorno;
}
int pokemon_getNombre(sPokemon* unPokemon,char* nombre)
{
    int retorno=0;

    if(unPokemon!=NULL&&nombre!=NULL)
    {
        strcpy(nombre,unPokemon->nombre);
        retorno=1;
    }


    return retorno;
}
int pokemon_getFuerza(sPokemon* unPokemon,int* fuerza)
{
    int retorno=0;
    if(unPokemon!=NULL&&fuerza!=NULL)
    {

        *fuerza=unPokemon->fuerza;
        retorno=1;


    }


    return retorno;
}
int pokemon_getPeso(sPokemon* unPokemon,float* peso)
{
    int retorno=0;
    if(unPokemon!=NULL&&peso!=NULL)
    {
        *peso=unPokemon->peso;
        retorno=1;


    }

    return retorno;
}
int cargarDesdeTexto(LinkedList* lista)
{
    int ok=0;
    FILE* f=fopen("data.csv","r");
//  FILE* b=fopen("data.bin","wb");
    sPokemon* unPokemon;
    int leido;
    //int tam;
    char bufferEntrada[3][200];

    if(f!=NULL)
    {
        leido=fscanf(f,"%[^,],%[^,],%[^\n]\n",bufferEntrada[0],bufferEntrada[1],bufferEntrada[2]);
        while(!feof(f))
        {
            leido=fscanf(f,"%[^,],%[^,],%[^\n]\n",bufferEntrada[0],bufferEntrada[1],bufferEntrada[2]);

            if(leido==3)
            {
                unPokemon=new_pokemonparam(bufferEntrada[0],bufferEntrada[1],bufferEntrada[2]);

                if(unPokemon!=NULL)
                {
                    //printf("%s %s %s",bufferEntrada[0],bufferEntrada[1],bufferEntrada[2]);

                    //printf("%d",isLetras(bufferEntrada[0]));

                    ll_add(lista,unPokemon);
                    ok=1;

                }

            }

        }
    }
    fclose(f);
//    use este bloque para crear el archivo data.bin la primera vez.
//    tam=ll_len(lista);
//    if(b!=NULL)
//    {
//        for(int i=0;i<tam;i++)
//        {
//            unPokemon=(sPokemon*)ll_get(lista,i);
//            if(unPokemon!=NULL)
//            {
//
//               fwrite(unPokemon,sizeof(sPokemon),1,b);
//
//            }
//
//        }
//
//    }
//

    return ok;
}
int cargarDesdeBinario(LinkedList* lista)
{
    int ok=0;
    FILE* b=fopen("data.bin","rb");

    //mi archivo data.bin al igual que mi archivo mi data.csv disponen de los mismos 16 pokemones.
    int tam=16;
    sPokemon* unPokemon;

    if(b!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            unPokemon=new_pokemon();
            if(unPokemon!=NULL)
            {
                fread(unPokemon,sizeof(sPokemon),1,b);
                pokemon_setId(unPokemon);
                ll_add(lista,unPokemon);
                ok=1;
            }

        }

    }


    return ok;

}



int list_pokemon(sPokemon* unPokemon)
{
    int ok=0;
    char auxNombre[200];
    pokemon_getNombre(unPokemon,auxNombre);
    int auxFuerza;
    pokemon_getFuerza(unPokemon,&auxFuerza);
    float auxPeso;
    pokemon_getPeso(unPokemon,&auxPeso);
    int auxId;
    pokemon_getId(unPokemon,&auxId);

    if(pokemon_getFuerza(unPokemon,&auxFuerza)
            &&pokemon_getPeso(unPokemon,&auxPeso)
            &&pokemon_getId(unPokemon,&auxId)
            &&pokemon_getNombre(unPokemon,auxNombre))
    {


        printf("%5d     %10s    %5d      %5.2f\n",auxId,auxNombre,auxFuerza,auxPeso);
        ok=1;

    }


    return ok;


}
void list_pokemons(LinkedList* lista)
{
    system("cls");
    int tam;
    int flag=0;
    sPokemon* aux;

    if(lista!=NULL)
    {
        tam=ll_len(lista);
        printf("  id          nombre     fuerza    peso\n\n");

        for(int i=0; i<tam ; i++)
        {
            aux=(sPokemon*)ll_get(lista,i);
            if(aux!=NULL)
            {
                if(list_pokemon(aux))
                {

                    flag=1;

                }

            }

        }
        if(!flag)
        {
            printf("  no hay pokemones que listar\n");

        }

    }

}
int add_pokemon(LinkedList* lista)
{
    int ok=0;
    sPokemon* aux=new_pokemon();
    int libre;
    char buffer[2][200];
    system("cls");
    printf("      \n  Agregar pokemon\n\n");


    if(aux!=NULL&&lista!=NULL)
    {
        do
        {
            printf("ingrese nombre:");
            scanf("%s",buffer[0]);
        }
        while(pokemon_setNombre(aux,buffer[0])!=1);
        do
        {
            printf("ingrese fuerza:");
            scanf("%s",buffer[1]);

        }
        while(pokemon_setFuerza(aux,buffer[1])!=1);
        do
        {
            printf("ingrese peso:");
            scanf("%s",buffer[2]);

        }
        while(pokemon_setPeso(aux,buffer[2])!=1);
        pokemon_setId(aux);
        libre=ll_len(lista);
        if(!ll_push(lista,libre,aux))
        {
            ok=1;

        }


    }

    return ok;
}
int guardarPokemonesCsv(LinkedList* lista)
{
    int ok=0;
    char path[200];

    utn_getCadena(path,200,100,"Ingrese nombre del archivo:","Error.Utilice solo letras");
    strcat(path,".csv");
    FILE* f=fopen(path,"w");
    sPokemon* aux;
    int tam=ll_len(lista);
    char auxNombre[200];
    int auxFuerza;
    int auxId;
    float auxPeso;

    if(lista!=NULL&&f!=NULL)
    {
        fprintf(f,"id,nombre,fuerza,peso\n");

        for(int i=0; i<tam; i++)
        {
            aux=ll_get(lista,i);
            pokemon_getNombre(aux,auxNombre);
            pokemon_getFuerza(aux,&auxFuerza);
            pokemon_getId(aux,&auxId);
            pokemon_getPeso(aux,&auxPeso);
            fprintf(f,"%d,%s,%d,%.2f\n",auxId,auxNombre,auxFuerza,auxPeso);
            ok=1;

        }


    }

    fclose(f);



    return ok;
}
int guardarPokemonesBin(LinkedList* lista)
{
    int ok=0;
    char path[200];

    utn_getCadena(path,200,100,"Ingrese nombre del archivo:","Error.Utilice solo letras");
    strcat(path,".bin");

    FILE* f=fopen(path,"wb");
    sPokemon* aux;
    int tam=ll_len(lista);

    if(lista!=NULL&&f!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            aux=ll_get(lista,i);

            if(fwrite(aux,sizeof(sPokemon),1,f))
            {
                ok=1;

            }


        }

    }

    fclose(f);

    return ok;


}
int menuModifica(void)
{
    int opcion;

    printf("1 modificar nombre\n");
    printf("2 modificar fuerza\n");
    printf("3 modificar peso\n");
    printf("4 salir\n");
    utn_getEntero(&opcion,100,"opcion:","Error.Opcion invalida",1,4);


    return opcion;

}
int modificaPokemon(LinkedList* lista)
{
    int ok=0;
    system("cls");
    char sigueModificando='s';
    char confirma;
    char buffer[3][200];
    int posicion;

    sPokemon* aux;

    printf("pokemones en el sistema\n\n");
    list_pokemons(lista);

    utn_getEntero(&posicion,100,"Ingrese posicion a modificar:","Error.Utilice solo numeros\n",0,100000);

    if(lista!=NULL)
    {
        aux=ll_get(lista,posicion);
        system("cls");
        printf("    menu de modificaciones pokemon\n\n");

        printf("datos del pokemon ingresado\n\n");
        if(list_pokemon(aux))
        {
            printf("%s","Ingrese s para confirmar:");
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                do
                {
                    switch(menuModifica())
                    {
                    case 1:
                        do
                        {
                            printf("ingrese nuevo nombre:");
                            scanf("%s",buffer[0]);
                        }
                        while(pokemon_setNombre(aux,buffer[0])!=1);
                        break;
                    case 2:
                        do
                        {
                            printf("ingrese nuevo valor de fuerza:");
                            scanf("%s",buffer[1]);

                        }
                        while(pokemon_setFuerza(aux,buffer[1])!=1);

                        break;
                    case 3:
                        do
                        {
                            printf("ingrese nuevo valor de peso:");
                            scanf("%s",buffer[2]);

                        }
                        while(pokemon_setPeso(aux,buffer[2])!=1);
                        break;
                    case 4:
                        sigueModificando='n';
                        break;

                    }




                }
                while(sigueModificando=='s');
                posicion=ll_indexOf(lista,aux);
                if(!ll_set(lista,posicion,aux))
                {
                    ok=1;

                }


            }
            else
            {
                printf("modificacion cancelada\n");
            }


        }
        else
        {
            printf("posicion indicada vacia\n");

        }


    }


    return ok;
}
int bajaPokemon(LinkedList* lista)
{
    int ok=0;
    int posicion;
    char confirma;
    sPokemon* aux;
    list_pokemons(lista);
    utn_getEntero(&posicion,100,"ingrese posicion del pokemon\n(las posiciones empiezan en el cero):","Error.Utilice numeros\n",0,100000);
    if(lista!=NULL)
    {
        system("cls");
        aux=ll_get(lista,posicion);
        printf("datos del pokemon elegido:\n");
        if(list_pokemon(aux))
        {
            printf("ingrese s para confirmar:");
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                //ll_remove(aux,posicion);
                aux=ll_pop(lista,posicion);

                if(!ll_contains(lista,aux))
                {

                    destroy_pokemon(aux);
                    ok=1;

                }

            }
            else
            {
                printf("baja cancelada\n");


            }



        }
        else
        {
            printf("posicion indicada vacia\n");
        }


    }


    return ok;

}
int cmpNombre(void* a,void* b)
{
    int retorno=0;
    sPokemon* aux1;
    sPokemon* aux2;
    char nombre1[200];
    char nombre2[200];

    if(a!=NULL&&b!=NULL)
    {
        aux1=(sPokemon*)a;
        aux2=(sPokemon*)b;
        pokemon_getNombre(aux1,nombre1);
        pokemon_getNombre(aux2,nombre2);

        retorno=strcmp(nombre1,nombre2);

    }

    return retorno;


}
int cmpFuerza(void* a,void* b)
{
    int retorno=0;
    sPokemon* aux1;
    sPokemon* aux2;
    int fuerza1;
    int fuerza2;

    if(a!=NULL&&b!=NULL)
    {
        aux1=(sPokemon*)a;
        aux2=(sPokemon*)b;
        pokemon_getFuerza(aux1,&fuerza1);
        pokemon_getFuerza(aux2,&fuerza2);

        if(fuerza1>fuerza2)
        {
            retorno=1;

        }
        else if(fuerza1<fuerza2)
        {
            retorno=-1;

        }


    }

    return retorno;


}
int cmpPeso(void* a,void* b)
{
    int retorno=0;
    sPokemon* aux1;
    sPokemon* aux2;
    float peso1;
    float peso2;

    if(a!=NULL&&b!=NULL)
    {
        aux1=(sPokemon*)a;
        aux2=(sPokemon*)b;
        pokemon_getPeso(aux1,&peso1);
        pokemon_getPeso(aux2,&peso2);

        if(peso1>peso2)
        {
            retorno=1;

        }
        else if(peso1<peso2)
        {
            retorno=-1;

        }


    }

    return retorno;

}
int menuOrdena(void)
{
    int opcion;
    printf("1 ordenar por nombre.\n");
    printf("2 ordenar por fuerza.\n");
    printf("3 ordenar por peso.\n");
    printf("4 salir.\n");
    utn_getEntero(&opcion,100,"opcion:","Error.Opcion invalida\n",1,4);

    return opcion;

}
int ordenaPokemons(LinkedList* lista)
{
    int ok=0;
    char sigue='s';
    int criterio;
    system("cls");

    printf(" menu de ordenamientos\n\n");
    utn_getEntero(&criterio,100,"ingrese 1 para ordenar de manera ascendente,\no cero para ordenar de manera descendente:","Error.Opcion invalida",0,1);

    if(lista!=NULL)
    {
        do
        {
            switch(menuOrdena())
            {
            case 1:
                if(!ll_sort(lista,cmpNombre,criterio))
                {
                    ok=1;
                }
                break;
            case 2:
                if(!ll_sort(lista,cmpFuerza,criterio))
                {
                    ok=1;
                }
                break;
            case 3:
                if(!ll_sort(lista,cmpPeso,criterio))
                {
                    ok=1;
                }
                break;
            case 4:
                sigue='n';
                break;


            }

        }
        while(sigue=='s');

    }



    return ok;

}
int crearCopiaBinaria(LinkedList* lista)
{
    int ok=0;
    FILE* f=fopen("copiaseguridad.bin","wb");
    int tam=ll_len(lista);
    sPokemon* auxPokemon;

    LinkedList* aux;

    if(f!=NULL&&lista!=NULL)
    {
        aux=ll_clone(lista);

        if(ll_containsAll(lista,aux))
        {
            for(int i=0; i<tam; i++)
            {
                auxPokemon=ll_get(aux,i);

                if(fwrite(auxPokemon,sizeof(sPokemon),1,f))
                {
                    ok=1;

                }



            }


        }


    }

    fclose(f);
    return ok;


}
LinkedList* crearCopiaRango(LinkedList* Lista)
{
    system("cls");

    printf("       Clonar lista en rango rango elegido\n\n\n");


    LinkedList* clonada=NULL;
    int Min;
    int Max;
    char confirma;

    if(Lista!=NULL)
    {
        utn_getEntero(&Min,100,"Ingrese el limite inferior de la Lista:","Error.Utilice numeros.",0,29999);
        utn_getEntero(&Max,100,"Ingrese el limite superior de la Lista:","Error.Utilice numeros./n el rango superior debe ser mayor al infieror.",Min,29999);

        if(ll_len(Lista)>=Max)
        {
            clonada=ll_subList(Lista,Min,Max);
            if(clonada!=NULL)
            {
                printf("Lista copiada correctamente\n");
                printf("Ingrese s para visualizar y guardar la lista creada:");
                fflush(stdin);
                scanf("%c",&confirma);
                if(confirma=='s')
                {
                    list_pokemons(clonada);
                    if(guardarPokemonesCsv(clonada))
                    {
                        printf("Lista clonada guardada con exito\n");

                    }

                }
                else
                {
                    printf("volviendo al menu\n");
                }




            }


        }
        else
        {
            printf("Error al copiar lista.La lista a clonar no contiene elementos en los rangos ingresados\n");

        }

    }




    return clonada;
}
