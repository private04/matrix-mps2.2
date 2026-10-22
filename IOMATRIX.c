
#include <stdio.h>
#include "IOMATRIX.h"

void visualizarMatriz(const int matriz[MATRIX_SIZE][MATRIX_SIZE])
{
    int i, j;

    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%5d", matriz[i][j]);
        }

        printf("\n");
    }
}