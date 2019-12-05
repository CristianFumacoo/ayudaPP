#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Jugadores.h"

#define MAX 100
#define CANT 51

/*INICIO FUNCIONES JUGADOR*/
void inicializarJugadores(eJugador jugadores[MAX])
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        jugadores[i].estaVacio = 0;
        jugadores[i].codigo = 0;
        strcpy(jugadores[i].nombreJugador, " ");
        strcpy(jugadores[i].apellidoJugador, " ");
        jugadores[i].sexoJugador = ' ';
        jugadores[i].fechaNacimientoJugador = ' ';
        //strcpy(jugadores[i].fechaNacimientoJugador, " ");
    }
}
int menuJugador(eJugador jugadores[MAX], int codigoJugador)
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
                ingresarJugador(jugadores, codigoJugador);
                codigoJugador++;
                printf("Se ha cargado correctamente. \n");
                system("pause");
                break;
            case '4':
                mostrarJugador(jugadores);
                system("pause");
                break;
            case '5':
                respuesta = 'n';
        }

    }while(respuesta == 's');

    return codigoJugador;
}
void ingresarJugador(eJugador jugadores[MAX],int codigoJugador)
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        printf("Ingrese el nombre del Jugador: ");
        fflush(stdin);
        scanf("%s", &jugadores[i].nombreJugador);

        while(validacionNombreEquipo(jugadores[i].nombreJugador) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(jugadores[i].nombreJugador);
        }

        printf("Ingrese el apellido del Jugador: ");
        fflush(stdin);
        scanf("%s", &jugadores[i].apellidoJugador);

        while(validacionLocalidadEquipo(jugadores[i].apellidoJugador) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(jugadores[i].apellidoJugador);
        }

        /////////////////////////////////////////////

        char sexo;

        printf("Ingrese sexo del Jugador: ");
        fflush(stdin);
        scanf("%c", &sexo);

        while(validacionSexoJugador(sexo) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            scanf("%c", &sexo);
        }
        jugadores[i].sexoJugador = sexo;

        int anio;
        int mes;
        int dia;

        printf("Ingrese nacimiento, (dia/mes/año): ");
        fflush(stdin);
        scanf("%d/%d/%d", &dia, &mes, &anio);

        while (validarFechaNacimientoJugador(dia,mes,anio) == 0)
        {
            fflush(stdin);
            scanf("%d/%d/%d", &dia, &mes, &anio);
        }
        jugadores[i].fechaNacimientoJugador = dia + '/' + mes + '/' + anio;

        //una vez ingresados todos los datos, asignamos el codigo.
        jugadores[i].codigo = codigoJugador;
        jugadores[i].estaVacio = 1;
        break;
    }
}

int validacionNombreJugador(char str[])
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

int validacionApellidoJugador(char str[])
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

int validacionSexoJugador(char str)
{
    if(str != 'F' && str != 'M' && str != 'f' && str != 'm')
        return 0;

    return 1;
}

int validarFechaNacimientoJugador(int dia, int mes, int anio)
{
    if(anio>=1900 && anio<=9999)
    {
        if(mes>=1 && mes<=12)
        {
            if((dia>=1 && dia<=31) && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12))
                return 1;
            else if((dia>=1 && dia<=30) && (mes==4 || mes==6 || mes==9 || mes==11))
                return 1;
            else if((dia>=1 && dia<=28) && (mes==2))
                return 1;
            else if(dia==29 && mes==2 && (anio%400==0 ||(anio%4==0 && anio%100!=0)))
                return 1;
            else
            {
                printf("El dia es invalido.\n");
                return 0;
            }

        }
        else
        {
            printf("El mes es invalido.\n");
            return 0;
        }
    }
    else
    {
        printf("El año es invalido.\n");
        return 0;
    }
}
void mostrarJugador(eJugador jugadores[MAX])
{
    int i;
    printf("Listado de jugadores ingresados: \n");
    printf("Codigo Jugador\t Nombre \t Apellido\t sexo\t fecha nac \n");

    for(i = 0; i < MAX; i++)
    {
        if(jugadores[i].estaVacio == 1)
        {
            printf("%d\t\t %s\t\t %s\t %c\t %c\n", jugadores[i].codigo,
                                                   jugadores[i].nombreJugador,
                                                   jugadores[i].apellidoJugador,
                                                   jugadores[i].sexoJugador,
                                                   jugadores[i].fechaNacimientoJugador);
        }
    }
}
/*FIN FUNCIONES JUGADOR*/
