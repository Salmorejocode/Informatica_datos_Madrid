
namespace Esquema_informatica

/*esquema muy basico de como iremso desarrollano el menu de la main */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_REGISTROS 3000 //swgun svc 

typedef struct {               /* declaracion de las variables,
                               cada una de ellas con su tipo de dato correspondiente, 
                               para almacenar la informacion del csv, sufrira modificaciones a medida que desarrollaremos el programa */
    int anio, mes, dia;
    char dia_semana[15];
    char hora_inicio[15];
    char hora_fin[15];
    char actividad[70];
    char modalidad[70];
    char centro[70];
    int plazas;
    int ocupadas;
    int libres;
    char tipo_actividad[50];
}
Registro;


    int void main()
{
    Registro datos[];
    int totalRegistros = 0;

    // 1. Cargar los datos desde el CSV
    /* paso mas impotante del codigo ya que implica la lectura correcta de los archivos csc que nos permitiran desarrollar el programa */
   

    // 2. Menú principal
    int opcion;
    do
    {
        printf("\n--- GESTION DEPORTIVA MADRID ---\n");
        printf("1. Listado de actividades por centro\n");
        printf("2. Actividad mas popular\n");
        printf("3. Calcular ocupacion media\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1: listadoPorCentro(datos, totalRegistros); 
                break;
            case 2: actividadPopular(datos, totalRegistros); 
                break;
            case 3: calcularOcupacionMedia(datos, totalRegistros);
                break;
            case 4: printf("Saliendo...\n"); 
                break;

            default: printf("Opcion no valida.\n");
        }
    } while (opcion != 4);

    return 0;

    // habra que desarrollar opcion por opcion con su corresponciente menu y funciones para cada una de ellas,
    // a medida que avancemos en el desarrollo del programa, se iran añadiendo mas funciones y opciones o modificaciones,
   
    void funcion listadoPorCentro(Registro datos[], int totalRegistros)
    {
        char centro[70];
        printf("Ingrese el nombre del centro: ");
        scanf("%s", centro);
        printf("\nActividades en el centro %s:\n", centro);
        for (int i = 0; i < totalRegistros; i++)
        {
            if (strcmp(datos[i].centro, centro) == 0) // comparacion y lectura de las cadenas de caracteres del svc para identificar el nombre del centro deportivo
            {
                printf("%s - %s - %s\n", datos[i].actividad, datos[i].modalidad, datos[i].tipo_actividad);
            }
        }
    }

    void media actividad actividadPopular(Registro datos[], int totalRegistros) // funcion para saber cual es la actividad mas popular 
    {
        char actividadMasPopular[70];
        int maxOcupacion = 0;
        for (int i = 0; i < totalRegistros; i++)
        {
            if (datos[i].ocupadas > maxOcupacion)
            {
                maxOcupacion = datos[i].ocupadas;
                strcpy(actividadMasPopular, datos[i].actividad);
            }
        }
        printf("La actividad mas popular es: %s con %d ocupantes.\n", actividadMasPopular, maxOcupacion);

    }

    void calcularOcupacionMedia(Registro datos[], int totalRegistros) //funcion para calcular la ocupacion media de las actividades deportivas
    {
        int totalPlazas = 0;
        int totalOcupadas = 0;
        for (int i = 0; i < totalRegistros; i++)
        {
            totalPlazas += datos[i].plazas;
            totalOcupadas += datos[i].ocupadas;
        }
        double ocupacionMedia = (double)totalOcupadas / totalPlazas * 100;
        printf("La ocupacion media es: %.2f%%\n", ocupacionMedia);
    }

}
