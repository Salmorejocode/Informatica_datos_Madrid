# Informatica_datos_Madrid

# Memoria del Proyecto de Informática - Gestión de Actividades

## 1. Objetivo
El objetivo principal es el desarrollo de una aplicación capaz de cargar un fichero de datos (dataset.csv), analizar la información y representar estadísticas que ayuden a comprender su comportamiento. Se han complementado las funcionalidades mínimas exigidas con opciones adicionales de análisis avanzado.

Para la realización del proyecto se ha utilizado:
* **Lenguaje:** C.
* **Bibliotecas Estándar:** `stdio.h`, `stdlib.h`, `string.h`, `locale.h`.
* **Interfaz y Diseño:** API de Windows para el control de la consola, colores y posicionamiento del cursor mediante funciones como `gotoxy(int x, int y)`.

---

## 2. Análisis y Diseño de Datos

### Estructura de Datos
Para gestionar la información del archivo CSV, se ha definido la estructura `Actividad`, que agrupa los datos en tres categorías:
* **Campos Temporales:** `anio`, `mes`, `dia`, `dia_semana`, `hora_inicio` y `hora_fin`.
* **Campos Descriptivos:** `actividad`, `modalidad`, `centro` y `tipo_actividad` (usando cadenas de caracteres `char[]`).
* **Campos Métricos:** `plazas`, `ocupadas` y `libres` (datos enteros para cálculos estadísticos).

### Gestión de Memoria Dinámica
Debido a que el volumen de datos del CSV puede variar, el programa implementa un algoritmo de redimensionamiento dinámico:
1. Se inicia con una capacidad de 100 registros (`capacidad_inicial`).
2. Si se supera este límite durante la lectura, se utiliza la función `realloc` para duplicar el espacio en la memoria RAM automáticamente.
3. Esto garantiza la eficiencia del programa al optimizar el uso de recursos.

### Interfaz y Flujo de Usuario
El programa utiliza un sistema de menú jerárquico:
* **Menú Principal (Selección de Fecha):** El usuario elige el día específico a analizar (29, 30 o 31).
* **Menú de Análisis:** Ofrece una interfaz visual mediante la API de Windows con funciones de filtrado por centro, frecuencias, popularidad, ocupación media y detección de plazas agotadas.

---

## 3. Descripción de Funcionalidades

### Carga y Procesamiento
* **Lectura del fichero:** Se utiliza un puntero `FILE*` para abrir `dataset.csv`. Se omite la cabecera del archivo mediante `fgets` para evitar errores de formato.
* **Almacenamiento:** Mediante `fscanf`, el sistema asigna cada columna al miembro correspondiente de la estructura `Actividad`, descartando filas con datos incompletos.

### Lógica de Funciones
* **`esMismoDia`**: Actúa como filtro principal para corroborar que la información corresponde a la fecha seleccionada.
* **`obtenerCentrosUnicos`**: Identifica los nombres de los centros disponibles sin duplicados utilizando `strcmp`.
* **`frecuenciaActividades`**: Recorre las sesiones del día y utiliza dos arrays paralelos para generar un histograma de texto con el conteo de cada actividad.
* **`actividadMasPopularPorCentro`**: Realiza una búsqueda por itinerancia para registrar la cifra más alta de ocupación.
* **`ocupacionMediaPorCentro`**: Calcula porcentajes de uso mediante operaciones matemáticas de precisión.
* **`detectorLlenos`**: Filtra el vector de estructuras buscando específicamente aquellas con `libres == 0`.
* **`listadoActividadesPorCentroInteractivo`**: Permite una navegación profunda mostrando horarios y modalidades en formato de tabla.
* **`gotoxy` y `DibujarMenu`**: Funciones encargadas de la estética y posicionamiento en la API de Windows.

---

## 4. Manual de Usuario

1. **Requisito previo:** Asegúrese de que el archivo `dataset.csv` esté en la misma carpeta que el ejecutable. (Diseñado para entornos Windows).
2. **Inicio:** Introduzca el número del día a analizar en el Menú Principal.
3. **Análisis:** Utilice los números del **1 al 6** para acceder a los reportes. En la opción 1, se podrá elegir un centro específico de una lista generada dinámicamente.
4. **Navegación:** Tras cada consulta, pulse **Enter** para regresar al menú. Use el **0** para retroceder o cerrar el programa.

---

## 5. Conclusiones

### Aprendizaje
El proyecto ha permitido consolidar nuestros conceptos avanzados de programación en C, destacando el manejo de estructuras de datos complejas, el uso de punteros y la gestión eficiente de ficheros.

### Trabajo en GitHub
Se ha utilizado la plataforma **GitHub** para la colaboración del equipo:
* **Sincronización:** Uso de comandos `push` y `pull` para trabajar sobre la última versión del código en tiempo real, evitando pérdida de información.
* **Organización:** El repositorio actúa como nodo central para el código fuente, el dataset y esta documentación, asegurando la disponibilidad de los recursos para todo el grupo.
