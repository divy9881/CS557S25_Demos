#include "MatMatMultiply.h"
#include "Timer.h"
#include "Utilities.h"

#include <iostream>
#include <iomanip>

int main(int argc, char *argv[])
{
    float *Araw = static_cast<float*>( AlignedAllocate( MATRIX_SIZE_1 * MATRIX_SIZE_2 * sizeof(float), 64 ) );
    float *Braw = static_cast<float*>( AlignedAllocate( MATRIX_SIZE_2 * MATRIX_SIZE_3 * sizeof(float), 64 ) );
    float *Craw = static_cast<float*>( AlignedAllocate( MATRIX_SIZE_1 * MATRIX_SIZE_3 * sizeof(float), 64 ) );
    float *referenceCraw = static_cast<float*>( AlignedAllocate( MATRIX_SIZE_1 * MATRIX_SIZE_3 * sizeof(float), 64 ) );

    using matrix_t_1 = float (&) [MATRIX_SIZE_1][MATRIX_SIZE_2];
    using matrix_t_2 = float (&) [MATRIX_SIZE_2][MATRIX_SIZE_3];
    using matrix_t_3 = float (&) [MATRIX_SIZE_1][MATRIX_SIZE_3];

    matrix_t_1 A = reinterpret_cast<matrix_t_1>(*Araw);
    matrix_t_2 B = reinterpret_cast<matrix_t_2>(*Braw);
    matrix_t_3 C = reinterpret_cast<matrix_t_3>(*Craw);
    matrix_t_3 referenceC = reinterpret_cast<matrix_t_3>(*referenceCraw);

    InitializeMatrices(A, B);
    Timer timer;

    // Correctness test
    std::cout << "Running candidate kernel for correctness test ... " << std::flush;
    timer.Start();
    MatMatMultiply(A, B, C);
    timer.Stop("Elapsed time : ");
    
    std::cout << "Running reference kernel for correctness test ... " << std::flush;
    timer.Start();
    MatMatMultiplyReference(A, B, referenceC);
    timer.Stop("Elapsed time : ");

    float discrepancy = MatrixMaxDifference(C, referenceC);
    std::cout << "Discrepancy between two methods : " << discrepancy << std::endl;
    
    for(int test = 1; test <= 20; test++)
    {
        std::cout << "Running kernel for performance run #" << std::setw(2) << test << " ... ";
        timer.Start();
        MatMatMultiply(A, B, C);
        timer.Stop("Elapsed time : ");
    }
    
    return 0;
}
