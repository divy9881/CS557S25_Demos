#include "ConjugateGradients.h"
#include "Timer.h"
#include "Utilities.h"

Timer timerLaplacianLine2;
Timer timerLaplacianLine6;

Timer timerSaxpyLine2;
Timer timerSaxpyLine8;
Timer timerSaxpyLine9_12;
Timer timerSaxpyLine16;

Timer timerInnerProductLine4;
Timer timerInnerProductLine6;
Timer timerInnerProductLine13;

Timer timerNormLine2;
Timer timerNormLine8;

Timer timerCopyLine4;
Timer timerCopyLine13;

Timer timerWriteAsImage;

int main(int argc, char *argv[])
{
    using array_t = float (&) [XDIM][YDIM][ZDIM];

    float *xRaw = new float [XDIM*YDIM*ZDIM];
    float *fRaw = new float [XDIM*YDIM*ZDIM];
    float *pRaw = new float [XDIM*YDIM*ZDIM];
    float *rRaw = new float [XDIM*YDIM*ZDIM];
    float *zRaw = new float [XDIM*YDIM*ZDIM];
    
    array_t x = reinterpret_cast<array_t>(*xRaw);
    array_t f = reinterpret_cast<array_t>(*fRaw);
    array_t p = reinterpret_cast<array_t>(*pRaw);
    array_t r = reinterpret_cast<array_t>(*rRaw);
    array_t z = reinterpret_cast<array_t>(*zRaw);
    
    // Initialization
    {
        Timer timer;
        timer.Start();
        InitializeProblem(x, f);
        timer.Stop("Initialization : ");
    }

    // Call Conjugate Gradients algorithm
    timerLaplacianLine2.Reset();
    timerLaplacianLine6.Reset();

    timerSaxpyLine2.Reset();
    timerSaxpyLine8.Reset();
    timerSaxpyLine9_12.Reset();
    timerSaxpyLine16.Reset();

    timerInnerProductLine4.Reset();
    timerInnerProductLine6.Reset();
    timerInnerProductLine13.Reset();

    timerNormLine2.Reset();
    timerNormLine8.Reset();

    timerCopyLine4.Reset();
    timerCopyLine13.Reset();

    timerWriteAsImage.Reset();

    ConjugateGradients(x, f, p, r, z);
    timerLaplacianLine2.Print("Line-2 Laplacian Time : ");
    timerLaplacianLine6.Print("Line-6 Laplacian Time : ");

    timerSaxpyLine2.Print("Line-2 Saxpy Time : ");
    timerSaxpyLine8.Print("Line-8 Saxpy Time : ");
    timerSaxpyLine9_12.Print("Line-9-12 Saxpy Time : ");
    timerSaxpyLine16.Print("Line-16 Saxpy Time : ");

    timerInnerProductLine4.Print("Line-4 InnerProduct Time : ");
    timerInnerProductLine6.Print("Line-6 InnerProduct Time : ");
    timerInnerProductLine13.Print("Line-13 InnerProduct Time : ");

    timerNormLine2.Print("Line-2 Norm Time : ");
    timerNormLine8.Print("Line-8 Norm Time : ");

    timerCopyLine4.Print("Line-4 Copy Time : ");
    timerCopyLine13.Print("Line-13 Copy Time : ");

    timerWriteAsImage.Print("WriteAsImage Time : ");
    
    return 0;
}
