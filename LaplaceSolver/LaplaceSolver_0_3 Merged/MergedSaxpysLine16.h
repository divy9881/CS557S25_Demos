#pragma once

#include "Parameters.h"

void MergedSaxpysLine16(float (&p)[XDIM][YDIM][ZDIM], float (&x)[XDIM][YDIM][ZDIM],
    float (&z)[XDIM][YDIM][ZDIM], const float alpha, const float beta);