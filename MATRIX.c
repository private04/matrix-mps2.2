#include <stdio.h>
#include "OPMATRIX.h"

void descargar_matriz(matrix matriz_solucion);
void mostrar_matriz(matrix matriz);
void cargar_matriz(matrix matriz);
void selector_operaciones(matrix matriz1, matrix matriz2, matrix matriz_solucion);

int main() {
    int option = 0;
    matrix matriz1, matriz2, matriz_solucion;
    
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

        switch (option) {
            case 1:
                printf("\033[H\033[J");
                printf("Has seleccionado cargar matriz 1.\n");
                // Lógica para cargar matriz 1
                cargar_matriz(matriz1);
                break;
            case 2:
                printf("\033[H\033[J");
                printf("Has seleccionado cargar matriz 2.\n");
                // Lógica para cargar matriz 2
                cargar_matriz(matriz2);
                break;
            case 3:
                printf("\033[H\033[J");
                printf("Has seleccionado mostrar matriz solución.\n");
                // Lógica para mostrar matriz solución
                mostrar_matriz(matriz_solucion);
                break;
            case 4:
                printf("\033[H\033[J");
                printf("Has seleccionado descargar matriz solución.\n");
                // Lógica para descargar matriz solución
                descargar_matriz(matriz_solucion);
                break;
            case 5:
                printf("\033[H\033[J");
                printf("Has seleccionado el selector de operaciones.\n");
                // Lógica para seleccionar operaciones
                selector_operaciones(matriz1 , matriz2 , matriz_solucion);
                break;
            case 6:
                printf("\033[H\033[J");
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Por favor, selecciona una opción del 1 al 6.\n");
        }
    } while (option != 6);

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
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
            break;
        case 2:
            // Lógica para cargar desde un archivo         <-- FALTA CODIGO
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
            break;
        default:
            printf("Opcion no válida.\n");
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
    }
}

void mostrar_matriz(matrix matriz) {
    printf("Matriz:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Presione cualquier tecla para continuar...\n");
    getchar(); // Captura el salto de línea pendiente
    getchar(); // Espera a que el usuario presione una tecla
}

void descargar_matriz(matrix matriz_solucion) {
    // Lógica para descargar la matriz solución
    printf("Descargando matriz solución...\n");
    // Aquí se implementaría la lógica para mostrar o guardar la matriz solución
    printf("Presione cualquier tecla para continuar...\n");
    getchar(); // Captura el salto de línea pendiente
    getchar(); // Espera a que el usuario presione una tecla
}

void selector_operaciones(matrix matriz1, matrix matriz2, matrix matriz_solucion) {
    // Lógica para seleccionar operaciones entre las matrices
    int scalar;
    
    int option = 0;
    printf("Seleccione la operación que desea realizar:\n");
    printf("1. Sumar matrices\n");
    printf("2. Restar matrices\n");
    printf("3. Producto escalar de matriz 1\n");
    printf("4. Producto escalar de matriz 2\n");
    printf("5. Producto de matrices\n");
    printf("Opcion: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            sum(matriz1, matriz2, matriz_solucion);
            printf("Matrices sumadas correctamente.\n");
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
            break;

        case 2:
            subtract(matriz1, matriz2, matriz_solucion);
            printf("Matrices restadas correctamente.\n");
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
            break;

        case 3:
            printf("Ingrese el escalar para multiplicar la matriz 1: ");
            scanf("%d", &scalar);
            esc_product(matriz1, scalar, matriz_solucion);
            printf("Producto escalar de matriz 1 realizado correctamente.\n");
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
            break;

        case 4:
            printf("Ingrese el escalar para multiplicar la matriz 2: ");
            scanf("%d", &scalar);
            esc_product(matriz2, scalar, matriz_solucion);
            printf("Producto escalar de matriz 2 realizado correctamente.\n");
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
            break;

        case 5:
            printf("Producto de matrices no implementado aún.\n");
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
            break;  

        default:
            printf("Opción no válida.\n");
            printf("Presione cualquier tecla para continuar...\n");
            getchar(); // Captura el salto de línea pendiente
            getchar(); // Espera a que el usuario presione una tecla
    }
}