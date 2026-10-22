#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "OPMATRIX.h"
#include "IOMATRIX.h"

static FILE *log_file;

void descargar_matriz(matrix matriz_solucion);
void mostrar_matriz(matrix matriz);
void cargar_matriz(matrix matriz);
void selector_operaciones(matrix matriz1, matrix matriz2, matrix matriz_solucion);
static int leer_entero(const char *mensaje, int *valor);
static int esperar_enter(void);
static void registrar_numero(const char *descripcion, int valor);
static int cerrar_log(void);
static void registrar_evento(const char *evento);
static void registrar_matriz(const char *descripcion, matrix matriz);

int main() {
    int option = 0;
    int lectura;
    matrix matriz1 = {0}, matriz2 = {0}, matriz_solucion = {0};

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
        lectura = leer_entero("Opcion: ", &option);
        if (lectura < 0) {
            registrar_evento("Entrada finalizada o error de lectura. Cerrando el programa.");
            break;
        }
        if (lectura == 0) {
            registrar_evento("Entrada no valida en el menu principal.");
            continue;
        }
        registrar_numero("Opcion seleccionada:", option);

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

    return cerrar_log() ? 0 : 1;
}

void descargar_matriz(matrix matriz_solucion) {
    printf("Descargando matriz solución...\n");
    guardarMatriz("matriz_solucion.txt", matriz_solucion);
    registrar_matriz("Matriz solucion descargada:", matriz_solucion);
    mostrar_matriz(matriz_solucion);
}

void mostrar_matriz(matrix matriz) {
    registrar_matriz("Matriz mostrada:", matriz);
    visualizarMatriz(matriz);
    printf("\n");
    esperar_enter();
}

void cargar_matriz(matrix matriz) {
    int option = 0;
    int vector[25]; // Vector para almacenar los valores de la matriz

    // Lógica para cargar una matriz
    printf("Seleccione un metodo para cargar la matriz:\n");
    printf("1. Ingresar valores manualmente\n");
    printf("2. Cargar desde un archivo\n");
    if (leer_entero("Opcion: ", &option) <= 0) {
        registrar_evento("Entrada invalida o finalizada al seleccionar el metodo de carga.");
        return;
    }
    switch (option) {
        case 1:
            printf("Ingrese los valores de la matriz 5x5:\n");
            for (int i = 0; i < 25; i++) {
                char mensaje[64];
                snprintf(mensaje, sizeof(mensaje),
                         "Valor en la posicion [%d][%d]: ",
                         i / MATRIX_COLUMNS + 1, i % MATRIX_COLUMNS + 1);
                if (leer_entero(mensaje, &vector[i]) <= 0) {
                    registrar_evento("Carga manual cancelada por una entrada invalida o finalizada.");
                    return;
                }
            }
            define_matrix(vector, matriz);
            printf("Matriz creada correctamente.\n");
            registrar_evento("Matriz cargada manualmente.");
            registrar_matriz("Valores de la matriz cargada:", matriz);
            visualizarMatriz(matriz);
            esperar_enter();
            break;
        case 2:
            if (cargarMatriz("matriz_cargada.txt", matriz)) {
                printf("Matriz cargada desde archivo correctamente.\n");
                registrar_evento("Matriz cargada desde archivo.");
                registrar_matriz("Valores de la matriz cargada desde archivo:", matriz);
                visualizarMatriz(matriz);
            } else {
                printf("Error al cargar la matriz desde el archivo.\n");
                registrar_evento("Error al cargar la matriz desde el archivo.");
            }
            esperar_enter();
            break;
        default:
            printf("Opcion no válida.\n");
            registrar_evento("Metodo de carga no valido.");
            esperar_enter();
    }
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
    if (leer_entero("Opcion: ", &option) <= 0) {
        registrar_evento("Entrada invalida o finalizada al seleccionar la operacion.");
        return;
    }
    registrar_numero("Operacion seleccionada:", option);

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
            if (leer_entero("", &scalar) <= 0) {
                registrar_evento("Producto escalar cancelado por una entrada invalida o finalizada.");
                return;
            }
            esc_product(matriz1, scalar, matriz_solucion);
            printf("Producto escalar de matriz 1 realizado correctamente.\n");
            registrar_numero("Producto escalar de matriz 1 realizado con escalar", scalar);
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
            esperar_enter();
    }
}

