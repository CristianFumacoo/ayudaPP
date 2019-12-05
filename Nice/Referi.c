#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Referi.h"

#define MAX 100
#define CANT 51

/*INICIO FUNCIONES REFERI*/
void inicializarReferi(eReferi referis[MAX])
{
    int i;

    for(i=0; i<MAX; i++)
    {
        strcpy(referis[i].nombreReferi, " ");
        strcpy(referis[i].apellidoReferi, " ");
        referis[i].fechaNacimientoReferi = ' ';
        referis[i].codigo = 0;
        referis[i].estaVacio = 0;
    }
}

int menuReferi(eReferi referis[MAX], int codigoReferi)
{
    char respuesta = 's';
    char opcion;
    int codigoModificacion;

    do
    {
        system("cls");
        printf("Ingrese la opcion a realizar.\n \n");
        printf("1.Ingresar. \n");
        printf("2.Modificar. \n");
        printf("3.Eliminar. \n");
        printf("4.Mostrar.\n");
        printf("5.Ordenar por Nombre.\n");
        printf("6.Salir de este menu. \n");
        fflush(stdin);
        scanf("%c", &opcion);

        switch(opcion)
        {
        case '1':
            ingresarReferi(referis, codigoReferi);
            codigoReferi++;
            printf("Se ha cargado correctamente. \n");
            system("pause");
            break;
        case '2':
            codigoModificacion = pedirModificado(referis);
            system("pause");
            //modificarReferi(referis, codigoModificacion);
            break;
        case '3':
            eliminarReferi(referis);
            break;
        case '4':
            mostrarReferis(referis);
            system("pause");
            break;
        case '5':
                ordenarReferis(referis);
                system("pause");
                break;
        case '6':
            respuesta = 'n';
        }

    }
    while(respuesta == 's');

    return codigoReferi;
}

void ingresarReferi(eReferi referi[MAX], int codigoReferi)
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        if(referi[i].estaVacio == 0)
        {
            printf("Ingrese el nombre del referi: ");
            fflush(stdin);
            scanf("%s", &referi[i].nombreReferi);

            while(validacionNombreReferi(referi[i].nombreReferi) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(referi[i].nombreReferi);
            }

            printf("Ingrese el apellido del referi: ");
            fflush(stdin);
            scanf("%s", &referi[i].apellidoReferi);

            while(validacionLocalidadEquipo(referi[i].apellidoReferi) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(referi[i].apellidoReferi);
            }

            /////////////////////////////////////////////

            char sexo;

            printf("Ingrese sexo del referi: ");
            fflush(stdin);
            scanf("%c", &sexo);

            while(validacionSexoJugador(sexo) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                scanf("%c", &sexo);
            }
            referi[i].sexoReferi = sexo;

            int anio;
            int mes;
            int dia;

            printf("Ingrese nacimiento, (dia/mes/año): ");
            fflush(stdin);
            scanf("%d/%d/%d", &dia, &mes, &anio);

            while (validacionFechaNacimientoReferi(dia,mes,anio) == 0)
            {
                fflush(stdin);
                scanf("%d/%d/%d", &dia, &mes, &anio);
            }
            referi[i].fechaNacimientoReferi = dia + '/' + mes + '/' + anio;

            referi[i].codigo = codigoReferi;
            referi[i].estaVacio = 1;
            break;
        }

    }
}

void mostrarReferis(eReferi referis[MAX])
{
    int i;

    if(hayReferis(referis) == 0)
    {
        printf("No hay referis ingresados\n");
    }
    else
    {
        printf("Listado de referis ingresados: \n");
        printf("Codigo Referis\t\t Nombre\t\t\t Apellido\t\t Sexo \t\t Fecha nac\n");

        for(i = 0; i < MAX; i++)
        {
            if(referis[i].estaVacio == 1)
            {
                printf("%d\t\t\t %s\t\t %s\t\t %c\t\t %c\t\t \n", referis[i].codigo, referis[i].nombreReferi, referis[i].apellidoReferi, referis[i].sexoReferi, referis[i].fechaNacimientoReferi);
            }
        }
    }
}

