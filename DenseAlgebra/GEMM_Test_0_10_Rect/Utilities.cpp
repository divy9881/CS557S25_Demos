#include "Utilities.h"

#include <algorithm>
#include <cmath>
#include <memory>
#include <new>
#include <random>

void* AlignedAllocate(const std::size_t size, const std::size_t alignment)
{
    std::size_t capacity = size + alignment - 1;
    void *ptr = new char[capacity];
    auto result = std::align(alignment, size, ptr, capacity);
    if (result == nullptr) throw std::bad_alloc();
    if (capacity < size) throw std::bad_alloc();
    return ptr;
}

void InitializeMatrices(float (&A)[MATRIX_SIZE_1][MATRIX_SIZE_2],float (&B)[MATRIX_SIZE_2][MATRIX_SIZE_3])
{
    std::random_device rd; std::mt19937 gen(rd());
    std::uniform_real_distribution<float> uniform_dist(-1., 1.);
    for (int i = 0; i < MATRIX_SIZE_1; i++)
        for (int j = 0; j < MATRIX_SIZE_2; j++) {
            A[i][j] = uniform_dist(gen);
        }
    
    for (int i = 0; i < MATRIX_SIZE_2; i++)
        for (int j = 0; j < MATRIX_SIZE_3; j++) {
            B[i][j] = uniform_dist(gen);
        }
}

float MatrixMaxDifference(const float (&A)[MATRIX_SIZE_1][MATRIX_SIZE_3],const float (&B)[MATRIX_SIZE_1][MATRIX_SIZE_3])
{
    float result = 0.;
    for (int i = 0; i < MATRIX_SIZE_1; i++)
    for (int j = 0; j < MATRIX_SIZE_2; j++)
        result = std::max( result, std::abs( A[i][j] - B[i][j] ) );
    return result;
}
