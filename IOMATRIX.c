
#include <stdio.h>
#include <stddef.h>
#include "IOMATRIX.h"

void visualizarMatriz(
    const int matriz[MATRIX_SIZE][MATRIX_SIZE]
)
{
    int i;
    int j;

    if (matriz == NULL)
    {
        fprintf(stderr, "Error: la matriz no es valida.\n");
        return;
    }

    printf("\nMatriz %dx%d\n", MATRIX_SIZE, MATRIX_SIZE);

    printf("        ");
    for (j = 0; j < MATRIX_SIZE; j++)
    {
        printf("%8d", j + 1);
    }

    printf("\n        ");

    for (j = 0; j < MATRIX_SIZE; j++)
    {
        printf("--------");
    }

    printf("\n");

    for (i = 0; i < MATRIX_SIZE; i++)
    {
        printf("Fila %-3d", i + 1);

        for (j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%8d", matriz[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}
