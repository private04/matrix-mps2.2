#include "OPMATRIX.h"

void define_matrix(int *V,matrix A)
{
	for (int i=0;i<25;i++)
	{
		A[i/5][i%5] = V[i];
	}
}
