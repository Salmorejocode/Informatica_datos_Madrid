#include "mylibrary.h"

#include <stdio.h>   // Para entrada/salida: maneja los printf, scanf y la lectura de archivos (FILE).
#include <stdlib.h>  // Para memoria y control: necesaria para malloc, realloc, free y la función exit.
#include <string.h>  // Para cadenas: contiene funciones clave como strcmp (comparar) y strcpy (copiar).
#include <locale.h>  // Para el idioma: permite configurar tildes y caracteres españoles.
#include <windows.h> //Proporciona accesoa a la API de windows, en este caso la manipulacion de la consola

void gotoxy(int x, int y) {
    HANDLE Identiventana;
    Identiventana = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Coordenadas;
    Coordenadas.X = x;
    Coordenadas.Y = y;
    SetConsoleCursorPosition(Identiventana, Coordenadas);
}

void escribiropciones() {

    gotoxy(20, 9);  printf("1. Ver por Centro");
    gotoxy(61, 9);  printf("2. Frecuencias");
    gotoxy(20, 16); printf("3. Mas Popular");
    gotoxy(61, 16); printf("4. Ocupacion Media");
    gotoxy(20, 23); printf("5. Franjas Pico");
    gotoxy(61, 23); printf("6. Sin Plazas");
    gotoxy(89, 28); printf("0. Volver");
    gotoxy(55, 7);  printf("Opcion: ");
}

void DibujarMenu() {
    int x = 19, y = 8, i, fila = 81, columna = 21;
    {
        {
            for (i = 0; i < fila; i++) { x++; gotoxy(x, y); printf("%c", 205); }
            gotoxy(x, y); printf("%c", 187);
            for (i = 0; i < columna; i++) { y++; gotoxy(x, y); printf("%c", 186); }
            gotoxy(x, y); printf("%c", 188);
            for (i = 0; i < fila; i++) { x--; gotoxy(x, y); printf("%c", 205); }
            gotoxy(x, y); printf("%c", 200);
            for (i = 0; i < columna; i++) { y--; gotoxy(x, y); printf("%c", 186); }
            gotoxy(x, y); printf("%c", 201);
        }
        {
            x = 60, y = 8;
            gotoxy(x, y); printf("%c", 203);
            for (i = 0; i < columna; i++) { y++; gotoxy(x, y); printf("%c", 186); }
            gotoxy(x, y); printf("%c", 202);
            x = 19, y = 15;
            gotoxy(x, y); printf("%c", 204);
            for (i = 0; i < fila; i++) { x++; gotoxy(x, y); printf("%c", 205); }
            gotoxy(x, y); printf("%c", 185);
            x = 19, y = 22;
            gotoxy(x, y); printf("%c", 204);
            for (i = 0; i < fila; i++) { x++; gotoxy(x, y); printf("%c", 205); }
            gotoxy(x, y); printf("%c", 185);
            gotoxy(60, 15), printf("%c", 206);
            gotoxy(60, 22), printf("%c", 206);
        }
    }
}

void Texto1() {
    int x = 19, y = 9, i, fila = 81, columna = 20;
    {
        {
            for (i = 0; i < fila; i++) { x++; gotoxy(x, y); printf("%c", 205); }
            gotoxy(x, y); printf("%c", 187);
            for (i = 0; i < columna; i++) { y++; gotoxy(x, y); printf("%c", 186); }
            gotoxy(x, y); printf("%c", 188);
            for (i = 0; i < fila; i++) { x--; gotoxy(x, y); printf("%c", 205); }
            gotoxy(x, y); printf("%c", 200);
            for (i = 0; i < columna; i++) { y--; gotoxy(x, y); printf("%c", 186); }
            gotoxy(x, y); printf("%c", 201);
        }
        {
            {
                x = 60, y = 9;
                gotoxy(x, y); printf("%c", 203);
                for (i = 0; i < columna; i++) { y++; gotoxy(x, y); printf("%c", 186); }
                gotoxy(x, y); printf("%c", 202);
            }
            {
                x = 19, y = 19;
                gotoxy(x, y); printf("%c", 204);
                for (i = 0; i < fila; i++) { x++; gotoxy(x, y); printf("%c", 205); }
                gotoxy(x, y); printf("%c", 185);
            }
            gotoxy(60, 19), printf("%c", 206);
        }
        {
            gotoxy(20, 10); printf("Datos Dia 29"); gotoxy(20, 18); printf("Presionar ( 29 )");
            gotoxy(61, 10); printf("Datos Dia 30"); gotoxy(61, 18); printf("Presionar ( 30 )");
            gotoxy(20, 20); printf("Datos Dia 31"); gotoxy(20, 28); printf("Presionar ( 31 )");
            gotoxy(61, 20); printf("Salir");        gotoxy(61, 28); printf("Presionar ( 0 ):");
            gotoxy(53, 4);  printf("MENU PRINCIPAL");
        }
        gotoxy(55, 7); printf("Ir a: "); gotoxy(65, 7);
    }
}


