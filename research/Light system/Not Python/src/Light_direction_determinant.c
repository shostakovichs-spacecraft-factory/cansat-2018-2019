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
static Matrixf M4;
static Matrixf A_t;

#define DEBUG
#ifdef DEBUG
void debug_matrixPrint(Matrixf *A)
{
	matrix_print(A);
}
#else
void m_print(Matrixf *A)
{

}
#endif

void LDR_init()
{
	M2.arr = malloc(sizeof(float)*8*3);
	M3.arr = malloc(sizeof(float)*8*3);
	M4.arr = malloc(sizeof(float)*8*3);
	A_t.arr = malloc(sizeof(float)*8*3);
}
void LDR_findSolution(Matrixf *A, Matrixf *b, Matrixf *x)
{
	matrix_setSize(&M2, A->width, A->width);
	matrix_setSize(&M3, A->width, A->width);
	matrix_setSize(&M4, A->width, A->height);
	matrix_setSize(&A_t, A->width, A->height);

	matrix_get_transpose(A, &A_t);
	matrix_multiplicate(&A_t, A, &M2);
	debug_matrixPrint(&M2);

	matrix_get_inverse(&M2, &M3);
	debug_matrixPrint(&M3);
	//matrix_print(M3);

	matrix_multiplicate(&M3, &A_t, &M4);
	debug_matrixPrint(&M4);

	matrix_multiplicate(&M4, b, x);
}
