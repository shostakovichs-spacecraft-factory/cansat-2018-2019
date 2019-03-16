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
	float arr[8][8];
	int height;
	int width;

} Matrixf;

void matrix_for_each(Matrixf *matrix, void (*fun)(Matrixf*, int, int));

void matrix_print(Matrixf *matrix);

Matrixf matrix_create(int height, int width);

void matrix_delete(Matrixf *source);

void matrix_swap_rows(Matrixf *matrix, int i1, int i2);

void matrix_mul_row_num(Matrixf *matrix, int index, float b);

void matrix_add_row(Matrixf *matrix, int source, int destination, float koef);

void matrix_equate(Matrixf *source, Matrixf *destination);

void matrix_get_transpose(Matrixf *source, Matrixf *result);

void matrix_get_inverse(Matrixf *source, Matrixf *result);

void matrix_multiplicate(Matrixf *left, Matrixf *right, Matrixf* result);

#endif /* MATRIX_H_ */
