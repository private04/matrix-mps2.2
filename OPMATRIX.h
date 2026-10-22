#ifndef OPMATRIX_H
#define OPMATRIX_H

#define MATRIX_ROWS 5
#define MATRIX_COLUMNS 5

typedef int matrix[5][5];

//Pre: V is a vector of 25 integers
//Post: Fills A row by row with the integers of V
void define_matrix(int * V,matrix A);

//Pre: A and B are defined
//Post: C becomes a matrix that is the sum of A and B
void sum(matrix A,matrix B,matrix C);

//Pre: A and B are defined
//Post: C becomes a matrix that is the subtraction of A and B
void subtract(matrix A,matrix B,matrix C);

//Pre: A is defined
//Post: C becomes a matrix that is the product of A and b
void esc_product(matrix A,int b,matrix C);

#endif
