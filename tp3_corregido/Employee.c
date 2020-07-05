#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn_biblioteca.h"
int obtenerId(int* id)
{
    int error=1;
    //*id=1000;

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

Employee* employee_new()
{


    return  (Employee*) malloc(sizeof(Employee));

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

    Employee* thiss=employee_new();
    Employee* retorno=NULL;

    if(thiss!=NULL)

    {


        if(employee_setId(thiss,idStr)
           &&employee_setHorasTrabajadas(thiss,horasTrabajadasStr)
           &&employee_setNombre(thiss,nombreStr)
           &&employee_setSueldo(thiss,sueldoStr))
        {

            retorno=thiss;

        }

    }

   return retorno;

   if(retorno==NULL)
   {
    employee_delete(thiss);
   }

}
void employee_delete(Employee* thiss)
{

    free(thiss);


}

int employee_setId(Employee* thiss,char* id)
{
    int ok=0;

    int auxid;

    if(thiss!=NULL&&id!=NULL&&!isInt(id))
    {
        auxid=atoi(id);

        obtenerId(&auxid);

        thiss->id=auxid;

        actualizarId(auxid);

        ok=1;


    }


    return ok;
}
int employee_getId(Employee* thiss,int* id)
{
    int ok=0;

    if(thiss!=NULL&&id!=NULL)
    {
        *id=thiss->id;
        ok=1;


    }

    return ok;
}

int employee_setNombre(Employee* thiss,char* nombre)
{
    int ok=0;

    if(thiss!=NULL&&nombre!=NULL&&strlen(nombre)<128&&!isLetras(nombre))
    {

        strcpy(thiss->nombre,nombre);
        ok=1;
    }


    return ok;


}
int employee_getNombre(Employee* thiss,char* nombre)
{
    int ok=0;

    if(thiss!=NULL&&nombre!=NULL)
    {

        strcpy(nombre,thiss->nombre);
        ok=1;


    }

    return ok;

}

int employee_setHorasTrabajadas(Employee* thiss,char* horasTrabajadas)
{
    int ok=0;


    if(thiss!=NULL&&horasTrabajadas!=NULL&&!isFloat(horasTrabajadas))
    {
        thiss->horasTrabajadas=atoi(horasTrabajadas);
        ok=1;

    }

    return ok;


}
int employee_getHorasTrabajadas(Employee* thiss,int* horasTrabajadas)
{
    int ok=0;

    if(thiss!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=thiss->horasTrabajadas;
        ok=1;

    }


    return ok;


}

int employee_setSueldo(Employee* thiss,char* sueldo)
{
    int ok=0;

        if(thiss!=NULL&&sueldo!=NULL&&!isInt(sueldo)) //la variable sueldo vino declarada como int en la cascara.
        {

            thiss->sueldo=atoi(sueldo);
            ok=1;

        }


    return ok;


}
int employee_getSueldo(Employee* thiss,int* sueldo)
{
    int ok=0;



    if(thiss!=NULL&&sueldo!=NULL)
    {
        *sueldo=thiss->sueldo;
        ok=1;


    }


    return ok;




}
