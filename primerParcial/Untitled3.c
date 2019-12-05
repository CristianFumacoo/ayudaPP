#include <stdio.h>
#include <stdlib.h>

#include "persona.h"
#include "llamada.h"

#define M 100
int main ()
{
    int opcion;
    char respuesta = 's';
    int idPersona = 1;
    int idLlamada = 1;
    ePersona personas[M];
    eLlamada llamadas[M];

    inicializarPersona(personas);

    do
    {
        printf("Bienvenido a mi parcial!\n\n");
        printf("¿Que desea ingresar?\n");
        printf("1.Persona\n");
        printf("2.Llamada\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                menuPersona(personas, idPersona);
                break;
            case 2:
                menuLlamada(llamadas,idPersona,idLlamada);
                break;
        }

    }while(respuesta == 's');


}
