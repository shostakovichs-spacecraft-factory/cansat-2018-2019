#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#include "Light_direction_determinant.h"
void test()
{
	LDR_init();

	Matrixf A = {4, 3, malloc(sizeof(float) * 3 * 3)};
	Matrixf b = {4, 1, malloc(sizeof(float) * 3 * 1)};
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
	*matrix_at(&A, 3, 0) = 9;
	*matrix_at(&A, 3, 1) = 3;
	*matrix_at(&A, 3, 2) = 1;

	*matrix_at(&b, 0, 0) = 1;
	*matrix_at(&b, 1, 0) = 2;
	*matrix_at(&b, 2, 0) = 3;
	*matrix_at(&b, 3, 0) = 4;

	LDR_findSolution(&A, &b, &x);

	matrix_print(&x);
}

void swapf(float *a,float *b)
{
	float t = *a;
	*a = *b;
	*b = t;
}
void swapi(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int main()
{
	Matrixf a = matrix_create(4, 1);
	*matrix_at(&a, 0, 0) = 1;
	*matrix_at(&a, 1, 0) = 2;
	*matrix_at(&a, 2, 0) = 3;
	*matrix_at(&a, 3, 0) = 4;

	matrix_print(&a);
	//AHRS_quatToMatrix4_4(&a);
	matrix_print(&a);

	matrix_delete(&a);
	return 0;
}
