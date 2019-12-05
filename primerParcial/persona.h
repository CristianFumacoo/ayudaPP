typedef struct
{
    int idPersona;
    char nombre[6][50];
    int numeroDeTelefono;
    int estaVacio;
}ePersona;

void inicializarPersona (ePersona[]);

void ingresarPersona(ePersona[], int);

void menuPersona(ePersona[], int);

void eliminarPersona(ePersona[]);

void mostrarPersona(ePersona[]);

int modificarPersona(ePersona[]);

int hayPersona(ePersona[]);

int validacionNombre(char[]);

int validacionNumero(char[]);
