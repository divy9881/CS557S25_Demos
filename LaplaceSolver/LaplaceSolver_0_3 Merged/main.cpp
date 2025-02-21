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

Timer timerNormLine2;
Timer timerNormLine8;

Timer timerCopyLine4;

Timer timerWriteAsImage;

Timer timerConjugateGradients;

Timer timerLine13;

using namespace std;

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
    timerConjugateGradients.Reset();

    timerLaplacianLine2.Reset();
    timerLaplacianLine6.Reset();

    timerSaxpyLine2.Reset();
    timerSaxpyLine8.Reset();
    timerSaxpyLine9_12.Reset();
    timerSaxpyLine16.Reset();

    timerInnerProductLine4.Reset();
    timerInnerProductLine6.Reset();

    timerNormLine2.Reset();
    timerNormLine8.Reset();

    timerCopyLine4.Reset();

    timerWriteAsImage.Reset();

    timerConjugateGradients.Restart(); ConjugateGradients(x, f, p, r, z, false); timerConjugateGradients.Pause();

    cout << "-----------------------------------------------------" << endl << endl;
    timerLaplacianLine2.Print("Line-2 Laplacian Time : ");
    timerLaplacianLine6.Print("Line-6 Laplacian Time : ");
    timerLaplacianLine6.PrintAverage("Line-6 Average Laplacian Time : ");
    unsigned int aggr_laplacian_time = timerLaplacianLine2.GetElapsedTime() + timerLaplacianLine6.GetElapsedTime();
    cout << "Aggregated Laplacian Time : " << aggr_laplacian_time << "ms" << endl;
    cout << "-----------------------------------------------------" << endl << endl;

    timerSaxpyLine2.Print("Line-2 Saxpy Time : ");
    timerSaxpyLine8.Print("Line-8 Saxpy Time : ");
    timerSaxpyLine8.PrintAverage("Line-8 Average Saxpy Time : ");
    timerSaxpyLine9_12.Print("Line-9-12 Saxpy Time : ");
    timerSaxpyLine9_12.PrintAverage("Line-9-12 Average Saxpy Time : ");
    timerSaxpyLine16.Print("Line-16 Saxpy Time : ");
    timerSaxpyLine16.PrintAverage("Line-16 Average Saxpy Time : ");
    unsigned int aggr_saxpy_time = timerSaxpyLine2.GetElapsedTime() + timerSaxpyLine8.GetElapsedTime() + timerSaxpyLine9_12.GetElapsedTime() + timerSaxpyLine16.GetElapsedTime();
    cout << "Aggregated Saxpy Time : " << aggr_saxpy_time << "ms" << endl;
    cout << "-----------------------------------------------------" << endl << endl;

    timerInnerProductLine4.Print("Line-4 InnerProduct Time : ");
    timerInnerProductLine6.Print("Line-6 InnerProduct Time : ");
    timerInnerProductLine6.PrintAverage("Line-6 Average InnerProduct Time : ");
    unsigned int aggr_inner_product_time = timerInnerProductLine4.GetElapsedTime() + timerInnerProductLine6.GetElapsedTime();
    cout << "Aggregated InnerProduct Time : " << aggr_inner_product_time << "ms" << endl;
    cout << "-----------------------------------------------------" << endl << endl;

    timerNormLine2.Print("Line-2 Norm Time : ");
    timerNormLine8.Print("Line-8 Norm Time : ");
    timerNormLine8.PrintAverage("Line-8 Average Norm Time : ");
    unsigned int aggr_norm_time = timerNormLine2.GetElapsedTime() + timerNormLine8.GetElapsedTime();
    cout << "Aggregated Norm Time : " << aggr_norm_time << "ms" << endl;
    cout << "-----------------------------------------------------" << endl << endl;

    timerCopyLine4.Print("Line-4 Copy Time : ");
    unsigned int aggr_copy_time = timerCopyLine4.GetElapsedTime();
    cout << "Aggregated Copy Time : " << aggr_copy_time << "ms" << endl;
    cout << "-----------------------------------------------------" << endl << endl;

    timerLine13.Print("Merged Line-13 Time : ");
    timerLine13.PrintAverage("Merged Line-13 Average Time : ");
    unsigned int aggr_line13_time = timerLine13.GetElapsedTime();
    cout << "-----------------------------------------------------" << endl << endl;

    timerWriteAsImage.Print("WriteAsImage Time : ");
    unsigned int write_as_image_time = timerWriteAsImage.GetElapsedTime();
    cout << "WriteAsImage Time : " << write_as_image_time << "ms" << endl;
    cout << "-----------------------------------------------------" << endl << endl;

    cout << "Total time : " << aggr_laplacian_time + aggr_saxpy_time + aggr_inner_product_time + aggr_norm_time + aggr_copy_time + aggr_line13_time + write_as_image_time << "ms" << endl;
    cout << "-----------------------------------------------------" << endl << endl;

    timerConjugateGradients.Print("Conjugate Gradients Time : ");
    cout << "-----------------------------------------------------" << endl << endl;

    return 0;
}
