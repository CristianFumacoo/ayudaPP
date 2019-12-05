typedef struct
{
    int codigo;
    char  nombreReferi[31];
    char  apellidoReferi[31];
    char  sexoReferi;
    char  eMail[31];
    char fechaNacimientoReferi;
    int estaVacio;
}eReferi;

int menuReferi(eReferi[], int);

void ingresarReferi(eReferi[], int);

void mostrarReferis(eReferi[]);

void inicializarReferis(eReferi[]);

void modificarReferi(eReferi[], int);

int pedirModificado(eReferi[]);

void eliminarReferi(eReferi[]);

void ordenarReferis(eReferi[]);

int existeCodigo(eReferi[], int);

int hayReferis(eReferi[]);

int validacionNombreReferi(char[]);

int validacionApellidoReferi(char[]);

int validacionSexoReferi(char);

int validacionFechaNacimientoReferi(int, int, int);
