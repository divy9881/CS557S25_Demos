#pragma once

#include "Parameters.h"

void MatMatMultiply(const float (&A)[MATRIX_SIZE_1][MATRIX_SIZE_2],
    const float (&B)[MATRIX_SIZE_2][MATRIX_SIZE_3], float (&C)[MATRIX_SIZE_1][MATRIX_SIZE_3]);

void MatMatMultiplyReference(const float (&A)[MATRIX_SIZE_1][MATRIX_SIZE_2],
    const float (&B)[MATRIX_SIZE_2][MATRIX_SIZE_3], float (&C)[MATRIX_SIZE_1][MATRIX_SIZE_3]);