int leerNumero() {
    char buffer[10];
    int i = 0, c_int;

    //Leemos lo que el usuario escribe hasta que pulse Enter
    while ((c_int = getchar()) != '\n' && i < sizeof(buffer) - 1) {
        buffer[i++] = (char)c_int;
    }
    buffer[i] = '\0'; // Cerramos la cadena con el carácter nulo

    //si se pulsa enter devolvemos -1
    if (i == 0) return -1;

    // Recorremos el buffer carácter por carácter
    for (int j = 0; j < i; j++) {
        // Si el carácter noo está entre cero y nueve , es una letra o símbolo
        if (buffer[j] < '0' || buffer[j] > '9') {
            // Evito que el programa lea una entrada invalida, al devolver -2, este valor sigue en el do while y no sale del programa
            return -2;
        }
    }

    //Si todos son números, convertimos la cadena a un entero real
    return atoi(buffer);
}

//  LÓGICA DE LAS FUNCIONES 

/**
 * esMismoDia: Función de filtrado booleano.
 * Recibe una estructura por valor (copia) y compara sus miembros enteros.
 * Retorna 1 (true) si todos los campos coinciden, lo que permite segmentar
 * el dataset masivo en el subconjunto específico de la fecha elegida.
 */
int esMismoDia(Actividad a, int dia, int mes, int anio) {
    return (a.dia == dia && a.mes == mes && a.anio == anio);
}

/**
 * obtenerCentrosUnicos: Implementación de un algoritmo de "Distinct".
 * Como los centros se repiten por cada actividad, usamos un array auxiliar 'centros'.
 * Por cada actividad del día:
 * 1. Verificamos si el nombre del centro ya existe en el array temporal usando strcmp.
 * 2. Si no existe (!existe), lo añadimos mediante strcpy.
 * Esto evita duplicados en los menús de selección.
 */
int obtenerCentrosUnicos(Actividad* v, int n, int dia, int mes, int anio, char centros[][120]) {
    int numCentros = 0;
    for (int i = 0; i < n; i++) {
        if (esMismoDia(v[i], dia, mes, anio)) {
            int existe = 0;
            for (int j = 0; j < numCentros; j++) {
                if (strcmp(centros[j], v[i].centro) == 0) { existe = 1; break; }
            }
            if (!existe && numCentros < 100) {
                strcpy(centros[numCentros], v[i].centro);
                numCentros++;
            }
        }
    }
    return numCentros;
}

/**
 * listadoActividadesPorCentroInteractivo: Filtro cruzado y formateo de salida.
 * Primero obtiene la lista de centros únicos para mostrar un submenú.
 * Tras la selección del usuario (sel), itera de nuevo sobre todo el array original
 * aplicando un doble filtro: fecha Y coincidencia de cadena (centro seleccionado).
 * Usa formateo de printf (%-20s) para alinear las columnas en la consola.
 */
void listadoActividadesPorCentroInteractivo(Actividad* v, int n, int dia, int mes, int anio) {
    char centros[100][120];
    int numC = obtenerCentrosUnicos(v, n, dia, mes, anio, centros);
    int sel;
    if (numC == 0) return;
    printf("\nSELECCIONE UN CENTRO:\n");
    for (int i = 0; i < numC; i++) printf("%d. %s\n", i + 1, centros[i]);
    printf("Opcion: ");
    scanf("%d", &sel);
    if (sel > 0 && sel <= numC) {
        char* centroElegido = centros[sel - 1];
        printf("\n ACTIVIDADES EN %s \n", centroElegido);
        printf("%-20s | %-12s | %-12s | %-10s\n", "ACTIVIDAD", "HORARIO", "MODALIDAD", "LIBRES");
        for (int j = 0; j < n; j++) {
            if (esMismoDia(v[j], dia, mes, anio) && strcmp(v[j].centro, centroElegido) == 0) {
                printf("%-20s | %s-%s | %-12s | %d/%d\n",
                    v[j].actividad, v[j].hora_inicio, v[j].hora_fin, v[j].modalidad, v[j].libres, v[j].plazas);
            }
        }
    }
    while (getchar() != '\n'); // Limpiar buffer
}

/**
 * frecuenciaActividades: Mapeo de frecuencias (Histograma de texto).
 * Utiliza dos arrays paralelos: 'nombres' para el ID de la actividad y 'conteo' para las ocurrencias.
 * Si strcmp encuentra la actividad, incrementa el índice correspondiente en 'conteo'.
 * Complejidad: O(D * A) donde D son actividades del día y A actividades únicas.
 */
