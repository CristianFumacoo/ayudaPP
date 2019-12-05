typedef struct
{
    int idPersona;
    int idDestino;
    char tipo;
    char estado;
    int estaVacio;
}eLlamada;

void inicializarLlamada(eLlamada[]);

void ingresarLlamada(eLlamada[], int, int);

void menuLlamada(eLlamada[], int, int);

int validacionNumeroL(char[]);
