typedef struct
{
    int codigo;
    char  nombreJugador[31];
    char  apellidoJugador[31];
    char  sexoJugador;
    char fechaNacimientoJugador;
    int estaVacio;
}eJugador;

void inicializarJugadores(eJugador[]);

void ingresarJugador(eJugador[],int);

int validacionNombreJugador(char[]);

int validacionApellidoJugador(char[]);

int validacionSexoJugador(char);

int validarFechaNacimientoJugador(int, int, int);

void mostrarJugador(eJugador[]);

int menuJugador(eJugador[],int);

