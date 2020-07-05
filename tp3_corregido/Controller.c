#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn_biblioteca.h"
#include "parser.h"
#include "controller.h"
#include "Employee.h"
int menu(void)
{
    int opcion;
    printf("        linkedlist         \n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    utn_getEntero(&opcion,100,"Opcion:","\nError.Opcion invalida",1,10);




    return opcion;
}


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ok=0;

    FILE* archivo;


    if(path!=NULL&&pArrayListEmployee!=NULL)
    {

        archivo=fopen(path,"r");
        if(parser_EmployeeFromText(archivo,pArrayListEmployee))
        {
            ok=1;



        }

    }

    fclose(archivo);



    return ok;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    int ok=0;
    FILE* archivo;

    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        archivo=fopen(path,"rb");
        if(parser_EmployeeFromBinary(archivo,pArrayListEmployee))
        {
            ok=1;

        }

    }

    fclose(archivo);

    return ok;

}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ok=0;
    system("cls");
    printf("    menu alta \n\n");
    Employee* nuevoEmpleado=employee_new();
    char auxNombre[200];
    char auxHorasTrabajadas[200];
    char auxSueldo[200];
    char auxId='0';

    if(pArrayListEmployee!=NULL&&nuevoEmpleado!=NULL)
    {
        do
        {
            printf("ingrese nombre:");
            scanf("%s",auxNombre);

        }
        while(!employee_setNombre(nuevoEmpleado,auxNombre));

        do
        {
            printf("ingrese horas trabajadas:");
            scanf("%s",auxHorasTrabajadas);

        }
        while(!employee_setHorasTrabajadas(nuevoEmpleado,auxHorasTrabajadas));
        do
        {
            printf("ingrese sueldo:");
            scanf("%s",auxSueldo);

        }
        while(!employee_setSueldo(nuevoEmpleado,auxSueldo));

        if( employee_setId(nuevoEmpleado,&auxId) )
        {
            ll_add(pArrayListEmployee,nuevoEmpleado);
            ok=1;


        }



    }


    return ok;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ok=0;
    int ubicacion;
    system("cls");
    Employee* aux;
    char auxNombre[200];
    char auxHorasTrabajadas[200];
    char auxSueldo[200];
    char sigue='s';
    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployees(pArrayListEmployee);
        utn_getEntero(&ubicacion,100,"posicion a modificar:","Error.Utilice numeros\n",0,10000);
        aux=ll_get(pArrayListEmployee,ubicacion);
        system("cls");
        printf("datos del empleado elegido: ");
        if(controller_ListEmployee(aux))
        {
            do
            {
                switch(opcionModifica())
                {
                case 1:
                    do
                    {
                        printf("Nombre nuevo:");
                        scanf("%s",auxNombre);
                        printf("modificacion exitosa\n");

                    }
                    while(!employee_setNombre(aux,auxNombre));
                    break;
                case 2:
                    do
                    {
                        printf("Nueva cantidad de horas trabajadas:");
                        scanf("%s",auxHorasTrabajadas);
                        printf("modificacion exitosa\n");
                    }
                    while(!employee_setHorasTrabajadas(aux,auxHorasTrabajadas));
                    break;
                case 3:
                    do
                    {
                        printf("sueldo nuevo:");
                        scanf("%s",auxSueldo);
                        printf("modificacion exitosa\n");

                    }
                    while(!employee_setSueldo(aux,auxSueldo));
                    break;
                case 4:
                    sigue='n';
                    break;
                }
                ok=1;

            }
            while(sigue=='s');

        }
        else
        {
            printf("no hay empleados en la posicion indicada\n");

        }

    }

    return ok;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ok=0;
    int posicion;
    char confirma;
    Employee* aux;
    system("cls");
    printf("menu de bajas\n\n");
    controller_ListEmployees(pArrayListEmployee);

    utn_getEntero(&posicion,100,"Ingrese posicion del empleado a eliminar:","Error.Utilice Numeros",0,100000);

    aux=(Employee*)ll_pop(pArrayListEmployee,posicion);

    system("cls");


    printf("datos del empleado ingresado:");

    if( controller_ListEmployee(aux))
    {
        printf("\n\n");
        printf("ingrese s para confirmar la baja:");
        scanf("%c",&confirma);

        if(confirma=='s')
        {

            employee_delete(aux);
            ok=1;

        }
        else
        {

            ll_push(pArrayListEmployee,posicion,aux);
            printf("baja cancelada\n");

        }


    }
    else
    {
        printf("no hay empleados en la posicion ingresada\n");

    }


    return ok;
}

int controller_ListEmployee(Employee* empleado)
{
    int ok=0;
    int auxHoras;
    int auxId;
    int auxSueldo;
    char auxNombre[200];

    if(empleado!=NULL)
    {
        if(employee_getHorasTrabajadas(empleado,&auxHoras)
                &&employee_getId(empleado,&auxId)
                &&employee_getSueldo(empleado,&auxSueldo)
                &&employee_getNombre(empleado,auxNombre))
        {

            printf("%5d  %10s   %5d               %6d\n",auxId,auxNombre,auxHoras,auxSueldo);
            ok=1;


        }


    }

    return ok;

}

int controller_ListEmployees(LinkedList* pArrayListEmployee)
{
    system("cls");
    int ok=0;
    int flagmostro=0;

    Employee* unEmpleado;

    if(pArrayListEmployee!=NULL)
    {

        int tam=ll_len(pArrayListEmployee);

        printf(" Id        Nombre     Horas trabajadas  Sueldo\n\n");

        for(int i=0; i<tam; i++)
        {
            unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

            if(controller_ListEmployee(unEmpleado))
            {
                flagmostro=1;

            }


        }

    }

    if(flagmostro==0)
    {

        printf("no hay empleados que listar\n");

    }


    return ok;
}

void controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    system("cls");
    printf("   menu de ordenamiento\n\n");
    int criterio;
    utn_getEntero(&criterio,100,"ingrese 1 para ordenamiento ascendente o 0 para ordenamiento descendente:","Error,Opcion invalida\n",0,1);

    switch(menuOrdenaPor())
    {

    case 1:
        ll_sort(pArrayListEmployee,cmpId,criterio);
        printf("ordenamiento realizado\n");
        break;
    case 2:
        ll_sort(pArrayListEmployee,cmpNombre,criterio);
        printf("ordenamiento realizado\n");
        break;
    case 3:
        ll_sort(pArrayListEmployee,cmpHoras,criterio);
        printf("ordenamiento realizado\n");
        break;
    case 4:
        ll_sort(pArrayListEmployee,cmpSueldo,criterio);
        printf("ordenamiento realizado\n");
        break;

    }

}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    int ok=0;
    int tam=ll_len(pArrayListEmployee);
    FILE* archivo=fopen(path,"w");
    Employee* unEmpleado;
    char auxNombre[200];
    int auxHoras;
    int auxSueldo;
    int auxId;

    if (path!=NULL&&pArrayListEmployee!=NULL&&archivo!=NULL)
    {

            fprintf(archivo,"id,nombre,horasTrabajadas,sueldo\n");
            for (int i=0; i<tam; i++)
            {
                unEmpleado=ll_get(pArrayListEmployee,i);

                employee_getHorasTrabajadas(unEmpleado,&auxHoras);
                employee_getNombre(unEmpleado,auxNombre);
                employee_getSueldo(unEmpleado,&auxSueldo);
                employee_getId(unEmpleado,&auxId);
                fprintf(archivo,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);
                ok=1;
            }



    }
    fclose(archivo);

    return ok;

}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ok=0;
    int escrito;
    int tam=ll_len(pArrayListEmployee);
    Employee* unEmpleado;
    FILE* archivo=fopen(path,"wb");

    if (path!=NULL&&pArrayListEmployee!=NULL&&archivo!=NULL)
    {
        for (int i=0; i<tam; i++)
        {
            unEmpleado=ll_get(pArrayListEmployee,i);
            escrito=fwrite(unEmpleado,sizeof(Employee),1,archivo);
            if(escrito)
            {
                ok=1;
            }


        }


    }

    return ok;


}

int opcionModifica(void)
{
    int modifica;

    printf("1 modifica nombre:\n");
    printf("2 modifica horas trabajadas:\n");
    printf("3 modifica sueldo:\n");
    printf("4 salir\n");
    utn_getEntero(&modifica,100,"opcion:","Error.Opcion invalida\n",1,4);



    return modifica;



}

int cmpId(void* a,void* b)
{
    int retorno=0;
    Employee* empleadoA;
    Employee* empleadoB;
    int idA;
    int idB;
    if(a!=NULL&&b!=NULL)
    {
        empleadoA=(Employee*)a;
        empleadoB=(Employee*)b;
        employee_getId(empleadoA,&idA);
        employee_getId(empleadoB,&idB);

        if(idA>idB)
        {
            retorno=1;

        }
        else if(idA<idB)
        {
            retorno=-1;

        }


    }

    return retorno;

}
int cmpSueldo(void* a,void*b)
{

    int retorno=0;
    Employee* empleadoA;
    Employee* empleadoB;
    int sueldoA;
    int sueldoB;

    if(a!=NULL&&b!=NULL)
    {
        empleadoA=(Employee*)a;
        empleadoB=(Employee*)b;
        employee_getSueldo(empleadoA,&sueldoA);
        employee_getSueldo(empleadoB,&sueldoB);
        if(sueldoA>sueldoB)
        {
            retorno=1;

        }
        else if(sueldoA<sueldoB)
        {
            retorno=-1;

        }


    }

    return retorno;


}
int cmpNombre(void* a,void*b)
{
    int retorno=0;
    Employee* empleadoA;
    Employee* empleadoB;
    char nombreA[200];
    char nombreB[200];

    if(a!=NULL&&b!=NULL)
    {
        empleadoA=(Employee*)a;
        empleadoB=(Employee*)b;
        employee_getNombre(empleadoA,nombreA);
        employee_getNombre(empleadoB,nombreB);

        retorno=strcmp(nombreA,nombreB);

    }


    return retorno;


}
int cmpHoras(void* a,void* b)
{

    int retorno=0;
    Employee* empleadoA;
    Employee* empleadoB;
    int auxHorasA;
    int auxHorasB;

    if(a!=NULL&&b!=NULL)
    {
        empleadoA=(Employee*)a;
        empleadoB=(Employee*)b;
        employee_getHorasTrabajadas(empleadoA,&auxHorasA);
        employee_getHorasTrabajadas(empleadoB,&auxHorasB);

        if(auxHorasA>auxHorasB)
        {
            retorno=1;

        }
        else if(auxHorasA<auxHorasB)
        {
            retorno=-1;

        }


    }

    return retorno;

}
int menuOrdenaPor(void)
{
    int retorno;
    printf("1 ordenar por id\n");
    printf("2 ordenar por nombre\n");
    printf("3 ordenar por horas trabajadas\n");
    printf("4 ordenar por sueldo\n");
    utn_getEntero(&retorno,100,"opcion:","Error.Opcion invalida\n",1,4);
    return retorno;

}

