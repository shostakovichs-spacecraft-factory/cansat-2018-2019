#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

#include "Light_direction_determinant.h"


int main()
{
	Matrixf A = matrix_create(3, 3);
	Matrixf b = matrix_create(3, 1);
	Matrixf x = matrix_create(3, 1);

	A.arr[0][0] = 1;
	A.arr[0][1] = 1;
	A.arr[0][2] = 1;
	A.arr[1][0] = 1;
	A.arr[1][1] = 2;
	A.arr[1][2] = 3;
	A.arr[2][0] = 3;
	A.arr[2][1] = 1;
	A.arr[2][2] = 1;

	b.arr[0][0] = 1;
	b.arr[1][0] = 2;
	b.arr[2][0] = 3;

	LDR_find_solution(&A, &b, &x);

	matrix_print(&x);

	return 0;
}
