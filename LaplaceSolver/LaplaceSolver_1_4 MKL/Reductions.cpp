#include "Reductions.h"

#include <algorithm>
#include <iostream>

using namespace std;

// #define DO_NOT_USE_MKL

#ifndef DO_NOT_USE_MKL
#include <mkl.h>
#endif

float Norm(const float (&x)[XDIM][YDIM][ZDIM])
{
#ifdef DO_NOT_USE_MKL
    float result = 0.;

#pragma omp parallel for reduction(max:result)
    for (int i = 1; i < XDIM-1; i++)
    for (int j = 1; j < YDIM-1; j++)
    for (int k = 1; k < ZDIM-1; k++)
        result = std::max(result, std::abs(x[i][j][k]));

    return result;
#else
    return std::abs(((const float *)x)[cblas_isamax(XDIM*YDIM*ZDIM, (const float*) x, 1)]);
#endif
}

float InnerProduct(const float (&x)[XDIM][YDIM][ZDIM], const float (&y)[XDIM][YDIM][ZDIM])
{
#ifdef DO_NOT_USE_MKL
    double result = 0.;

#pragma omp parallel for reduction(+:result)
    for (int i = 1; i < XDIM-1; i++)
    for (int j = 1; j < YDIM-1; j++)
    for (int k = 1; k < ZDIM-1; k++)
        result += (double) x[i][j][k] * (double) y[i][j][k];

    return result;
#else
    return cblas_sdot(XDIM*YDIM*ZDIM, (const float *)x, 1, (const float *)y, 1);
#endif
}
