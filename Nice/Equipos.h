#include "Jugadores.h"
typedef struct
{
    int codigo;
    char  nombreEquipo[51];
    char  localidad[51];
    eJugador jugadores;
    int estaVacio;
}eEquipo;

/*typedef struct
{
    int codigo;
    eEquipo equipo;
    eJugador jugador;
    eReferi referi;
    char fecha;
}ePartido;*/

//////////////////////////////////////
void inicializarEquipos(eEquipo[]);

void ingresarEquipo(eEquipo[], int);

int validacionNombreEquipo (char[]);

int validacionLocalidadEquipo(char[]);

void mostrarEquipos(eEquipo[]);

int menuEquipo(eEquipo[], int);
//////////////////////////////////////
