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

#define EPS 1 / (1 << 20)

void matrix_for_each(Matrixf *matrix, void (*fun)(Matrixf*, int, int))
{
	for (int i = 0; i < matrix->height; i++)
		for (int j = 0; j < matrix->width; j++)
			fun(matrix, i, j);
}

void print(Matrixf *x, int a, int b)
{
	printf("%f ", x->arr[a][b]);
	if (b == x->width - 1)
		printf("\n");

}
void matrix_print(Matrixf *matrix)
{
	matrix_for_each(matrix, print);
	printf("\n");
}

//Don't worry! Dynamic arrays just for testing. One day will be optimized
Matrixf *matrix_create(int height, int width)
{
	Matrixf *res = malloc(sizeof(res[0]));
	res->arr = calloc(sizeof(res->arr[0]), height);
	for (int i = 0; i < height; i++) {
		res->arr[i] = calloc(sizeof(res->arr[0][0]), width);
	}
	res->height = height;
	res->width = width;
	return res;
}

void matrix_make_identity(Matrixf *matrix)
{
	for (int i = 0; i < matrix->height; i++)
		for (int j = 0; j < matrix->width; j++)
		{
			if (i != j)
				matrix->arr[i][j] = 0;
			else
				matrix->arr[i][j] = 1;
		}
}

void matrix_delete(Matrixf *matrix)
{
	for (int i = 0; i < matrix->height; i++)
	{
		free(matrix->arr[i]);
	}
	free(matrix->arr);
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
			result->arr[i][j] = 0;
			for (int k = 0; k < left->height; k++)
			{
				result->arr[i][j] += left->arr[i][k] * right->arr[k][j];
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
	float *t = matrix->arr[i1];
	matrix->arr[i1] = matrix->arr[i2];
	matrix->arr[i2] = t;
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
		matrix->arr[index][i] *= b;
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
		matrix->arr[destination][i] += koef * matrix->arr[source][i];
	}
}

void matrix_get_transpose(Matrixf *matrix, Matrixf *result) //do we need error processing
{
	for (int i = 0; i < matrix->height; i++)
		for (int j = 0; j < matrix->width; j++)
			result->arr[j][i] = matrix->arr[i][j];
}
void matrix_get_inverse(Matrixf *matrix, Matrixf *result)
{
	if (matrix->height != matrix->width)
	{
		printf("bad inverse\n");
		return;
	}
	Matrixf *temp = matrix_create(matrix->height, matrix->width);
	matrix_equate(matrix, temp);
	matrix_make_identity(result);
	matrix_print(temp);

	for (int x = 0; x < temp->width - 1; x++)
	{
		int i1 = -1;
		for (int i = x; i < temp->height; i++)
		{
			if (temp->arr[i][x] > EPS || temp->arr[i][x] < -EPS)
			{
				i1 = i;
				break;
			}
		}
		matrix_swap_rows(temp, x, i1);
		matrix_swap_rows(result, x, i1);

		float k = -1 / temp->arr[x][x];

		for (int i = x + 1; i < temp->height; i++)
		{
			float t = k * temp->arr[i][x];
			//printf("%f",t);
			matrix_add_row(temp, x, i, t);
			matrix_add_row(result, x, i, t);
			//matrix_print(temp);
		}
	}
	for (int i = temp->width - 1; i >= 0; i--)
	{
		matrix_mul_row_num(result, i, 1 / temp->arr[i][i]);
		temp->arr[i][i] = 1;

		for (int j = i - 1; j >= 0; j--)
		{
			float t = -temp->arr[j][i];
			matrix_add_row(temp, i, j, t);
			matrix_add_row(result, i, j, t);
		}
	}
	//matrix_print(temp);
	matrix_delete(temp);
}

void matrix_equate(Matrixf *source, Matrixf *destination)
{

	for (int i = 0; i < destination->height; i++)
		for (int j = 0; j < source->width; j++)
			destination->arr[i][j] = source->arr[i][j];
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
