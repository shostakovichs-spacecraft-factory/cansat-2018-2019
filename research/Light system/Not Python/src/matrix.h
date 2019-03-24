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

} Matrixf;

float *matrix_at(Matrixf *matrix, int row, int column);

void matrix_for_each(Matrixf *matrix, void (*fun)(Matrixf*, int, int));

void matrix_print(Matrixf *matrix);

void matrix_setSize(Matrixf *matrix, int height, int width);

void matrix_swap_rows(Matrixf *matrix, int i1, int i2);

void matrix_mul_row_num(Matrixf *matrix, int index, float b);

void matrix_add_row(Matrixf *matrix, int source, int destination, float koef);

void matrix_copy(Matrixf *source, Matrixf *destination, int isForced);

void matrix_transpose(Matrixf* matrix);

void matrix_inverse(Matrixf *matrix);

void matrix_multiplicate(Matrixf *left, Matrixf *right, Matrixf* result);


#endif /* MATRIX_H_ */
