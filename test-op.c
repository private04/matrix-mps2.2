#include <stdio.h>
#include "OPMATRIX.h"
#include "IOMATRIX.h"

int main() {
    // 1. Definimos dos matrices A y B con valores sencillos para comprobar el cálculo a simple vista
    matrix A = {
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4},
        {5, 5, 5, 5, 5}
    };

    matrix B = {
        {5, 5, 5, 5, 5},
        {4, 4, 4, 4, 4},
        {3, 3, 3, 3, 3},
        {2, 2, 2, 2, 2},
        {1, 1, 1, 1, 1}
    };

    matrix R; // Matriz donde se guardará el resultado de cada cálculo
    // 2. Probar SUMA (A + B) -> Todas las posiciones deben dar 6
    sum(A, B, R);
    // 3. Probar RESTA (A - B)
    subtract(A, B, R);
    // 4. Probar PRODUCTO ESCALAR (3 * A)
    esc_product(A, 3, R);

    // 5. Probar MULTIPLICACION MATRICIAL (A x B)
    product(A, B, R);
    
    // 6. Probar Matriz simétrica
    if (simetric(A))
	    printf("A es simetrica");
    else
	    printf("A no es simetrica");

    printf("\nPrueba completada.\n");
    return 0;
}
