#include <stdio.h>
#include <stdlib.h>

#define MATRIX_ROWS 5
#define MATRIX_COLUMNS 5

typedef int matrix[MATRIX_ROWS][MATRIX_COLUMNS];

// Puntero global al fichero de log requerido por las funciones
static FILE *log_file = NULL;

static void registrar_evento(const char *evento) {
    if (log_file == NULL) {
        return;
    }

    fprintf(log_file, "%s\n", evento);
    fflush(log_file);
}

static void registrar_matriz(const char *descripcion, matrix matriz) {
    if (log_file == NULL) {
        return;
    }

    fprintf(log_file, "%s\n", descripcion);
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLUMNS; j++) {
            fprintf(log_file, "%d", matriz[i][j]);
            if (j < MATRIX_COLUMNS - 1) {
                fprintf(log_file, " ");
            }
        }
        fprintf(log_file, "\n");
    }
    fflush(log_file);
}


int main() {
    const char *nombre_log = "test_matrix.log";


    // 1. Abrir fichero de log en modo escritura / añadir
    log_file = fopen(nombre_log, "w");
    if (log_file == NULL) {
        printf("Error: no se pudo abrir el archivo %s para escribir.\n", nombre_log);
        return 1;
    }

    // 2. Probar registrar_evento()
    printf("-> Registrando evento simple...\n");
    registrar_evento("[INFO] Inicio del test de logging.");
    registrar_evento("[OP] Operacion SUMA realizada.");

    // 3. Crear una matriz de prueba 5x5
    matrix M = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // 4. Probar registrar_matriz()
    printf("-> Registrando matriz 5x5 en el log...\n");
    registrar_matriz("--- Matriz Resultado R ---", M);

    registrar_evento("[INFO] Fin del test.");

    // 5. Cerrar el fichero de log
    fclose(log_file);
    log_file = NULL;

    // 6. Leer y mostrar en consola lo que se guardo en el fichero
    printf("\n=== CONTENIDO GENERADO EN '%s' ===\n\n", nombre_log);
    FILE *lectura = fopen(nombre_log, "r");
    if (lectura != NULL) {
        char linea[256];
        while (fgets(linea, sizeof(linea), lectura) != NULL) {
            printf("%s", linea);
        }
        fclose(lectura);
    }

    printf("\nPrueba finalizada con exito.\n");
    return 0;
}
