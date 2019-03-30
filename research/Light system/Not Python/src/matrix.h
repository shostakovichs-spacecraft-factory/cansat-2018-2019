/*
 * matrix.h
 *
 *  Created on: Mar 9, 2019
 *      Author: sereshotes
 */

#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct
{
	int height;
	int width;
	float *arr;

	int reserved;

} Matrixf;

///////Basic
Matrixf matrix_create(int height, int width);

void matrix_delete(Matrixf *matrix);

void matrix_resize(Matrixf *matrix, int height, int width);

float *matrix_at(Matrixf *matrix, int row, int column);

void matrix_print(Matrixf *matrix);

void matrix_setSize(Matrixf *matrix, int height, int width);

int matrix_copy(Matrixf *source, Matrixf *destination, int isForced);
///////

///////Unique matrices
void matrix_make_zero(Matrixf *matrix);

void matrix_make_identity(Matrixf *matrix);
///////

///////Matrix properties
void matrix_transpose(Matrixf* matrix);

int matrix_inverse(Matrixf *matrix);

float matrix_norm(Matrixf *matrix);
///////

///////Operations
int matrix_normalize(Matrixf *matrix);

int matrix_swapRows(Matrixf *matrix, int i1, int i2);

int matrix_mulRowNum(Matrixf *matrix, int index, float b);

int matrix_addRow(Matrixf *matrix, int source, int destination, float koef);

int matrix_multiplicate(Matrixf *left, Matrixf *right, Matrixf* result);

int matrix_add(Matrixf *left, Matrixf *right);

int matrix_sub(Matrixf *left, Matrixf *right);

void matrix_mulNumber(Matrixf *matrix, float koef);
///////


#endif /* MATRIX_H_ */
