/*
 * Light_direction_determinant.c
 *
 *  Created on: 16 мар. 2019 г.
 *      Author: sereshotes
 */


#include "Light_direction_determinant.h"
#include <stdlib.h>

static Matrixf M2;
static Matrixf M3;
static Matrixf A_t;

void LDR_init()
{
	M2.arr = malloc(sizeof(float)*3*3);
	M3.arr = malloc(sizeof(float)*8*3);
	A_t.arr = malloc(sizeof(float)*8*3);
}

void LDR_deinit()
{
	free(M2.arr);
	free(M3.arr);
	free(A_t.arr);
}

//x = ((A_t*A)^-1)*A_t*b
void LDR_findSolution(Matrixf *A, Matrixf *b, Matrixf *x)
{
	matrix_setSize(&M2, A->width, A->width);
	matrix_setSize(&M3, A->width, A->height);

	matrix_copy(A, &A_t, 1);
	matrix_transpose(&A_t);
	matrix_multiplicate(&A_t, A, &M2);

	matrix_inverse(&M2);

	matrix_multiplicate(&M2, &A_t, &M3);

	matrix_multiplicate(&M3, b, x);
}
