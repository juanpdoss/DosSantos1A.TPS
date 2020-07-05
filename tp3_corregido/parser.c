#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ok=0;
    int leido;
    Employee* unEmpleado;

    char bufferEntrada[4][200];

    if (pFile!=NULL&&pArrayListEmployee!=NULL)
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferEntrada[0],bufferEntrada[1],bufferEntrada[2],bufferEntrada[3]);
        while(!feof(pFile))
        {

            leido=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferEntrada[0],bufferEntrada[1],bufferEntrada[2],bufferEntrada[3]);
            unEmpleado=employee_new();
            if(unEmpleado!=NULL)
            {
                if (leido==4)
                {

                    unEmpleado=employee_newParametros(bufferEntrada[0],bufferEntrada[1],bufferEntrada[2],bufferEntrada[3]);
                    ll_add(pArrayListEmployee,unEmpleado);
                    ok=1;


                }


            }

        }

    }

   //bloque para generar el archivo data.bin la primera vez

//    int tam=ll_len(pArrayListEmployee);
//
//    FILE* b=fopen("data.bin","wb");
//
//    for(int i=0;i<tam;i++)
//    {
//
//        unEmpleado=employee_new();
//        unEmpleado=ll_get(pArrayListEmployee,i);
//        if(unEmpleado!=NULL)
//        {
//          fwrite(unEmpleado,sizeof(Employee),1,b);
//
//        }
//
//
//    }
//
//    fclose(b);

    return ok;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ok=0;
    int leido;
    Employee* unEmpleado;


    if(pFile!=NULL&&pArrayListEmployee!=NULL)
    {
        while (!feof(pFile))
        {

            unEmpleado=employee_new();

            if (unEmpleado!=NULL)
            {
                leido=fread(unEmpleado,sizeof(Employee),1, pFile);

                if (leido == 1)
                {
                    employee_setId(unEmpleado,"1");
                    ll_add(pArrayListEmployee,unEmpleado);
                    ok = 1;

                }

            }

        }


    }



    return ok;

}
