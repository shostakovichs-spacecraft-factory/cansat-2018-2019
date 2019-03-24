#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

#include "Light_direction_determinant.h"

void test()
{
	LDR_init();

	Matrixf A = {3, 3, malloc(sizeof(float) * 3 * 3)};
	Matrixf b = {3, 1, malloc(sizeof(float) * 3 * 1)};
	Matrixf x = {3, 1, malloc(sizeof(float) * 3 * 1)};
	*matrix_at(&A, 0, 0) = 1;
	*matrix_at(&A, 0, 1) = 1;
	*matrix_at(&A, 0, 2) = 1;
	*matrix_at(&A, 1, 0) = 1;
	*matrix_at(&A, 1, 1) = 2;
	*matrix_at(&A, 1, 2) = 3;
	*matrix_at(&A, 2, 0) = 3;
	*matrix_at(&A, 2, 1) = 1;
	*matrix_at(&A, 2, 2) = 1;

	*matrix_at(&b, 0, 0) = 1;
	*matrix_at(&b, 1, 0) = 2;
	*matrix_at(&b, 2, 0) = 3;

	LDR_findSolution(&A, &b, &x);

	matrix_print(&x);
}

int main()
{
	int n = 20;
	int *a = malloc(n*sizeof(n));
	for(int i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	test();


	return 0;
}
