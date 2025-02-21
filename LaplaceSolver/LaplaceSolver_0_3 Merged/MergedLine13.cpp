#include "MergedLine13.h"

float MergedLine13(const float (&x)[XDIM][YDIM][ZDIM], float (&z)[XDIM][YDIM][ZDIM])
{
    double result = 0.;

#pragma omp parallel for reduction(+:result)
    for (int i = 1; i < XDIM-1; i++) {
        for (int j = 1; j < YDIM-1; j++) {
            for (int k = 1; k < ZDIM-1; k++) {
                z[i][j][k] = x[i][j][k];
                result += (double) x[i][j][k] * (double) x[i][j][k];
            }
        }
    }

    return (float) result;
}
