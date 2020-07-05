#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_biblioteca.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char sigue='s';
    int flagCargo=0;


    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados==NULL)
    {
        printf("Error.No se consiguio memoria");
        exit(EXIT_FAILURE);

    }


    do
    {
        switch(menu())
        {
        case 1:
           if(!flagCargo)
           {
              controller_loadFromText("data.csv",listaEmpleados);
              printf("empleados cargados con exito\n");
              flagCargo=1;


           }
           else
           {
              printf("ya se han cargado los empleados\n");

           }


            break;
        case 2:
            if(!flagCargo)
            {
                controller_loadFromBinary("data.bin",listaEmpleados);
                printf("empleados cargados con exito\n");
                flagCargo=1;
            }
            else
            {
                printf("ya se han cargado los empleados\n");

            }

            break;
        case 3:
            if(controller_addEmployee(listaEmpleados))
            {
                printf("alta exitosa\n");


            }
            else
            {
                printf("no se pudo realizar el alta");

            }
            break;
        case 4:
            if(ll_len(listaEmpleados)>0)
            {
              if(controller_editEmployee(listaEmpleados))
              {
                  printf("modificaciones guardadas\n");
              }
              else
              {

              }

            }
            else
            {
                printf("sistema vacio\n");

            }
            break;
        case 5:
            if(ll_len(listaEmpleados)>0)
            {
               if(controller_removeEmployee(listaEmpleados))
               {
                  printf("baja exitosa\n");
               }
               else
               {
                  printf("no se realizo la baja\n");
               }

            }
            else
            {
                printf("sistema vacio\n");
            }
            break;
        case 6:
            if(ll_len(listaEmpleados)>0)
            {

                controller_ListEmployees(listaEmpleados);
            }
            else
            {
                printf("sistema vacio\n");

            }
            break;
        case 7:
            if(ll_len(listaEmpleados)>0)
            {

                controller_sortEmployee(listaEmpleados);

            }
            else
            {
                printf("sistema vacio\n");

            }

            break;
        case 8:
            if(ll_len(listaEmpleados)>0)
            {
                if(controller_saveAsText("datosguardados.csv",listaEmpleados))
                {
                    printf("archivo guardado correctamente\n");

                }
                else
                {
                    printf("no se pudo guardar el archivo\n");
                }

            }
            else
            {
                printf("sistema vacio\n");

            }
            break;
        case 9:
            if(ll_len(listaEmpleados)>0)
            {

                if( controller_saveAsBinary("datosguardados.bin",listaEmpleados))
                {
                    printf("archivo guardado correctamente\n");
                }
                else
                {
                    printf("no se pudo guardar el archivo\n");

                }

            }
            else
            {
                printf("sistema vacio\n");

            }

            break;
        case 10:
            sigue='n';
            ll_deleteLinkedList(listaEmpleados);
            break;

        }

        system("pause");
        system("cls");
    }
    while(sigue=='s');
    return 0;
}
