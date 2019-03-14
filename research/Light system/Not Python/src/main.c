#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void find_solution(Matrixf *A, Matrixf *b, Matrixf *x)
{
	Matrixf *M2 = matrix_create(A->height, A->height);
	Matrixf *M3 = matrix_create(A->height, A->height);
	Matrixf *M4 = matrix_create(A->width, A->height);
	Matrixf *A_t = matrix_create(A->width, A->height);

	matrix_get_transpose(A, A_t);
	matrix_multiplicate(A_t, A, M2);

	matrix_get_inverse(M2, M3);
	//matrix_print(M3);

	matrix_multiplicate(M3, A_t, M4);

	matrix_multiplicate(M4, b, x);

	matrix_delete(M2);
	matrix_delete(M3);
	matrix_delete(M4);
	matrix_delete(A_t);
}

int main()
{
	Matrixf *A = matrix_create(3, 3);
	Matrixf *b = matrix_create(3, 1);
	Matrixf *x = matrix_create(3, 1);

	A->arr[0][0] = 1;
	A->arr[0][1] = 1;
	A->arr[0][2] = 1;
	A->arr[1][0] = 1;
	A->arr[1][1] = 2;
	A->arr[1][2] = 3;
	A->arr[2][0] = 3;
	A->arr[2][1] = 1;
	A->arr[2][2] = 1;

	b->arr[0][0] = 1;
	b->arr[1][0] = 2;
	b->arr[2][0] = 3;

	find_solution(A, b, x);

	matrix_print(x);

	return 0;
}
