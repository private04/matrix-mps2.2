
#include <stdio.h>
#include <stddef.h>
#include "OPMATRIX.h"

#define MATRIX_SIZE 5
void visualizarMatriz(
    const int matriz[MATRIX_SIZE][MATRIX_SIZE]
);
/*
 * Step 2: Save the matrix to a file
 * Returns 1 on success, 0 on failure.
 */
int guardarMatriz(
    const char *nombreArchivo,
    const int matriz[MATRIX_SIZE][MATRIX_SIZE]
);
/*
 * Step 3: Load a matrix from a file
 * Expected format: 5 rows, each containing 5 integers.
 * Returns 1 on success, 0 on failure.
 */
int cargarMatriz(
    const char *nombreArchivo,
    int matriz[MATRIX_SIZE][MATRIX_SIZE]
);

