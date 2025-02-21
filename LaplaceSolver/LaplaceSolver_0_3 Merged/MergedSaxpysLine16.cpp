#include "MergedSaxpysLine16.h"

void MergedSaxpysLine16(float (&p)[XDIM][YDIM][ZDIM], float (&x)[XDIM][YDIM][ZDIM],
    float (&z)[XDIM][YDIM][ZDIM], const float alpha, const float beta)
{
    // Should we use OpenMP parallel for here?
    for (int i = 1; i < XDIM-1; i++) {
        for (int j = 1; j < YDIM-1; j++) {
            for (int k = 1; k < ZDIM-1; k++) {
                x[i][j][k] = x[i][j][k] + alpha * p[i][j][k];
                p[i][j][k] = z[i][j][k] + beta * p[i][j][k];
            }
        }
    }
}