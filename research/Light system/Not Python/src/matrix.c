/*
 * matrix.c
 *
 *  Created on: Mar 8, 2019
 *      Author: sereshotes
 */
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include <errno.h>


#define EPS 1 / (1 << 20)

int matrix_isInRange(Matrixf *matrix, int row, int column)
{
	return !(row >= matrix->height || column >= matrix->width);
}

float *matrix_at(Matrixf *matrix, int row, int column)
{
	if(!matrix_isInRange(matrix, row, column))
	{
		fprintf(stderr, "Out of range!\n");
		return NULL;
	}
	return &matrix->arr[row * matrix->width + column];
}

void matrix_for_each(Matrixf *matrix, void (*fun)(Matrixf*, int, int))
{
	for (int i = 0; i < matrix->height; i++)
		for (int j = 0; j < matrix->width; j++)
			fun(matrix, i, j);
}

static void _matrix_print(Matrixf *x, int a, int b)
{
	printf("%f ", *matrix_at(x, a, b));
	if (b == x->width - 1)
		printf("\n");

}
void matrix_print(Matrixf *matrix)
{
	matrix_for_each(matrix, _matrix_print);
	printf("\n");
}



void matrix_make_identity(Matrixf *matrix)
{
	for (int i = 0; i < matrix->height; i++)
		for (int j = 0; j < matrix->width; j++)
		{
			if (i != j)
				*matrix_at(matrix, i, j) = 0;
			else
				*matrix_at(matrix, i, j) = 1;
		}
}


void matrix_multiplicate(Matrixf *left, Matrixf *right, Matrixf* result)
{
	if (left->width != right->height || right->width != result->width
			|| left->height != result->height)
	{
		//some error
		printf("bad mul\n");
		return;
	}
	for (int i = 0; i < left->height; i++)
	{
		for (int j = 0; j < right->width; j++)
		{
			*matrix_at(result, i, j) = 0;
			for (int k = 0; k < left->width; k++)
			{
				*matrix_at(result, i, j) += *matrix_at(left, i, k) * *matrix_at(right, k, j);
			}
		}
	}
}
void matrix_swap_rows(Matrixf *matrix, int i1, int i2)
{
	if (i1 >= matrix->height || i2 >= matrix->height)
	{
		//error
		printf("bad swap\n");
		return;
	}
	for(int i = 0; i < matrix->width; i++)
	{
		float t = *matrix_at(matrix, i1, i);
		*matrix_at(matrix, i1, i) = *matrix_at(matrix, i2, i);
		*matrix_at(matrix, i2, i) = t;
	}
}
void matrix_mul_row_num(Matrixf *matrix, int index, float b)
{
	if (index >= matrix->height)
	{
		//error
		return;
	}
	for (int i = 0; i < matrix->width; i++)
	{
		*matrix_at(matrix, index, i) *= b;
	}
}

void matrix_add_row(Matrixf *matrix, int source, int destination, float koef)
{
	if (source >= matrix->height || destination >= matrix->height)
	{
		printf("bad add row\n");
		//error
		return;
	}
	for (int i = 0; i < matrix->width; i++)
	{
		*matrix_at(matrix, destination, i) += koef * *matrix_at(matrix, source, i);
	}
}

#warning "Надо исправить это"
void matrix_get_transpose(Matrixf *matrix, Matrixf *result) //do we need error processing
{
	for (int i = 0; i < matrix->height; i++)
		for (int j = 0; j < matrix->width; j++)
			*matrix_at(result, j, i) = *matrix_at(matrix, i, j);
}

//Метод Гаусса
void matrix_get_inverse(Matrixf *matrix, Matrixf *result)
{
	if (matrix->height != matrix->width)
	{
		printf("bad inverse\n");
		return;
	}

	float _arr[matrix->height * matrix->width];
	Matrixf temp;
	temp.arr = _arr;
	matrix_copy(matrix, &temp, 1);

	matrix_make_identity(result);
	//matrix_print(&temp);

	for (int x = 0; x < temp.width - 1; x++)
	{
		int i1 = -1;
		for (int i = x; i < temp.height; i++)
		{
			if (*matrix_at(&temp, i, x) > EPS || *matrix_at(&temp, i, x) < -EPS)
			{
				i1 = i;
				break;
			}
		}
		matrix_swap_rows(result, x, i1);
		matrix_swap_rows(&temp, x, i1);

		float k = -1 / *matrix_at(&temp, x, x);

		for (int i = x + 1; i < temp.height; i++)
		{
			float t = k * *matrix_at(&temp, i, x);
			//printf("%f",t);
			matrix_add_row(&temp, x, i, t);
			matrix_add_row(result, x, i, t);
			//matrix_print(&temp);
		}
	}
	for (int i = temp.width - 1; i >= 0; i--)
	{
		matrix_mul_row_num(result, i, 1 / *matrix_at(&temp, i, i));
		*matrix_at(&temp, i, i) = 1;

		for (int j = i - 1; j >= 0; j--)
		{
			float t = -*matrix_at(&temp, j, i);
			matrix_add_row(&temp, i, j, t);
			matrix_add_row(result, i, j, t);
		}
	}
	//matrix_print(&temp);
}

//isForced != 0 => copy size too
void matrix_copy(Matrixf *source, Matrixf *destination, int isForced)
{
	if(isForced)
	{
		destination->height = source->height;
		destination->width = source->width;
	}
	else if(destination->height != source->height || destination->width != source->width)
	{
		fprintf(stderr, "Sizes do not appropriate\n");
		return;
	}
	for (int i = 0; i < destination->height; i++)
		for (int j = 0; j < source->width; j++)
			*matrix_at(destination, i, j) = *matrix_at(source, i, j);
}


void matrix_setSize(Matrixf *matrix, int height, int width)
{
	matrix->height = height;
	matrix->width = width;
}




/*
 float matrix_det1(Matrixf a)
 {
 if(a.height != a.width)
 {
 //some error
 return nanf();
 }
 return a.arr[0][0];
 }
 float matrix_det2(Matrixf a)
 {
 if(a.height != a.width)
 {
 //some error
 return nanf();
 }
 return a.arr[0][0] * a.arr[1][1] - a.arr[0][1] * a.arr[1][0];
 }
 float det2(float a11, float a12, float a21, floa)
 float matrix_det3(Matrixf a)
 {
 if(a.height != a.width)
 {
 //some error
 return nanf();
 }
 float sum = 0;
 sum += a.arr[0][0] * a.arr[1][1] * a.arr[2][2];
 sum += a.arr[0][1] * a.arr[1][2] * a.arr[2][0];
 sum += a.arr[1][0] * a.arr[2][1] * a.arr[0][2];

 sum -= a.arr[0][2] * a.arr[1][1] * a.arr[2][0];
 sum -= a.arr[0][1] * a.arr[1][0] * a.arr[2][2];
 sum -= a.arr[0][0] * a.arr[2][1] * a.arr[1][2];
 return sum;
 }

 void matrix_inv(Matrixf a, Matrixf res)
 {

 }
 */
