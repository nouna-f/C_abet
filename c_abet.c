#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARRERAS 7
#define NUM_SEMESTRES 2
#define NUM_ANIOS 5

/**
 * Genera datos aleatorios de ingresos de alumnos en las diferentes carreras y años.
 * se ingresa el arreglo tridimensional para almacenar los datos generados.
 */
void generarDatosAleatorios(int ingresos[][NUM_SEMESTRES][NUM_ANIOS]) {
    srand(time(NULL)); // Inicializar la semilla aleatoria con el tiempo actual

    int i, j, k;
    for (i = 0; i < NUM_CARRERAS; i++) {
        for (j = 0; j < NUM_SEMESTRES; j++) {
            for (k = 0; k < NUM_ANIOS; k++) {
                ingresos[i][j][k] = rand() % 100 + 1; // Generar un número aleatorio entre 1 y 100
            }
        }
    }
}

/**
 * Calcula los ingresos totales de alumnos por carrera.
 * el arreglo tridimensional  contiene los datos de ingreso.
 *  se ve los totales arreglos que almacenan los ingresos totales por carrera.
 */
void obtenerIngresosTotales(int ingresos[][NUM_SEMESTRES][NUM_ANIOS], int totales[]) {
    int i, j, k;
    for (i = 0; i < NUM_CARRERAS; i++) {
        totales[i] = 0;
        for (j = 0; j < NUM_SEMESTRES; j++) {
            for (k = 0; k < NUM_ANIOS; k++) {
                totales[i] += ingresos[i][j][k];
            }
        }
    }
}

/**
 * Obtiene el año en que ingresó la mayor cantidad de alumnos a la universidad.
 * segun los ingresos arreglo tridimensional que contiene los datos de ingresos.
 * y muestra el año en que ingresó la mayor cantidad de alumnos.
 */
int obtenerAnioMaxIngresos(int ingresos[][NUM_SEMESTRES][NUM_ANIOS]) {
    int totales[NUM_CARRERAS];
    obtenerIngresosTotales(ingresos, totales);

    int maxIngresos = totales[0];
    int maxAnio = 0;

    int i;
    for (i = 1; i < NUM_ANIOS; i++) {
        if (totales[i] > maxIngresos) {
            maxIngresos = totales[i];
            maxAnio = i;
        }
    }

    return maxAnio;
}

/**
 * Obtiene el nombre de una carrera dado su número asociado.
 * segun la carrera el número asociado a la carrera.
 * tambien retorna el nombre de la carrera.
 */
char* obtenerNombreCarrera(int carrera) {
    switch (carrera) {
        case 0:
            return "Ingeniería de Software";
        case 1:
            return "Administración";
        case 2:
            return "Economía";
        case 3:
            return "Relaciones Internacionales";
        case 4:
            return "Matemáticas";
        case 5:
            return "Contabilidad";
        case 6:
            return "Ingeniería Industrial";
        default:
            return "";
    }
}

/**
 * Obtiene la carrera que recibió la mayor cantidad de alumnos en el último año.
 * en funcion a los ingresos arreglo tridimensional que contiene los datos de ingresos.
 * y la palabra" anio" el índice del último año.
 * el programa entrega el número asociado a la carrera con la mayor cantidad de alumnos en el último año.
 */
int obtenerCarreraMaxIngresosUltimoAnio(int ingresos[][NUM_SEMESTRES][NUM_ANIOS], int anio) {
    int totales[NUM_CARRERAS];
    obtenerIngresosTotales(ingresos, totales);

    int maxIngresos = ingresos[0][0][anio] + ingresos[0][1][anio];
    int maxCarrera = 0;

    int i;
    for (i = 1; i < NUM_CARRERAS; i++) {
        int ingresosCarrera = ingresos[i][0][anio] + ingresos[i][1][anio];
        if (ingresosCarrera > maxIngresos) {
            maxIngresos = ingresosCarrera;
            maxCarrera = i;
        }
    }

    return maxCarrera;
}

/**
 * Obtiene el año en que la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos.
 * los ingresos del arreglo tridimensional que contiene los datos de ingresos.
 * el programa entrega el año en que la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos.
 */
int obtenerAnioMaxIngresosIngenieriaSoftware(int ingresos[][NUM_SEMESTRES][NUM_ANIOS]) {
    int maxIngresos = ingresos[0][0][0] + ingresos[0][1][0];
    int maxAnio = 0;

    int i, j;
    for (i = 0; i < NUM_SEMESTRES; i++) {
        for (j = 1; j < NUM_ANIOS; j++) {
            int ingresosAnio = ingresos[0][i][j] + ingresos[0][i][j];
            if (ingresosAnio > maxIngresos) {
                maxIngresos = ingresosAnio;
                maxAnio = j;
            }
        }
    }

    return maxAnio;
}

int main() {
    int ingresos[NUM_CARRERAS][NUM_SEMESTRES][NUM_ANIOS];

    generarDatosAleatorios(ingresos);

    // a) El año en que ingresó la mayor cantidad de alumnos a la universidad
    int maxAnio = obtenerAnioMaxIngresos(ingresos);
    printf("El año con la mayor cantidad de alumnos ingresados es: %d\n", 2019 + maxAnio);

    // b) La Carrera que recibió la mayor cantidad de alumnos en el último año
    int maxCarreraUltimoAnio = obtenerCarreraMaxIngresosUltimoAnio(ingresos, NUM_ANIOS - 1);
    printf("La carrera con la mayor cantidad de alumnos en el último año es: %s\n", obtenerNombreCarrera(maxCarreraUltimoAnio));

    // c) ¿En qué año la carrera de Ingeniería de Software recibió la mayor cantidad de alumnos?
    int maxAnioIngenieriaSoftware = obtenerAnioMaxIngresosIngenieriaSoftware(ingresos);
    printf("El año con la mayor cantidad de alumnos ingresados en Ingeniería de Software es: %d\n", 2019 + maxAnioIngenieriaSoftware);

    return 0;
}
