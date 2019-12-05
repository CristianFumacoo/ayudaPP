#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Equipos.h"

#define MAX 100
#define CANT 51

/*INICIO FUNCIONES DE LOS EQUIPOS*/
void inicializarEquipos(eEquipo equipos[MAX])
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        equipos[i].estaVacio = 0;
        equipos[i].codigo = 0;
        strcpy(equipos[i].localidad, " ");
        strcpy(equipos[i].nombreEquipo, " ");
    }
}
int menuEquipo(eEquipo equipos[MAX], int codigoEquipo)
{
    char respuesta = 's';
    char opcion;
    do
    {
        system("cls");
        printf("Ingrese la opcion a realizar.\n \n");
        printf("1.Ingresar. \n");
        printf("2.Modificar. \n");
        printf("3.Eliminar. \n");
        printf("4.Mostrar.\n");
        printf("5.Salir de este menu. \n");
        fflush(stdin);
        scanf("%c", &opcion);

        switch(opcion)
        {
            case '1':
                ingresarEquipo (equipos, codigoEquipo);
                codigoEquipo++;
                printf("Se ha cargado correctamente. \n");
                system("pause");
                break;
            case '4':
                mostrarEquipos(equipos);
                system("pause");
                break;
            case '5':
                respuesta = 'n';
        }

    }while(respuesta == 's');

    return codigoEquipo;
}
void ingresarEquipo (eEquipo equipos[MAX], int codigoEquipo)
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        //cuando encontramos el primer lugar del array vacio, asignamos los valores a ese espacio
        if(equipos[i].estaVacio == 0)
        {
            printf("Ingrese el nombre del equipo: ");
            fflush(stdin);
            scanf("%s", &equipos[i].nombreEquipo);

            while(validacionNombreEquipo(equipos[i].nombreEquipo) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(equipos[i].nombreEquipo);
            }

            printf("Ingrese la localidad del equipo: ");
            fflush(stdin);
            scanf("%s", &equipos[i].localidad);

            while(validacionLocalidadEquipo(equipos[i].localidad) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(equipos[i].localidad);
            }

            /*asignamos los ultimos valores y salimos del metodo*/
            equipos[i].codigo = codigoEquipo;
            equipos[i].estaVacio = 1;//cambiamos la bandera para indicar que ya tiene valores cargados
            break;
        }
    }
}

int validacionNombreEquipo(char str[])
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

int validacionLocalidadEquipo(char str[CANT])
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

void mostrarEquipos(eEquipo equipos[MAX])
{
    int i;
    printf("Listado de equipos ingresados: \n");
    printf("Codigo Equipo\t\t Nombre\t\t\t Localidad\t\t \n");

    for(i = 0; i < MAX; i++)
    {
        if(equipos[i].estaVacio == 1)
        {
            printf("%d\t\t\t %s\t\t\t %s\t\t \n", equipos[i].codigo, equipos[i].nombreEquipo, equipos[i].localidad);
        }
    }
}
/*FIN FUNCIONES DE LOS EQUIPOS*/

