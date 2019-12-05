#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "llamada.h"

#define M 100

void inicializarLlamada(eLlamada llamadas[M])
{
    int i;

    for(i=0;i<M;i++)
    {
         llamadas[i].idPersona = 0;
         llamadas[i].idDestino = 0;
         strcpy(llamadas[i].tipo, " ");
         strcpy(llamadas[i].estado, " ");
    }

}

void menuLlamada(eLlamada llamadas[M], int idLlamadas, int idPersona)
{
    int opcion;
    char respuesta = 's';
    int codigoModificacion;

    do
    {
        system("cls");
        printf("Ingrese la opcion a realizar.\n \n");
        printf("1.Ingresar. \n");
        printf("5.Salir de este menu. \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                ingresarLlamada(llamadas, idLlamadas, idPersona);
                idLlamadas++;
                printf("Ingresado correctamente.");
                system("pause");
                break;
            case 5:
                respuesta = 'n';
                break;

        }
    }while(respuesta == 's');
}

ingresarLlamada(eLlamada llamadas[M], int idLlamadas, int idPersonaL)
{
    int i;
    int tipo;
    //char tipoElegido[50];
    int estado;
    //char estadoElegido[50];
    for(i = 0; i < M; i++)
    {
        if(llamadas[i].estaVacio == 0)
        {
            char auxLlamante[M];
            printf("Ingrese el id del que llama: ");
            fflush(stdin);
            scanf("%s", &auxLlamante);

            while(validacionNumero(auxLlamante) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxLlamante);
            }
            llamadas[i].idPersona=atoi(auxLlamante);


            char auxLlamado[M];
            printf("Ingrese el id del que va a ser llamado: ");
            fflush(stdin);
            scanf("%s", &auxLlamado);

            while(validacionNumero(auxLlamado) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxLlamado);
            }
            llamadas[i].idPersona=atoi(auxLlamado);

            printf("Ingrese tipo de la llamada \n");
            printf("1.Corta\n");
            printf("2.Larga\n");
            fflush(stdin);
            scanf("%d", &tipo);

            switch(tipo)
            {
                case 1:
                    strcpy(llamadas[i].tipo, "Corta");
                    //tipoElegido[50] = ("Corta");
                    break;
                case 2:
                    strcpy(llamadas[i].tipo, "Larga");
                    //tipoElegido[50] = ("LargaDistancia");
                    break;
            }

            printf("Ingrese estado de la llamada \n");
            printf("1.En curso.\n");
            printf("2.Terminada.\n");
            printf("3.No se pudo conectar.\n");
            fflush(stdin);
            scanf("%d", &estado);

            switch(estado)
            {
                case 1:
                    strcpy(llamadas[i].estado, "EnCurso");
                    //estadoElegido[50] = ("EnCurso");
                    break;
                case 2:
                    break;
                case 3:

                    break;
            }

            llamadas[i].idPersona = idPersonaL;
            llamadas[i].idDestino = idLlamadas;
            llamadas[i].estaVacio = 1;
            break;


        }
    }
}



int validacionNumeroL(char str[])
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
