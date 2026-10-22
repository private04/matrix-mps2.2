#include "OPMATRIX.h"

void define_matrix(int *V,matrix A)
{
	for (int i=0;i<25;i++)
	{
		A[i/5][i%5] = V[i];
	}
}

void sum(matrix A,matrix B,matrix C)
{
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)
			C[i][j] = A[i][j] + B[i][j];
}
void subtract(matrix A,matrix B,matrix C)
{
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)
			C[i][j] = A[i][j] - B[i][j];
}

void esc_product(matrix A, int b,matrix C)
{
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)
			C[i][j] = A[i][j] * b;
}

void product(matrix A,matrix B,matrix C)
{
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)
		{
			C[i][j] = 0;
			for (int a=0;a<5;a++)
			{
				C[i][j] += A[i][a] * B[a][j];
			}
		}
}

