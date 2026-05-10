#ifndef MYLIBRARY_H
#define MYLIBRARY_H
//Defino estructuras y prototipos de funciones

// Aquí defino cómo es una "Actividad". Es básicamente una ficha con toda la info del CSV.
typedef struct {
    int anio, mes, dia;
    char dia_semana[40];
    char hora_inicio[15];
    char hora_fin[15];
    char actividad[120];
    char modalidad[120];
    char centro[120];
    int plazas, ocupadas, libres;
    char tipo_actividad[120];
} Actividad;

int esMismoDia(Actividad a, int dia, int mes, int anio);
int obtenerCentrosUnicos(Actividad* v, int n, int dia, int mes, int anio, char centros[][120]);
void listadoActividadesPorCentroInteractivo(Actividad* v, int n, int dia, int mes, int anio);
void frecuenciaActividades(Actividad* v, int n, int dia, int mes, int anio);
void actividadMasPopularPorCentro(Actividad* v, int n, int dia, int mes, int anio);
void ocupacionMediaPorCentro(Actividad* v, int n, int dia, int mes, int anio);
void franjasHorariasPico(Actividad* v, int n, int dia, int mes, int anio);
void detectarLlenos(Actividad* v, int n, int dia, int mes, int anio);
//Funcionesd e la interfaz
void gotoxy(int x, int y);
void escribiropciones();
void DibujarMenu();
void Texto1();
int leerNumero();

#endif
