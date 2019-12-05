#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "persona.h"

#define M 4

void inicializarPersona(ePersona personas[M])
{
    int i;
    int idPersonaHard[4] = {1,2,3,4};
    char nombreHard[4][50] = {"Emilio","Juana","Pedrito","Juliana"};
    int numeroHard[4] = {4789589,45789612,45576133,45163316};

    for(i=0;i<M;i++)
    {
        personas[i].estaVacio = 4;
        personas[i].idPersona = idPersonaHard[i];
        strcpy(personas[i].nombre, nombreHard[i]);
        personas[i].numeroDeTelefono = numeroHard[i];
    }
}


void menuPersona(ePersona personas[M], int idPersona)
{
    int opcion;
    char respuesta = 's';
    int codigoModificacion;

    do
    {
        system("cls");
        printf("Ingrese la opcion a realizar.\n \n");
        printf("1.Ingresar. \n");
        printf("2.Modificar. \n");
        printf("3.Eliminar. \n");
        printf("4.Mostrar\n");
        printf("5.Salir de este menu. \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                ingresarPersona(personas, idPersona);
                idPersona++;
                printf("Se ha cargado correctamente!\n");
                system("pause");
                break;
            case 2:
                codigoModificacion = modificarPersona(personas);
                break;
            case 3:
                eliminarPersona(personas);
                system("pause");
                break;
            case 4:
                mostrarPersona(personas);
                system("pause");
                break;
            case 5:
                respuesta = 'n';
                break;
        }
    }while(respuesta == 's');
}

void ingresarPersona(ePersona persona[M], int idPersona)
{
    int i;
    for(i = 0; i < M; i++)
    {
        if(persona[i].estaVacio == 4)
        {

        printf("Ingrese el nombre de la persona: ");
        fflush(stdin);
        scanf("%s", &persona[i].nombre);

        while(validacionNombre(persona[i].nombre) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(persona[i].nombre);
        }


            char auxNumero[M];
            printf("Ingrese numero de celular de la persona: ");
            fflush(stdin);
            scanf("%s", &auxNumero);

            while(validacionNumero(auxNumero) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxNumero);
            }
            persona[i].numeroDeTelefono=atoi(auxNumero);

            persona[i].idPersona = idPersona;
            persona[i].estaVacio = 1;

            break;
        }
    }
}

void eliminarPersona(ePersona personas[M])
{
    int i;
    int auxCodigo;
    printf("¿Que persona quiere eliminar?\n");
    mostrarPersona(personas);
    fflush(stdin);
    scanf("%d", &auxCodigo);

    for(i=0;i<M;i++)
    {
        if(personas[i].idPersona == auxCodigo)
        {
            personas[i].estaVacio = 0;
            personas[i].idPersona = 0;
            strcpy(personas[i].nombre, " ");
            personas[i].numeroDeTelefono = 0;

            printf("Se borro exitosamente.");
        }
    }
}

void mostrarPersona(ePersona personas[M])
{
    int i;

    if(hayPersona(personas) == 0)
    {
        printf("No hay personas ingresadas\n");
    }
    else
    {
        printf("Listado de personas ingresadas: \n");
        printf("Id Persona\t\t Nombre\t\t Numero de Celular\n");

        for(i = 0; i < M; i++)
        {
            if(personas[i].estaVacio == 1)
            {
                printf("%d\t\t\t %s\t\t\t %d\n", personas[i].idPersona, personas[i].nombre, personas[i].numeroDeTelefono);
            }
        }
    }
}


int hayPersona(ePersona personas[M])
{
    int i;

    for(i=0; i<M; i++)
    {
        if(personas[i].estaVacio == 1)
        {
            return 1;
        }
    }
    return 0;
}

int modificarPersona(ePersona personas[M])
{
    int i;
    int auxCodigo;
    printf("¿Que persona quiere modificar?\n");
    mostrarPersona(personas);
    fflush(stdin);
    scanf("%d", &auxCodigo);

    for(i=0;i<M;i++)
    {
        if(personas[i].idPersona == auxCodigo)
        {
            char auxNumero[M];
            printf("Ingrese nuevo numero de celular de la persona: ");
            fflush(stdin);
            scanf("%s", &auxNumero);

            while(validacionNumero(auxNumero) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxNumero);
            }
            personas[i].numeroDeTelefono=atoi(auxNumero);
        }

    }
}

























int validacionNombre(char str[])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int validacionNumero(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