static int leer_entero(const char *mensaje, int *valor) {
    char linea[128];
    char *fin;
    long resultado;

    fputs(mensaje, stdout);
    if (ferror(stdout)) {
        fprintf(stderr, "Error al mostrar el mensaje de entrada.\n");
        return -1;
    }

    if (fgets(linea, sizeof(linea), stdin) == NULL) {
        if (ferror(stdin)) {
            perror("Error al leer la entrada");
        } else {
            fprintf(stderr, "Fin de la entrada.\n");
        }
        return -1;
    }

    if (strchr(linea, '\n') == NULL) {
        int caracter;
        while ((caracter = getchar()) != '\n' && caracter != EOF) {
        }
        if (caracter == EOF && ferror(stdin)) {
            perror("Error al limpiar la entrada");
            return -1;
        }
        fprintf(stderr, "La entrada es demasiado larga.\n");
        return 0;
    }

    errno = 0;
    resultado = strtol(linea, &fin, 10);
    if (fin == linea || errno == ERANGE ||
        resultado < INT_MIN || resultado > INT_MAX) {
        fprintf(stderr, "Entrada no válida. Introduzca un número entero.\n");
        return 0;
    }

    while (*fin == ' ' || *fin == '\t' || *fin == '\r' || *fin == '\n') {
        fin++;
    }
    if (*fin != '\0') {
        fprintf(stderr, "Entrada no válida. Introduzca solo un número entero.\n");
        return 0;
    }

    *valor = (int) resultado;
    return 1;
}

static int esperar_enter(void) {
    char linea[128];
    int caracter;

    fputs("Presione Enter para continuar...\n", stdout);
    if (ferror(stdout)) {
        fprintf(stderr, "Error al mostrar el mensaje de continuación.\n");
        return 0;
    }
    if (fgets(linea, sizeof(linea), stdin) == NULL) {
        if (ferror(stdin)) {
            perror("Error al leer la entrada");
        }
        return 0;
    }
    if (strchr(linea, '\n') == NULL) {
        while ((caracter = getchar()) != '\n' && caracter != EOF) {
        }
        if (caracter == EOF && ferror(stdin)) {
            perror("Error al limpiar la entrada");
            return 0;
        }
    }
    return 1;
}

static void registrar_numero(const char *descripcion, int valor) {
    char mensaje[128];

    snprintf(mensaje, sizeof(mensaje), "%s %d.", descripcion, valor);
    registrar_evento(mensaje);
}

static int cerrar_log(void) {
    int resultado;

    if (log_file == NULL) {
        return 1;
    }
    resultado = fclose(log_file);
    log_file = NULL;
    if (resultado != 0) {
        perror("Error al cerrar log.txt");
        return 0;
    }
    return 1;
}

static void registrar_evento(const char *evento) {
    if (log_file == NULL) {
        return;
    }

    if (fprintf(log_file, "%s\n", evento) < 0 || fflush(log_file) != 0) {
        perror("Error al escribir en log.txt");
        fclose(log_file);
        log_file = NULL;
    }
}

static void registrar_matriz(const char *descripcion, matrix matriz) {
    if (log_file == NULL) {
        return;
    }

    if (fprintf(log_file, "%s\n", descripcion) < 0) {
        perror("Error al escribir en log.txt");
        fclose(log_file);
        log_file = NULL;
        return;
    }
    for (int i = 0; i < MATRIX_ROWS; i++) {
        for (int j = 0; j < MATRIX_COLUMNS; j++) {
            if (fprintf(log_file, "%d", matriz[i][j]) < 0) {
                perror("Error al escribir en log.txt");
                fclose(log_file);
                log_file = NULL;
                return;
            }
            if (j < MATRIX_COLUMNS - 1) {
                if (fputc(' ', log_file) == EOF) {
                    perror("Error al escribir en log.txt");
                    fclose(log_file);
                    log_file = NULL;
                    return;
                }
            }
        }
        if (fputc('\n', log_file) == EOF) {
            perror("Error al escribir en log.txt");
            fclose(log_file);
            log_file = NULL;
            return;
        }
    }
    if (fflush(log_file) != 0) {
        perror("Error al guardar log.txt");
        fclose(log_file);
        log_file = NULL;
    }
}
