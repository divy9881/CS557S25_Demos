#pragma once

#include "Parameters.h"

#include <cstdlib>

void* AlignedAllocate(const std::size_t size, const std::size_t alignment);
void InitializeMatrices(float (&A)[MATRIX_SIZE_1][MATRIX_SIZE_2],float (&B)[MATRIX_SIZE_2][MATRIX_SIZE_3]);
float MatrixMaxDifference(const float (&A)[MATRIX_SIZE_1][MATRIX_SIZE_3],const float (&B)[MATRIX_SIZE_1][MATRIX_SIZE_3]);
