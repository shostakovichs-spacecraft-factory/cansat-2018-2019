/*
 * Light_direction_determinant.c
 *
 *  Created on: 16 мар. 2019 г.
 *      Author: sereshotes
 */


#include "Light_direction_determinant.h"

static Matrixf M2;
static Matrixf M3;
static Matrixf M4;
static Matrixf A_t;
void LDR_find_solution(Matrixf *A, Matrixf *b, Matrixf *x)
{
	M2 = matrix_create(A->height, A->height);
	M3 = matrix_create(A->height, A->height);
	M4 = matrix_create(A->width, A->height);
	A_t = matrix_create(A->width, A->height);

	matrix_get_transpose(A, &A_t);
	matrix_multiplicate(&A_t, A, &M2);

	matrix_get_inverse(&M2, &M3);
	//matrix_print(M3);

	matrix_multiplicate(&M3, &A_t, &M4);

	matrix_multiplicate(&M4, b, x);

	matrix_delete(&M2);
	matrix_delete(&M3);
	matrix_delete(&M4);
	matrix_delete(&A_t);
}