void frecuenciaActividades(Actividad* v, int n, int dia, int mes, int anio) {
    char nombres[200][120];
    int conteo[200] = { 0 }, numA = 0;
    for (int i = 0; i < n; i++) {
        if (esMismoDia(v[i], dia, mes, anio)) {
            int idx = -1;
            for (int j = 0; j < numA; j++) if (strcmp(nombres[j], v[i].actividad) == 0) { idx = j; break; }
            if (idx != -1) conteo[idx]++;
            else if (numA < 200) { strcpy(nombres[numA], v[i].actividad); conteo[numA] = 1; numA++; }
        }
    }
    printf("\n FRECUENCIA DE ACTIVIDADES (%02d/%02d) \n", dia, mes);
    for (int i = 0; i < numA; i++) printf("%-25s: %d veces\n", nombres[i], conteo[i]);
}

/**
 * actividadMasPopularPorCentro: Búsqueda de máximo relativo por grupo.
 * Itera centro por centro y, para cada uno, realiza una búsqueda lineal del
 * valor máximo en el campo 'ocupadas'. Guarda el índice 'idx' del struct que
 * cumple la condición para imprimirlo al finalizar el ciclo interno.
 */
void actividadMasPopularPorCentro(Actividad* v, int n, int dia, int mes, int anio) {
    char centros[100][120];
    int numC = obtenerCentrosUnicos(v, n, dia, mes, anio, centros);
    printf("\nMAS POPULAR POR CENTRO \n");
    for (int i = 0; i < numC; i++) {
        int maxOcu = -1, idx = -1;
        for (int j = 0; j < n; j++) {
            if (esMismoDia(v[j], dia, mes, anio) && strcmp(v[j].centro, centros[i]) == 0) {
                if (v[j].ocupadas > maxOcu) { maxOcu = v[j].ocupadas; idx = j; }
            }
        }
        if (idx != -1) printf("%-25s: %s (%d ocupados)\n", centros[i], v[idx].actividad, maxOcu);
    }
}

/**
 * ocupacionMediaPorCentro: Cálculo de agregación (Promedio ponderado).
 * Suma acumulativa de 'ocupadas' y 'plazas' para cada centro.
 * Importante: Se realiza un casting a (float) antes de la división para evitar
 * el truncamiento de la división entera y obtener precisión decimal.
 * Incluye una guarda (sumPla > 0) para evitar la división por cero.
 */
void ocupacionMediaPorCentro(Actividad* v, int n, int dia, int mes, int anio) {
    char centros[100][120];
    int numC = obtenerCentrosUnicos(v, n, dia, mes, anio, centros);
    printf("\n OCUPACION MEDIA POR CENTRO \n");
    for (int i = 0; i < numC; i++) {
        int sumOcu = 0, sumPla = 0;
        for (int j = 0; j < n; j++) {
            if (esMismoDia(v[j], dia, mes, anio) && strcmp(v[j].centro, centros[i]) == 0) {
                sumOcu += v[j].ocupadas; sumPla += v[j].plazas;
            }
        }
        float porc = (sumPla > 0) ? ((float)sumOcu / sumPla) * 100 : 0;
        printf("%-25s: %.1f%%\n", centros[i], porc);
    }
}

/**
 * franjasHorariasPico: Análisis de densidad temporal.
 * Similar a frecuenciaActividades, pero utiliza la 'hora_inicio' como clave de agrupación.
 * Permite identificar visualmente los momentos del día con mayor carga de sesiones.
 */
void franjasHorariasPico(Actividad* v, int n, int dia, int mes, int anio) {
    char horas[100][15];
    int conteo[100] = { 0 }, numH = 0;
    for (int i = 0; i < n; i++) {
        if (esMismoDia(v[i], dia, mes, anio)) {
            int idx = -1;
            for (int j = 0; j < numH; j++) if (strcmp(horas[j], v[i].hora_inicio) == 0) { idx = j; break; }
            if (idx != -1) conteo[idx]++;
            else if (numH < 100) { strcpy(horas[numH], v[i].hora_inicio); conteo[numH] = 1; numH++; }
        }
    }
    printf("\n ACTIVIDADES POR FRANJA \n");
    for (int i = 0; i < numH; i++) printf("Hora %s: %d sesiones\n", horas[i], conteo[i]);
}

/**
 * detectarLlenos: Filtro por estado crítico.
 * Recorre el vector buscando elementos donde el campo 'libres' sea exactamente 0.
 * Es una operación de complejidad O(n) que sirve como sistema de alertas para el usuario.
 */
void detectarLlenos(Actividad* v, int n, int dia, int mes, int anio) {
    int cont = 0;
    printf("\n ACTIVIDADES SIN PLAZAS LIBRES\n");
    for (int i = 0; i < n; i++) {
        if (esMismoDia(v[i], dia, mes, anio) && v[i].libres == 0) {
            printf("[LLENO] %s en %s (%s)\n", v[i].actividad, v[i].centro, v[i].hora_inicio);
            cont++;
        }
    }
    if (cont == 0) printf("No hay actividades completas en este dia.\n");
}

