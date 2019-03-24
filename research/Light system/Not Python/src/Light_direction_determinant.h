/*
 * Light_direction_determinant.h
 *
 *  Created on: 16 мар. 2019 г.
 *      Author: sereshotes
 */

#ifndef LIGHT_DIRECTION_DETERMINANT_H_
#define LIGHT_DIRECTION_DETERMINANT_H_

#include "matrix.h"

void LDR_findSolution(Matrixf *A, Matrixf *b, Matrixf *x);

void LDR_init();

#endif /* LIGHT_DIRECTION_DETERMINANT_H_ */