int hayReferis(eReferi referis[MAX])
{
    int i;

    for(i=0; i<MAX; i++)
    {
        if(referis[i].estaVacio == 1)
        {
            return 1;
        }
    }
    return 0;
}

int existeCodigo(eReferi referis[MAX], int codigoReferi)
{
    int i;

    for(i=0; i<MAX; i++)
    {
        if(referis[i].estaVacio == 1)
        {
            if(referis[i].codigo == codigoReferi);
            {
                //printf("Codigo de lista: %d\t codigo ingresado %d", referis[i].codigo, codigoReferi);
                return 1;
                break;
            }
        }
    }
    return 0;
}

int pedirModificado(eReferi referis[MAX])
{
    int auxCodigo;
    int i;
    printf("¿Que referi quiere modificar?\n");
    mostrarReferis(referis);
    fflush(stdin);
    scanf("%d", &auxCodigo);

    /*while(existeCodigo(referis, auxCodigo) == 1)
    {
        printf("El codigo no existe.");
        fflush(stdin);
        scanf("%d", &auxCodigo);
    }*/

    for(i=0;i<MAX;i++)
    {
    if(referis[i].codigo == auxCodigo)
    {
            char respuesta = 's';

        do
        {
            int menuModificar;
            printf("¿Que quiere modificar?");
            printf("1.Nombre\n");
            printf("2.Apellido\n");
            printf("3.Sexo.\n");
            printf("4.Fecha de nacimiento\n");
            printf("5.Salir\n");
            fflush(stdin);
            scanf("%d", &menuModificar);

            switch(menuModificar)
            {
            case 1:
                printf("Ingrese nuevo nombre: ");
                scanf("%s", &referis[i].nombreReferi);
                printf("Se modifico con exito");
                break;
            case 2:
                printf("Ingrese nuevo apellido: ");
                scanf("%s", &referis[i].apellidoReferi);
                printf("Se modifico con exito");
                break;
            case 3:
                printf("Ingrese nuevo sexo: ");
                scanf("%c", &referis[i].sexoReferi);
                printf("Se modifico con exito");
                break;
            case 4:
                printf("Ingrese nueva fecha de nacimiento: ");
                scanf("%s", &referis[i].fechaNacimientoReferi);
                printf("Se ha midificado con exito");
                break;
            case 5:
                respuesta = 'n';
                break;
            }
        }
        while(respuesta == 's');
    }
}
}

void eliminarReferi(eReferi referis[MAX])
{
    int i;
    int auxCodigo;
    printf("¿Que referi quiere eliminar?\n");
    mostrarReferis(referis);
    fflush(stdin);
    scanf("%d", &auxCodigo);

    for(i=0;i<MAX;i++)
    {
        if(referis[i].codigo == auxCodigo)
        {
            strcpy(referis[i].nombreReferi, " ");
            strcpy(referis[i].apellidoReferi, " ");
            referis[i].fechaNacimientoReferi = ' ';
            referis[i].codigo = 0;
            referis[i].estaVacio = 0;

            printf("Se borro exitosamente.");
        }
    }
}

void ordenarReferis(eReferi referis[MAX])
{
    int i, j;
    eReferi auxReferi;

    for(i=0;i<MAX;i++)
    {
        for(j=i;j<MAX;j++)
        {
            if(strcmp(referis[i].nombreReferi, referis[j].nombreReferi) > 0)
            {
                auxReferi = referis[i];
                referis[i] = referis[j];
                referis[j] = auxReferi;
            }
        }
    }
    mostrarReferis(referis);
}

int validacionNombreReferi(char str[CANT])
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

int validacionApellidoReferi(char str[CANT])
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

int validacionSexoReferi(char str)
{
    if(str != 'F' && str != 'M' && str != 'f' && str != 'm')
    {
        return 0;
    }
    return 1;
}

int validacionFechaNacimientoReferi(int dia, int mes, int anio)
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

/*FIN FUNCIONES REFERI*/

