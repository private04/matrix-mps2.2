
#include <stdio.h>
#include <stddef.h>
#include "IOMATRIX.h"

/*
 * Step 1: Display the matrix on screen
 */
void visualizarMatriz(
    const int matriz[MATRIX_SIZE][MATRIX_SIZE]
)
{
    int i;
    int j;

    if (matriz == NULL)
    {
        fprintf(stderr, "Error: matriz invalida.\n");
        return;
    }

    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%d", matriz[i][j]);

            if (j < MATRIX_SIZE - 1)
            {
                printf("\t");
            }
        }

        printf("\n");
    }
}

/*
 * Step 2: Save the matrix to a file
 * Returns 1 on success, 0 on failure.
 */
int guardarMatriz(
    const char *nombreArchivo,
    const int matriz[MATRIX_SIZE][MATRIX_SIZE]
)
{
    FILE *fichier;
    int i;
    int j;

    if (nombreArchivo == NULL || matriz == NULL)
    {
        fprintf(stderr, "Error: argumento invalido.\n");
        return 0;
    }

    fichier = fopen(nombreArchivo, "w");

    if (fichier == NULL)
    {
        perror("Error al abrir el archivo");
        return 0;
    }

    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            if (fprintf(fichier, "%d", matriz[i][j]) < 0)
            {
                fclose(fichier);
                fprintf(stderr, "Error al escribir el archivo.\n");
                return 0;
            }

            if (j < MATRIX_SIZE - 1)
            {
                if (fprintf(fichier, " ") < 0)
                {
                    fclose(fichier);
                    fprintf(stderr, "Error al escribir el archivo.\n");
                    return 0;
                }
            }
        }

        if (fprintf(fichier, "\n") < 0)
        {
            fclose(fichier);
            fprintf(stderr, "Error al escribir el archivo.\n");
            return 0;
        }
    }

    if (fclose(fichier) == EOF)
    {
        fprintf(stderr, "Error al cerrar el archivo.\n");
        return 0;
    }

    return 1;

    
}

/*
 * Step 3: Load a matrix from a file
 * Expected format: 5 rows, each containing 5 integers.
 * Returns 1 on success, 0 on failure.
 */
int cargarMatriz(
    const char *nombreArchivo,
    int matriz[MATRIX_SIZE][MATRIX_SIZE]
)
{
    FILE *fichier;
    int i;
    int j;

    if (nombreArchivo == NULL || matriz == NULL)
    {
        fprintf(stderr, "Error: argumento invalido.\n");
        return 0;
    }

    fichier = fopen(nombreArchivo, "r");

    if (fichier == NULL)
    {
        perror("Error al abrir el archivo");
        return 0;
    }

    for (i = 0; i < MATRIX_SIZE; i++)
    {
        for (j = 0; j < MATRIX_SIZE; j++)
        {
            if (fscanf(fichier, "%d", &matriz[i][j]) != 1)
            {
                fprintf(stderr,
                        "Error: formato de matriz invalido.\n");
                fclose(fichier);
                return 0;
            }
        }
    }

    if (fclose(fichier) == EOF)
    {
        fprintf(stderr, "Error al cerrar el archivo.\n");
        return 0;
    }

    return 1;
}
