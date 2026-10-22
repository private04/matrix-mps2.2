
#include <stdio.h>
#include "IOMATRIX.h"

int main(void)
{
    int matrice[MATRIX_SIZE][MATRIX_SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int matriceChargee[MATRIX_SIZE][MATRIX_SIZE];

    printf("=== TEST 1: AFFICHAGE ===\n");
    visualizarMatriz(matrice);

    printf("\n=== TEST 2: SAUVEGARDE ===\n");

    if (guardarMatriz("matrice_test.txt", matrice))
    {
        printf("Sauvegarde reussie.\n");
    }
    else
    {
        printf("Echec de la sauvegarde.\n");
        return 1;
    }

    printf("\n=== TEST 3: CHARGEMENT ===\n");

    if (cargarMatriz("matrice_test.txt", matriceChargee))
    {
        printf("Chargement reussi.\n");
        visualizarMatriz(matriceChargee);
    }
    else
    {
        printf("Echec du chargement.\n");
        return 1;
    }

    return 0;
}
