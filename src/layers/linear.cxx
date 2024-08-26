#include "linear.hxx"
#include <cblas.h>
Linear::Linear(int inFeat, int outFeat) : inFeatures(inFeat), outFeatures(outFeat)
{
    weightMatrix = new double[outFeatures*inFeatures];
    auto counter = 0;
    for (int i = 0; i < outFeatures*inFeatures; ++i) {
        weightMatrix[i] = counter+1;
        counter++;
    }
    bias = new double[outFeat];

    for (int i = 0; i < outFeatures; ++i) {
        bias[i] = 1.0;
    }

    // print weight and bias
    printf("Weight matrix:\n");
    for (int i = 0; i < outFeatures; ++i) {
        for (int j = 0; j < inFeatures; ++j) {
            printf("%f ", weightMatrix[i*inFeatures + j]);
        }
        printf("\n");
    }

    printf("Bias:\n");

    for (int i = 0; i < outFeatures; ++i) {
       
        printf("%f ", bias[i]);
        printf("\n");
    }
}

Linear::~Linear()
{
    
    delete[] weightMatrix;
    delete[] bias;
}

double* Linear::forward(double* input)
{
    printf("Forwarding linear layer\n");
    double* output = new double[outFeatures];

    // forward the linear layer as w*in + b
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
            outFeatures, 1, inFeatures, 1.0, weightMatrix, inFeatures, input , 1, 0.0, output, 1);
    // add bias
    cblas_daxpy(outFeatures, 1.0, bias, 1, output, 1);

    return output;
}