#include <stdio.h>
#include "OPMATRIX.h"
#include "IOMATRIX.h"

static FILE *log_file;

void descargar_matriz(matrix matriz_solucion);
void mostrar_matriz(matrix matriz);
void cargar_matriz(matrix matriz);
void selector_operaciones(matrix matriz1, matrix matriz2, matrix matriz_solucion);
static void registrar_evento(const char *evento);
static void registrar_matriz(const char *descripcion, matrix matriz);


int main() {
    int option = 0;
    matrix matriz1, matriz2, matriz_solucion;

    log_file = fopen("log.txt", "w");
    if (log_file == NULL) {
        perror("No se pudo crear o sobrescribir log.txt");
        return 1;
    }
    registrar_evento("Inicio de la calculadora de matrices.");
    
    printf("Bienvenido a la calculadora de matrices!\n");
    printf("Esta calculadora puede realizar operaciones con matrices 5x5.\n");
    do {
        printf("\033[H\033[J"); // Limpiar la pantalla
        printf("Por favor, introduce la opcion que deseas realizar:\n");
        printf("1. Cargar matriz 1\n");
        printf("2. Cargar matriz 2\n");
        printf("3. Mostrar matriz solucion\n");
        printf("4. Descargar matriz solucion\n");
        printf("5. Selector de operaciones\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &option);
        fprintf(log_file, "Opcion seleccionada: %d\n", option);
        fflush(log_file);

        switch (option) {
            case 1:
                printf("\033[H\033[J");
                printf("Has seleccionado cargar matriz 1.\n");
                registrar_evento("Solicitud de carga de matriz 1.");
                cargar_matriz(matriz1);
                break;
            case 2:
                printf("\033[H\033[J");
                printf("Has seleccionado cargar matriz 2.\n");
                registrar_evento("Solicitud de carga de matriz 2.");
                cargar_matriz(matriz2);
                break;
            case 3:
                printf("\033[H\033[J");
                printf("Has seleccionado mostrar matriz solución.\n");
                registrar_evento("Solicitud de visualizacion de la matriz solucion.");
                mostrar_matriz(matriz_solucion);
                break;
            case 4:
                printf("\033[H\033[J");
                printf("Has seleccionado descargar matriz solución.\n");
                registrar_evento("Solicitud de descarga de la matriz solucion.");
                descargar_matriz(matriz_solucion);
                break;
            case 5:
                printf("\033[H\033[J");
                printf("Has seleccionado el selector de operaciones.\n");
                registrar_evento("Apertura del selector de operaciones.");
                selector_operaciones(matriz1 , matriz2 , matriz_solucion);
                break;
            case 6:
                printf("\033[H\033[J");
                printf("Saliendo del programa...\n");
                registrar_evento("Fin de la calculadora de matrices.");
                break;
            default:
                printf("Opción no válida. Por favor, selecciona una opción del 1 al 6.\n");
                registrar_evento("Opcion no valida.");
        }
    } while (option != 6);

    fclose(log_file);
    log_file = NULL;
    return 0;
}

void cargar_matriz(matrix matriz) {
    int option = 0;
    int vector[25]; // Vector para almacenar los valores de la matriz

    // Lógica para cargar una matriz
    printf("Seleccione un metodo para cargar la matriz:\n");
    printf("1. Ingresar valores manualmente\n");
    printf("2. Cargar desde un archivo\n");
    printf("Opción: ");
    scanf("%d", &option);
    switch (option) {
        case 1:
            printf("Ingrese los valores de la matriz 5x5:\n");
            for (int i = 0; i < 25; i++) {
                printf("Valor %d: ", i + 1);
                scanf("%d", &vector[i]);
            }
            define_matrix(vector, matriz);
            printf("Matriz creada correctamente.\n");
            registrar_evento("Matriz cargada manualmente.");
            registrar_matriz("Valores de la matriz cargada:", matriz);
            visualizarMatriz(matriz);
            break;
        case 2:
            registrar_evento("Solicitud de carga desde archivo no implementada.");
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
            break;
        default:
            printf("Opcion no válida.\n");
            registrar_evento("Metodo de carga no valido.");
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
    }
}

void mostrar_matriz(matrix matriz) {
    registrar_matriz("Matriz mostrada:", matriz);
    visualizarMatriz(matriz);
    printf("\n");
    printf("Presione cualquier tecla para continuar...\n");
    getchar(); // Captura el salto de línea pendiente
    getchar(); // Espera a que el usuario presione una tecla
}

void descargar_matriz(matrix matriz_solucion) {
    printf("Descargando matriz solución...\n");
    registrar_matriz("Matriz solucion descargada:", matriz_solucion);
    mostrar_matriz(matriz_solucion);
}

void selector_operaciones(matrix matriz1, matrix matriz2, matrix matriz_solucion) {
    // Lógica para seleccionar operaciones entre las matrices
    int scalar;
    
    int option = 0;
    printf("Seleccione la operación que desea realizar:\n");
    printf("1. Sumar matrices\n");
    printf("2. Restar matrices\n");
    printf("3. Producto escalar de matriz 1\n");
    printf("4. Producto de matrices\n");
    printf("5. Matriz Simétrica\n");
    printf("Opcion: ");
    scanf("%d", &option);
    fprintf(log_file, "Operacion seleccionada: %d\n", option);
    fflush(log_file);

    switch (option) {
        case 1:
            sum(matriz1, matriz2, matriz_solucion);
            printf("Matrices sumadas correctamente.\n");
            registrar_evento("Suma de matrices realizada.");
            registrar_matriz("Resultado de la suma:", matriz_solucion);
            mostrar_matriz(matriz_solucion);
            break;

        case 2:
            subtract(matriz1, matriz2, matriz_solucion);
            printf("Matrices restadas correctamente.\n");
            registrar_evento("Resta de matrices realizada.");
            registrar_matriz("Resultado de la resta:", matriz_solucion);
            mostrar_matriz(matriz_solucion);
            break;

        case 3:
            printf("Ingrese el escalar para multiplicar la matriz 1: ");
            scanf("%d", &scalar);
            esc_product(matriz1, scalar, matriz_solucion);
            printf("Producto escalar de matriz 1 realizado correctamente.\n");
            fprintf(log_file, "Producto escalar de matriz 1 realizado con escalar %d.\n", scalar);
            fflush(log_file);
            registrar_matriz("Resultado del producto escalar de matriz 1:", matriz_solucion);
            mostrar_matriz(matriz_solucion);
            break;

        case 4:
            product(matriz1, matriz2, matriz_solucion);
            printf("Producto de matrices realizado correctamente.\n");
            registrar_evento("Producto de matrices realizado.");
            registrar_matriz("Resultado del producto de matrices:", matriz_solucion);
            mostrar_matriz(matriz_solucion);
            break;  
        
        case 5:
            if (simetric(matriz1)) {
                printf("La matriz 1 es simétrica.\n");
                registrar_evento("Matriz 1 es simétrica.");
            } else {
                printf("La matriz 1 no es simétrica.\n");
                registrar_evento("Matriz 1 no es simétrica.");
            }
            registrar_evento("Verificación de simetría de matriz 1 realizada.");
            mostrar_matriz(matriz1);
            break;

        default:
            printf("Opción no válida.\n");
            registrar_evento("Operacion no valida.");
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
    }
}

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